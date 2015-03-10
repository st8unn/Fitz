#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#include<fstream>
const string FileDes = "lab2.txt";
const int LineLenght = 80;
#include"cCell.h"
#include<fstream>
#include<string>

//он игнорирует исключение "!
/*//здесь должна быть READ
string Read(string FileName){
char Out[LineLenght];
Out[0]='\0';
fstream TxtFile(FileName);
if(TxtFile.eof()==0){
//,vLetter;
//for(int i=0;i<LineLenght;i++){
//TxtFile.getline(Out,LineLenght,' ');
TxtFile.getline(Out,LineLenght);
//Res=1;
//ну допустим, оно только пробелами
}
return Out;
//	return Res;
}*/

int Ot_l1_5(){//выбор int
	int temp;
	temp = getch() - 48;
	//cin>>temp; 
	fflush(stdin);
	return temp;
}

string Ot_l1_6(){//выбор int
	string temp;
	cin >> temp;
	fflush(stdin);
	return temp;
}

int PrintMenu(){
	cout << "0 exit" << endl
		<< "1 Viewed Table " << endl
		<< "2 Ordered Table" << endl
		<< "3 Hash Table" << endl
		<< "4 Efficiency" << endl
		; int temp = Ot_l1_5();
	system("cls");
	return temp;
}


int PrintMenuTables(){
	cout << "0 exit" << endl
		<< "1 Open File" << endl
		<< "2 Print table" << endl
		<< "3 Search" << endl
		<< "4 Efficiency" << endl
		<< "5 Add" << endl
		<< "6 Remove" << endl
		<< "7 Full/Empty" << endl
		; int temp = Ot_l1_5();
	system("cls");
	return temp;
}

double mTVTable(string Des){
	TVTable Table;
	int exit1 = 1;
	//к ней второе меню.
	do {
		switch (PrintMenuTables())
		{
		case 0:{
			exit1 = 0;
			break; }
		case 1:{
			char temp;
			char Word[NAMESIZE];
			int exit = 1, i = 0;
			fstream TxtFile(Des);
			do {
				temp = TxtFile.get();
				if (temp == EOF){
					i = -1;
					if (!strlen(Word)){
						string str(Word);
						Table.mPut(str);
					}
					exit = 0;
				}
				else
					if ((temp != ' ') && (temp != ',') && (temp != '.') && (temp != '\n') && (temp != '"')){
					Word[i] = temp;
					Word[i + 1] = '\0';
					}
					else{
						i = -1;
						string str(Word);
						Table.mPut(str);
					}
					i++;
			} while (exit);
			break;
		}
			//print
		case 2:{
			Table.mPrint();
			break;
		}
			//Search
		case 3:{
			int result = Table.mIsHere(Ot_l1_6());
			if (result)
				cout << "There are " << result << "of them" << endl;
			else
				cout << "There isn't any" << endl;
			break;
		}
			//Eff
		case 4:{
			cout << "Efficiency is " << Table.vEff.mEff() << endl;
			/*cout<<"Good "<<Table.vEff.vGood<<endl;
			cout<<"Tries"<<Table.vEff.vTries<<endl;
			int i=(100* Table.vEff.vGood)/Table.vEff.vTries;
			cout<<"Efficiency is "<<i<<"%"<<endl;*/
			break;
		}
			//Add
		case 5:{
			if (Table.mPut(Ot_l1_6()))
				cout << "Inserted" << endl;
			else
				cout << "Not Found" << endl;
			break;
		}
			//Remove
		case 6:{
			if (Table.mDelete(Ot_l1_6()))
				cout << "Deleted" << endl;
			else
				cout << "Not Found" << endl;
			break;
		}
			//Full/Empty
		case 7:{
			if (Table.IsEmpty())
				cout << "Empty and ";
			else
				cout << "Not empty and ";
			if (Table.IsFull())
				cout << "Full" << endl;
			else
				cout << "Not Full" << endl;
			break;
		}
		default:
			cout << "Choose wisely!" << endl;
			break;
		}
	} while (exit1);
	return Table.vEff.mEff();
}

double mTOrTable(string Des){
	TOrTable Table;
	int exit1 = 1;
	//к ней второе меню.
	do {
		switch (PrintMenuTables())
		{
		case 0:{
			exit1 = 0;
			break;
		}
			//open
		case 1:{
			/*
			string temp;
			int exit=1;
			do{
			temp=Read(Des);
			if(temp.c_str()[0]=='\0')
			exit=0;
			else
			Table.mPut(temp);
			} while (exit);
			break;
			}*/
			char temp;
			char Word[NAMESIZE];
			int exit = 1, i = 0;
			fstream TxtFile(Des);
			do {
				temp = TxtFile.get();
				if (temp == EOF){
					i = -1;
					if (!strlen(Word)){
						string str(Word);
						Table.mPut(str);
					}
					exit = 0;
				}
				else
					if ((temp != ' ') && (temp != ',') && (temp != '.') && (temp != '\n') && (temp != '"')){
					Word[i] = temp;
					Word[i + 1] = '\0';
					}
					else{
						i = -1;
						string str(Word);
						Table.mPut(str);
					}
					i++;
			} while (exit);
			break;
		}
			//print
		case 2:{
			Table.mPrint();
			break;
		}
			//Search
		case 3:{
			int result = Table.mIsHere(Ot_l1_6());
			if (result)
				cout << "There are " << result << " of them" << endl;
			else
				cout << "There isn't any" << endl;
			break;
		}
			//Eff
		case 4:{
			cout << "Efficiency is " << Table.vEff.mEff() << endl;
			break;
		}
			//Add
		case 5:{
			if (Table.mPut(Ot_l1_6()))
				cout << "Inserted" << endl;
			else
				cout << "Not Found" << endl;
			break;
		}
			//Remove
		case 6:{
			if (Table.mDelete(Ot_l1_6()))
				cout << "Deleted" << endl;
			else
				cout << "Not Found" << endl;
			break;
		}
			//Full/Empty
		case 7:{
			if (Table.IsEmpty())
				cout << "Empty and ";
			else
				cout << "Not empty and ";
			if (Table.IsFull())
				cout << "Full" << endl;
			else
				cout << "Not Full" << endl;
			break;
		}
		default:
			cout << "Choose wisely!" << endl;
			break;
		}
	} while (exit1);
	return Table.vEff.mEff();
}

double mThaTable(string Des){
	ThaTable Table;
	int exit1 = 1;
	//к ней второе меню.
	do {
		switch (PrintMenuTables())
		{
		case 0:{
			exit1 = 0;
			break;
		}
			//open
		case 1:{
			char temp;
			char Word[NAMESIZE];
			int exit = 1, i = 0;
			fstream TxtFile(Des);
			do {
				temp = TxtFile.get();
				if (temp == EOF){
					i = -1;
					if (!strlen(Word)){
						string str(Word);
						Table.mPut(str);
					}
					exit = 0;
				}
				else
					if ((temp != ' ') && (temp != ',') && (temp != '.') && (temp != '\n') && (temp != '"')){
					Word[i] = temp;
					Word[i + 1] = '\0';
					}
					else{
						i = -1;
						string str(Word);
						Table.mPut(str);
					}
					i++;
			} while (exit);
			break;
		}
			//print
		case 2:{
			Table.mPrint();
			break;
		}
			//Search
		case 3:{
			int result = Table.mIsHere(Ot_l1_6());
			if (result)
				cout << "There are " << result << "of them" << endl;
			else
				cout << "There isn't any" << endl;
			break;
		}
			//Eff
		case 4:{
			cout << "Efficiency is " << Table.vEff.mEff() << endl;
			break;
		}
			//Add
		case 5:{
			if (Table.mPut(Ot_l1_6()))
				cout << "Inserted" << endl;
			else
				cout << "Not Found" << endl;
			break;
		}
			//Remove
		case 6:{
			if (Table.mDelete(Ot_l1_6()))
				cout << "Deleted" << endl;
			else
				cout << "Not Found" << endl;
			break;
		}
			//Full/Empty
		case 7:{
			if (Table.IsEmpty())
				cout << "Empty and ";
			else
				cout << "Not empty and ";
			if (Table.IsFull())
				cout << "Full" << endl;
			else
				cout << "Not Full" << endl;
			break;
		}
		default:
			cout << "Choose wisely!" << endl;
			break;
		}
	} while (exit1);
	return Table.vEff.mEff();
}

int main(){
	//char fileName[20],ch;
	int result[3];
	result[0] = result[1] = result[2] = 0;
	do{
		switch (PrintMenu())
		{
		case 0:{
			cout << "G-Bye" << endl;
			exit(0); }
		case 1:{
			result[0] = mTVTable(FileDes);
			break; }
		case 2:{
			result[1] = mTOrTable(FileDes);
			break; }
		case 3:{
			result[2] = mThaTable(FileDes);
			break; }
		case 4:{
			cout << "Efficiency:" << endl
				<< "Viewed:  " << result[0] << endl
				<< "Ordered: " << result[1] << endl
				<< "Vw Hash: " << result[2] << endl;
			if ((result[0]) || (result[1]) || (result[2]))
				cout << "Tries per value: " << endl;
			if (result[0])
				cout << "Viewed:  " << 100 / result[0] << endl;
			if (result[1])
				cout << "Ordered: " << 100 / result[1] << endl;
			if (result[2])
				cout << "Vw Hash: " << double(100 / result[2]) << endl;
			break; }
		default:
			cout << "Choose wisely!" << endl;
			break;
		}
	} while (true);
}