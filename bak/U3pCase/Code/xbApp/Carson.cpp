//#include "stdafx.h"
#include "Carson.h"
#include <cmath>
#include <iostream>


#include "CHvdcDefs.h"


#define GAMMA 1.7811
#define SERISES 5
#define SQRT_RE 0
#define SQRT_IM 1
#define N 5000
#define E_MIN 0.000000001

double fun_re(double vx, double vrcos, double vrsin);
double fun_im(double vx, double vrcos, double vrsin);
double comcal(double vre, double vim, unsigned int vtype);
double Trap(double(*pfun)(double, double, double), double va, double vb, double vrcos, double vrsin);

int carson(double *vE, double *vF, double vr, double vtheta)
{
	double vrsin = vr*sin(vtheta);
	double vrcos = vr*cos(vtheta);
	double vt;
	double vi = 0;
	*vE = 0;
	*vF = 0;
	while (1)
	{
		vt = Trap(fun_re, vi * 10, vi * 10 + 10, vrcos, vrsin);
		*vE += vt;
		if (abs(vt / *vE) < E_MIN) break;
		//vs = vt;
		vi++;
	}
	vi = 0;
	while (1)
	{
		vt = Trap(fun_im, vi * 10, vi * 10 + 10, vrcos, vrsin);
		*vF += vt;
		if (abs(vt / *vF) < E_MIN) break;
		//vs = vt;
		vi++;
	}
	return 0;
}
double fun_re(double vx, double vrcos, double vrsin)
{
	return exp(-vx*vrcos)*cos(vx*vrsin)*(comcal(vx*vx, 1, SQRT_RE) - vx);
}
double fun_im(double vx, double vrcos, double vrsin)
{
	return exp(-vx*vrcos)*cos(vx*vrsin)*comcal(vx*vx, 1, SQRT_IM);
}
double Trap(double(*pfun)(double, double, double), double va, double vb, double vrcos, double vrsin)      //求fun在a，b区间定积分
{
	double vs, vh;
	int vi;
	vs = ((*pfun)(va, vrcos, vrsin) + (*pfun)(vb, vrcos, vrsin)) / 2.0;
	vh = (vb - va) / N;
	for (vi = 1; vi<N; vi++)
		vs += (*pfun)(va + vi*vh, vrcos, vrsin);
	return(vs*vh);
}
double comcal(double vre, double vim, unsigned int vtype)
{
	double vr, va;
	vr = sqrt(vre*vre + vim*vim);
	va = atan2(vim, vre);
	switch (vtype)
	{
	case SQRT_RE:
		return sqrt(vr)*cos(va / 2);
	case SQRT_IM:
		return sqrt(vr)*sin(va / 2);

	default:break;
	}
	return 0;
}

double an(double vr, unsigned int vn, double vbuf[]);
double cn(double vr, unsigned int vn, double vbuf[]);
double en(double vr, unsigned int vn, double vbuf[]);
double fn(double vr, unsigned int vn, double vbuf[]);
double gn(double vr, unsigned int vn, double vbuf[]);
double hn(double vr, unsigned int vn, double vbuf[]);

double S1(double vr, double vtheta);
double S2(double vr, double vtheta);
double S3(double vr, double vtheta);
double S4(double vr, double vtheta);
double S5(double vr, double vtheta);
double S6(double vr, double vtheta);
double S7(double vr, double vtheta);
double S8(double vr, double vtheta);

double carson_E(double vr, double vtheta)
{
	double v_E = 0;
	double v_S1, v_S2, v_S3, v_S4, v_S5, v_S6, v_S7, v_S8;
	v_S1 = S1(vr, vtheta);
	v_S2 = S2(vr, vtheta);
	v_S3 = S3(vr, vtheta);
	v_S4 = S4(vr, vtheta);
	v_S5 = S5(vr, vtheta);
	v_S6 = S6(vr, vtheta);
	v_S7 = S7(vr, vtheta);
	v_S8 = S8(vr, vtheta);
	if (vr<0.25)
	{
		v_E = PI*0.125 - vr*cos(vtheta) / (3.0*sqrt(2))
			+ vr*vr*cos(2.0*vtheta)*(0.6728 + log(2 / vr)) / 16.0
			+ vr*vr*vtheta*sin(2.0*vtheta) / 16.0;
		return v_E;
	}
	else if (vr <= 5)
	{
		v_E = PI*0.125*(1 - v_S4) + 0.5*log(2.0 / (GAMMA * vr))*v_S2
			+ 0.5*vtheta*v_S1 - v_S5 / sqrt(2)
			+ 0.5*v_S6 + v_S7 / sqrt(2);
		return v_E;
	}
	else
	{
		v_E = cos(vtheta) / (vr*sqrt(2)) - cos(2.0*vtheta) / (vr*vr)
			+ cos(3.0*vtheta) / (vr*vr*vr*sqrt(2))
			+ 3.0*cos(5.0*vtheta) / (pow(vr, 5)*sqrt(2));
		return v_E;
	}

}
double carson_F(double vr, double vtheta)
{
	double v_F = 0;
	double v_S1, v_S2, v_S3, v_S4, v_S5, v_S6, v_S7, v_S8;
	v_S1 = S1(vr, vtheta);
	v_S2 = S2(vr, vtheta);
	v_S3 = S3(vr, vtheta);
	v_S4 = S4(vr, vtheta);
	v_S5 = S5(vr, vtheta);
	v_S6 = S6(vr, vtheta);
	v_S7 = S7(vr, vtheta);
	v_S8 = S8(vr, vtheta);
	if (vr<0.25)
	{
		v_F = 0.5*log(2.0 / vr) - 0.0386 + vr*cos(vtheta) / (3 * sqrt(2));
		return v_F;
	}
	else if (vr <= 5)
	{
		v_F = 0.25 + 0.5*log(2.0 / (GAMMA * vr))*(1 - v_S4)
			- 0.5*vtheta*v_S3 + v_S5 / sqrt(2)
			- PI*0.125*v_S2 + v_S7 / sqrt(2) - 0.5*v_S8;
		return v_F;
	}
	else
	{
		v_F = cos(vtheta) / (vr*sqrt(2))
			- cos(3.0*vtheta) / (vr*vr*vr*sqrt(2))
			+ 3.0*cos(5.0*vtheta) / (pow(vr, 5)*sqrt(2));
		return v_F;
	}
}

double an(double vr, unsigned int vn, double vbuf[])
{
	if (!vn)
	{
		vbuf[0] = vr*vr / 8;
		return vbuf[vn];
	}
	double v2n = 2.0*vn;
	vbuf[vn] = -an(vr, vn - 1, vbuf) / (v2n*pow(v2n + 1, 2)*(v2n + 2))*pow(vr / 2, 4);
	return vbuf[vn];
}
double cn(double vr, unsigned int vn, double vbuf[])
{
	if (!vn)
	{
		vbuf[0] = vr*vr*vr*vr / 192;
		return vbuf[vn];
	}
	double v2n = 2.0*vn;
	vbuf[vn] = -cn(vr, vn - 1, vbuf) / ((v2n + 1)*pow(v2n + 2, 2)*(v2n + 3))*pow(vr / 2, 4);
	return vbuf[vn];
}
double en(double vr, unsigned int vn, double vbuf[])
{
	if (!vn)
	{
		vbuf[0] = vr / 3;
		return vbuf[vn];
	}
	double v4n = 4.0*vn;
	vbuf[vn] = -en(vr, vn - 1, vbuf) / ((v4n - 1)*pow(v4n + 1, 2)*(v4n + 3))*pow(vr, 4);
	return vbuf[vn];
}
double fn(double vr, unsigned int vn, double vbuf[])
{
	if (!vn)
	{
		vbuf[0] = vr*vr*vr / 45;
		return vbuf[vn];
	}
	double v4n = 4.0*vn;
	vbuf[vn] = -fn(vr, vn - 1, vbuf) / ((v4n + 1)*pow(v4n + 3, 2)*(v4n + 5))*pow(vr, 4);
	return vbuf[vn];
}
double gn(double vr, unsigned int vn, double vbuf[])
{
	if (!vn)
	{
		vbuf[0] = 1.25;
		return vbuf[vn];
	}
	vbuf[vn] = gn(vr, vn - 1, vbuf) + 0.25 / vn + 0.5 / (0.5 + vn) + 0.25 / (vn + 1);
	return vbuf[vn];
}
double hn(double vr, unsigned int vn, double vbuf[])
{
	if (!vn)
	{
		vbuf[0] = 1.25;
		return vbuf[vn];
	}
	vbuf[vn] = hn(vr, vn - 1, vbuf) + 0.25 / (1.5 + vn) + 0.25 / (0.5 + vn) + 0.5 / (1 + vn);
	return vbuf[vn];
}
double S1(double vr, double vtheta)
{
	double vs = 0;
	double vbuf[SERISES + 1];
	an(vr, SERISES, vbuf);
	//std::cout << "an" << std::endl;
	for (int n = 0; n <= SERISES; n++)
	{
		vs += vbuf[n] * sin(4 * n + 2)*vtheta;
		//std::cout << vbuf[n] << std::endl;
	}
	//std::cout << vs << std::endl;
	return vs;
}
double S2(double vr, double vtheta)
{
	double vs = 0;
	double vbuf[SERISES + 1];
	an(vr, SERISES, vbuf);
	//std::cout << "an" << std::endl;
	for (int n = 0; n <= SERISES; n++)
	{
		vs += vbuf[n] * cos(4 * n + 2)*vtheta;
		//std::cout << vbuf[n] << std::endl;
	}
	//std::cout << vs << std::endl;
	return vs;
}
double S3(double vr, double vtheta)
{
	double vs = 0;
	double vbuf[SERISES + 1];
	cn(vr, SERISES, vbuf);
	//std::cout << "cn" << std::endl;
	for (int n = 0; n <= SERISES; n++)
	{
		vs += vbuf[n] * sin(4 * n + 4)*vtheta;
		//std::cout << vbuf[n] << std::endl;
	}
	//std::cout << vs << std::endl;
	return vs;
}
double S4(double vr, double vtheta)
{
	double vs = 0;
	double vbuf[SERISES + 1];
	cn(vr, SERISES, vbuf);
	//std::cout << "cn" << std::endl;
	for (int n = 0; n <= SERISES; n++)
	{
		vs += vbuf[n] * cos(4 * n + 4)*vtheta;
		//std::cout << vbuf[n] << std::endl;
	}
	//std::cout << vs << std::endl;
	return vs;
}
double S5(double vr, double vtheta)
{
	double vs = 0;
	double vbuf[SERISES + 1];
	en(vr, SERISES, vbuf);
	//std::cout << "en" << std::endl;
	for (int n = 0; n <= SERISES; n++)
	{
		vs += vbuf[n] * cos(4 * n + 1)*vtheta;
		//std::cout << vbuf[n] << std::endl;
	}
	//std::cout << vs << std::endl;
	return vs;
}
double S6(double vr, double vtheta)
{
	double vs = 0;
	double v_an_buf[SERISES + 1];
	double v_gn_buf[SERISES + 1];
	an(vr, SERISES, v_an_buf);
	gn(vr, SERISES, v_gn_buf);
	//std::cout << "gn" << std::endl;
	for (int n = 0; n <= SERISES; n++)
	{
		vs += v_an_buf[n] * v_gn_buf[n] * cos(4 * n + 2)*vtheta;
		//std::cout << vbuf[n] << std::endl;
	}
	//std::cout << vs << std::endl;
	return vs;
}
double S7(double vr, double vtheta)
{
	double vs = 0;
	double vbuf[SERISES + 1];
	fn(vr, SERISES, vbuf);
	//std::cout << "fn" << std::endl;
	for (int n = 0; n <= SERISES; n++)
	{
		vs += vbuf[n] * cos(4 * n + 3)*vtheta;
		//std::cout << vbuf[n] << std::endl;
	}
	//std::cout << vs << std::endl;
	return vs;
}
double S8(double vr, double vtheta)
{
	double vs = 0;
	double v_cn_buf[SERISES + 1];
	double v_hn_buf[SERISES + 1];
	cn(vr, SERISES, v_cn_buf);
	hn(vr, SERISES, v_hn_buf);
	//std::cout << "hn" << std::endl;
	for (int n = 0; n <= SERISES; n++)
	{
		vs += v_cn_buf[n] * v_hn_buf[n] * cos(4 * n + 4)*vtheta;
		//std::cout << vbuf[n] << std::endl;
	}
	//std::cout << vs << std::endl;
	return vs;
}