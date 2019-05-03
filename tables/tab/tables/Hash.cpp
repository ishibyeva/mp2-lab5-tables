#include "stdafx.h"
#include "Hash.h"


Hash::Hash()
{
	count =0;
	vector<list<cell>> tmp(256);
	tbl3 = tmp;
}




void Hash::Insert(cell a)
{
	int mp = Hashing(a.name);
	if (Search(a.name) != NULL)
	{
		cout << "This cell in the table now";
		return;
	}
	count++;
	tbl3[mp].push_back(a);

}
void Hash::Delete(string str)
{
	int mi = Hashing(str);
	for (auto it = tbl3[mi].begin(); it != tbl3[mi].end(); it++, count++)
	{
		if ((*it).name == str)
		{
			tbl3[mi].erase(it);
			return;
		}
	}
}
Poly* Hash::Search(string& str)
{
	int mi = Hashing(str);
	if (tbl3.empty())
	{
		count++;
		return NULL;
	}
	for (auto it = tbl3[mi].begin(); it != tbl3[mi].end(); it++, count++) 
	{
		if ((*it).name == str)
			return (*it).pol;
	}
	return NULL;
}
int Hash::Hashing(string& a)
{
	double rez, summ;
	double k = 0.6180339887499;
	rez = k*(double)(a[0] + a[a.size()-1]);
	return (int)rez%256;
}