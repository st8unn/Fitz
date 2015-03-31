#ifndef __cCell_H
#define __cCell_H
#include<conio.h>
#include <iostream>
using namespace std;
//const int NAMESIZE = 15;

class cCell{
	//� ����, ����� ���� ������������ �������, ����� ��� ����� ����������
	bool vActivated=false;
	double koefW;
	//�������
	double koefE;
	//�������� �����
	double koefA;

public:
	//���������
	double x=0;
	double y=0;
	//����������� �����
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
	//����� ��� �������� �����, ���� ��� ��� �� ���� �������
public: void vActivate(double A, double E, double D);
	//����� ������� �����
public: double GetW();
	//���������� ������� ����� 
public: void PutW(double W);
	//����������� ����������� �� x
public:	double GetXdot(double forc);
	//����������� ����������� �� y
public:	double GetYdot();
	//����������� �������� �.
public:	double GetX();
	//����������� �������� Y.
public:	double GetY();
	//������� �� X.
public:	double PutX(double inc);
	//������� �� Y.
public:	double PutY(double inc);
	//����������� ����������� �� x
public:	double fGetXdot(double x,double y, double forc);
	//����������� ����������� �� y
public:	double fGetYdot(double x);

};
#endif;