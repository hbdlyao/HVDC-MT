#pragma once

#include "CMyRwDev.h"
#include "CxbDevBase.h"
#include "CxbHvdcGrid.h"

#include "CxbOrder.h"
#include "CxbResult.h"

class CxbRw : public CMyRwDev
{
protected:

	void doLoad(CDevBase * vDevice) override;
	void doSave(CDevBase * vDevice) override;

};

