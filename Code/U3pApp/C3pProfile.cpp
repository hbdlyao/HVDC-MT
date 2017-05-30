
#include "C3pProfile.h"

#include "C3pDefs.h"

#include "C3pParams.h"

#include "CIntergral.h"

#define vprcise 0.000000001

void C3pProfile::InitOrder(C3pOrder * vOrder)
{
	p3pOrder = vOrder;
}

void C3pProfile::ClearData()
{
	delete[] pU3pData;
}

void C3pProfile::NewU3pData(int vGNDType)
{
	switch (vGNDType)
	{
	case Ground10:
		doNewU3pData1();
		break;
	case Ground11:
		doNewU3pData1();
		break;
	case Ground20:
		doNewU3pData2();
		break;
	case Ground21:
		doNewU3pData2();
		break;
	default:
		break;
	}

}
void C3pProfile::doNewU3pData1()
{	//单极

	n6pValor = 2 * ValvorNum();
	pU3pData = new struct_3p_hData[n6pValor];

	for (int i = 0; i < StaCount(); i++)
	{
		switch (ValvorNum())
		{
		case 1:
			pU3pData[0 + i * 2].StaIndex = i;
			pU3pData[0 + i * 2].ValvorIndex = U3p_6pValvor_Pos11;

			pU3pData[1 + i * 2].StaIndex = i;
			pU3pData[1 + i * 2].ValvorIndex = U3p_6pValvor_Pos12;

			break;

		case 2:
			pU3pData[0 + i * 4].StaIndex = i;
			pU3pData[0 + i * 4].ValvorIndex = U3p_6pValvor_Pos11;

			pU3pData[1 + i * 4].StaIndex = i;
			pU3pData[1 + i * 4].ValvorIndex = U3p_6pValvor_Pos12;

			pU3pData[2 + i * 4].StaIndex = i;
			pU3pData[2 + i * 4].ValvorIndex = U3p_6pValvor_Pos21;

			pU3pData[3 + i * 4].StaIndex = i;
			pU3pData[3 + i * 4].ValvorIndex = U3p_6pValvor_Pos22;

			break;

		default:
			break;
		}//switch	

	}//for
	for (int i = 0; i < n6pValor; i++)
	{
		pU3pData[i].hUv = nullptr;
		pU3pData[i].USrc3p1 = new struct_3p_hUv[C3pParams::hMax];
		pU3pData[i].USrc3p2 = new struct_3p_hUv[C3pParams::hMax];
	}
}

void C3pProfile::doNewU3pData2()
{//双极

	n6pValor = 4 * ValvorNum();
	pU3pData = new struct_3p_hData[n6pValor];

	for (int i = 0; i < StaCount(); i++)
	{
		switch (ValvorNum())
		{
		case 1:
			pU3pData[0 + i * 4].StaIndex = i;
			pU3pData[0 + i * 4].ValvorIndex = U3p_6pValvor_Pos11;

			pU3pData[1 + i * 4].StaIndex = i;
			pU3pData[1 + i * 4].ValvorIndex = U3p_6pValvor_Pos12;

			pU3pData[2 + i * 4].StaIndex = i;
			pU3pData[2 + i * 4].ValvorIndex = U3p_6pValvor_Neg21;

			pU3pData[3 + i * 4].StaIndex = i;
			pU3pData[3 + i * 4].ValvorIndex = U3p_6pValvor_Neg22;

			break;

		case 2:
			pU3pData[0 + i * 8].StaIndex = i;
			pU3pData[0 + i * 8].ValvorIndex = U3p_6pValvor_Pos11;

			pU3pData[1 + i * 8].StaIndex = i;
			pU3pData[1 + i * 8].ValvorIndex = U3p_6pValvor_Pos12;

			pU3pData[2 + i * 8].StaIndex = i;
			pU3pData[2 + i * 8].ValvorIndex = U3p_6pValvor_Pos21;

			pU3pData[3 + i * 8].StaIndex = i;
			pU3pData[3 + i * 8].ValvorIndex = U3p_6pValvor_Pos22;

			pU3pData[4 + i * 8].StaIndex = i;
			pU3pData[4 + i * 8].ValvorIndex = U3p_6pValvor_Neg11;

			pU3pData[5 + i * 8].StaIndex = i;
			pU3pData[5 + i * 8].ValvorIndex = U3p_6pValvor_Neg12;

			pU3pData[6 + i * 8].StaIndex = i;
			pU3pData[6 + i * 8].ValvorIndex = U3p_6pValvor_Neg21;

			pU3pData[7 + i * 8].StaIndex = i;
			pU3pData[7 + i * 8].ValvorIndex = U3p_6pValvor_Neg22;

			break;

		default:
			break;
		}//switch	

	}//for
	for (int i = 0; i < n6pValor; i++)
	{
		pU3pData[i].hUv = nullptr;
		pU3pData[i].USrc3p1 = new struct_3p_hUv[C3pParams::hMax];
		pU3pData[i].USrc3p2 = new struct_3p_hUv[C3pParams::hMax];
	}
}

int C3pProfile::StaCount()
{
	return C3pParams::StationCount;

}

int C3pProfile::ValvorNum()
{
	return (p3pOrder->nValNum);

}

void C3pProfile::ReSetData()
{
	
}

void C3pProfile::SolveMiu()
{
	for (int vK = 0; vK < CellDim; vK++)
		doSolveMiu(vK);
}

void C3pProfile::doSolveMiu(int vK)
{
	//刘畅
	int vStationType = pU3pData[vK].StationType;
	double vL = pU3pData[vK].LabcNd;
	double valpha = pU3pData[vK].AngleNdRad;
	double vR = pU3pData[vK].RabcNd;
	double vId = pU3pData[vK].Id;
	double vU1 = pU3pData[vK].UvRms;
	double vLabc[3];
	double vMiuNd = pU3pData[vK].MiuNd;
	double vMiu[6];
	double vOmega;//?

				  //
	vOmega = C3pParams::Frequence * 2 * PI;

	for (int i = 0; i < 6; i++)
		vMiu[i] = pU3pData[vK].Miu[i];
	for (int i = 0; i < 3; i++)
		vLabc[i] = pU3pData[vK].Labc[i];
	double valphai[6];
	for (int i = 0; i < 6; i++)
		valphai[i] = pU3pData[vK].AngleRad[i];

	//整流侧
	if (vStationType == 0)
	{
		//无偏差
		double vIs = (sqrt(2))*vU1 / sqrt(4 * vR*vR + 4 * vOmega*vOmega*vL*vL);
		double vbeta = atan(vOmega*vL / vR);
		double vF = vId - vIs*sin(valpha + vMiuNd - vbeta) - vId / 2 + (vIs*sin(valpha - vbeta) + vId / 2)*exp(-vMiuNd*vR / vOmega / vL);
		double dvF = -vIs*cos(valpha + vMiuNd - vbeta) - ((vIs*sin(valpha - vbeta) + vId / 2)*exp(-vR*vMiuNd / vOmega / vL))*vR / vOmega / vL;
		while (abs(vF) > vprcise)
		{
			vF = vId - vIs*sin(valpha + vMiuNd - vbeta) - vId / 2 + (vIs*sin(valpha - vbeta) + vId / 2)*exp(-vMiuNd*vR / vOmega / vL);
			dvF = -vIs*cos(valpha + vMiuNd - vbeta) - ((vIs*sin(valpha - vbeta) + vId / 2)*exp(-vR*vMiuNd / vOmega / vL))*vR / vOmega / vL;
			vMiuNd = vMiuNd - vF / dvF;
		}
		//有偏差
		vMiu[0] = doOneMiuRec(vR, vLabc[0], vLabc[2], vId, valphai[0], vOmega, vMiu[0], vU1);
		vMiu[1] = doOneMiuRec(vR, vLabc[1], vLabc[2], vId, valphai[1], vOmega, vMiu[1], vU1);
		vMiu[2] = doOneMiuRec(vR, vLabc[0], vLabc[1], vId, valphai[2], vOmega, vMiu[2], vU1);
		vMiu[3] = doOneMiuRec(vR, vLabc[0], vLabc[2], vId, valphai[3], vOmega, vMiu[3], vU1);
		vMiu[4] = doOneMiuRec(vR, vLabc[1], vLabc[2], vId, valphai[4], vOmega, vMiu[4], vU1);
		vMiu[5] = doOneMiuRec(vR, vLabc[0], vLabc[1], vId, valphai[5], vOmega, vMiu[5], vU1);

	}
	else//逆变侧
	{
		//无偏差
		double vIs = (sqrt(2))*vU1 / sqrt(4 * vR*vR + 4 * vOmega*vOmega*vL*vL);
		double vbeta = atan(vOmega*vL / vR);
		double vF = vId - vIs*sin(PI - valpha - vbeta) - vId / 2 + (vIs*sin(PI - vMiuNd - valpha - vbeta) + vId / 2)*exp(-vMiuNd*vR / vOmega / vL);
		double dvF = -vIs*cos(PI - vMiuNd - vR - vbeta)*exp(-vR*vMiuNd / vL / vOmega) - (vIs*sin(PI - vMiuNd - valpha - vbeta) + vId / 2)*(exp(-vMiuNd*vR / vOmega / vL))*vR / vOmega / vL;
		while (abs(vF) > vprcise)
		{
			vF = vId - vIs*sin(PI - valpha - vbeta) - vId / 2 + (vIs*sin(PI - vMiuNd - valpha - vbeta) + vId / 2)*exp(-vMiuNd*vR / vOmega / vL);
			dvF = -vIs*cos(PI - vMiuNd - vR - vbeta)*exp(-vR*vMiuNd / vL / vOmega) - (vIs*sin(PI - vMiuNd - valpha - vbeta) + vId / 2)*(exp(-vMiuNd*vR / vOmega / vL))*vR / vOmega / vL;
			vMiuNd = vMiuNd - vF / dvF;
		}
		//有偏差
		vMiu[0] = doOneMiuInv(vR, vLabc[0], vLabc[2], vId, valphai[0], vOmega, vMiu[0], vU1);
		vMiu[1] = doOneMiuInv(vR, vLabc[1], vLabc[2], vId, valphai[1], vOmega, vMiu[1], vU1);
		vMiu[2] = doOneMiuInv(vR, vLabc[0], vLabc[1], vId, valphai[2], vOmega, vMiu[2], vU1);
		vMiu[3] = doOneMiuInv(vR, vLabc[0], vLabc[2], vId, valphai[3], vOmega, vMiu[3], vU1);
		vMiu[4] = doOneMiuInv(vR, vLabc[1], vLabc[2], vId, valphai[4], vOmega, vMiu[4], vU1);
		vMiu[5] = doOneMiuInv(vR, vLabc[0], vLabc[1], vId, valphai[5], vOmega, vMiu[5], vU1);
	}


	//
	for (int i = 0; i < 6; i++)
		pU3pData[vK].Miu[i] = vMiu[i];
	pU3pData[vK].MiuNd = vMiuNd;
}

double C3pProfile::doOneMiuRec(double vR, double vL1, double vL2, double vId, double va, double vOmega, double vu, double vU1)  //计算换相角整流侧
{
	double vIs = (sqrt(2))*vU1 / sqrt(4 * vR*vR + (vOmega*vL1 + vOmega*vL2)*(vOmega*vL1 + vOmega*vL2));
	double vbeta = atan(vOmega*(vL1 + vL2) / 2 / vR);
	double vF = vId - vIs*sin(va + vu - vbeta) - vId / 2 + (vIs*sin(va - vbeta) + vId / 2)*exp(-2 * vR*vu / ((vL1 + vL2) * vOmega));
	double dvF = -vIs*cos(va + vu - vbeta) - ((vIs*sin(va - vbeta) + vId / 2)*exp(-(2 * vR)*vu / ((vL1 + vL2)*vOmega)))*(2 * vR) / (vOmega*(vL1 + vL2));
	while (abs(vF)> vprcise)
	{
		vF = vId - vIs*sin(va + vu - vbeta) - vId / 2 + (vIs*sin(va - vbeta) + vId / 2)*exp(-(2 * vR)*vu / ((vL1 + vL2)*vOmega));
		dvF = -vIs*cos(va + vu - vbeta) - ((vIs*sin(va - vbeta) + vId / 2)*exp(-(2 * vR)*vu / ((vL1 + vL2)*vOmega)))*(2 * vR) / (vOmega*(vL1 + vL2));
		vu = vu - vF / dvF;
	}
	return vu;
}

double C3pProfile::doOneMiuInv(double vR, double vL1, double vL2, double vId, double va, double vOmega, double vu, double vU1)  //计算换相角逆变侧
{
	double vIs = (sqrt(2))*vU1 / sqrt(4 * vR*vR + (vOmega*vL1 + vOmega*vL2)*(vOmega*vL1 + vOmega*vL2));
	double vbeta = atan(vOmega*(vL1 + vL2) / 2 / vR);
	double vF = vId - vIs*sin(PI - va - vbeta) - vId / 2 + (vIs*sin(PI - vu - va - vbeta) + vId / 2)*exp(-2 * vR*vu / ((vL1 + vL2)*vOmega));
	double dvF = -vIs*cos(PI - vu - va - vbeta)*exp(-2 * vR*vu / (vL1 + vL2) / vOmega) - (vIs*sin(PI - vu - va - vbeta) + vId / 2)*exp(-2 * vR*vu / (vL1 + vL2)) * 2 * vR / (vL1 + vL2) / vOmega;
	while (abs(vF)> vprcise)
	{
		vF = vId - vIs*sin(PI - va - vbeta) - vId / 2 + (vIs*sin(PI - vu - va - vbeta) + vId / 2)*exp(-2 * vR*vu / ((vL1 + vL2)*vOmega));
		dvF = -vIs*cos(PI - vu - va - vbeta)*exp(-2 * vR*vu / (vL1 + vL2) / vOmega) - (vIs*sin(PI - vu - va - vbeta) + vId / 2)*exp(-2 * vR*vu / (vL1 + vL2)) * 2 * vR / (vL1 + vL2) / vOmega;
		vu = vu - vF / dvF;
	}
	return vu;
}


void C3pProfile::SolveU3p()
{
	for (int vK = 0; vK < CellDim; vK++)
		doSolveU3p(vK);
}

void C3pProfile::doSolveU3p(int vK)
{
	//刘畅
	//刘畅
	int vStationType = pU3pData[vK].StationType;
	double vAlpha[3], vMiu[3], vAn, vBn;
	int vhMax = C3pParams::hMax;
	if (vStationType == 0)//整流侧
	{
		for (int i = 0; i < 6; i = i + 2)     //V1,V3,V5
		{
			vAlpha[i] = pU3pData[vK].AngleRad[i];
			vMiu[i] = pU3pData[vK].Miu[i];
		}

		for (int i = 1; i < vhMax; i++)
		{
			vAn = doSolveOneAnRec(vK, vAlpha, vMiu, i);
			vBn = doSolveOneBnRec(vK, vAlpha, vMiu, i);
			pU3pData[vK].USrc3p1[i].Urms = sqrt(vAn*vAn + vBn*vBn);
			pU3pData[vK].USrc3p1[i].PhaseRad = atan2(vBn, vAn);
		}
		for (int i = 1; i < 6; i = i + 2) //V2,V4,V6
		{
			vAlpha[i] = pU3pData[vK].AngleRad[i];
			vMiu[i] = pU3pData[vK].Miu[i];
		}

		for (int i = 1; i < vhMax; i++)
		{
			vAn = doSolveOneAnRec(vK, vAlpha, vMiu, i);
			vBn = doSolveOneBnRec(vK, vAlpha, vMiu, i);
			pU3pData[vK].USrc3p2[i].Urms = sqrt(vAn*vAn + vBn*vBn);
			pU3pData[vK].USrc3p2[i].PhaseRad = atan2(vBn, vAn);
		}
	}
	else//逆变侧
	{
		for (int i = 0; i < 6; i = i + 2)     //V1,V3,V5
		{
			vAlpha[i] = pU3pData[vK].AngleRad[i];
			vMiu[i] = pU3pData[vK].Miu[i];
		}
		for (int i = 1; i < vhMax; i++)
		{
			vAn = doSolveOneAnInv(vK, vAlpha, vMiu, i);
			vBn = doSolveOneBnInv(vK, vAlpha, vMiu, i);
			pU3pData[vK].USrc3p1[i].Urms = sqrt(vAn*vAn + vBn*vBn);
			pU3pData[vK].USrc3p1[i].PhaseRad = atan2(vBn, vAn);
		}
		for (int i = 1; i < 6; i = i + 2) //V2,V4,V6
		{
			vAlpha[i] = pU3pData[vK].AngleRad[i];
			vMiu[i] = pU3pData[vK].Miu[i];
		}
		for (int i = 1; i < vhMax; i++)
		{
			vAn = doSolveOneAnInv(vK, vAlpha, vMiu, i);
			vBn = doSolveOneBnInv(vK, vAlpha, vMiu, i);
			pU3pData[vK].USrc3p2[i].Urms = sqrt(vAn*vAn + vBn*vBn);
			pU3pData[vK].USrc3p2[i].PhaseRad = atan2(vBn, vAn);
		}
	}

}

void C3pProfile::SolveU3p0()
{
	for (int vK = 0; vK < CellDim; vK++)
		doSolveU3p0(vK);
}

void C3pProfile::doSolveU3p0(int vK)
{
	//刘畅
	//刘畅
	int vStationType = pU3pData[vK].StationType;
	double vAlpha[3], vMiu[3], a0[2];
	if (vStationType == 0)//整流侧
	{
		for (int i = 0; i < 6; i = i + 2)     //V1,V3,V5
		{
			vAlpha[i] = pU3pData[vK].AngleRad[i];
			vMiu[i] = pU3pData[vK].Miu[i];
		}
		a0[0] = 0.5*doSolveOneAnRec(vK, vAlpha, vMiu, 0);
		for (int i = 1; i < 6; i = i + 2) //V2,V4,V6
		{
			vAlpha[i] = pU3pData[vK].AngleRad[i];
			vMiu[i] = pU3pData[vK].Miu[i];
		}
		a0[1] = 0.5*doSolveOneAnRec(vK, vAlpha, vMiu, 0);
	}
	else//逆变侧
	{
		for (int i = 0; i < 6; i = i + 2)     //V1,V3,V5
		{
			vAlpha[i] = pU3pData[vK].AngleRad[i];
			vMiu[i] = pU3pData[vK].Miu[i];
		}
		a0[0] = 0.5*doSolveOneAnInv(vK, vAlpha, vMiu, 0);
		for (int i = 1; i < 6; i = i + 2) //V2,V4,V6
		{
			vAlpha[i] = pU3pData[vK].AngleRad[i];
			vMiu[i] = pU3pData[vK].Miu[i];
		}
		a0[1] = 0.5*doSolveOneAnInv(vK, vAlpha, vMiu, 0);
	}
	pU3pData[vK].USrc3p1[0].Urms = a0[0];
	pU3pData[vK].USrc3p2[0].Urms = a0[1];
}

void C3pProfile::SolveL()
{
	for (int vK = 0; vK < CellDim; vK++)
		doSolveL(vK);
}

void C3pProfile::SaveU3pMax()
{
	for (int vK = 0; vK < CellDim; vK++)
	{

		//USrc3p1.[i] = Umax;

	}
}

void C3pProfile::doSolveL(int vK)
{
	//刘畅
	//无偏差
	double vL = pU3pData[vK].LabcNd;
	double vmiu = pU3pData[vK].MiuNd;
	double valpha = pU3pData[vK].AngleNdRad;



	double vL3p = (3 * vmiu*vL / 2 + 3 * (2 * PI / 3 - vmiu)*vL) / PI / 2;

	pU3pData[vK].L3p1 = pU3pData[vK].L3p2 = vL3p;

}


double C3pProfile::doSolveOneAnRec(int vK, double va[3], double vu[3], int j)//计算整流侧第j次谐波的实部
{
	int vNum = pU3pData[vK].DimhUv;
	double vPhase, vUn;
	double La, Lb, Lc, vL[6], vPhaseA;
	vPhaseA = pU3pData[vK].PhaseA;
	La = pU3pData[vK].Labc[0];
	Lb = pU3pData[vK].Labc[1];
	Lc = pU3pData[vK].Labc[2];
	int k, vOrder;
	vL[0] = Lc / (La + Lc);
	vL[1] = La / (La + Lc);
	vL[2] = Lb / (La + Lb);
	vL[3] = La / (La + Lb);
	vL[4] = Lc / (Lc + Lb);
	vL[5] = Lb / (Lc + Lb);

	double va1, va2, va3, va4, va5, va6;

	va1 = va2 = va3 = va4 = va5 = va6 = 0;

	for (k = 1; k <= vNum; k++)
	{
		vUn = pU3pData[vK].hUv[k - 1].hUrms;
		vPhase = pU3pData[vK].hUv[k - 1].hAngle;
		vOrder = pU3pData[vK].hUv[k - 1].hIndex;

		if (vOrder > 0)
		{
			va1 += vUn * (integral(uacos, va[0] - vPhaseA + PI / 6, va[0] + vu[0] - vPhaseA + PI / 6, vL[0], j, vPhase, vOrder) + integral(uccos, va[0] - vPhaseA + PI / 6, va[0] + vu[0] - vPhaseA + PI / 6, vL[1], j, vPhase, vOrder));
			va2 += vUn * integral(uacos, va[0] + vu[0] - vPhaseA + PI / 6, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			va3 += vUn * (integral(uacos, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[2], j, vPhase, vOrder) + integral(ubcos, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[3], j, vPhase, vOrder));
			va4 += vUn * integral(ubcos, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			va5 += vUn * (integral(ubcos, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[4], j, vPhase, vOrder) + integral(uccos, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[5], j, vPhase, vOrder));
			va6 += vUn * integral(uccos, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[0] + 2 * PI - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
		}
		else
		{
			va1 += vUn * (integral(uacos, va[0] - vPhaseA + PI / 6, va[0] + vu[0] - vPhaseA + PI / 6, vL[0], j, vPhase, vOrder) + integral(ubcos, va[0] - vPhaseA + PI / 6, va[0] + vu[0] - vPhaseA + PI / 6, vL[1], j, vPhase, vOrder));
			va2 += vUn * integral(uacos, va[0] + vu[0] - vPhaseA + PI / 6, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			va3 += vUn * (integral(uacos, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[2], j, vPhase, vOrder) + integral(uccos, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[3], j, vPhase, vOrder));
			va4 += vUn * integral(uccos, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			va5 += vUn * (integral(uccos, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[4], j, vPhase, vOrder) + integral(ubcos, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[5], j, vPhase, vOrder));
			va6 += vUn * integral(ubcos, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[0] + 2 * PI - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
		}
	}
	double an = (va1 + va2 + va3 + va4 + va5 + va6) / PI;
	return an;
}

double C3pProfile::doSolveOneAnInv(int vK, double va[3], double vu[3], int j)
{
	int vNum = pU3pData[vK].DimhUv;
	double vPhase, vUn;
	double La, Lb, Lc, vL[6], vPhaseA;
	vPhaseA = pU3pData[vK].PhaseA;
	La = pU3pData[vK].Labc[0];
	Lb = pU3pData[vK].Labc[1];
	Lc = pU3pData[vK].Labc[2];
	int k, vOrder;
	vL[0] = Lc / (La + Lc);
	vL[1] = La / (La + Lc);
	vL[2] = Lb / (La + Lb);
	vL[3] = La / (La + Lb);
	vL[4] = Lc / (Lc + Lb);
	vL[5] = Lb / (Lc + Lb);

	double va1, va2, va3, va4, va5, va6;

	va1 = va2 = va3 = va4 = va5 = va6 = 0;

	for (k = 1; k <= vNum; k++)
	{
		vUn = pU3pData[vK].hUv[k - 1].hUrms;
		vPhase = pU3pData[vK].hUv[k - 1].hAngle;
		vOrder = pU3pData[vK].hUv[k - 1].hIndex;

		if (vOrder > 0)
		{
			va1 += vUn * (integral(uacos, PI - vu[0] - va[0] - vPhaseA + PI / 6, PI - va[0] - vPhaseA + PI / 6, vL[0], j, vPhase, vOrder) + integral(uccos, PI - vu[0] - va[0] - vPhaseA + PI / 6, PI - va[0] - vPhaseA + PI / 6, vL[1], j, vPhase, vOrder));
			va2 += vUn * integral(uacos, PI - va[0] - vPhaseA + PI / 6, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			va3 += vUn * (integral(uacos, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[2], j, vPhase, vOrder) + integral(ubcos, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[3], j, vPhase, vOrder));
			va4 += vUn * integral(ubcos, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			va5 += vUn * (integral(ubcos, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[4], j, vPhase, vOrder) + integral(uccos, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[5], j, vPhase, vOrder));
			va6 += vUn * integral(uccos, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - vu[0] - va[0] + 2 * PI - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
		}
		else
		{
			va1 += vUn * (integral(uacos, PI - vu[0] - va[0] - vPhaseA + PI / 6, PI - va[0] - vPhaseA + PI / 6, vL[0], j, vPhase, vOrder) + integral(ubcos, PI - vu[0] - va[0] - vPhaseA + PI / 6, PI - va[0] - vPhaseA + PI / 6, vL[1], j, vPhase, vOrder));
			va2 += vUn * integral(uacos, PI - va[0] - vPhaseA + PI / 6, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			va3 += vUn * (integral(uacos, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[2], j, vPhase, vOrder) + integral(uccos, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[3], j, vPhase, vOrder));
			va4 += vUn * integral(uccos, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			va5 += vUn * (integral(uccos, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[4], j, vPhase, vOrder) + integral(ubcos, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[5], j, vPhase, vOrder));
			va6 += vUn * integral(ubcos, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - vu[0] - va[0] + 2 * PI - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
		}
	}
	double an = (va1 + va2 + va3 + va4 + va5 + va6) / PI;
	return an;
}

double C3pProfile::doSolveOneBnRec(int vK, double va[3], double vu[3], int j)
{
	int vNum = pU3pData[vK].DimhUv;
	double vPhase, vUn;
	double La, Lb, Lc, vL[6], vPhaseA;
	vPhaseA = pU3pData[vK].PhaseA;
	La = pU3pData[vK].Labc[0];
	Lb = pU3pData[vK].Labc[1];
	Lc = pU3pData[vK].Labc[2];
	int k, vOrder;
	vL[0] = Lc / (La + Lc);
	vL[1] = La / (La + Lc);
	vL[2] = Lb / (La + Lb);
	vL[3] = La / (La + Lb);
	vL[4] = Lc / (Lc + Lb);
	vL[5] = Lb / (Lc + Lb);

	double vb1, vb2, vb3, vb4, vb5, vb6;
	vb1 = vb2 = vb3 = vb4 = vb5 = vb6 = 0;
	for (k = 1; k <= vNum; k++)
	{
		vUn = pU3pData[vK].hUv[k - 1].hUrms;
		vPhase = pU3pData[vK].hUv[k - 1].hAngle;
		vOrder = pU3pData[vK].hUv[k - 1].hIndex;

		if (vOrder > 0)
		{
			vb1 += vUn * (integral(uasin, va[0] - vPhaseA + PI / 6, va[0] + vu[0] - vPhaseA + PI / 6, vL[0], j, vPhase, vOrder) + integral(ucsin, va[0] - vPhaseA + PI / 6, va[0] + vu[0] - vPhaseA + PI / 6, vL[1], j, vPhase, vOrder));
			vb2 += vUn * integral(uasin, va[0] + vu[0] - vPhaseA + PI / 6, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			vb3 += vUn * (integral(uasin, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[2], j, vPhase, vOrder) + integral(ubsin, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[3], j, vPhase, vOrder));
			vb4 += vUn * integral(ubsin, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			vb5 += vUn * (integral(ubsin, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[4], j, vPhase, vOrder) + integral(ucsin, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[5], j, vPhase, vOrder));
			vb6 += vUn * integral(ucsin, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[0] + 2 * PI - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
		}
		else
		{
			vb1 += vUn * (integral(uasin, va[0] - vPhaseA + PI / 6, va[0] + vu[0] - vPhaseA + PI / 6, vL[0], j, vPhase, vOrder) + integral(ubsin, va[0] - vPhaseA + PI / 6, va[0] + vu[0] - vPhaseA + PI / 6, vL[1], j, vPhase, vOrder));
			vb2 += vUn * integral(uasin, va[0] + vu[0] - vPhaseA + PI / 6, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			vb3 += vUn * (integral(uasin, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[2], j, vPhase, vOrder) + integral(ucsin, va[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[3], j, vPhase, vOrder));
			vb4 += vUn * integral(ucsin, va[1] + vu[1] + 2 * PI / 3 - vPhaseA + PI / 6, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			vb5 += vUn * (integral(ucsin, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[4], j, vPhase, vOrder) + integral(ubsin, va[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[5], j, vPhase, vOrder));
			vb6 += vUn * integral(ubsin, va[2] + vu[2] + 4 * PI / 3 - vPhaseA + PI / 6, va[0] + 2 * PI - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
		}
	}
	double bn = (vb1 + vb2 + vb3 + vb4 + vb5 + vb6) / PI;
	return bn;
}

double C3pProfile::doSolveOneBnInv(int vK, double va[3], double vu[3], int j)
{
	int vNum = pU3pData[vK].DimhUv;
	double vPhase, vUn;
	int k, vOrder;
	double La, Lb, Lc, vL[6], vPhaseA;
	vPhaseA = pU3pData[vK].PhaseA;
	La = pU3pData[vK].Labc[0];
	Lb = pU3pData[vK].Labc[1];
	Lc = pU3pData[vK].Labc[2];
	vL[0] = Lc / (La + Lc);
	vL[1] = La / (La + Lc);
	vL[2] = Lb / (La + Lb);
	vL[3] = La / (La + Lb);
	vL[4] = Lc / (Lc + Lb);
	vL[5] = Lb / (Lc + Lb);

	double vb1, vb2, vb3, vb4, vb5, vb6;
	vb1 = vb2 = vb3 = vb4 = vb5 = vb6 = 0;
	for (k = 1; k <= vNum; k++)
	{
		vUn = pU3pData[vK].hUv[k - 1].hUrms;
		vPhase = pU3pData[vK].hUv[k - 1].hAngle;
		vOrder = pU3pData[vK].hUv[k - 1].hIndex;

		if (vOrder > 0)
		{
			vb1 += vUn * (integral(uasin, PI - vu[0] - va[0] - vPhaseA + PI / 6, PI - va[0] - vPhaseA + PI / 6, vL[0], j, vPhase, vOrder) + integral(ucsin, PI - vu[0] - va[0] - vPhaseA + PI / 6, PI - va[0], vL[1] - vPhaseA + PI / 6, j, vPhase, vOrder));
			vb2 += vUn * integral(uasin, PI - va[0] - vPhaseA + PI / 6, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			vb3 += vUn * (integral(uasin, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[2], j, vPhase, vOrder) + integral(ubsin, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[3], j, vPhase, vOrder));
			vb4 += vUn * integral(ubsin, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			vb5 += vUn * (integral(ubsin, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[4], j, vPhase, vOrder) + integral(ucsin, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[5], j, vPhase, vOrder));
			vb6 += vUn * integral(ucsin, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - vu[0] - va[0] + 2 * PI - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
		}
		else
		{
			vb1 += vUn * (integral(uasin, PI - vu[0] - va[0] - vPhaseA + PI / 6, PI - va[0] - vPhaseA + PI / 6, vL[0], j, vPhase, vOrder) + integral(ubsin, PI - vu[0] - va[0] - vPhaseA + PI / 6, PI - va[0] - vPhaseA + PI / 6, vL[1], j, vPhase, vOrder));
			vb2 += vUn * integral(uasin, PI - va[0] - vPhaseA + PI / 6, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			vb3 += vUn * (integral(uasin, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[2], j, vPhase, vOrder) + integral(ucsin, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, vL[3], j, vPhase, vOrder));
			vb4 += vUn * integral(ucsin, PI - vu[1] - va[1] + 2 * PI / 3 - vPhaseA + PI / 6, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
			vb5 += vUn * (integral(ucsin, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[4], j, vPhase, vOrder) + integral(ubsin, PI - vu[2] - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, vL[5], j, vPhase, vOrder));
			vb6 += vUn * integral(ubsin, PI - va[2] + 4 * PI / 3 - vPhaseA + PI / 6, PI - vu[0] - va[0] + 2 * PI - vPhaseA + PI / 6, 1, j, vPhase, vOrder);
		}
	}
	double bn = (vb1 + vb2 + vb3 + vb4 + vb5 + vb6) / PI;
	return bn;
}