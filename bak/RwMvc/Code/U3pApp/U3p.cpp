#include <math.h>
#include<iostream>
#include"U3p.h"

using namespace std;

void main()
{
	UTP test;
	test.ma();
	system("pause");
}


void UTP::ma()
{
	double u[3], a[3], L3p;

	La = cal_L(La, deltaLa);
	Lb = cal_L(Lb, deltaLb);
	Lc = cal_L(Lc, deltaLc);

	a[0] = cal_a(a1, deltaa1);
	a[1] = cal_a(a5, deltaa5);
	a[2] = cal_a(a9, deltaa9);

	u[0] = cal_u(Ra, Rc, La, Lc, Id, cal_Is(Ra, Rc, La, Lc, omega, U1), a[0], cal_beta(Ra, Rc, La, Lc, omega), omega);
	u[1] = cal_u(Rb, Ra, Lb, La, Id, cal_Is(Rb, Ra, Lb, La, omega, U1), a[1], cal_beta(Rb, Ra, Lb, La, omega), omega);
	u[2] = cal_u(Rc, Rb, Lc, Lb, Id, cal_Is(Rc, Rb, Lc, Lb, omega, U1), a[2], cal_beta(Rc, Rb, Lc, Lb, omega), omega);
	cout << "u" << u[0] << endl;
	
	double Lm1G1[6];
	Lm1G1[0] = cal_Lm1G1ij(Lc, La);
	Lm1G1[1] = cal_Lm1G1i(La);
	Lm1G1[2] = cal_Lm1G1ij(La, Lb);
	Lm1G1[3] = cal_Lm1G1i(Lb);
	Lm1G1[4] = cal_Lm1G1ij(Lb, Lc);
	Lm1G1[5] = cal_Lm1G1i(Lc);
	L3p=cal_L3p(u, Lm1G1, a);
	cout << "三脉动电感：" << endl;
	cout << L3p << endl;
	
	double L[6];
	L[0] = getL(Lc, La);
	L[1] = getL(La, Lc);
	L[2] = getL(Lb, La);
	L[3] = getL(La, Lb);
	L[4] = getL(Lc, Lb);
	L[5] = getL(Lb, Lc);
	
	int i;
	for (i = 0; i < 11; i++)
	{
		phasei1[i] = getphi(phasei1[i]);
		phasei2[i] = getphi(phasei2[i]);
	}
	cal_u3p(u, a, number, phasei1,phasei2 ,L, Un1,Un2);

}

double UTP::cal_L(double vL, double vdeltaL)  //叠加不平衡量
{
	vL+=vdeltaL;
	return vL;
}

double UTP::cal_a(double va, double vdeltaa)  //叠加不平衡量
{
	va = va + vdeltaa;
	return va*pi/180;
}


double UTP::cal_Is(double vr1, double vr2, double vL1, double vL2, double vomega, double vU1)
{
	double vIs;
	vIs = (sqrt(2))*vU1 / sqrt((vr1 + vr2)*(vr1 + vr2) + (vomega*vL1 + vomega*vL2)*(vomega*vL1 + vomega*vL2));
	return vIs;
}

double UTP::cal_beta(double vr1, double vr2, double vL1, double vL2, double vomega)
{
	double vbeta;
	vbeta = atan(vomega*(vL1 + vL2) / (vr1 + vr2));
	return vbeta;
}

double UTP::cal_u(double vr1, double vr2, double vL1, double vL2, double vId, double vIs, double va,  double vbeta, double vomega)  //计算换相角
{
	double vu = 20*pi/180;
	double v =vId- vIs*sin(va + vu - vbeta) - vId*vr2 / (vr1 + vr2) + (vIs*sin(va - vbeta) + vId*vr2 / (vr1 + vr2))*exp(-(vr1 + vr2)*vu / ((vL1 + vL2)*vomega));
	double dv = -vIs*cos(va + vu - vbeta) - ((vIs*sin(va - vbeta) + vId*vr2 / (vr1 + vr2))*exp(-(vr1 + vr2)*vu / ((vL1 + vL2)*vomega)))*(vr1 + vr2) / (vomega*(vL1 + vL2));
	while (abs(v)> vprcise)
	{
		v = vId - vIs*sin(va + vu - vbeta) - vId*vr2 / (vr1 + vr2) + (vIs*sin(va - vbeta) + vId*vr2 / (vr1 + vr2))*exp(-(vr1 + vr2)*vu / ((vL1 + vL2)*vomega));
		dv = -vIs*cos(va + vu - vbeta) - ((vIs*sin(va - vbeta) + vId*vr2 / (vr1 + vr2))*exp(-(vr1 + vr2)*vu / ((vL1 + vL2)*vomega)))*(vr1 + vr2) / (vomega*(vL1 + vL2));
		vu = vu - v / dv;
	}
	return vu;
}

double UTP::cal_Lm1G1ij(double vL1, double vL2)
{
	double vL = vL1*vL2 / (vL1 + vL2);
	return vL;
}

double UTP::cal_Lm1G1i(double vL1)
{
	double vL = vL1;
	return vL;
}

double UTP::cal_L3p(double vu[3], double vL[6], double va[3])  //计算三脉动电感
{
	double v1 = vu[0] * vL[0];
	double v2 = (va[1] + 2 * pi / 3 - va[0] - vu[0])*vL[1];
	double v3 = vu[1] * vL[2];
	double v4 = (va[2] + 4 * pi / 3 - va[1] - 2 * pi / 3 - vu[1])*vL[3];
	double v5 = vu[2] * vL[4];
	double v6 = (va[0] + 2 * pi - va[2] - 4 * pi / 3 - vu[2])*vL[5];
	double vL3p = (v1 + v2 + v3 + v4 + v5 + v6)/2/pi;
	return vL3p;
}

double UTP::uacos(double vx, int vn, double vphi, int vt)    //返回原函数
{
	double a = vt*vx + vphi;
	double b = vx*vn;
	if (vt == vn)
		return (-cos(a + b) / (vt + vn) + sin(vphi)*vx)*0.5;
	return (-cos(a + b) / (vt + vn) - cos(a - b) / (vt - vn))*0.5;
	//return sin(vt*vx + vphi) * cos(vx*vn);
}

double UTP::ubcos(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi - pi* 2 / 3;
	double b = vx*vn;
	if (vt == vn)
		return (-cos(a + b) / (vt + vn) + sin(vphi - pi * 2 / 3)*vx)*0.5;
	return (-cos(a + b) / (vt + vn) - cos(a - b) / (vt - vn))*0.5;
	//return sin(vt*vx - PI * 2 / 3 + vphi)* cos(vx*vn);
}
double UTP::uccos(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi + pi * 2 / 3;
	double b = vx*vn;
	if (vt == vn)
		return (-cos(a + b) / (vt + vn) + sin(vphi + pi * 2 / 3)*vx)*0.5;
	return (-cos(a + b) / (vt + vn) - cos(a - b) / (vt - vn))*0.5;
	//return sin(vt*vx + PI * 2 / 3 + vphi)* cos(vx*vn);
}

double UTP::uasin(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi;
	double b = vx*vn;
	if (vt == vn)
		return (-sin(a + b) / (vt + vn) + cos(vphi)*vx)*0.5;
	return (sin(a - b) / (vt - vn) - sin(a + b) / (vt + vn))*0.5;
	//return sin(vt*vx + vphi) * sin(vn*vx);
}
double UTP::ubsin(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi - pi * 2 / 3;
	double b = vx*vn;
	if (vt == vn)
		return (-sin(a + b) / (vt + vn) + cos(vphi - pi* 2 / 3)*vx)*0.5;
	return (sin(a - b) / (vt - vn) - sin(a + b) / (vt + vn))*0.5;
	//return sin(vt*vx - PI * 2 / 3 + vphi)* sin(vx*vn);
}
double UTP::ucsin(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi + pi * 2 / 3;
	double b = vx*vn;
	if (vt == vn)
		return (-sin(a + b) / (vt + vn) + cos(vphi + pi * 2 / 3)*vx)*0.5;
	return (sin(a - b) / (vt - vn) - sin(a + b) / (vt + vn))*0.5;
	//return sin(vt*vx + PI * 2 / 3 + vphi)* sin(vx*vn);
}

double UTP::integral(double(*pfun)(double , int, double, int), double va, double vb, double vk, int vn, double vphi, int vt)      //求a，b区间定积分
{
	return ((*pfun)(vb, vn, vphi, vt) - (*pfun)(va, vn, vphi, vt)) * vk;
}

double UTP::getL(double vL1, double vL2)  
{
	return(vL1 / (vL1 + vL2));
}

double UTP::getphi(double vphase)  
{
	return(vphase* pi / 180);
}

void UTP::cal_u3p(double vu[3],  double va[3],double vnumber, double vphase1[11],double vphase2[11],double vL[6],double vU1[11],double vU2[11])  //三脉动电压源
{
	int i = 1, j = 1, k = 1;
	double U[11], phase[11];
	double va1 , va2 , va3 , va4 ,va5 , va6 ;
	double vb1, vb2, vb3, vb4, vb5, vb6;
	va1 = va2 = va3 = va4 = va5 = va6 = vb1 = vb2 = vb3 = vb4 = vb5 = vb6 = 0;
	double a0,v1,v2;
	for (k = 1; k <= vnumber; k++) //正序
	{
		va1 += vU1[k - 1] * (integral(uacos, va[0], va[0] + vu[0], vL[0], 0, vphase1[k - 1], k) + integral(uccos, va[0], va[0] + vu[0], vL[1], 0, vphase1[k - 1], k));
		va2 += vU1[k - 1] * integral(uacos, va[0] + vu[0], va[1] + 2 * pi / 3, 1, 0, vphase1[k - 1], k);
		va3 += vU1[k - 1] * (integral(uacos, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[2], 0, vphase1[k - 1], k) + integral(ubcos, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[3], 0, vphase1[k - 1], k));
		va4 += vU1[k - 1] * integral(ubcos, va[1] + vu[1] + 2 * pi / 3, va[2] + 4 * pi / 3, 1, 0, vphase1[k - 1], k);
		va5 += vU1[k - 1] * (integral(ubcos, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[4], 0, vphase1[k - 1], k) + integral(uccos, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[5], 0, vphase1[k - 1], k));
		va6 += vU1[k - 1] * integral(uccos, va[2] + vu[2] + 4 * pi / 3, va[0] + 2 * pi, 1, 0, vphase1[k - 1], k);
	}
	for (k = 1; k <= vnumber; k++) //负序
	{
		va1 += vU2[k - 1] * (integral(uacos, va[0], va[0] + vu[0], vL[0], 0, vphase2[k - 1], k) + integral(ubcos, va[0], va[0] + vu[0], vL[1], 0, vphase2[k - 1], k));
		va2 += vU2[k - 1] * integral(uacos, va[0] + vu[0], va[1] + 2 * pi / 3, 1, 0, vphase2[k - 1], k);
		va3 += vU2[k - 1] * (integral(uacos, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[2], 0, vphase2[k - 1], k) + integral(uccos, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[3], 0, vphase2[k - 1], k));
		va4 += vU2[k - 1] * integral(uccos, va[1] + vu[1] + 2 * pi / 3, va[2] + 4 * pi / 3, 1, 0, vphase2[k - 1], k);
		va5 += vU2[k - 1] * (integral(uccos, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[4], 0, vphase2[k - 1], k) + integral(ubcos, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[5], 0, vphase2[k - 1], k));
		va6 += vU2[k - 1] * integral(ubcos, va[2] + vu[2] + 4 * pi / 3, va[0] + 2 * pi, 1, 0, vphase2[k - 1], k);
	}
	a0 = sqrt(2)*(va1 + va2 + va3 + va4 + va5 + va6) / (2 * pi);
	

	cout << "直流电压分量：" << a0 << endl;
	va1 = va2 = va3 = va4 = va5 = va6 = vb1 = vb2 = vb3 = vb4 = vb5 = vb6 = v1 = v2 = 0;
    double an[11],bn[11];
	for (j = 1; j <=vnumber; j++) 
	{
		for (i = 1; i <=vnumber; i++)//正序
		{
			va1 += vU1[i - 1] * (integral(uacos, va[0], va[0] + vu[0], vL[0], j, vphase1[i - 1], i) + integral(uccos, va[0], va[0] + vu[0], vL[1], j, vphase1[i - 1], i));
			va2 += vU1[i - 1] * integral(uacos, va[0] + vu[0], va[1] + 2 * pi / 3, 1, j, vphase1[i - 1], i);
			va3 += vU1[i - 1] * (integral(uacos, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[2], j, vphase1[i - 1], i) + integral(ubcos, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[3], j, vphase1[i - 1], i));
			va4 += vU1[i - 1] * integral(ubcos, va[1] + vu[1] + 2 * pi / 3, va[2] + 4 * pi / 3, 1, j, vphase1[i - 1], i);
			va5 += vU1[i - 1] * (integral(ubcos, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[4], j, vphase1[i - 1], i) + integral(uccos, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[5], j, vphase1[i - 1], i));
			va6 += vU1[i - 1] * integral(uccos, va[2] + vu[2] + 4 * pi / 3, va[0] + 2 * pi, 1, j, vphase1[i - 1], i);
			
			vb1 += vU1[i - 1] * (integral(uasin, va[0], va[0] + vu[0], vL[0], j, vphase1[i - 1], i) + integral(ucsin, va[0], va[0] + vu[0], vL[1], j, vphase1[i - 1], i));
			vb2 += vU1[i - 1] * integral(uasin, va[0] + vu[0], va[1] + 2 * pi / 3, 1, j, vphase1[i - 1], i);
			vb3 += vU1[i - 1] * (integral(uasin, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[2], j, vphase1[i - 1], i) + integral(ubsin, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[3], j, vphase1[i - 1], i));
			vb4 += vU1[i - 1] * integral(ubsin, va[1] + vu[1] + 2 * pi / 3, va[2] + 4 * pi / 3, 1, j, vphase1[i - 1], i);
			vb5 += vU1[i - 1] * (integral(ubsin, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[4], j, vphase1[i - 1], i) + integral(ucsin, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[5], j, vphase1[i - 1], i));
			vb6 += vU1[i - 1] * integral(ucsin, va[2] + vu[2] + 4 * pi / 3, va[0] + 2 * pi, 1, j, vphase1[i - 1], i);
			
		}
		for (i = 1; i <= vnumber; i++)//负序
		{
			va1 += vU2[i - 1] * (integral(uacos, va[0], va[0] + vu[0], vL[0], j, vphase2[i - 1], i) + integral(ubcos, va[0], va[0] + vu[0], vL[1], j, vphase2[i - 1], i));
			va2 += vU2[i - 1] * integral(uacos, va[0] + vu[0], va[1] + 2 * pi / 3, 1, j, vphase2[i - 1], i);
			va3 += vU2[i - 1] * (integral(uacos, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[2], j, vphase2[i - 1], i) + integral(uccos, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[3], j, vphase2[i - 1], i));
			va4 += vU2[i - 1] * integral(uccos, va[1] + vu[1] + 2 * pi / 3, va[2] + 4 * pi / 3, 1, j, vphase2[i - 1], i);
			va5 += vU2[i - 1] * (integral(uccos, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[4], j, vphase2[i - 1], i) + integral(ubcos, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[5], j, vphase2[i - 1], i));
			va6 += vU2[i - 1] * integral(ubcos, va[2] + vu[2] + 4 * pi / 3, va[0] + 2 * pi, 1, j, vphase2[i - 1], i);

			vb1 += vU2[i - 1] * (integral(uasin, va[0], va[0] + vu[0], vL[0], j, vphase2[i - 1], i) + integral(ubsin, va[0], va[0] + vu[0], vL[1], j, vphase2[i - 1], i));
			vb2 += vU2[i - 1] * integral(uasin, va[0] + vu[0], va[1] + 2 * pi / 3, 1, j, vphase2[i - 1], i);
			vb3 += vU2[i - 1] * (integral(uasin, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[2], j, vphase2[i - 1], i) + integral(ucsin, va[1] + 2 * pi / 3, va[1] + vu[1] + 2 * pi / 3, vL[3], j, vphase2[i - 1], i));
			vb4 += vU2[i - 1] * integral(ucsin, va[1] + vu[1] + 2 * pi / 3, va[2] + 4 * pi / 3, 1, j, vphase2[i - 1], i);
			vb5 += vU2[i - 1] * (integral(ucsin, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[4], j, vphase2[i - 1], i) + integral(ubsin, va[2] + 4 * pi / 3, va[2] + vu[2] + 4 * pi / 3, vL[5], j, vphase2[i - 1], i));
			vb6 += vU2[i - 1] * integral(ubsin, va[2] + vu[2] + 4 * pi / 3, va[0] + 2 * pi, 1, j, vphase2[i - 1], i);
		}
		an[j-1] = (va1 + va2 + va3 + va4 + va5 + va6) / pi;
		bn[j-1] = (vb1 + vb2 + vb3 + vb4 + vb5 + vb6) / pi;
		U[j-1] = sqrt(an[j-1] * an[j-1] + bn[j-1] * bn[j-1]);
		phase[j-1 ] = atan2(bn[j-1 ] , an[j-1]);
		cout << "第" << j << "次电压幅值：" << endl;
		cout << U[j-1 ] << endl;
		cout << "第" << j << "次电压相位：" << endl;
		cout << (phase[j -1])*180/pi << endl;
		va1 = va2 = va3 = va4 = va5 = va6 = vb1 = vb2 = vb3 = vb4 = vb5 = vb6 = 0;
	}
	
}


 