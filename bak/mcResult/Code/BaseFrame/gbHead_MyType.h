#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

typedef unsigned char Byte;

//各基本类型的Vector容器
typedef vector<float> floatVector;
typedef vector<double> doubleVector;
typedef vector<int> intVector;
typedef vector<unsigned int> uintVector;


typedef vector<string> StrVector;
typedef vector<StrVector> Str2Array;
typedef vector<StrVector> StrTable;

//
typedef vector<intVector> intMatrix;
typedef vector<doubleVector> dbMatrix;

////////////////
typedef map<string, int> NodeMap;
typedef map<string, int> StationMap;
