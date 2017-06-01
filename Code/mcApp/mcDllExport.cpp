
#define mcDLL_API __declspec(dllexport)

#include "CmcMain.h"



extern "C" mcDLL_API void DLLMain(char * vCalName)
{
	CmcMain::DLLMain(vCalName);
}


extern "C" mcDLL_API void mcResult(char * vdbfFile,struct_mcResultData * vData)
{
	//�޿���������

	CmcMain::mcInit(vdbfFile);

	CmcResult * vResult = new CmcResult();

	CmcMvcs::OnLoadResult(vdbfFile, vResult);


	//CmcMain::mcCalculate(vCalName);

}

extern "C" mcDLL_API void mcCalculate(char * vCalName)
{
	CmcMain::mcCalculate(vCalName);
}

extern "C" mcDLL_API void mcCalculateNormal()
{
	CmcMain::mcCalculateNormal();
}

extern "C" mcDLL_API void mcInit(char* vDBFFile)
{
	CmcMain::mcInit(vDBFFile);
}

extern "C" mcDLL_API void mcLoad()
{
	CmcMain::mcLoad();
}
extern "C" mcDLL_API void mcClose()
{
	CmcMain::mcClose();
}
