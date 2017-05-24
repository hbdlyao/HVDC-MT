#pragma once


#include <string>

#include <map>

using namespace std;

struct struct_3pXf2Data
{
public:
	string CaseID;

	string PowLevel;

	//∑ß≤‡µÁ—π
	double UvRms;

};


typedef map<string, struct_3pXf2Data *> p3pXf2Data_Map;