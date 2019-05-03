#pragma once
#include "../../include/List.h"
#include "string"
#include "vector"
#include "iostream"

using namespace std;
struct cell
{
	string name;
	Poly* pol;
};

class Table
{
protected:
	int count;
public:
	Table() {}
	virtual ~Table() {}
	virtual void Insert(cell) = 0;
	virtual void Delete(string) = 0;
	virtual Poly* Search(string&) = 0;
	int GetCount() { return count; }
	void CleanCount() { count = 0;  }
};