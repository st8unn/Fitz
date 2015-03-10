#ifndef __cCell_H
#define __cCell_H
#include<conio.h>
#include <iostream>
#include"TEff.h"
using namespace std;
const int NAMESIZE = 15;

class TCell{
public:
	char vName[NAMESIZE];
	int vCount;

	TCell(){};

	TCell(char *str){
		strncpy_s(vName, str, NAMESIZE);
		vName[NAMESIZE - 1] = '\0';
		vCount = 1;
	}

	TCell(string str){
		strncpy_s(vName, str.c_str(), NAMESIZE);
		vName[NAMESIZE - 1] = '\0';
		vCount = 1;
	}

	int Incr(){
		return vCount++;
	};

	//возвращает 1, если ДА
	int operator == (const TCell &temp){
		return !strcmp(temp.vName, vName);
	}

	TCell& operator = (const TCell &temp){
		if (this == &temp)
			return *this;
		strncpy_s(vName, temp.vName, NAMESIZE);
		vCount = temp.vCount;
		return *this;
	}

	//возвращает разницу
	int Compare(const TCell &value2){
		return strcmp(vName, value2.vName);
	}

};
#endif;