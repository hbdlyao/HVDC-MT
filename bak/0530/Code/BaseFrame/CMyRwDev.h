#pragma once


#include "CMyRw.h"
#include "CDevBase.h"
#include "CDevGrid.h"

#include <string>

using namespace std;

class CMyRwDev : public CMyRwDbf
{
protected:
	CDevGrid * pGrid;

public:
	void InitGrid(CDevGrid * pGrid);

public:
	void OnLoad() override;
	void OnSave() override;

protected:
	string StaField(int vStaCount, int vIndex);
	string NodeNameField(int vStaCount, int vIndex);
	string NodeIDField(int vStaCount, int vIndex);

	virtual string GetSQL_Load();

	virtual void doLoad(CDevBase * vDevice);
	virtual void doSave(CDevBase * vDevice);

};
