#include "cCell.h"

TVTable::TVTable(){
	vTSize = MaxTVsize;
	pHead = new TCell[vTSize];
	vTCount = 0;
};

TVTable* TVTable::GetCopy(){
	TCell* temp = new TCell[vTSize];
	for (int i = 0; i<vTCount; i++)
		temp[i] = pHead[i];
	return (TVTable*)temp;
};//создание копии от TDatvalue

TVTable::~TVTable(){
	delete pHead;
	pHead = 0;
};

int TVTable::mSearch(string targ){
	int result = vTCount;
	//char* temp;
	TCell temp(targ);
	for (int i = 0; i<vTCount; i++){
		//temp=pHead[i].vName;
		vEff.mTry();
		if (temp == pHead[i])
			result = i;
	}
	vEff.mFound();
	return result;
};

//сдвиг
void TVTable::mPushUp(int vIndex){
	for (int i = vIndex; i<vTCount - 1; i++)
		pHead[i] = pHead[i + 1];
};
//удалить-добавить, проверить.
int TVTable::mPut(string Name){
	TCell temp(Name);//ленивый
	int Result = mSearch(Name);
	//найдено
	if (Result<vTCount){
		pHead[Result].Incr();//просто повысили количество
	}
	//если нет такого
	if (Result == vTCount){
		if (!IsFull())
		{
			pHead[vTCount] = temp;
			vTCount++;
			Result = vTCount;
		}
	}
	//в плохом случае у нас будет -1, в случае если не найдено и vTCount кол-во звеньев = размеру, тогда мы -1 так и оставляем
	return Result++;//будет 0, если мы не вставляли. И индекс+1, куда вставили.
};

int TVTable::mDelete(string Name){
	int Result = mSearch(Name);
	if (Result<vTCount){//когда найдено-индекс в резалте
		mPushUp(Result);
		vTCount--;
	}
	return Result++;//0 выдаст, если не найдена
};

int TVTable::IsFull(){
	return vTCount == MaxTVsize;
};

int TVTable::IsEmpty(){
	return vTCount == 0;
};

void TVTable::mPrint(){
	for (int i = 0; i<vTCount; i++){
		cout << i + 1 << ". " << pHead[i].vName << ", " << pHead[i].vCount << endl;
	}
};

int TVTable::mIsHere(string Name){
	TCell temp(Name);
	int index = mSearch(Name), result = 0;
	if (index>-1)
		if (pHead[index] == temp)
			result = pHead[index].vCount;
	return result;
};