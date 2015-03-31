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
	//��, ��� ��� ����
	double *vKoord;
	//���� ����, ����� � ����� �� ����������. �������, ����� �������� ���� �� ������.
	double *vResult;
	double *vRicK1;
	double *vRicK2;
	double *vRicK3;
	double *vRicK4;
public:
	//���������
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
	//��������� �������� ����� ����� �������� �� ������� �������. ���������
	double GetDifFree(int in1, int in2);
private:
	//��������� �������� ����� ����� �������� �� ������� �������. ������
	double GetDifChaind(int in1, int in2);

	double GetDifFreeKoord(int in);
private:
	//���� ����������� x ��� �����
	double GetXdotF(int);
	//���� ����������� y ��� �����
	double GetYdotF(int);
public:
	//��������� ����� ��� ��� x,y
	void vKoordIn();
	//������ � vKordIn ���� F
	void vKoordFill(double*);
};
#endif;