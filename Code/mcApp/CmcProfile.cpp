///////////////////////////////////////////////////////////
//  CmcProfile.cpp
//  Implementation of the Class CmcProfile
//  Created on:      03-5月-2017 19:55:50
//  Original author: Administrator
///////////////////////////////////////////////////////////

#include "CmcProfile.h"
#include "CmcParams.h"

#include "time.h"
#include "CMatrix.h"

#include <iostream>

CmcProfile::~CmcProfile()
{
	Release();
}


void CmcProfile::Release()
{
	//delete pmcOrder;
	//pmcOrder = nullptr;

	delete[] pmcStaData;
	pmcStaData = nullptr;

	delete[] pmcStaDataN;
	pmcStaDataN = nullptr;

	//
	delete[] J_Matrix;
	delete[] F_Vect;
	delete[] X_Vect;
	delete[] dX_Vect;

	//
	J_Matrix = nullptr;
	F_Vect = nullptr;
	X_Vect = nullptr;
	dX_Vect = nullptr;
}


void CmcProfile::Clear()
{
	//CPowerProfile::Clear();

	delete[] pmcStaData;
	pmcStaData = nullptr;

	delete[] pmcStaDataN;
	pmcStaDataN = nullptr;

	//
	delete[] J_Matrix;
	delete[] F_Vect;
	delete[] X_Vect;
	delete[] dX_Vect;

	//
	J_Matrix = nullptr;
	F_Vect = nullptr;
	X_Vect = nullptr;
	dX_Vect = nullptr;
}

void CmcProfile::Init()
{
	//CPowerProfile::Init();
	//
	Ydim = 0;
	Jdim = 0;
	Kdim = 0;

	//
	J_Matrix = nullptr;
	F_Vect = nullptr;
	X_Vect = nullptr;

	dX_Vect = nullptr;

	//
	pmcStaData = nullptr;
	pmcStaDataN = nullptr;

	//
	doInitData();

}

void CmcProfile::InitOrder(CmcOrder * vOrder)
{
	pmcOrder = vOrder;
}

void CmcProfile::doInitData()
{
	//
	pmcStaData = new struct_mcStationData[StaDim()];
	//
	pmcStaDataN = new struct_mcStationData[StaDim()];
	//
	Ud_Max = 0;
	LimitOK = true;
	IsUrefToGround = false;

	BalanceStation = -1;

	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		pmcStaData[i].RefStaIndex = -1;
		pmcStaData[i].J_Index = -1;
		pmcStaData[i].StaCtrlType = -1;
		pmcStaData[i].iNodeID = -1;
		pmcStaData[i].jNodeID = -1;
		pmcStaData[i].alphaOrgamma = 0;
		pmcStaData[i].Ang_Min = 0;
		pmcStaData[i].AngCtrl_Max = 0;
		pmcStaData[i].AngCtrl_Min = 0;
		pmcStaData[i].WorkState = -1;
		pmcStaData[i].deltaK = 0;
		pmcStaData[i].dr = 0;
		pmcStaData[i].dx = 0;
		pmcStaData[i].Id = 0;
		pmcStaData[i].miu = 0;
		pmcStaData[i].Nnom = 0;
		pmcStaData[i].nPoleNum = 0;
		pmcStaData[i].nT = 0;
		pmcStaData[i].Pconv = 0;
		pmcStaData[i].Pd = 0;
		pmcStaData[i].PdPer = 0;
		pmcStaData[i].QacInMax = 0;
		pmcStaData[i].QacOutMax = 0;
		pmcStaData[i].Qconv = 0;
		pmcStaData[i].Qf_max = 0;
		pmcStaData[i].Qf_min = 0;
		pmcStaData[i].StationName = "";
		pmcStaData[i].Tap_Max = 0;
		pmcStaData[i].Tap_Min = 0;
		pmcStaData[i].TapCtrlType = -1;
		pmcStaData[i].TC = 0;
		pmcStaData[i].Uac = 0;
		pmcStaData[i].Ud = 0;
		pmcStaData[i].Udio = 0;
		pmcStaData[i].UdL = 0;
		pmcStaData[i].UT = 0;
		pmcStaData[i].Uv = 0;
		pmcStaData[i].Uv_Max = 0;

		pmcStaDataN[i].RefStaIndex = -1;
		pmcStaDataN[i].J_Index = -1;
		pmcStaDataN[i].StaCtrlType = -1;
		pmcStaDataN[i].iNodeID = -1;
		pmcStaDataN[i].jNodeID = -1;
		pmcStaDataN[i].alphaOrgamma = 0;
		pmcStaDataN[i].Ang_Min = 0;
		pmcStaDataN[i].AngCtrl_Max = 0;
		pmcStaDataN[i].AngCtrl_Min = 0;
		pmcStaDataN[i].WorkState = -1;
		pmcStaDataN[i].deltaK = 0;
		pmcStaDataN[i].dr = 0;
		pmcStaDataN[i].dx = 0;
		pmcStaDataN[i].Id = 0;
		pmcStaDataN[i].miu = 0;
		pmcStaDataN[i].Nnom = 0;
		pmcStaDataN[i].nPoleNum = 0;
		pmcStaDataN[i].nT = 0;
		pmcStaDataN[i].Pconv = 0;
		pmcStaDataN[i].Pd = 0;
		pmcStaDataN[i].PdPer = 0;
		pmcStaDataN[i].QacInMax = 0;
		pmcStaDataN[i].QacOutMax = 0;
		pmcStaDataN[i].Qconv = 0;
		pmcStaDataN[i].Qf_max = 0;
		pmcStaDataN[i].Qf_min = 0;
		pmcStaDataN[i].StationName = "";
		pmcStaDataN[i].Tap_Max = 0;
		pmcStaDataN[i].Tap_Min = 0;
		pmcStaDataN[i].TapCtrlType = -1;
		pmcStaDataN[i].TC = 0;
		pmcStaDataN[i].Uac = 0;
		pmcStaDataN[i].Ud = 0;
		pmcStaDataN[i].Udio = 0;
		pmcStaDataN[i].UdL = 0;
		pmcStaDataN[i].UT = 0;
		pmcStaDataN[i].Uv = 0;
		pmcStaDataN[i].Uv_Max = 0;
	}
}



void CmcProfile::ResetMatrix() 
{
	Jdim = Ydim + Kdim;
	//
	doInitMatrix();
}


void CmcProfile::ResetData() 
{
	Ud_Max = 0;
	LimitOK = true;
	IsUrefToGround = false;
	BalanceStation = -1;

	//
	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		pmcStaData[i].RefStaIndex = -1;
		pmcStaData[i].J_Index = -1;
		pmcStaData[i].StaCtrlType = -1;
		pmcStaData[i].iNodeID = -1;
		pmcStaData[i].jNodeID = -1;
		pmcStaData[i].alphaOrgamma = 0;
		pmcStaData[i].Ang_Min = 0;
		pmcStaData[i].AngCtrl_Max = 0;
		pmcStaData[i].AngCtrl_Min = 0;
		pmcStaData[i].WorkState = 0;
		pmcStaData[i].deltaK = 0;
		pmcStaData[i].dr = 0;
		pmcStaData[i].dx = 0;
		pmcStaData[i].Id = 0;
		pmcStaData[i].miu = 0;
		pmcStaData[i].Nnom = 0;
		pmcStaData[i].nPoleNum = 0;
		pmcStaData[i].nT = 0;
		pmcStaData[i].Pconv = 0;
		pmcStaData[i].Pd = 0;
		pmcStaData[i].PdPer = 0;
		pmcStaData[i].QacInMax = 0;
		pmcStaData[i].QacOutMax = 0;
		pmcStaData[i].Qconv = 0;
		pmcStaData[i].Qf_max = 0;
		pmcStaData[i].Qf_min = 0;
		pmcStaData[i].StationName = "";
		pmcStaData[i].Tap_Max = 0;
		pmcStaData[i].Tap_Min = 0;
		pmcStaData[i].TapCtrlType = 0;
		pmcStaData[i].TC = 0;
		pmcStaData[i].Uac = 0;
		pmcStaData[i].Ud = 0;
		pmcStaData[i].Udio = 0;
		pmcStaData[i].UdL = 0;
		pmcStaData[i].UT = 0;
		pmcStaData[i].Uv = 0;
		pmcStaData[i].Uv_Max = 0;
	}
}


void CmcProfile::doInitMatrix() 
{

	delete[] J_Matrix;
	delete[] F_Vect;
	delete[] X_Vect;
	delete[] dX_Vect;
	//
	J_Matrix = new double[Jdim*Jdim];
	F_Vect = new double[Jdim];
	X_Vect = new double[Jdim];
	dX_Vect = new double[Jdim];


	int i, j;

	for (i = 0; i < Jdim; i++)
		for (j = 0; j < Jdim; j++)
			J_Matrix[i*Jdim + j] = 0;

	for (i = 0; i < Jdim; i++)
	{
		F_Vect[i] = 0;
		X_Vect[i] = 0;
		dX_Vect[i] = 0;
	}

}


int CmcProfile::StaDim()
{
	//应该从工程属性中读取
	return CmcParams::mcStationCount;
}

void CmcProfile::OffSet()
{
	int vN;
	bool vOk;

	Kdim = 0;

	vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		pmcStaData[i].J_Index = -1;

		vOk = pmcStaData[i].StaCtrlType != StaCtrl_ConstantId;
		vOk = vOk && pmcStaData[i].StaCtrlType != StaCtrl_TrackId;
		if (vOk)
		{
			pmcStaData[i].J_Index = Kdim;
			Kdim = Kdim + 1;
		}
	}
}


bool CmcProfile::IsBiPole()
{

	bool vOk;

	vOk = (pmcOrder->GroundType == Ground20);

	return vOk;
}


bool CmcProfile::IsMetalLine()
{

	bool vOk;

	vOk = (pmcOrder->GroundType == Ground11);

	return vOk;
}


void CmcProfile::InitX_Y(int vNode, double vUnode){

	//给定迭代初值
	X_Vect[vNode] = vUnode + (rand() % 3000) / 100.0 - 15;
}


void CmcProfile::InitX_I(int vK, double vId){

	int vRow = Ydim + vK;
	//给定迭代初值
	X_Vect[vRow] = vId + (rand() % 200) / 100.0 - 1;
}


void CmcProfile::UpdateY0(int iNode, double vY){

	double vX;

	vX = J_Matrix[iNode*Jdim + iNode];
	J_Matrix[iNode*Jdim + iNode] = vX + vY;
}


void CmcProfile::UpdateY(int iNode, int jNode, double vY){

	double vX;

	//
	vX = J_Matrix[iNode*Jdim + iNode];
	J_Matrix[iNode*Jdim + iNode] = vX + vY;
	//
	vX = J_Matrix[jNode*Jdim + jNode];
	J_Matrix[jNode*Jdim + jNode] = vX + vY;

	//
	vX = J_Matrix[iNode*Jdim + jNode];
	J_Matrix[iNode*Jdim + jNode] = vX - vY;
	J_Matrix[jNode*Jdim + iNode] = vX - vY;

	//
}


void CmcProfile::UpdateX(){

	for (int i = 0; i < Jdim; i++)
		X_Vect[i] = X_Vect[i] - dX_Vect[i];
}


void CmcProfile::Solve_dX(){

	CMatrix J_inv = CMatrix(Jdim);
	for (int i = 0; i < Jdim; i++)
		for (int j = 0; j < Jdim; j++)
			J_inv._mat[i][j] = J_Matrix[i*Jdim + j];

	J_inv = J_inv.inversion();

	for (int i = 0; i < Jdim; i++)
	{
		dX_Vect[i] = 0;
		for (int j = 0; j < Jdim; j++)
			dX_Vect[i] += J_inv._mat[i][j].real() * F_Vect[j];
	}
}


double CmcProfile::GetMaxdX(){

	double vMax = 0;
	for (int i = 0; i < Jdim; i++)
		if (abs(dX_Vect[i])>vMax)
		{
			vMax = abs(dX_Vect[i]);
		}
	return vMax;
}


void CmcProfile::SaveX(int vOffset, int vK_s, int iNode_s, int jNode_s){

	double vUd, vId, vUdL;
	vUd = 0;
	if (iNode_s != -1)
		vUd += +X_Vect[iNode_s];

	vUdL = vUd;

	if (jNode_s != -1)
		vUd += -X_Vect[jNode_s];

	vId = 0;
	for (int i = 0; i < Ydim; i++)
		vId += J_Matrix[iNode_s*Jdim + i] * X_Vect[i];

	pmcStaData[vK_s].Ud = vUd;
	pmcStaData[vK_s].UdL = vUdL;
	pmcStaData[vK_s].Id = vId;
}


void CmcProfile::UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s){

	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= pmcStaData[vK_s].Id;
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -pmcStaData[vK_s].Id;
}


void CmcProfile::UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m){

	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= (pmcStaDataN[vK_s].Pd / pmcStaDataN[vK_m].Pd)*X_Vect[Ydim + vK_m];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -(pmcStaDataN[vK_s].Pd / pmcStaDataN[vK_m].Pd)*X_Vect[Ydim + vK_m];
}


void CmcProfile::UpdateF_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s){

	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= X_Vect[Ydim + vOffset];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -X_Vect[Ydim + vOffset];

	//Pd-U1Id+U2Id
	double vPd, vU1, vU2, vId;

	vPd = pmcStaData[vK_s].Pd;
	vU1 = X_Vect[iNode_s];
	vU2 = X_Vect[jNode_s];
	vId = X_Vect[Ydim + vOffset];

	vRow = Ydim + vOffset;
	F_Vect[vRow] = vPd;
	if (iNode_s != -1)
		F_Vect[vRow] += -vU1*vId;
	if (jNode_s != -1)
		F_Vect[vRow] += +vU2*vId;
}


void CmcProfile::UpdateF_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m){

	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= X_Vect[Ydim + vOffset];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -X_Vect[Ydim + vOffset];

	if (IsUrefToGround)
	{
		//UdL-U1
		double vUdL, vU1;

		vUdL = pmcStaData[vK_m].UdL;
		vU1 = X_Vect[iNode_m];

		vRow = Ydim + vOffset;
		F_Vect[vRow] = vUdL;

		if (iNode_m != -1)
			F_Vect[vRow] += -vU1;
	}
	else
	{
		//Ud-U1+U2
		double vUd, vU1, vU2;

		vUd = pmcStaData[vK_m].Ud;
		vU1 = X_Vect[iNode_m];
		vU2 = X_Vect[jNode_m];

		vRow = Ydim + vOffset;
		F_Vect[vRow] = vUd;
		if (iNode_m != -1)
			F_Vect[vRow] += -vU1;
		if (jNode_m != -1)
			F_Vect[vRow] += +vU2;

	}
}

void CmcProfile::UpdateF_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s){

	int vRow;

	//YU-I
	vRow = iNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= X_Vect[Ydim + vOffset];
	vRow = jNode_s;
	if (vRow != -1)
		F_Vect[vRow] -= -X_Vect[Ydim + vOffset];

	//Udio*cos(alpha)-(U1-U2)/nT-UT-(dx+dr)/100*UdioN/IdN*Id
	//或Udio*cos(gamma)-(U1-U2)/nT+UT-(dx-dr)/100*UdioN/IdN*Id
	double vUdio, vangle, vU1, vU2, vnT, vUT, vdx, vdr, vUdioN, vIdN, vId;

	vUdio = pmcStaData[vK_s].Udio;
	vangle = pmcStaData[vK_s].alphaOrgamma;
	vU1 = X_Vect[iNode_s];
	vU2 = X_Vect[jNode_s];
	vnT = pmcStaData[vK_s].nT;
	vUT = pmcStaData[vK_s].UT;
	vdx = pmcStaData[vK_s].dx;
	vdr = pmcStaData[vK_s].dr;
	vUdioN = pmcStaDataN[vK_s].Udio;
	vIdN = pmcStaDataN[vK_s].Id;
	vId = X_Vect[Ydim + vOffset];

	vRow = Ydim + vOffset;
	if (pmcStaData[vK_s].WorkState == Hvdc_Rectify)
		F_Vect[vRow] = vUdio*cos(vangle) - vUT - (vdx + vdr) / 100 * vUdioN / vIdN*vId;
	else
		F_Vect[vRow] = vUdio*cos(vangle) + vUT - (vdx - vdr) / 100 * vUdioN / vIdN*vId;
	if (iNode_s != -1)
		F_Vect[vRow] += -vU1 / vnT;
	if (jNode_s != -1)
		F_Vect[vRow] += +vU2 / vnT;
}


void CmcProfile::UpdateJ_IdCtrl(int vK_s, int iNode_s, int jNode_s){

}


void CmcProfile::UpdateJ_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s){

	int vRow, vCol;

	//右上i
	vRow = iNode_s;
	vCol = Ydim + vOffset;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

	//右上j
	vRow = jNode_s;
	vCol = Ydim + vOffset;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1

	//左下i
	vRow = Ydim + vOffset;
	vCol = iNode_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -X_Vect[Ydim + vOffset];// -Id[vK]

	//左下j
	vRow = Ydim + vOffset;
	vCol = jNode_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +X_Vect[Ydim + vOffset];// +Id[vK]

	//右下
	vRow = Ydim + vOffset;
	vCol = Ydim + vOffset;
	J_Matrix[vRow*Jdim + vCol] = 0;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] += -X_Vect[iNode_s];
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] += +X_Vect[jNode_s];
}


void CmcProfile::UpdateJ_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m){

	int vRow, vCol;

	//右上i
	vRow = iNode_s;
	vCol = Ydim + vOffset;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

	//右上j
	vRow = jNode_s;
	vCol = Ydim + vOffset;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1

	//左下i
	vRow = Ydim + vOffset;
	vCol = iNode_m;
	if (iNode_m != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

	//左下j
	vRow = Ydim + vOffset;
	vCol = jNode_m;
	if (!IsUrefToGround && jNode_m != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1
}

void CmcProfile::UpdateJ_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s){

	int vRow, vCol;

	//右上i
	vRow = iNode_s;
	vCol = Ydim + vOffset;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1;// -1

	//右上j
	vRow = jNode_s;
	vCol = Ydim + vOffset;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1;// +1

	//左下i
	vRow = Ydim + vOffset;
	vCol = iNode_s;
	if (iNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = -1.0 / pmcStaData[vK_s].nT;// -1/n

	//左下j
	vRow = Ydim + vOffset;
	vCol = jNode_s;
	if (jNode_s != -1)
		J_Matrix[vRow*Jdim + vCol] = +1.0 / pmcStaData[vK_s].nT;// +1/n

	//右下
	vRow = Ydim + vOffset;
	vCol = Ydim + vOffset;

	// -(dx+dr)/100*UdioN/IdN 或 -(dx-dr)/100*UdioN/IdN
	double X = 0;
	if (pmcStaData[vK_s].WorkState == Hvdc_Rectify)
		X = -(pmcStaData[vK_s].dx + pmcStaData[vK_s].dr) / 100.0*pmcStaDataN[vK_s].Udio / pmcStaDataN[vK_s].Id;
	else
		X = -(pmcStaData[vK_s].dx - pmcStaData[vK_s].dr) / 100.0*pmcStaDataN[vK_s].Udio / pmcStaDataN[vK_s].Id;
	J_Matrix[vRow*Jdim + vCol] = X;
}

void CmcProfile::UpdateUdio(){

	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		if (pmcStaData[i].TapCtrlType == xfCtrl_ConstantUv)
			UpdateXf2_Port(i);
		else
			UpdateXf2_l(i);
		UpdateUdio(i);
	}
}


void CmcProfile::UpdateUdio(int vK){

	pmcStaData[vK].Udio = 3 * sqrt(2.0) / M_PI*pmcStaData[vK].Uv;
}


void CmcProfile::UpdateCtrl_Angle(int vK){

	double temPd, temUd, temId;
	temPd = pmcStaData[vK].Pd;
	temUd = pmcStaData[vK].Ud;
	temId = pmcStaData[vK].Id;
	//temAngle = pmcStaData[vK].alphaOrgamma;

	pmcStaData[vK].alphaOrgamma = pmcStaData[vK].Ang_Min;
	UpdateConvertor_AC(vK);

	pmcStaData[vK].Pd = temPd;
	pmcStaData[vK].Ud = temUd;
	pmcStaData[vK].Id = temId;
	//pmcStaData[vK].alphaOrgamma = temAngle;
}


void CmcProfile::UpdateCtrl_Pd(int vK){

	double temUd, temId, temAngle;
	//temPd = pmcStaData[vK].Pd;
	temUd = pmcStaData[vK].Ud;
	temId = pmcStaData[vK].Id;
	temAngle = pmcStaData[vK].alphaOrgamma;

	pmcStaData[vK].alphaOrgamma = pmcStaData[vK].Ang_Min;
	UpdateConvertor_AC(vK);

	//pmcStaData[vK].Pd = temPd;
	pmcStaData[vK].Ud = temUd;
	pmcStaData[vK].Id = temId;
	pmcStaData[vK].alphaOrgamma = temAngle;
}

void CmcProfile::UpdateCtrl_Ud(int vK){

	double temPd, temId, temAngle;
	temPd = pmcStaData[vK].Pd;
	//temUd = pmcStaData[vK].Ud;
	temId = pmcStaData[vK].Id;
	temAngle = pmcStaData[vK].alphaOrgamma;

	pmcStaData[vK].alphaOrgamma = pmcStaData[vK].Ang_Min;
	UpdateConvertor_AC(vK);

	pmcStaData[vK].Pd = temPd;
	//pmcStaData[vK].Ud = temUd;
	pmcStaData[vK].Id = temId;
	pmcStaData[vK].alphaOrgamma = temAngle;
}

void CmcProfile::UpdateCtrl_Id(int vK){

	double temPd, temUd, temAngle;
	temPd = pmcStaData[vK].Pd;
	temUd = pmcStaData[vK].Ud;
	//temId = pmcStaData[vK].Id;
	temAngle = pmcStaData[vK].alphaOrgamma;

	pmcStaData[vK].alphaOrgamma = pmcStaData[vK].Ang_Min;
	UpdateConvertor_AC(vK);

	pmcStaData[vK].Pd = temPd;
	pmcStaData[vK].Ud = temUd;
	//pmcStaData[vK].Id = temId;
	pmcStaData[vK].alphaOrgamma = temAngle;
}

void CmcProfile::UpdateConvertor_N(int vK){

	double vUd, vId, vAngle;
	vUd = pmcStaData[vK].Ud;
	vId = pmcStaData[vK].Id;
	vAngle = pmcStaData[vK].alphaOrgamma;
	double nT, UT, dx, dr, npoleNum;
	nT = pmcStaData[vK].nT;				UT = pmcStaData[vK].UT;
	dx = pmcStaData[vK].dx;				dr = pmcStaData[vK].dr;
	npoleNum = pmcStaData[vK].nPoleNum;

	pmcStaData[vK].Pd = vUd*vId;
	if (pmcStaData[vK].WorkState == Hvdc_Rectify)
		pmcStaData[vK].Udio = (vUd / nT + UT) / (cos(vAngle) - (dx + dr) / 100);
	else
		pmcStaData[vK].Udio = (vUd / nT - UT) / (cos(vAngle) - (dx - dr) / 100);
	pmcStaData[vK].miu = acos(cos(vAngle) - 2 * dx / 100 * pmcStaData[vK].Udio / pmcStaData[vK].Udio) - vAngle;
	pmcStaData[vK].Uv = M_PI / 3 / sqrt(2.0)*pmcStaData[vK].Udio;
	pmcStaData[vK].Pconv = npoleNum * nT*pmcStaData[vK].Udio*vId*cos(vAngle + pmcStaData[vK].miu / 2)*cos(pmcStaData[vK].miu / 2);
	pmcStaData[vK].Qconv = npoleNum * nT*pmcStaData[vK].Udio*vId*(2 * pmcStaData[vK].miu + sin(2 * vAngle) - sin(2 * (vAngle + pmcStaData[vK].miu))) / (4 * (cos(vAngle) - cos(vAngle + pmcStaData[vK].miu)));
}


void CmcProfile::UpdateConvertor_DC(int vK){

	double vUd, vId, vAngle;
	vUd = pmcStaData[vK].Ud;
	vId = pmcStaData[vK].Id;
	vAngle = pmcStaData[vK].alphaOrgamma;
	double nT, UT, dx, dr, Id_N, Udio_N, npoleNum;
	nT = pmcStaData[vK].nT;				UT = pmcStaData[vK].UT;
	dx = pmcStaData[vK].dx;				dr = pmcStaData[vK].dr;
	Id_N = pmcStaDataN[vK].Id;			Udio_N = pmcStaDataN[vK].Udio;
	npoleNum = pmcStaData[vK].nPoleNum;

	pmcStaData[vK].Pd = vUd*vId;
	if (pmcStaData[vK].WorkState == Hvdc_Rectify)
		pmcStaData[vK].Udio = (vUd / nT + UT + (dx + dr) / 100 * vId / Id_N *Udio_N) / cos(vAngle);
	else
		pmcStaData[vK].Udio = (vUd / nT - UT + (dx - dr) / 100 * vId / Id_N *Udio_N) / cos(vAngle);
	pmcStaData[vK].miu = acos(cos(vAngle) - 2 * dx / 100 * vId / Id_N * Udio_N / pmcStaData[vK].Udio) - vAngle;
	pmcStaData[vK].Uv = M_PI / 3 / sqrt(2.0)*pmcStaData[vK].Udio;
	pmcStaData[vK].Pconv = npoleNum * nT*pmcStaData[vK].Udio*vId*cos(vAngle + pmcStaData[vK].miu / 2)*cos(pmcStaData[vK].miu / 2);
	pmcStaData[vK].Qconv = npoleNum * nT*pmcStaData[vK].Udio*vId*(2 * pmcStaData[vK].miu + sin(2 * vAngle) - sin(2 * (vAngle + pmcStaData[vK].miu))) / (4 * (cos(vAngle) - cos(vAngle + pmcStaData[vK].miu)));
}


void CmcProfile::UpdateConvertor_AC(int vK){

	double vUv, vId, vAngle;
	vUv = pmcStaData[vK].Uv;
	vId = pmcStaData[vK].Id;
	vAngle = pmcStaData[vK].alphaOrgamma;
	double nT, UT, dx, dr, Id_N, Udio_N, npoleNum;
	nT = pmcStaData[vK].nT;				UT = pmcStaData[vK].UT;
	dx = pmcStaData[vK].dx;				dr = pmcStaData[vK].dr;
	Id_N = pmcStaDataN[vK].Id;			Udio_N = pmcStaDataN[vK].Udio;
	npoleNum = pmcStaData[vK].nPoleNum;

	pmcStaData[vK].Udio = 3 * sqrt(2.0) / M_PI*vUv;
	if (pmcStaData[vK].WorkState == Hvdc_Rectify)
		pmcStaData[vK].Ud = nT*(pmcStaData[vK].Udio*cos(vAngle) - UT - (dx + dr) / 100 * vId / Id_N*Udio_N);
	else
		pmcStaData[vK].Ud = nT*(pmcStaData[vK].Udio*cos(vAngle) + UT - (dx - dr) / 100 * vId / Id_N*Udio_N);
	pmcStaData[vK].Pd = pmcStaData[vK].Ud*vId;
	pmcStaData[vK].miu = acos(cos(vAngle) - 2 * dx / 100 * vId / Id_N * Udio_N / pmcStaData[vK].Udio) - vAngle;
	pmcStaData[vK].Pconv = npoleNum * nT*pmcStaData[vK].Udio*vId*cos(vAngle + pmcStaData[vK].miu / 2)*cos(pmcStaData[vK].miu / 2);
	pmcStaData[vK].Qconv = npoleNum * nT*pmcStaData[vK].Udio*vId*(2 * pmcStaData[vK].miu + sin(2 * vAngle) - sin(2 * (vAngle + pmcStaData[vK].miu))) / (4 * (cos(vAngle) - cos(vAngle + pmcStaData[vK].miu)));
}


void CmcProfile::UpdateConvertor_Port(int vK){

	double vUd, vId, vUv;
	vUd = pmcStaData[vK].Ud;
	vId = pmcStaData[vK].Id;
	vUv = pmcStaData[vK].Uv;
	double nT, UT, dx, dr, Id_N, Udio_N, npoleNum;
	nT = pmcStaData[vK].nT;				UT = pmcStaData[vK].UT;
	dx = pmcStaData[vK].dx;				dr = pmcStaData[vK].dr;
	Id_N = pmcStaDataN[vK].Id;			Udio_N = pmcStaDataN[vK].Udio;
	npoleNum = pmcStaData[vK].nPoleNum;

	pmcStaData[vK].Pd = vUd*vId;
	pmcStaData[vK].Udio = 3 * sqrt(2.0) / M_PI*vUv;
	if (pmcStaData[vK].WorkState == Hvdc_Rectify)
		pmcStaData[vK].alphaOrgamma = acos((vUd / nT + UT + (dx + dr) / 100 * vId / Id_N*Udio_N) / pmcStaData[vK].Udio);
	else
		pmcStaData[vK].alphaOrgamma = acos((vUd / nT - UT + (dx - dr) / 100 * vId / Id_N*Udio_N) / pmcStaData[vK].Udio);
	pmcStaData[vK].miu = acos(cos(pmcStaData[vK].alphaOrgamma) - 2 * dx / 100 * vId / Id_N * Udio_N / pmcStaData[vK].Udio) - pmcStaData[vK].alphaOrgamma;
	pmcStaData[vK].Pconv = npoleNum * nT*pmcStaData[vK].Udio*vId*cos(pmcStaData[vK].alphaOrgamma + pmcStaData[vK].miu / 2)*cos(pmcStaData[vK].miu / 2);
	pmcStaData[vK].Qconv = npoleNum * nT*pmcStaData[vK].Udio*vId*(2 * pmcStaData[vK].miu + sin(2 * pmcStaData[vK].alphaOrgamma) - sin(2 * (pmcStaData[vK].alphaOrgamma + pmcStaData[vK].miu))) / (4 * (cos(pmcStaData[vK].alphaOrgamma) - cos(pmcStaData[vK].alphaOrgamma + pmcStaData[vK].miu)));
}


void CmcProfile::UpdateXf2_N(int vK){

	double vUv, vUl;
	vUl = pmcStaData[vK].Uac;
	vUv = pmcStaData[vK].Uv;
	double TC, deltaK;
	TC = pmcStaData[vK].TC;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].Nnom = vUl / vUv / (1 + TC*deltaK / 100);
}

void CmcProfile::UpdateXf2_l(int vK){

	double vUl, vTC;
	vUl = pmcStaData[vK].Uac;
	vTC = pmcStaData[vK].TC;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].Uv = vUl / (Nnom*(1 + vTC*deltaK / 100));

	if (pmcStaData[vK].Uv > pmcStaData[vK].Uv_Max)
	{
		pmcStaData[vK].Uv = pmcStaData[vK].Uv_Max;
		UpdateXf2_Port(vK);
	}
}


void CmcProfile::UpdateXf2_v(int vK){

	double vUv, vTC;
	vUv = pmcStaData[vK].Uv;
	vTC = pmcStaData[vK].TC;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	if (vUv > pmcStaData[vK].Uv_Max)
		vUv = pmcStaData[vK].Uv_Max;

	pmcStaData[vK].Uac = vUv * (Nnom*(1 + vTC*deltaK / 100));
}


void CmcProfile::UpdateXf2_Port(int vK){

	double vUv, vUl;
	vUl = pmcStaData[vK].Uac;
	vUv = pmcStaData[vK].Uv;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	if (vUv > pmcStaData[vK].Uv_Max)
		vUv = pmcStaData[vK].Uv_Max;

	if ((100 / deltaK*(vUl / Nnom / vUv - 1)) >= 0)
		pmcStaData[vK].TC = (int)(0.5 + (100 / deltaK*(vUl / Nnom / vUv - 1)));//“0.5+”：四舍五入
	else
		pmcStaData[vK].TC = (int)(-0.5 + (100 / deltaK*(vUl / Nnom / vUv - 1)));//“0.5+”：四舍五入
	pmcStaData[vK].Uv = vUl / (Nnom*(1 + pmcStaData[vK].TC*deltaK / 100));

	if (pmcStaData[vK].Uv > pmcStaData[vK].Uv_Max)
	{
		pmcStaData[vK].TC += 1;
		pmcStaData[vK].Uv = vUl / (Nnom*(1 + pmcStaData[vK].TC*deltaK / 100));
	}
}


void CmcProfile::UpdateXf2_UpShift(int vK){

	double vUl;
	vUl = pmcStaData[vK].Uac;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].TC += 1;
	UpdateXf2_l(vK);
}


void CmcProfile::UpdateXf2_DownShift(int vK){

	double vUl;
	vUl = pmcStaData[vK].Uac;
	double Nnom, deltaK;
	Nnom = pmcStaDataN[vK].Nnom;
	deltaK = pmcStaData[vK].deltaK;

	pmcStaData[vK].TC -= 1;
	UpdateXf2_l(vK);
}

bool CmcProfile::IsTapUpAble(int vK){

	if (pmcStaData[vK].TapCtrlType == xfCtrl_ConstantUv)
		return false;
	if (pmcStaData[vK].TC >= pmcStaData[vK].Tap_Max)
		return false;
	if (pmcStaData[vK].Uac / (pmcStaData[vK].Nnom*(1 + (pmcStaData[vK].TC + 1)*pmcStaData[vK].deltaK / 100)) > pmcStaData[vK].Uv_Max)
		return false;
	return true;
}


bool CmcProfile::IsTapDownAble(int vK){

	if (pmcStaData[vK].TapCtrlType == xfCtrl_ConstantUv)
		return false;
	if (pmcStaData[vK].TC <= pmcStaData[vK].Tap_Min)
		return false;
	if (pmcStaData[vK].Uac / (pmcStaData[vK].Nnom*(1 + (pmcStaData[vK].TC - 1)*pmcStaData[vK].deltaK / 100)) > pmcStaData[vK].Uv_Max)
		return false;
	return true;
}

void CmcProfile::UpdateACSide(int vK){

	pmcStaData[vK].Qf_max = pmcStaData[vK].Qconv + pmcStaData[vK].QacOutMax;
	pmcStaData[vK].Qf_min = pmcStaData[vK].Qconv - pmcStaData[vK].QacInMax;
}


void CmcProfile::InitX(){

	srand((unsigned int)time(0));
	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		doInitX(i);
	}
}


void CmcProfile::UpdateJ(){

	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		doUpdateJ(i);
	}
}


void CmcProfile::UpdateF_Y(){

	//计算U*Y，赋值给F_Vect的前YDim项。后面其他的UpdateF中将在此基础上追加
	for (int i = 0; i < Ydim; i++)
	{
		F_Vect[i] = 0;
		for (int j = 0; j < Ydim; j++)
		{
			F_Vect[i] += J_Matrix[i*Jdim + j] * X_Vect[j];
		}
	}
}


void CmcProfile::UpdateF_J(){

	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		doUpdateF_J(i);
	}
}


void CmcProfile::SaveX(){

	int iNode, jNode;
	int vOffSet;

	int vN = StaDim();
	for (int vK = 0; vK < vN; vK++)
	{
		iNode = pmcStaData[vK].iNodeID;
		jNode = pmcStaData[vK].jNodeID;

		vOffSet = pmcStaData[vK].J_Index;

		SaveX(vOffSet, vK, iNode, jNode);

		int vWork = pmcStaData[vK].WorkState;
		if (vWork == Hvdc_Invertor)
		{
			pmcStaData[vK].Id *= -1;
			pmcStaData[vK].Pd *= -1;
			pmcStaDataN[vK].Id *= -1;
			pmcStaDataN[vK].Pd *= -1;
		}//if
	}//for
}


void CmcProfile::LimitUd(){

	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		doLimitUd(i);
		if (!LimitOK)
			break;
	}
}


void CmcProfile::CalStation(){

	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		doCalStation(i);
		if (!LimitOK)
			break;
	}
}


void CmcProfile::CalAngleStation(int vK){

	double vAngle;
	double vAngleRangeMax, vAngleRangeMin, vAngleMin;
	bool vOk;

	vAngleRangeMax = pmcStaData[vK].AngCtrl_Max;
	vAngleRangeMin = pmcStaData[vK].AngCtrl_Min;
	vAngleMin = pmcStaData[vK].Ang_Min;

	UpdateXf2_l(vK);

	while (true)
	{
		UpdateConvertor_Port(vK);

		vAngle = pmcStaData[vK].alphaOrgamma;

		vOk = (vAngle - vAngleRangeMax) > Epsilon;
		vOk = vOk && IsTapUpAble(vK);
		if (vOk)
		{
			UpdateXf2_UpShift(vK);
			continue;
		}

		vOk = (vAngleRangeMin - vAngle) > Epsilon;
		vOk = vOk || vAngle != vAngle;//判断vAngle是否为(负)非法
		vOk = vOk && IsTapDownAble(vK);
		if (vOk)
		{
			UpdateXf2_DownShift(vK);
			continue;
		}

		vOk = (vAngleMin - vAngle) > Epsilon;
		vOk = vOk || vAngle != vAngle;//判断vAngle是否为(负)非法
		if (vOk)
		{
			LimitOK = false;
			ChangeStationCtrlType(vK);
			break;
		}
		break;
	}
}


void CmcProfile::CalUvStation(int vK){

	double vAngle;
	double vAngleMin;
	bool vOk;

	UpdateXf2_Port(vK);
	UpdateConvertor_Port(vK);

	vAngle = pmcStaData[vK].alphaOrgamma;
	vAngleMin = pmcStaData[vK].Ang_Min;

	vOk = (vAngleMin - vAngle) > Epsilon;
	vOk = vOk || vAngle != vAngle;//判断vAngle是否为(负)非法
	if (vOk)
	{
		LimitOK = false;
		ChangeStationCtrlType(vK);
	}
}


void CmcProfile::ChangeStationCtrlType(int vK){

	int vCtrl = pmcStaData[vK].StaCtrlType;
	int vStaDim = StaDim();

	//定电流、电流跟随
	if (vCtrl == StaCtrl_TrackId || vCtrl == StaCtrl_ConstantId)
	{
		pmcStaData[vK].StaCtrlType = StaCtrl_ConstantAngle;
		UpdateCtrl_Angle(vK);
		return;
	}
	//定电压
	if (vCtrl == StaCtrl_ConstantUd)
	{
		pmcStaData[vK].RefStaIndex = vK;
		UpdateCtrl_Ud(vK);
		IsUrefToGround = false;
		return;
	}
	//定角度
	if (vCtrl == StaCtrl_ConstantAngle)
	{
		UpdateCtrl_Angle(vK);
		return;
	}
	//定功率
	if (vCtrl == StaCtrl_ConstantPd)
	{
		//保证功率平衡站具有调节能力，若没有，选取新的功率平衡站
		bool vOk = pmcStaData[BalanceStation].alphaOrgamma - pmcStaData[BalanceStation].Ang_Min > Epsilon;
		vOk = vOk || IsTapUpAble(BalanceStation);
		if (!vOk)
			UpdateBalanceStation();

		if (pmcStaData[BalanceStation].StaCtrlType == StaCtrl_ConstantUd)
		{//功率平衡站是定电压站
			UpdateCtrl_Ud(vK);
			pmcStaData[BalanceStation].RefStaIndex = vK;
			IsUrefToGround = false;
		}
		else if (IsTapUpAble(BalanceStation))
		{//功率平衡站是定角度站且分接头可调
			UpdateXf2_UpShift(BalanceStation);
			UpdateUdio(BalanceStation);
		}
		else
		{//功率平衡站是定角度站且分接头不可调
			UpdateCtrl_Ud(vK);
			pmcStaData[BalanceStation].RefStaIndex = vK;
			pmcStaData[BalanceStation].StaCtrlType = StaCtrl_ConstantUd;
			IsUrefToGround = false;
		}
	}
}


void CmcProfile::CalStation_N(){

	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		doCalStation_N(i);
	}
}


void CmcProfile::CalACSide(){

	int vN = StaDim();
	for (int i = 0; i < vN; i++)
	{
		doCalACSide(i);
	}
}


void CmcProfile::doUpdateJ(int vK){

	int iNode, jNode;
	int vRef, iRefNode, jRefNode;

	iNode = pmcStaData[vK].iNodeID;
	jNode = pmcStaData[vK].jNodeID;

	vRef = pmcStaData[vK].RefStaIndex;
	iRefNode = pmcStaData[vRef].iNodeID;
	jRefNode = pmcStaData[vRef].jNodeID;

	int  vOffSet = pmcStaData[vK].J_Index;
	//
	switch (pmcStaData[vK].StaCtrlType)
	{
	case StaCtrl_ConstantId:
	case StaCtrl_TrackId:
		break;

	case StaCtrl_ConstantPd:
		UpdateJ_PdCtrl(vOffSet, vK, iNode, jNode);
		break;

	case StaCtrl_ConstantUd:
		UpdateJ_UdCtrl(vOffSet, vK, iNode, jNode, vRef, iRefNode, jRefNode);
		break;

	case StaCtrl_ConstantAngle:
		UpdateJ_AngCtrl(vOffSet, vK, iNode, jNode);

		break;

	default:
		break;
	}// switch
}


void CmcProfile::doUpdateF_J(int vK){

	int iNode, jNode;
	int vRef, iRefNode, jRefNode;

	iNode = pmcStaData[vK].iNodeID;
	jNode = pmcStaData[vK].jNodeID;

	vRef = pmcStaData[vK].RefStaIndex;
	iRefNode = pmcStaData[vRef].iNodeID;
	jRefNode = pmcStaData[vRef].jNodeID;

	//
	int vOffSet = pmcStaData[vK].J_Index;
	//
	switch (pmcStaData[vK].StaCtrlType)
	{
	case StaCtrl_ConstantId:
		UpdateF_IdCtrl(vK, iNode, jNode);
		break;

	case StaCtrl_TrackId:
		UpdateF_IdCtrl(vK, iNode, jNode, vRef);
		break;

	case StaCtrl_ConstantPd:
		UpdateF_PdCtrl(vOffSet, vK, iNode, jNode);
		break;

	case StaCtrl_ConstantUd:
		UpdateF_UdCtrl(vOffSet, vK, iNode, jNode, vRef, iRefNode, jRefNode);
		break;

	case StaCtrl_ConstantAngle:
		UpdateF_AngCtrl(vOffSet, vK, iNode, jNode);
		break;
	default:
		break;
	}// switch
}

void CmcProfile::doLimitUd(int vK){

	if (pmcStaData[vK].Ud - Ud_Max > Epsilon)
	{
		LimitOK = false;
		//保证功率平衡站具有调节能力，若没有，选取新的功率平衡站
		bool vOk = pmcStaData[BalanceStation].alphaOrgamma - pmcStaData[BalanceStation].Ang_Min > Epsilon;
		vOk = vOk || IsTapUpAble(BalanceStation);
		if (!vOk)
			UpdateBalanceStation();

		if (pmcStaData[BalanceStation].StaCtrlType == StaCtrl_ConstantUd)
		{//功率平衡站是定电压站
			pmcStaData[vK].Ud = Ud_Max;
			pmcStaData[BalanceStation].RefStaIndex = vK;
			IsUrefToGround = false;
		}
		else if (IsTapUpAble(BalanceStation))
		{//功率平衡站是定角度站且分接头可调
			UpdateXf2_UpShift(BalanceStation);
			UpdateUdio(BalanceStation);
		}
		else
		{//功率平衡站是定角度站且分接头不可调
			pmcStaData[vK].Ud = Ud_Max;
			pmcStaData[BalanceStation].RefStaIndex = vK;
			pmcStaData[BalanceStation].StaCtrlType = StaCtrl_ConstantUd;
			IsUrefToGround = false;
		}
	}
}


void CmcProfile::doCalStation_N(int vK){

	UpdateConvertor_N(vK);

	UpdateXf2_N(vK);
}


void CmcProfile::doCalACSide(int vK){

	pmcStaData[vK].Qf_min = pmcStaData[vK].Qconv - pmcStaData[vK].QacOutMax;
	pmcStaData[vK].Qf_max = pmcStaData[vK].Qconv + pmcStaData[vK].QacInMax;
}


void CmcProfile::doInitX(int vK){

	int iNode, jNode;
	int vWork, vOffSet;
	double vUdN, vIdN;

	vWork = pmcStaData[vK].WorkState;
	if (vWork == Hvdc_Invertor)
	{
		pmcStaData[vK].Id *= -1;
		pmcStaData[vK].Pd *= -1;
		pmcStaDataN[vK].Id *= -1;
		pmcStaDataN[vK].Pd *= -1;
	}

	iNode = pmcStaData[vK].iNodeID;
	jNode = pmcStaData[vK].jNodeID;

	vUdN = pmcStaDataN[vK].Ud;
	vIdN = pmcStaDataN[vK].Id;
	vOffSet = pmcStaData[vK].J_Index;


	if (iNode != -1)
		InitX_Y(iNode, vUdN);

	if (jNode != -1)
		InitX_Y(jNode, 0);

	if (vOffSet != -1)
		InitX_I(vOffSet, vIdN);
}


void CmcProfile::doCalStation(int vK){

	switch (pmcStaData[vK].TapCtrlType)
	{
	case xfCtrl_FixedAngle:
		CalAngleStation(vK);
		break;
	case xfCtrl_ConstantUv:
		CalUvStation(vK);
		break;
	default:
		break;
	}
}

void CmcProfile::UpdateBalanceStation()
{
	int vN = StaDim();
	bool vOk;
	double vX;
	double minX;

	minX = DBL_MAX;
	//优先选取具有调节能力的定电压站，交流系统强(换相电抗小)的优先
	for (int i = 0; i < vN; i++)
	{
		if (pmcStaData[i].WorkState == Hvdc_Rectify)
			vX = (pmcStaData[i].dx + pmcStaData[i].dr) / 100.0*pmcStaDataN[i].Udio / pmcStaDataN[i].Id;
		else
			vX = (pmcStaData[i].dx - pmcStaData[i].dr) / 100.0*pmcStaDataN[i].Udio / pmcStaDataN[i].Id;

		vOk = pmcStaData[i].StaCtrlType == StaCtrl_ConstantUd;
		vOk = vOk && (pmcStaData[i].alphaOrgamma - pmcStaData[i].Ang_Min>Epsilon || IsTapUpAble(i));
		vOk = vOk && vX < minX;
		if (vOk)
		{
			BalanceStation = i;
			minX = vX;
		}
	}

	if (minX != DBL_MAX)
		return;

	//次之考虑具有调节能力的定角度站，交流系统强(换相电抗小)的优先
	for (int i = 0; i < vN; i++)
	{
		if (pmcStaData[i].WorkState == Hvdc_Rectify)
			vX = (pmcStaData[i].dx + pmcStaData[i].dr) / 100.0*pmcStaDataN[i].Udio / pmcStaDataN[i].Id;
		else
			vX = (pmcStaData[i].dx - pmcStaData[i].dr) / 100.0*pmcStaDataN[i].Udio / pmcStaDataN[i].Id;

		vOk = pmcStaData[i].StaCtrlType == StaCtrl_ConstantAngle;
		vOk = vOk && (pmcStaData[i].alphaOrgamma - pmcStaData[i].Ang_Min>Epsilon || IsTapUpAble(i));
		vOk = vOk && vX < minX;
		if (vOk)
		{
			BalanceStation = i;
			minX = vX;
		}
	}

	if (minX != DBL_MAX)
		return;

	//最后有无调节能力的定角度站，交流系统强(换相电抗小)的优先
	for (int i = 0; i < vN; i++)
	{
		if (pmcStaData[i].WorkState == Hvdc_Rectify)
			vX = (pmcStaData[i].dx + pmcStaData[i].dr) / 100.0*pmcStaDataN[i].Udio / pmcStaDataN[i].Id;
		else
			vX = (pmcStaData[i].dx - pmcStaData[i].dr) / 100.0*pmcStaDataN[i].Udio / pmcStaDataN[i].Id;

		vOk = pmcStaData[i].StaCtrlType == StaCtrl_ConstantAngle;
		vOk = vOk && vX < minX;
		if (vOk)
		{
			BalanceStation = i;
			minX = vX;
		}
	}
}