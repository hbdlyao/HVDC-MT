
#include "CLineModel.h"
#include "CxbDefs.h"

using namespace std;

extern double BernoulliNum[];
extern double fac(unsigned int n);

//初始化谐波电流计算所需的参数
void CLineModel::Init_xbCurrentY()
{
	FreqStart = CxbParams::Frequence;
	FreqStep = CxbParams::Frequence;
	FreqDim = CxbParams::hMax;
	
	Z = new  CMatrix[FreqDim];
	Y = new  CMatrix[FreqDim];
	Ys = new CMatrix[FreqDim];
	Ym = new CMatrix[FreqDim];
	Yss = new CMatrix[FreqDim];
	Ymm = new CMatrix[FreqDim];
	AllLine_Y = new CMatrix[FreqDim];

	doInitY();
}

//初始化阻抗扫描所需参数
void CLineModel::Init_ImScanY(double vFreqStart, double vFreqStep, int vFreqDim)
{
	FreqStart = vFreqStart;
	FreqStep = vFreqStep;
	FreqDim = vFreqDim;

	Z = new  CMatrix[FreqDim];
	Y = new  CMatrix[FreqDim];
	Ys = new CMatrix[FreqDim];
	Ym = new CMatrix[FreqDim];
	Yss = new CMatrix[FreqDim];
	Ymm = new CMatrix[FreqDim];
	AllLine_Y = new CMatrix[FreqDim];

	doInitY();
}

void CLineModel::doInitY()
{
	CalAllLine();
}

//
void CLineModel::Clear()
{
	if (Z != nullptr)
		delete[] Z;//线路分段自导纳阵
	if (Y != nullptr)
		delete[] Y;//线路分段互导纳阵
	if (Ys != nullptr)
		delete [] Ys;//线路分段自导纳阵
	if (Ym != nullptr)
		delete [] Ym;//线路分段互导纳阵
	if (Yss != nullptr)
		delete [] Yss;//线路总自导纳阵
	if (Ymm != nullptr)
		delete [] Ymm;//线路总互导纳阵
	if (AllLine_Y != nullptr)
		delete [] AllLine_Y;//线路总导纳阵
}

double CLineModel::Omega(int k)
{
	return PI * 2 * (FreqStart + k * FreqStep);
}

void CLineModel::CalAllLine()
{

	CMatrix AllLine_T;
	CMatrix v_TMat, v_Ts, v_Tm;

	double vOmega;


	L = WireParam.get_Long();

	for (unsigned int k = 0; k < FreqDim; k++)
	{
		vOmega = Omega(k);

		WireParam.CalMatrix_Z(vOmega);
		WireParam.CalMatrix_Y(vOmega);

		Z[k] = WireParam.Z;
		Y[k] = WireParam.Y;

		//确定分段长度
		doCal_SegLength(k);

		//计算单长参数
		doCal_YsYm(k);

		//
		doCal_TMat(k, v_TMat);

		v_TMat.PowMat(SegCount, AllLine_T);

		AllLine_T.Split(v_Ts, v_Tm);

		v_Tm.inversion(Ymm[k]);

		Yss[k] = CMatrix(v_Ts.row) - Ymm[k] * v_Ts;

		AllLine_Y[k].Merge(Yss[k], Ymm[k], Ymm[k], Yss[k]);

	}
}

void CLineModel::doCal_SegLength(unsigned int k)
{
	CMatrix v_PowMat;

	double v_ZYNorm2;
	double v_Temp;


	(Z[k] * Y[k]).PowMat(9, v_PowMat);

	v_ZYNorm2 = (v_PowMat * Y[k]).norm2();
	v_ZYNorm2 = pow(16, 5)*v_ZYNorm2*BernoulliNum[2 * LINE_SEQ_SERIES_NUM];

	v_Temp = abs(LINE_GAMMA_MAX * SINGLE_LINE_COE * fac(2 * LINE_SEQ_SERIES_NUM) / v_ZYNorm2);

	SegLength = pow(abs(LINE_GAMMA_MAX * SINGLE_LINE_COE * fac(2 * LINE_SEQ_SERIES_NUM) / (pow(16, 5)*(v_PowMat * Y[k]).norm2()*BernoulliNum[2 * LINE_SEQ_SERIES_NUM])), 1.0 / (LINE_SEQ_SERIES_NUM * 2 - 1));
	//double SegLength1= pow(v_Temp,1.0 / (LINE_SEQ_SERIES_NUM * 2 - 1));
	SegCount = (unsigned int)(L * 1000 / SegLength);
#ifdef SEQ_5KM
	SegLength = 5000;
	SegCount = (unsigned int)(L * 1000 / SegLength);
#endif
	if (SegCount == 0)
		SegCount = 1;
	SegLength = L / SegCount * 1000;

}

void CLineModel::doCal_YsYm(unsigned int k)
{
	CMatrix v_InverMat, v_ZlYlMat, v_CothXMat, v_CschXMAt;
	//double v_temp=-0.1;
	(Z[k] * SegLength).inversion(v_InverMat);
	v_ZlYlMat = Z[k] * SegLength * Y[k] * SegLength;
	v_ZlYlMat.Cothx(v_CothXMat, LINE_SEQ_SERIES_NUM);
	v_ZlYlMat.Cschx(v_CschXMAt, LINE_SEQ_SERIES_NUM);
	Ys[k] = v_InverMat * v_CothXMat;
	Ym[k] = CMatrix(Z[0].row) - v_InverMat * v_CschXMAt;

}

void CLineModel::doCal_TMat(unsigned int k, CMatrix &v_TMat)
{
	CMatrix v_AMat, v_BMat,
		v_CMat, v_DMat;

	//double v_temp=-0.1;
	Ym[k].inversion(v_BMat);

	v_AMat = CMatrix(Z[0].row) - v_BMat * Ys[k];

	v_CMat = Ys[k] * v_BMat * Ys[k] - Ym[k];
	v_DMat = CMatrix(Z[0].row) - Ys[k] * v_BMat;

	v_TMat.Merge(v_AMat, v_BMat, v_CMat, v_DMat);


}