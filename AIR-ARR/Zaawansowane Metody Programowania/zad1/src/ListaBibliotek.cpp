/*
$HeadURL: svn+ssh://dperdek@panamint.ict.pwr.wroc.pl/home/dperdek/repos/z1/trunk/src/ListaBibliotek.cpp $
$Author: dperdek $
$Date: 2015-11-17 02:39:31 +0100 (wto) $
$Revision: 9 $
*/

#include "ListaBibliotek.hh"

using namespace std;

/*!
 * \file
 * \brief Plik zawierający implementację metod klasy ObslugaBibliotek.
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


