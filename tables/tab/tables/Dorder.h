#pragma once
#include "Tabl.h"

class Dorder: public Table 
{
	vector<cell> tbl1;
public:
	Dorder();
	~Dorder() {};
	void Insert(cell);
	void Delete(string);
	Poly* Search(string&);
};

