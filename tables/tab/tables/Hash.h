#pragma once
#include "Tabl.h"
#include <list>
#include <algorithm>


class Hash : public Table
{
	vector<list<cell>> tbl3;
public:
	Hash();
	~Hash() {};
	void Insert(cell);
	void Delete(string);
	Poly* Search(string&);
	int Hashing(string&);
};

