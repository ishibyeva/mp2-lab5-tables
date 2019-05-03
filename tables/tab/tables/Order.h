#ifndef _Or_
#define _Or_
#include "Tabl.h"
class Order : public Table
{
	vector<cell> tbl2;

public:
	Order();
	~Order() {};
	void Insert(cell);
	void Delete(string);
	Poly* Search(string&);
	int Position(string);

};
#endif
