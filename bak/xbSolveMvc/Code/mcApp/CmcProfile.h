///////////////////////////////////////////////////////////
//  CmcProfile.h
//  Implementation of the Class CmcProfile
//  Created on:      03-5ÔÂ-2017 19:55:50
//  Original author: Administrator
///////////////////////////////////////////////////////////

#if !defined(EA_BDE7A645_7B7D_4155_8947_D2742E0A88F7__INCLUDED_)
#define EA_BDE7A645_7B7D_4155_8947_D2742E0A88F7__INCLUDED_

#include "CmcOrder.h"
#include "CmcDefs.h"
#include "CPowerProfile.h"
class CmcProfile : public CPowerProfile
{
public:
	CmcOrder* pmcOrder;

protected:
	int Jdim;
	int Kdim;
	double* J_Matrix;
	double* F_Vect;
	double* X_Vect;
	double* dX_Vect;

public:
	bool LimitOK;
	double Ud_Max;	
	int BalanceStation;
	bool IsUrefToGround;
	struct_mcStationData* pmcStaData;
	struct_mcStationData* pmcStaDataN;

public:
	~CmcProfile();

	void Init() override;
	void Clear() override;
	void Release() override;

	virtual void InitOrder(CmcOrder * vOrder);

public:
	int StaDim();

	bool IsBiPole();
	bool IsMetalLine();

	void ResetData();
	void ResetMatrix();

	void OffSet();

public:
	void InitX();
	void InitX_Y(int vNode, double vUnode);
	void InitX_I(int vK, double vId);

	//
	void UpdateY0(int iNode, double vY);
	void UpdateY(int iNode, int jNode, double vY);	

	void UpdateJ();
	void UpdateF_Y();
	void UpdateF_J();

	//
	void UpdateX();

	void UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s);
	void UpdateF_IdCtrl(int vK_s, int iNode_s, int jNode_s, int vK_m);
	void UpdateF_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s);
	void UpdateF_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m);
	void UpdateF_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s);
	void UpdateJ_IdCtrl(int vK_s, int iNode_s, int jNode_s);
	void UpdateJ_PdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s);
	void UpdateJ_UdCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s, int vK_m, int iNode_m, int jNode_m);
	void UpdateJ_AngCtrl(int vOffset, int vK_s, int iNode_s, int jNode_s);

public:

	void Solve_dX();

	void SaveX();
	void SaveX(int vOffset, int vK_s, int iNode_s, int jNode_s);

	double GetMaxdX();
	bool IsTapUpAble(int vK);
	bool IsTapDownAble(int vK);

	void UpdateBalanceStation();

	void UpdateUdio();
	void UpdateUdio(int vK);
	void UpdateCtrl_Angle(int vK);
	void UpdateCtrl_Pd(int vK);
	void UpdateCtrl_Ud(int vK);
	void UpdateCtrl_Id(int vK);
	void UpdateConvertor_N(int vK);
	void UpdateConvertor_DC(int vK);
	void UpdateConvertor_AC(int vK);
	void UpdateConvertor_Port(int vK);
	void UpdateXf2_N(int vK);
	void UpdateXf2_l(int vK);
	void UpdateXf2_v(int vK);
	void UpdateXf2_Port(int vK);
	void UpdateXf2_UpShift(int vK);
	void UpdateXf2_DownShift(int vK);

	void UpdateACSide(int vK);

	void LimitUd();
	void CalStation();
	void CalAngleStation(int vK);
	void CalUvStation(int vK);
	void ChangeStationCtrlType(int vK);
	void CalStation_N();
	void CalACSide();

protected:
	void doInitMatrix();
	void doInitData();
	void doUpdateJ(int vK);
	void doUpdateF_J(int vK);
	void doLimitUd(int vK);
	void doCalStation_N(int vK);
	void doCalACSide(int vK);
	void doInitX(int vK);
	void doCalStation(int vK);

};
#endif // !defined(EA_BDE7A645_7B7D_4155_8947_D2742E0A88F7__INCLUDED_)
