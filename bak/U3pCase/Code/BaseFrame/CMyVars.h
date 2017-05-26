#pragma once


class CMyVars
{
protected:
	CMyVars(const CMyVars& theInstance) {};

	CMyVars() {};
	~CMyVars() {};

public:
	static void Release();
	static void Clear();
	static void Init();

};

