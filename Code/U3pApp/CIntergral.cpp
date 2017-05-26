#include "C3pDefs.h"
#include <math.h>
#include "CIntergral.h"

double uacos(double vx, int vn, double vphi, int vt)    //返回原函数
{
	double a = vt*vx + vphi;
	double b = vx*vn;
	if (vt == vn)
		return (-cos(a + b) / (vt + vn) + sin(vphi)*vx)*0.5;
	return (-cos(a + b) / (vt + vn) - cos(a - b) / (vt - vn))*0.5;
	//return sin(vt*vx + vphi) * cos(vx*vn);
}

double ubcos(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi - PI * 2 / 3;
	double b = vx*vn;
	if (vt == vn)
		return (-cos(a + b) / (vt + vn) + sin(vphi - PI * 2 / 3)*vx)*0.5;
	return (-cos(a + b) / (vt + vn) - cos(a - b) / (vt - vn))*0.5;
	//return sin(vt*vx - PI * 2 / 3 + vphi)* cos(vx*vn);
}
double uccos(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi + PI * 2 / 3;
	double b = vx*vn;
	if (vt == vn)
		return (-cos(a + b) / (vt + vn) + sin(vphi + PI * 2 / 3)*vx)*0.5;
	return (-cos(a + b) / (vt + vn) - cos(a - b) / (vt - vn))*0.5;
	//return sin(vt*vx + PI * 2 / 3 + vphi)* cos(vx*vn);
}

double  uasin(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi;
	double b = vx*vn;
	if (vt == vn)
		return (-sin(a + b) / (vt + vn) + cos(vphi)*vx)*0.5;
	return (sin(a - b) / (vt - vn) - sin(a + b) / (vt + vn))*0.5;
	//return sin(vt*vx + vphi) * sin(vn*vx);
}
double ubsin(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi - PI * 2 / 3;
	double b = vx*vn;
	if (vt == vn)
		return (-sin(a + b) / (vt + vn) + cos(vphi - PI * 2 / 3)*vx)*0.5;
	return (sin(a - b) / (vt - vn) - sin(a + b) / (vt + vn))*0.5;
	//return sin(vt*vx - PI * 2 / 3 + vphi)* sin(vx*vn);
}
double ucsin(double vx, int vn, double vphi, int vt)
{
	double a = vt*vx + vphi + PI * 2 / 3;
	double b = vx*vn;
	if (vt == vn)
		return (-sin(a + b) / (vt + vn) + cos(vphi + PI * 2 / 3)*vx)*0.5;
	return (sin(a - b) / (vt - vn) - sin(a + b) / (vt + vn))*0.5;
	//return sin(vt*vx + PI * 2 / 3 + vphi)* sin(vx*vn);
}

double integral(double(*pfun)(double, int, double, int), double va, double vb, double vk, int vn, double vphi, int vt)      //求a，b区间定积分
{
	return ((*pfun)(vb, vn, vphi, vt) - (*pfun)(va, vn, vphi, vt)) * vk;
}