#ifndef __cCell_H
#define __cCell_H
#include<conio.h>
#include <iostream>
using namespace std;
//const int NAMESIZE = 15;

class cCell{
	//я хочу, чтобы сюда записывалась частота, когда она будет вычисленна
	bool vActivated=false;
	double koefW;
	//эпсилон
	double koefE;
	//смещение точки
	double koefA;

public:
	//состояние
	double x=0;
	double y=0;
	//коэфиициент связи
	double koefD;
	double vState;
public:	cCell(){};
public:	cCell(double A, double E, double D)
	{
		koefA = A;
		koefE = E;
		koefD = D;
		vActivated = true;
	};
	//задаёт три значения звена, если оно уже не было активно
public: void vActivate(double A, double E, double D);
	//выдаёт частоту звена
public: double GetW();
	//возвращает частоту звена 
public: void PutW(double W);
	//возвращение производной по x
public:	double GetXdot(double forc);
	//возвращение производной по y
public:	double GetYdot();
	//возвращение значения Х.
public:	double GetX();
	//возвращение значения Y.
public:	double GetY();
	//прирост по X.
public:	double PutX(double inc);
	//прирост по Y.
public:	double PutY(double inc);
	//возвращение производной по x
public:	double fGetXdot(double x,double y, double forc);
	//возвращение производной по y
public:	double fGetYdot(double x);

};
#endif;