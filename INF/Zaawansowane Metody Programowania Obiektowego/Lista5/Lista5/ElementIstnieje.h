#ifndef ELEMENTISTNIEJE_H
#define ELEMENTISTNIEJE_H

#include <exception>
using namespace std; 

class ElementIstnieje : public exception {
public:
	ElementIstnieje() {}
	~ElementIstnieje() {}
	virtual const char* what() const throw() { return "Blad! Bryla o podanym identyfikatorze juz istnieje"; }
};

#endif