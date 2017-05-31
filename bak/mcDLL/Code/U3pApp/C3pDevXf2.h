#pragma once

#include "C3pDevTwo.h"

class C3pDevXf2 : public C3pDevTwo
{

protected:
	/**
	* 变压器额定容量
	*/
	double SN;
	/**
	* 网侧额定交流电压
	*/
	double UacN;
	/**
	* 阀侧额定交流电压
	*/
	double UvN;
	/**
	* 短路阻抗百分比
	*/
	double Ukp;
	/**
	* 阻性压降百分比
	*/
	double Urp;
	/**
	* 额定变比
	*/
	double TkN;
	/**
	* 额定变比偏差
	*/
	double dTkN;
	/**
	* 变压器正序阀侧滞后网侧角度
	*/
	double PhaseShift;
	/**
	* 变压器等效电感电感标准差
	*/
	double Std_Lt;
	/**
	* 偏差程序分配模式变压器等效电感偏差
	*/
	double Dis_dLt;
	/**
	* 变压器等效电感A相偏差
	*/
	double dLtA;
	/**
	* 变压器等效电感B相偏差
	*/
	double dLtB;
	/**
	* 变压器等效电感B相偏差
	*/
	double dLtC;

	//double LtNd//无偏差的等值电抗
	/**
	* 变压器等效电感A相偏差
	*/
	double * dLtAVec;
	/**
	* 变压器等效电感B相偏差
	*/
	double * dLtBVec;
	/**
	* 变压器等效电感B相偏差
	*/
	double * dLtCVec;
	/**
	* 换流器类型（整流逆变）
	*/
	int StationType;
	/**
	* 结线方式（YY YD）
	*/
	int ConMode;

	int DType;
public:
	double GetdTkN();
	void SetdTkN(double newVal);
	double GetStd_Lt();
	void SetStd_Lt(double newVal);
	double GetdLtA();
	void SetdLtA(double newVal);
	double GetdLtB();
	void SetdLtB(double newVal);
	double GetdLtC();
	void SetdLtC(double newVal);
	double GetTkN();
	void SetTkN(double newVal);
	double GetUacN();
	void SetUacN(double newVal);
	double GetUkp();
	void SetUkp(double newVal);
	double GetUrp();
	void SetUrp(double newVal);
	double GetUvN();
	void SetUvN(double newVal);
	double GetSN();
	void SetSN(double newVal);
	double GetPhaseShift();
	void SetPhaseShift(double newVal);
	double GetDis_dLt();
	void SetDis_dLt(double newVal);

public:
	virtual void Prepare3pData(int vDType, int vLoopTimes);

private:
	void doDFixed();

	void doDAutoDis();

	void doDRandom(int vLoopTimes);
};
