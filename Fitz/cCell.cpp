#include "cCell.h"

double cCell::GetW(){
	return koefW;
};

void cCell::PutW(double W){
	koefW = W;
};


double cCell::GetXdot(double forc){
	return x - (x *x * x) / 3 - y + koefD*forc;
}

double cCell::GetYdot(){
	return koefE*(x + koefA);
}
double cCell::GetX(){
	return x;
}
double cCell::GetY(){
	return y;
}
double cCell::PutX(double inc){
	return x = x + inc;
}
double cCell::PutY(double inc){
	return y = y + inc;
}
void cCell::vActivate(double A, double E, double D){
	if (vActivated)
		return;
	koefA = A;
	koefE = E;
	koefD = D;
	vActivated = true;
}

double cCell::fGetXdot(double x1, double y1, double forc)
{
	return x1 - (x1 * x1 * x1) / 3 - y1 + koefD*forc;
}

double cCell::fGetYdot(double x1)
{
	return koefE*(x1 + koefA);
}