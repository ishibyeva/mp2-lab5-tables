#include "stdafx.h"
#include "Order.h"


Order::Order()
{
	count = 0;
	vector < cell > vv;
	tbl2 = vv;

}

void Order::Insert(cell a)
{
	int pp = Position(a.name);
	if (pp == -1)
	{	
		if (tbl2.empty())
		{
			count++;
			tbl2.push_back(a);
			return;
		}
		
			for (int i = 0; i < tbl2.size(); i++, count++)
			{
				if (a.name < tbl2[i].name)
				{
					tbl2.insert(tbl2.begin() + i, a);
					return;
				}
			}
			tbl2.push_back(a);
	}
	else 
	{
		if (a.name != tbl2[pp].name)
		{
			count++;
			tbl2.insert(tbl2.begin() + pp, a);
		}
		else 			
			cout << "Polynom in table now";
	}
	
}
Poly* Order::Search(string& a)
{
	int pp = Position(a);
	if (pp >= 0)
		return tbl2[pp].pol;
	else return NULL;
}

int Order::Position(string a)
{
	if (!tbl2.empty())
	{
		int mid = 0, st = 0, fn = tbl2.size() - 1;
		while (st <= fn)
		{
			count++;
			mid = (st + fn) / 2;
			if (a < tbl2[mid].name)
				fn = mid-1;
			else
				if (a > tbl2[mid].name)
					st = mid + 1;
				else
					return mid;
		}
		return -1;
	}
	else
	{
		count++;
		return -1;
	}
}
void Order::Delete(string a)
{
	int pp = Position(a);
	if (pp != -1)
	{
		if (tbl2[pp].name == a)
		{
			count++;
			tbl2.erase(tbl2.begin() + pp);
		}
	}
}
