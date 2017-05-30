///////////////////////////////////////////////////////////
//  CmcSolvesNormal.h
//  Implementation of the Class CmcSolvesNormal
//  Created on:      21-5ÔÂ-2017 0:48:10
//  Original author: open2
///////////////////////////////////////////////////////////

#if !defined(EA_644CC2CD_A2DB_414a_AC38_79BF7453F656__INCLUDED_)
#define EA_644CC2CD_A2DB_414a_AC38_79BF7453F656__INCLUDED_

#include "CmcSolves.h"

class CmcSolvesNormal : public CmcSolves
{

public:
	/**
	 * CmcSolvesNormal
	 */
	void Run();
	void SaveNorml();

protected:
	void doCalStation() override;

};
#endif // !defined(EA_644CC2CD_A2DB_414a_AC38_79BF7453F656__INCLUDED_)
