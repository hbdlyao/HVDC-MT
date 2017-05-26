
#include "CWire.h"
#include "Carson.h"
#include "CHvdcDefs.h"

/************************导体初始参数计算相关函数************************/

//计算导体分裂数目***********输入导体编号，返回分裂数目
double Cwire::doCal_SplitAmount(unsigned int vWirerNum)
{
	if (WireCount<5)
	{
		if (vWirerNum < 2) return L_SplitAmount;
		else return G_SplitAmount;
	}
	else
	{
		if (vWirerNum < 4) return L_SplitAmount;
		else return G_SplitAmount;
	}
}

//计算几何参数b矩阵*********************输入初始化的b矩阵容器
void  Cwire::doCal_b(dbMatrix &v_b)
{
	dbMatrix v_D(WireCount, doubleVector(WireCount)),
		v_d(WireCount, doubleVector(WireCount));
	doCal_D(v_D);
	doCal_d(v_d);
	for (unsigned int i = 0; i < WireCount; i++)
	{
		for (unsigned int j = 0; j < i; j++)
		{

			v_b[i][j] = log(v_D[i][j] / v_d[i][j]);
			v_b[j][i] = v_b[i][j];

		}
		v_b[i][i] = log(v_D[i][i] / v_d[i][i]);

	}

}

//计算几何参数Theta矩阵*****************输入初始化的v_Th矩阵容器
void  Cwire::doCal_Th(dbMatrix &v_Th)
{
	dbMatrix v_Hspace(WireCount, doubleVector(WireCount)),
		v_Height(WireCount, doubleVector(WireCount));
	doCal_Hspace(v_Hspace);
	doCal_Height(v_Height);
	for (unsigned int i = 0; i < WireCount; i++)
	{
		for (unsigned int j = 0; j < WireCount; j++)
			v_Th[i][j] = atan(v_Hspace[i][j] / v_Height[i][j]);
	}
}
//计算r矩阵******************输入频率w，初始化的v_Z_r矩阵容器
void  Cwire::doCal_r(double v_w, dbMatrix &v_Z_r)
{
	//double v_w = PI * 2 * DEFAULT_FREQUENCY ;
	dbMatrix v_D(WireCount, doubleVector(WireCount));
	doCal_D(v_D);

	for (unsigned int i = 0; i < WireCount; i++)
	{
		for (unsigned int j = 0; j < WireCount; j++)
		{
			v_Z_r[i][j] = sqrt(v_w*MU / SoilRe)*v_D[i][j];
		}
	}

}

//计算镜像距离D矩阵******************输入初始化的v_D矩阵容器
void Cwire::doCal_D(dbMatrix &v_D)
{
	dbMatrix v_Hspace(WireCount, doubleVector(WireCount)),
		v_Height(WireCount, doubleVector(WireCount));

	doCal_Hspace(v_Hspace);
	doCal_Height(v_Height);

	for (unsigned int i = 0; i<WireCount; i++)
	{
		for (unsigned int j = 0; j<WireCount; j++)
			v_D[i][j] = sqrt(v_Hspace[i][j] * v_Hspace[i][j] + v_Height[i][j] * v_Height[i][j]);
	}
}

//计算导体间的水平距离矩阵*******************v_Hspace存放数据
void Cwire::doCal_Hspace(dbMatrix &v_Hspace)
{
	v_Hspace[0][1] = Hspace[0];
	v_Hspace[0][2] = abs(Hspace[0] - Hspace[1]) / 2.0;
	v_Hspace[1][2] = (Hspace[0] + Hspace[1]) / 2.0;

	if (WireCount>3)
	{
		v_Hspace[0][3] = v_Hspace[1][2];
		v_Hspace[2][3] = Hspace[1];
		v_Hspace[1][3] = v_Hspace[0][2];
	}

	if (WireCount>4)
	{
		v_Hspace[0][4] = abs(Hspace[0] - Hspace[2]) / 2;
		v_Hspace[2][4] = abs(Hspace[1] - Hspace[2]) / 2;
		v_Hspace[1][4] = (Hspace[0] + Hspace[2]) / 2;
		v_Hspace[3][4] = (Hspace[1] + Hspace[2]) / 2;
	}
	if (WireCount>5)
	{
		v_Hspace[0][5] = v_Hspace[1][4];
		v_Hspace[2][5] = v_Hspace[3][4];
		v_Hspace[1][5] = v_Hspace[0][4];
		v_Hspace[3][5] = v_Hspace[2][4];
		v_Hspace[4][5] = Hspace[2];
	}

	for (unsigned int i = 0; i < WireCount; i++)
	{
		v_Hspace[i][i] = 0;
		for (unsigned int j = 0; j < i; j++)
		{
			v_Hspace[i][j] = v_Hspace[j][i];
		}
	}

}

//计算导体间的垂直距离矩阵*****************v_Height存放数据
void Cwire::doCal_Height(dbMatrix &v_Height)
{
	for (unsigned int i = 0; i<WireCount; i++)
	{
		for (unsigned int j = 0; j<WireCount; j++)
			v_Height[i][j] = doCal_AvHeight(i) + doCal_AvHeight(j);
	}
}

//计算导线间距d矩阵*****************v_d存储数据
void Cwire::doCal_d(dbMatrix &v_d)
{
	dbMatrix v_Hspace(WireCount, doubleVector(WireCount));

	doCal_Hspace(v_Hspace);

	v_d[0][1] = v_Hspace[0][1];
	v_d[0][2] = hypot(v_Hspace[0][2], doCal_AvHeight(2) - doCal_AvHeight(0));
	v_d[1][2] = hypot(v_Hspace[1][2], doCal_AvHeight(2) - doCal_AvHeight(1));

	if (WireCount>3)
	{
		v_d[0][3] = v_d[1][2];
		v_d[1][3] = v_d[0][2];
		v_d[2][3] = v_Hspace[2][3];
	}

	if (WireCount>4)
	{
		v_d[0][4] = hypot(v_Hspace[0][4], doCal_AvHeight(4) - doCal_AvHeight(0));
		v_d[1][4] = hypot(v_Hspace[1][4], doCal_AvHeight(4) - doCal_AvHeight(1));
		v_d[2][4] = hypot(v_Hspace[2][4], doCal_AvHeight(4) - doCal_AvHeight(2));
	}
	if (WireCount>5)
	{
		v_d[0][5] = v_d[1][4];
		v_d[1][5] = v_d[0][4];
		v_d[2][5] = hypot(v_Hspace[2][5], doCal_AvHeight(5) - doCal_AvHeight(2));
	}
	for (unsigned int i = 0; i<WireCount; i++)
	{
		v_d[i][i] = doCal_EqRadius(i);
		for (unsigned int j = 0; j<i; j++)
			v_d[i][j] = v_d[j][i];
	}
}

//计算导线平局高度*******************输入线路编号，返回平均高度
double Cwire::doCal_AvHeight(unsigned int vWireNum)
{
	if (vWireNum<2)
		return Height[0] - Sag[0] * 2.0 / 3.0;
	else if (vWireNum<4)
		return Height[0] + Height[1] - Sag[1] * 2.0 / 3.0;
	else
		return Height[0] + Height[1] + Height[2] - Sag[2] * 2.0 / 3.0;

}

//计算各导线的等值半径**********输入导体编号，返回半径值
double  Cwire::doCal_EqRadius(unsigned int vWireNum)
{
	double v_SplitAmount, v_CondRadius;
	v_SplitAmount = doCal_SplitAmount(vWireNum);
	v_CondRadius = doCal_CondRadius(vWireNum);
	if (v_SplitAmount == 1)
		return v_CondRadius;
	double vM = L_BundleSpace / (2.0 * sin(PI / v_SplitAmount));
	return vM*pow(v_SplitAmount * v_CondRadius / vM, 1.0 / v_SplitAmount);

}


/**************计算  Z   矩阵时用到的初始参数计算子函数******************/

double Cwire::doCal_CondMU(unsigned int vWireNum)
{
	return MU;
}

double Cwire::doCal_CondRadius(unsigned int vWireNum)
{
	if (WireCount<5)
	{
		if (vWireNum < 2) return L_CondRadius;
		else return G_CondRadius;
	}
	else
	{
		if (vWireNum < 4) return L_CondRadius;
		else return G_CondRadius;
	}
}

double Cwire::doCal_CondDelta(unsigned int vWireNum)
{
	double v_CondValue, v_CondRadius;
	unsigned int v_CondType;
	doCal_CondValue(vWireNum, v_CondValue, v_CondType);
	v_CondRadius = doCal_CondRadius(vWireNum);
	switch (v_CondType)
	{
	case CondMeter: return v_CondValue;
	case ResisMeter: return 1.0 / v_CondValue;
	case ResisPerKilo: return 1.0 / v_CondValue / PI / v_CondRadius / v_CondRadius * 1000;
	default: cout << "线路电导率计算错误" << endl; return -1;
	}
}

void Cwire::doCal_CondValue(unsigned int vWireNum, double &v_CondValue, unsigned int &v_CondType)
{
	if (WireCount<5)
	{
		if (vWireNum<2)   { v_CondValue = L_CondValue; v_CondType = L_CondType; }
		else			  { v_CondValue = G_CondValue; v_CondType = G_CondType; }
	}
	else
	{
		if (vWireNum<4)   { v_CondValue = L_CondValue; v_CondType = L_CondType; }
		else			  { v_CondValue = G_CondValue; v_CondType = G_CondType; }
	}
}

/***********************计算单长参数Y矩阵相关函数*******************/

void Cwire::CalMatrix_Y(double vOmega)
{

	doCalMatrix_C();

	Y = C * CComplex(0, vOmega);
}


void Cwire::doCalMatrix_C()
{
	unsigned int v_Kn = 0;
	if (WireCount<5)   v_Kn = 2;
	else              v_Kn = 4;
	CMatrix v_Y_P(v_Kn);
	doCalMatrix_P(v_Y_P);
	v_Y_P.inversion(C);
}


//求解Y矩阵时的P矩阵
void Cwire::doCalMatrix_P(CMatrix &v_Y_P)
{

	dbMatrix v_b(WireCount, doubleVector(WireCount));

	doCal_b(v_b);
	unsigned int v_Kn = 0, v_Nn = 0;

	switch (WireCount)
	{
	case 3:   v_Kn = 2;  v_Nn = 1; break;
	case 4:   v_Kn = 2;  v_Nn = 2; break;
	case 5:   v_Kn = 4;  v_Nn = 1; break;
	case 6:   v_Kn = 4;  v_Nn = 2; break;

	}

	CMatrix v_YK(v_Kn, v_Kn), v_YL(v_Kn, v_Nn),
		v_YM(v_Nn, v_Kn), v_YN(v_Nn, v_Nn);

	doCal_YK(v_YK, v_b);
	doCal_YL(v_YL, v_b);
	doCal_YM(v_YM, v_b);
	doCal_YN(v_YN, v_b);
	v_YN.inversion(v_YN);
	v_Y_P = v_YK - v_YL*v_YN*v_YM;
	//v_Y_P = v_YK - v_YL*v_YN*v_YM;
}

void Cwire::doCal_YK(CMatrix &v_YK, dbMatrix &v_b)
{
	for (unsigned int i = 0; i < v_YK.row; i++)
	{
		for (unsigned int j = 0; j < v_YK.col; j++)
		{
			v_YK._mat[i][j] = v_b[i][j] / (2.0* PI * EPSILON);
		}
	}
}

void Cwire::doCal_YL(CMatrix &v_YL, dbMatrix &v_b)
{
	unsigned int v_Kn;
	v_Kn = v_b[0].size() - v_YL.col;
	for (unsigned int i = 0; i < v_YL.row; i++)
	{
		for (unsigned int j = 0; j < v_YL.col; j++)
		{
			v_YL._mat[i][j] = v_b[i][j + v_Kn] / (2.0 * PI * EPSILON);
		}
	}
}

void Cwire::doCal_YM(CMatrix &v_YM, dbMatrix &v_b)
{
	unsigned int v_Kn;
	v_Kn = v_b[0].size() - v_YM.row;
	for (unsigned int i = 0; i < v_YM.row; i++)
	{
		for (unsigned int j = 0; j < v_YM.col; j++)
		{
			v_YM._mat[i][j] = v_b[i + v_Kn][j] / (2.0 * PI * EPSILON);
		}
	}
}

void Cwire::doCal_YN(CMatrix &v_YN, dbMatrix &v_b)
{
	unsigned int v_Kn;
	v_Kn = v_b[0].size() - v_YN.row;
	for (unsigned int i = 0; i < v_YN.row; i++)
	{
		for (unsigned int j = 0; j < v_YN.col; j++)
		{
			v_YN._mat[i][j] = v_b[i + v_Kn][j + v_Kn] / (2.0* PI * EPSILON);
		}
	}
}

/**********************计算单长参数Z矩阵相关函数******************/

double br0(unsigned int v_WireNum, double v_x);
double bi0(unsigned int v_WireNum, double v_x);
double br1(unsigned int v_WireNum, double v_x);
double bi1(unsigned int v_WireNum, double v_x);


void Cwire::CalMatrix_Z(double vOmega)
{
	dbMatrix v_Z_R(WireCount, doubleVector(WireCount)),
		v_Z_L(WireCount, doubleVector(WireCount));

	double v_w = vOmega;

	doCal_Z_RL(v_w, v_Z_R, v_Z_L);

	unsigned int v_An = 0, v_Dn = 0;

	switch (WireCount)
	{
	case 3:   v_An = 2;  v_Dn = 1; break;
	case 4:   v_An = 2;  v_Dn = 2; break;
	case 5:   v_An = 4;  v_Dn = 1; break;
	case 6:   v_An = 4;  v_Dn = 2; break;

	}

	CMatrix v_Z_A(v_An, v_An),
		v_Z_B(v_An, v_Dn),
		v_Z_C(v_Dn, v_An),
		v_Z_D(v_Dn, v_Dn);


	doCal_Z_A(v_Z_A, v_Z_R, v_Z_L);
	doCal_Z_B(v_Z_B, v_Z_R, v_Z_L);
	doCal_Z_C(v_Z_C, v_Z_R, v_Z_L);
	doCal_Z_D(v_Z_D, v_Z_R, v_Z_L);

	v_Z_D.inversion(v_Z_D);

	Z = v_Z_A - v_Z_B*v_Z_D*v_Z_C;

}


void Cwire::doCal_Z_A(CMatrix &v_Z_A, dbMatrix &v_Z_R, dbMatrix &v_Z_L)
{
	for (unsigned int i = 0; i < v_Z_A.row; i++)
	{
		for (unsigned int j = 0; j < v_Z_A.col; j++)
		{
			v_Z_A._mat[i][j] = CComplex(v_Z_R[i][j], v_Z_L[i][j]);
		}
	}
}


void Cwire::doCal_Z_B(CMatrix &v_Z_B, dbMatrix &v_Z_R, dbMatrix &v_Z_L)
{
	unsigned int v_An;
	v_An = v_Z_R[0].size() - v_Z_B.col;

	for (unsigned int i = 0; i < v_Z_B.row; i++)
	{
		for (unsigned int j = 0; j < v_Z_B.col; j++)
		{
			v_Z_B._mat[i][j] = CComplex(v_Z_R[i][j + v_An], v_Z_L[i][j + v_An]);
		}
	}
}

void Cwire::doCal_Z_C(CMatrix &v_Z_C, dbMatrix &v_Z_R, dbMatrix &v_Z_L)
{
	unsigned int v_An;
	v_An = v_Z_R[0].size() - v_Z_C.row;

	for (unsigned int i = 0; i < v_Z_C.row; i++)
	{
		for (unsigned int j = 0; j < v_Z_C.col; j++)
		{
			v_Z_C._mat[i][j] = CComplex(v_Z_R[i + v_An][j], v_Z_L[i + v_An][j]);
		}
	}
}

void Cwire::doCal_Z_D(CMatrix &v_Z_D, dbMatrix &v_Z_R, dbMatrix &v_Z_L)
{
	unsigned int v_An;
	v_An = v_Z_R[0].size() - v_Z_D.col;

	for (unsigned int i = 0; i < v_Z_D.row; i++)
	{
		for (unsigned int j = 0; j < v_Z_D.col; j++)
		{
			v_Z_D._mat[i][j] = CComplex(v_Z_R[i + v_An][j + v_An], v_Z_L[i + v_An][j + v_An]);
		}
	}
}

void Cwire::doCal_Z_RL(double v_w, dbMatrix &v_Z_R, dbMatrix &v_Z_L)

{
	dbMatrix v_Z_Re(WireCount, doubleVector(WireCount)),
		v_Z_Le(WireCount, doubleVector(WireCount)),
		v_Z_Li(WireCount, doubleVector(WireCount));
	doubleVector v_Z_Rc(WireCount), v_Z_Lc(WireCount);

	doCal_Z_Li(v_Z_Li);
	doCal_Z_ReLe(v_w, v_Z_Re, v_Z_Le);
	doCal_Z_RcLc(v_w, v_Z_Rc, v_Z_Lc);


	for (unsigned int i = 0; i < WireCount; i++)
	{
		for (unsigned int j = 0; j < WireCount; j++)
		{
			v_Z_R[i][j] = v_Z_Re[i][j];
			v_Z_L[i][j] = v_Z_Li[i][j] + v_Z_Le[i][j];
			v_Z_L[i][j] = v_Z_L[i][j] * v_w;
		}
		v_Z_R[i][i] = v_Z_R[i][i] + v_Z_Rc[i];
		v_Z_L[i][i] = v_Z_L[i][i] / v_w + v_Z_Lc[i];
		v_Z_L[i][i] = v_Z_L[i][i] * v_w;
	}


}

// 求解理想电感矩阵Li  需要外部定义二维数组v_Z_Li
void  Cwire::doCal_Z_Li(dbMatrix &v_Z_Li)
{
	dbMatrix  v_b(WireCount, doubleVector(WireCount));
	doCal_b(v_b);


	for (unsigned int i = 0; i < WireCount; i++)
	{
		for (unsigned int j = 0; j < WireCount; j++)
		{
			//理想电感
			v_Z_Li[i][j] = MU / 2 / PI * v_b[i][j];
		}
	}

}

//需外部定义二维数组v_Z_Re和v_Z_Le  
void  Cwire::doCal_Z_ReLe(double v_w, dbMatrix &v_Z_Re, dbMatrix &v_Z_Le)
{
	dbMatrix v_Th(WireCount, doubleVector(WireCount)),
		//v_D(WireCount,doubleVector(WireCount)),
		v_Z_r(WireCount, doubleVector(WireCount));

	doCal_Th(v_Th);
	//doCal_D(v_D);
	doCal_r(v_w, v_Z_r);


	double v_Z_E, v_Z_F;

	for (unsigned int i = 0; i < WireCount; i++)
	{
		for (unsigned int j = 0; j < WireCount; j++)
		{
			v_Z_E = carson_E(v_Z_r[i][j], v_Th[i][j]);
			v_Z_F = carson_F(v_Z_r[i][j], v_Th[i][j]);
			/*if (!carson(&v_Z_E, &v_Z_F, v_Z_r[i][j], v_Th[i][j]))
			{*/
			v_Z_Re[i][j] = v_w * MU / PI * v_Z_E;
			v_Z_Le[i][j] = MU / PI * v_Z_F;
			//}
			//else { cout << "error: carson calculation wrong" << endl; }
		}
	}
}


//需要外部定义一维数组v_Z_Rc和v_Z_Lc  
void  Cwire::doCal_Z_RcLc(double v_w, doubleVector &v_Z_Rc, doubleVector &v_Z_Lc)
{
	double v_x;

	double v_br0, v_br1, v_bi0, v_bi1;
	double v_CondRadius, v_CondDelta, v_CondMU;

	for (unsigned int i = 0; i < WireCount; i++)
	{


		v_x = doCal_RcLc_x(i, v_w);

		v_br0 = br0(i, v_x);
		v_br1 = br1(i, v_x);
		v_bi0 = bi0(i, v_x);
		v_bi1 = bi1(i, v_x);

		v_CondRadius = doCal_CondRadius(i);
		v_CondDelta = doCal_CondDelta(i);
		v_CondMU = doCal_CondMU(i);

		v_Z_Rc[i] = v_x / 2.0 * (v_br0*v_br1 + v_bi0*v_bi1);
		v_Z_Rc[i] = v_Z_Rc[i] / (v_br1*v_br1 + v_bi1*v_bi1);
		v_Z_Rc[i] = v_Z_Rc[i] / (PI * v_CondRadius * v_CondRadius *v_CondDelta);
		//v_Z_Rc[i]=v_x/2*(v_br0*v_br1 + v_bi0*v_bi1)/(v_br1*v_br1 + v_bi1*v_bi1)/PI/v_CondRadius/v_CondRadius/v_CondDelta;
		v_Z_Rc[i] = v_Z_Rc[i] / doCal_SplitAmount(i);

		v_Z_Lc[i] = (v_br1*v_bi0 - v_br0*v_bi1)*v_CondMU;
		v_Z_Lc[i] = v_Z_Lc[i] / (v_x*(v_br1*v_br1 + v_bi1*v_bi1));
		v_Z_Lc[i] = v_Z_Lc[i] / (2.0*PI);

		//v_Z_Lc[i]=0.5/v_x*(v_bi0*v_br1-v_br0*v_bi1)/(v_br1*v_br1 + v_bi1*v_bi1)/PI*v_CondMU;
		v_Z_Lc[i] = v_Z_Lc[i] / doCal_SplitAmount(i);
	}

}


double Cwire::doCal_RcLc_x(unsigned int vWireNum, double v_w)
{
	double v_CondMU, v_CondDelta, v_CondRadius;
	v_CondMU = doCal_CondMU(vWireNum);
	v_CondDelta = doCal_CondDelta(vWireNum);
	v_CondRadius = doCal_CondRadius(vWireNum);
	double v_x = sqrt(v_w*v_CondMU*v_CondDelta)*v_CondRadius;
	return v_x;
}

//计算r0、r1、i0、i1时需要计算n值
unsigned int RcLc_n(double v_x)
{
	unsigned int v_n;
	if (v_x < 7)
		v_n = 5;
	else if (v_x < 13)
		v_n = 8;
	else if (v_x < 20)
		v_n = 13;
	else if (v_x < 30)
		v_n = 17;
	else if (v_x < 40)
		v_n = 20;
	else
		v_n = 40;
	return v_n;
}


//计算Rc和Lc时需要计算r0、r1、i0、i1
double br0(unsigned int v_WireNum, double v_x)
{

	double v_An = 1;
	double vs = v_An;
	unsigned int v_n;
	v_n = RcLc_n(v_x);

	for (unsigned int i = 1; i <= v_n; i++)
	{
		v_An = -1.0*v_An*pow(v_x, 4) / (pow(4.0*i, 2)*pow(4.0*i - 2.0, 2));
		vs += v_An;
	}
	return vs;
}

double bi0(unsigned int v_WireNum, double v_x)
{

	double v_Bn = v_x*v_x / 4.0;
	double vs = v_Bn;

	unsigned int v_n;
	v_n = RcLc_n(v_x);

	for (unsigned int i = 1; i <= v_n; i++)
	{
		v_Bn = -1.0*v_Bn*pow(v_x, 4) / (pow(4.0*i, 2)*pow(4.0*i + 2.0, 2));
		vs += v_Bn;
	}
	return vs;
}

double br1(unsigned int v_WireNum, double v_x)
{
	double v_Cn = v_x / 2.0;
	double vs = v_Cn;

	unsigned int v_n;
	v_n = RcLc_n(v_x);

	for (unsigned int i = 1; i <= v_n; i++)
	{
		v_Cn = -1.0*v_Cn*pow(v_x, 4) / (pow(4.0*i, 2)*(4.0*i - 2.0)*(4.0*i + 2.0));
		vs += v_Cn;
	}
	return vs;
}

double bi1(unsigned int v_WireNum, double v_x)
{
	double v_Dn = v_x*v_x*v_x / 16.0;
	double vs = v_Dn;

	unsigned int v_n;
	v_n = RcLc_n(v_x);

	for (unsigned int i = 1; i <= v_n; i++)
	{
		v_Dn = -1.0*v_Dn*pow(v_x, 4) / ((4.0*i)*pow(4.0*i + 2.0, 2)*(4.0*i + 4.0));
		vs += v_Dn;
	}
	return vs;
}
