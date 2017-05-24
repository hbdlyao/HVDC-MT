#pragma once

#include <string>
#include <map>
#include "CMydefs.h"
using namespace std;

struct struct_xbU3PData
{
public:
	string CaseID;

	string PowLevel;

	double * Urms =nullptr;
	double * Angle = nullptr;

	double * Ire = nullptr;
	double * Iim = nullptr;

	double * Yb = nullptr;

};


typedef map<string, struct_xbU3PData *> pxbU3PData_Map;
typedef map<string, pxbU3PData_Map *> pxbU3PPowPre_Map;

