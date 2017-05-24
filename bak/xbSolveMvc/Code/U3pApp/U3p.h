#pragma once
#include<math.h>
#include<iostream>
#define pi 3.1415926535
#define vprcise 0.000000001
#define N 1000
using namespace std;

class UTP
{
public:
	void ma();

	double cal_L(double vL, double vdeltaL);
	double cal_a(double va, double vdeltaa);
	double cal_Is(double vr1, double vr2, double vL1, double vL2, double vomega,double vU1);
	double cal_beta(double vr1, double vr2, double vL1, double vL2, double vomega);
	double cal_u(double vr1, double vr2, double vL1, double vL2,double vId,double vIs,double va,double vbeta,double vomega);
	double cal_Lm1G1ij(double vL1, double vL2);
	double cal_Lm1G1i(double vL1);
	double cal_L3p(double vu[3], double vL[6], double va[3]);
	static double uacos(double vx, int vn, double vphi, int vt);
	static double ubcos(double vx, int vn, double vphi, int vt);
	static double uccos(double vx, int vn, double vphi, int vt);
	static double uasin(double vx, int vn, double vphi, int vt);
	static double ubsin(double vx, int vn, double vphi, int vt);
	static double ucsin(double vx, int vn, double vphi, int vt);
	double integral(double(*pfun)(double , int, double, int), double va, double vb, double vk, int vn, double vphi, int vt);
	double getL(double vL1, double vL2);
	double getphi(double vphase);
	void cal_u3p(double vu[3], double va[3], double vnumber, double vphase1[11],double vphase2[11], double vL[6], double vU1[11],double vU2[11]);
	
	UTP()
	{
		La = 0.0252;
		Lb = 0.0252;
		Lc = 0.0252;
		deltaLa = 0.0005;
		deltaLb = 0;
		deltaLc = -0.0005;
		Ra = 0.264;
		Rb = 0.264;
		Rc = 0.264;
		a1 = 15;
		a5 = 15;
		a9 = 15;
		deltaa1 = 0.1;
		deltaa5 = 0.1;
		deltaa9 = 0;
		Id = 3000;
		U1 = 209.7*1000;
		Un1[0] = 209.7 * 1*1000/sqrt(3);     Un2[0] = 209.7*0.020*1000 / sqrt(3);
		Un1[1] = 209.7 * 0;          Un2[1] = 209.7 * 0;
		Un1[2] = 209.7*0.005*1000 / sqrt(3);   Un2[2] = 209.7*0.005*1000 / sqrt(3);
		Un1[3] = 209.7 * 0;          Un2[3] = 209.7 * 0;
		Un1[4] = 209.7*0.0135*1000 / sqrt(3);  Un2[4] = 209.7*0.0135*1000 / sqrt(3);
		Un1[5] = 209.7 * 0;          Un2[5] = 209.7 * 0;
		Un1[6] = 209.7*0.0035*1000 / sqrt(3);  Un2[6] = 209.7*0.0035*1000 / sqrt(3);
		Un1[7] = 209.7 * 0;          Un2[7] = 209.7 * 0;
		Un1[8] = 209.7*0.001*1000 / sqrt(3);   Un2[8] = 209.7*0.001*1000 / sqrt(3);
		Un1[9] = 209.7 * 0;          Un2[9] = 209.7 * 0;
		Un1[10] = 209.7*0.0015*1000 / sqrt(3); Un2[10] = 209.7*0.0015*1000 / sqrt(3);

		phasei1[0] = 30.0000;   phasei2[0] = 323.8823;
		phasei1[1] = 0;         phasei2[1] = 0;
		phasei1[2] = 229.7394;  phasei2[2] = 334.9632;
		phasei1[3] = 0;         phasei2[3] = 0;
		phasei1[4] = 295.7161;  phasei2[4] = 351.7081;
		phasei1[5] = 0;         phasei2[5] = 0;
		phasei1[6] = 321.7893;  phasei2[6] =287.2848;
		phasei1[7] = 0;         phasei2[7] = 0;
		phasei1[8] = 126.3713;  phasei2[8] = 250.7340;
		phasei1[9] = 0;         phasei2[9] = 0;
		phasei1[10] = 246.8395; phasei2[10]=146.8395;
		
		omega = 2 * pi * 50;
		number = 11;
	}

private:	
	double La, Lb, Lc;
	double deltaLa, deltaLb, deltaLc;
	double Ra, Rb, Rc;
	double a1, a5, a9;
	double deltaa1, deltaa5, deltaa9;
	double Id;
	double U1;
	double Un1[11];
	double Un2[11];
	double phasei1[11];
	double phasei2[11];
	double omega;
	int number;
};

