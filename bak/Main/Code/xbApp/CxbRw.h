#pragma once

#include "CRwDev.h"
#include "CxbDevBase.h"
#include "CxbHvdcGrid.h"

#include "CxbOrder.h"
#include "CxbResult.h"

class CxbRw : public CRwDev
{
protected:

	void doLoad(CDevBase * vDevice) override;
	void doSave(CDevBase * vDevice) override;

};

