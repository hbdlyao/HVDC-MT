#pragma once

#include <string>

using namespace std;


class CMyParams
{
protected:
	CMyParams(const CMyParams& theInstance) {};

	CMyParams() {};
	~CMyParams() {}
	
	//
	static void GetExeFilePath();;
public:
	static int ProjectID;
	static string ProjectName;

	static void Init();
	//
	static string PRJFilePath;
	static string ExeFilePath;

	static string PRJFile;

};




