#ifndef __ricSolver_H
#define __ricSolver_H
#include"cCell.h"
#include<conio.h>
#include <iostream>
using namespace std;
//const int NAMESIZE = 15;

class ricSolver{	
	int vSize;
	double RKhstep;
	//те, что нам даны
	double *vKoord;
	//если надо, лучше € потом всЄ переименую. √лавное, чтобы работало хот€ бы сейчас.
	double *vResult;
	double *vRicK1;
	double *vRicK2;
	double *vRicK3;
	double *vRicK4;
public:
	//состо€ние
	cCell *vMassive;
	
public:	ricSolver(int size)
	{
		vSize = size;
		vMassive = new cCell[vSize];
	};
public:	~ricSolver()
	{
		if (vMassive)
			delete[] vMassive;
		if (vKoord)
			delete[] vKoord;
	}
	
private:
	//вы€снение разности между двум€ звень€ми по индексу звеньев. —вободное
	double GetDifFree(int in1, int in2);
private:
	//вы€снение разности между двум€ звень€ми по индексу звеньев.  ольцо
	double GetDifChaind(int in1, int in2);

	double GetDifFreeKoord(int in);
private:
	//берЄм производную x дл€ звена
	double GetXdotF(int);
	//берЄм производную y дл€ звена
	double GetYdotF(int);
public:
	//выделение места под все x,y
	void vKoordIn();
	//запись в vKordIn всех F
	void vKoordFill(double*);
};
#endif;