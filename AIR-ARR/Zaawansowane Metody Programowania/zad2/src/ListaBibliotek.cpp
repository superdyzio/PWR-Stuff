/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z2/trunk/src/ListaBibliotek.cpp $
$Author: dperdek $
$Date: 2015-12-05 02:18:25 +0100 (sob) $
$Revision: 3 $
*/

#include "ListaBibliotek.hh"

using namespace std;

/*!
 * \file
 * \brief Plik zawierający implementację metod klasy ListaBibliotek.
*/

ListaBibliotek::~ListaBibliotek() {
	for (auto& lib : (*this))
		delete lib.second;
}

bool ListaBibliotek::dodaj(const char* nazwaBiblioteki) {
	Biblioteka *nowaBiblioteka = new Biblioteka();
	if(!nowaBiblioteka->wczytaj(nazwaBiblioteki))
		return false; 
	this->insert(pair<string,Biblioteka*>(nowaBiblioteka->GetCmdName(),nowaBiblioteka));
	return true;
}

bool ListaBibliotek::usun(const char* nazwaBiblioteki) {
	auto iter = map<string,Biblioteka*>::find(nazwaBiblioteki);
	if (iter == end()) 
		return false;
	delete iter->second;
	this->erase(iter);
	return true;
}


