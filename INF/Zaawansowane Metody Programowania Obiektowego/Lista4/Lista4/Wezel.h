#ifndef WEZEL_H
#define WEZEL_H

#include <cstdlib>
#include <iostream> 

using namespace std;

template <typename T>
class CWezel {
	T* pt_dane;
	CWezel<T>* pw_poprzedni;
	CWezel<T>* pw_nastepny;
public:
	CWezel<T>() { pt_dane = pw_poprzedni = pw_nastepny = NULL; }
	CWezel<T>(T* ptDane) { pt_dane = ptDane; pw_poprzedni = pw_nastepny = NULL; }
	CWezel<T>(CWezel<T>* pwWezel) { pt_dane = pwWezel->pt_dane; pw_poprzedni = pwWezel->pw_poprzedni; pw_nastepny = pwWezel->pw_nastepny; }
	~CWezel<T>() {}

	T* ptGetDane() { return pt_dane; }
	CWezel<T>* pwGetPoprzedni() { return pw_poprzedni; }
	CWezel<T>* pwGetNastepny() { return pw_nastepny; }
	void vSetPoprzedni(CWezel<T>* pwPoprzedni) { pw_poprzedni = pwPoprzedni; }
	void vSetNastepny(CWezel<T>* pwNastepny) { pw_nastepny = pwNastepny; }
	void vSetDane(T* ptDane) { pt_dane = ptDane; }
}

#endif