/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/src/Biblioteka.cpp $
$Author: dperdek $
$Date: 2015-12-04 22:30:22 +0100 (pią) $
$Revision: 2 $
*/

#include <iostream>
#include <iomanip>
#include <dlfcn.h>
#include "Biblioteka.hh"
#include "command.hh"

using namespace std;

/*!
 * \file 
 * \brief Plik zawierający implementację metod klasy Biblioteka.
*/

bool Biblioteka::ReadParams(std::istream& Strm_CmdsList) {
	_pCmd->ReadParams(Strm_CmdsList); 
	return true;
}

void Biblioteka::PrintCmd() {
	_pCmd->PrintCmd();
}

void Biblioteka::PrintSyntax() {	
	_pCmd->PrintSyntax();
}

const char* Biblioteka::GetCmdName() const {
	return _pCmd->GetCmdName();
}

bool Biblioteka::wczytaj(const char* nazwaBiblioteki) {
	void *pLibHnd = dlopen(nazwaBiblioteki,RTLD_LAZY);
	void *pFun;
	if (!pLibHnd) {
		cerr << "Brak biblioteki: "<< nazwaBiblioteki << endl;
		return false;
	}
	pFun = dlsym(pLibHnd,"CreateCmd");
	if (!pFun) {
		cerr << "Wczytanie biblioteki nieudane." << endl;
		return false;
	}
	_pCreateCmd = *reinterpret_cast<Command* (**)(void)>(&pFun);  
	_pCmd = _pCreateCmd();
  	return true;
}

