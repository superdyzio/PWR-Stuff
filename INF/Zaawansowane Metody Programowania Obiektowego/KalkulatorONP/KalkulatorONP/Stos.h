#ifndef STOS_H
#define STOS_H

#include "DrzewoWyrazenia.h"

class CElement {
	CWezel c_element;
	CElement* pc_poprzedni;

public:
	CElement():c_element(),pc_poprzedni(NULL) {}
	CElement(CWezel cElement):c_element(cElement),pc_poprzedni(NULL) {}
	CElement(CWezel cElement, CElement* pcNastepny):c_element(cElement),pc_poprzedni(pcNastepny) {}
	~CElement() {}
} typedef CElement;

class CStos {
	CElement* pc_wierzcholek;

public:
	CStos():pc_wierzcholek(NULL) {}
	CStos(CElement* pcPodstawa):c_pwierzcholek(pcPodstawa) {}
	~CStos() {}

	void vPush(CElement** ppcElement);
	bool bPop();
	CElement cTop() { return 
} typedef CStos;

#endif