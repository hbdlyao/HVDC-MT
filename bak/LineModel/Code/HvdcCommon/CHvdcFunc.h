#pragma once

#include <stdarg.h>
#include <string>
#include <vector>

#include "CHvdcDefs.h"

using namespace std;

class CHvdcFunc
{
	CHvdcFunc() {};
	virtual ~CHvdcFunc() {};
	CHvdcFunc(const CHvdcFunc& vFunc) {};

public:

	static double R2D(double rad) { return rad / M_PI * 180; }
	static double D2R(double degree) { return degree / 180 * M_PI; }


	static void print(FILE* foutFile, const char* fmt, ...)
	{
		va_list ap;
		va_start(ap, fmt);//将ap指向fmt后的第一个参数
						  //vprintf(fmt, ap);
		vfprintf(foutFile, fmt, ap);
		va_end(ap);//将ap置为NULL
	}

};
