#include "stdafx.h"
#include "Dorder.h"


Dorder::Dorder()
{
	count = 0;
	
}


void Dorder::Insert(cell el)
{
	if (Search(el.name) != NULL)
	{
		cout <<"This poly in table now" << endl ;
		return;
	}
	tbl1.push_back(el);
	count++;
}

Poly* Dorder::Search(string& el)
{
	for (int i = 0; i < tbl1.size(); i++, count++)
	{
		if (el == tbl1[i].name)
			return tbl1[i].pol;
	}
	return NULL;
}

void Dorder::Delete(string el)
{
	for (int i = 0; i < tbl1.size(); i++, count++)
	{
		if (el == tbl1[i].name)
		{
			tbl1.erase(tbl1.begin() + i);
			return;
		}

	}
}