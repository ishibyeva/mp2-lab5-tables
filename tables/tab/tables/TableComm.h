#pragma once
#include "Order.h"
#include "Dorder.h"
#include "Hash.h"

class TableComm
{
	Order or;
	Dorder dor;
	Hash hash;

public:
	TableComm();
	void Insert(cell&);
	void Delete(string);
	Poly* Search(string);
	void RetCounter();
	void CleanCounter();
	~TableComm();
};

