#include "stdafx.h"
#include "TableComm.h"


TableComm::TableComm() : or (), dor(), hash() {}


TableComm::~TableComm()
{
}
void TableComm::Insert(cell& _cell)
{
	dor.Insert(_cell);
	or.Insert(_cell);
	hash.Insert(_cell);
	cout << "Insert cell " <<_cell.name<<" in 3 tables"<< endl;
}
void TableComm::Delete(string str)
{
	dor.Delete(str);
	or .Delete(str);
	hash.Delete(str);

	cout << "Delete cell " << str << " from 3 tables" << endl;

}
Poly* TableComm::Search(string str)
{
	Poly* rez;
	rez = dor.Search(str);
	or .Search(str);
	hash.Search(str);
	cout << "Search "<< str << endl;
	return rez;
}
void TableComm::RetCounter()
{
	cout << "________________________" << endl<<endl;
	cout<<  "| Disorder's count:    " << dor.GetCount()<<"|"<< endl;
	cout << "| Order's count:       " << or .GetCount() <<"|"<< endl;
	cout << "| Hash-tables's count: " << hash.GetCount() <<"|"<< endl;
	cout << "________________________" << endl;


}
void TableComm::CleanCounter()
{
	dor.CleanCount();
	or .CleanCount();
	hash.CleanCount();
}