#pragma once


#include "CDevTBL.h"
#include "CDevBase.h"

class C3pDevTBL : public CDevTBL
{

public:
	string TypeToName(int vDevType) override;
	static CDevBase * NewDevice(int vDevType);

protected:
	CDevBase * doNewDevice(int vDevType) override;

};
