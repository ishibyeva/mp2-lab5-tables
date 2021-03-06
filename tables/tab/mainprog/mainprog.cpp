// mainprog.cpp : Defines the entry point for the console application.
//
#include "stdlib.h"
#include "stdafx.h"
#include "../tab/tables/TableComm.h"
#include "List.h"
Poly Random_Poly(int size);
Poly User_Poly(int size);


void main()
{

	int flag = 1, var, i=0;
	vector<Poly> poly_s(500);
	string user_str;
	TableComm EX;
	Poly rez;
	cout << "__________Welcom to programm!__________" << endl;
	while (flag)
	{
		cout << "Select a menu item:" << endl;
		cout << "1. Insert\n2. Search\n3. Delete\n4. Exit" << endl;
		cin >> var;
		switch (var)
		{
		case 1:
		{
			Poly A;
			cell _inp;
			int fl, size;
			cout << "Input name" << endl;
			cin >> user_str;
			_inp.name = user_str;
			cout << "Choose size of poly" << endl;
			cin >> size;
			cout << "1. Input my poly\n2. Input random poly" << endl;
			cin >> fl;
			if (fl == 1)
				 poly_s[i]= User_Poly(size);
			else poly_s[i] = Random_Poly(size);
			_inp.pol = &poly_s[i];
			i++;
			EX.Insert(_inp);
			EX.RetCounter();
			EX.CleanCounter();
			break;
		}
		case 2:
		{
			cout << "Input string" << endl;
			cin >> user_str;
			if (EX.Search(user_str) != NULL)
			{
				rez = *EX.Search(user_str);
				cout << rez << endl;
			}
			else
				cout << "Poly not in table" << endl;
			EX.RetCounter();
			EX.CleanCounter();
			break;
		}
		case 3:
		{
			cout << "Input string" << endl;
			cin >> user_str;
			EX.Delete(user_str);
			EX.RetCounter();
			EX.CleanCounter();
			break;
		}
		default:
		{
			flag = 0;
			break;
		}
		}
	}
	
	system("pause");
}

Poly User_Poly(int size)
{
	int rezd; double rezc;
	int* deg1 = new int[size];
	double* coef1 = new double[size];
	cout << "Enter coef for 1" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> rezc;
		coef1[i] = rezc;
	}
	cout << "Enter deg for 1" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> rezd;
		if (rezd < 100 || rezd>999)
		{
			cout << "Please, enter deg(x)deg(y)deg(z)";
			i--;
		}
		else
			deg1[i] = rezd;
	}
	Poly A(coef1, deg1, size);
	return A;
}

Poly Random_Poly(int size)
{
	int* deg1 = new int[size];
	double* coef1 = new double[size];
	for (int i = 0; i < size; i++)
	{
		coef1[i] = rand()%1000;
		deg1[i] = rand() % 899 + 100;
	}
	Poly rez(coef1, deg1, size);
	return rez;
}