#include "ricSolver.h"

double ricSolver::GetDifFree(int in1, int in2)
{
	if ((in1<0) || (in1>vSize - 1) || (in2 < 0) || (in2>vSize-1))
	{
		return 0;
	}
	return vMassive[in1].GetX() - vMassive[in2].GetX();
};
double ricSolver::GetDifChaind(int in1, int in2)
{
	in1 += vSize;
	in2 += vSize;
	in1 = in1 % vSize;
	in2 = in1 % vSize;
	return vMassive[in1].GetX() - vMassive[in2].GetX();
}
double ricSolver::GetDifFreeKoord(int in)
{
	if ((in1<0) || (in1>vSize - 1) || (in2 < 0) || (in2>vSize - 1))
	{
		return 0;
	}
	return vMassive[in1].GetX() - vMassive[in2].GetX();
};

double ricSolver::GetXdotF(int ind)
{
	double forc=0;
	forc += GetDifFree(ind, ind - 1);
	forc += GetDifFree(ind, ind + 1);
	return vMassive[ind].GetXdot(forc);
}
double ricSolver::GetYdotF(int ind)
{
	return vMassive[ind].GetYdot();
}
void ricSolver::vKoordIn()
{
	vKoord = new double[vSize * 2];
	vResult = new double[vSize * 2];
	vRicK1 = new double[vSize * 2];
	vRicK2 = new double[vSize * 2];
	vRicK3 = new double[vSize * 2];
	vRicK4 = new double[vSize * 2];
}
void ricSolver::vKoordFill(double *vPrevK)
{
	for (int i = 0; i < vSize; i++)
	{
		vResult[2*i] = vMassive[2*i].fGetXdot(vKoord[2*i],vKoord[2*i+1],);
		vKoord[i + 1] = vMassive[i].fGetYdot();
	}
}