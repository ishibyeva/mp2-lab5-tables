#include "../gtest/gtest.h"
#include "../tab/tables/Dorder.h"

TEST(Dorder, can_create)
{
	ASSERT_NO_THROW(Dorder A);
}
TEST(Dorder, can_insert)
{
	Poly A;
	Dorder AA;
	cell aaa;
	aaa.name = "P1";
	aaa.pol = &A;
	ASSERT_NO_THROW(AA.Insert(aaa));
}
TEST(Dorder, can_delete)
{
	Poly A,B,C;
	Dorder AA;
	cell aaa,bbb,ccc;
	aaa.name = "P1";
	bbb.name = "P2";
	ccc.name = "P3";
	aaa.pol = &A;
	bbb.pol = &B;
	ccc.pol = &C;
	ASSERT_NO_THROW(AA.Delete(aaa.name));
}
TEST(Dorder, can_get_counter_value)
{
	Poly A, B;
	Dorder AA;
	cell aaa, bbb;
	aaa.name = "P1";
	bbb.name = "P2";
	aaa.pol = &A;
	bbb.pol = &B;
	AA.Insert(aaa);
	AA.Insert(bbb);
	EXPECT_EQ(3,AA.GetCount());
}
TEST(Dorder, can_find_unknown_poly)
{
	Poly A,B;
	Dorder AA;
	cell aaa,bbb,ccc;
	aaa.name = "P1";	
	bbb.name = "P2";
	ccc.name = "Nnnn";
	aaa.pol = &A;
	bbb.pol = &B;
	AA.Insert(aaa);
	AA.Insert(bbb);
	int* deg1 = new int[3];
	double* coef1 = new double[3];
	for (int i = 0; i < 3; i++)
	{
		coef1[i] = i;
		deg1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly C(coef1, deg1, 3);
	ccc.pol = &C;
	EXPECT_EQ(NULL, AA.Search(ccc.name));

}
TEST(Dorder, can_find_poly)
{
	Dorder AA;
	cell aaa, bbb, ccc;
	aaa.name = "P1";
	bbb.name = "P2";
	ccc.name = "Nnnn";
	int* deg1 = new int[3];
	int* deg2 = new int[3];
	int* deg3 = new int[3];
	double* coef1 = new double[3];
	double* coef2 = new double[3];
	double* coef3 = new double[3];
	for (int i = 0; i < 3; i++)
	{
		coef1[i] = i;
		deg1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
		coef2[i] = i+1;
		deg2[i] = (i + 2) * 100 + (i + 1) * 10 + i + 1; 
		coef3[i] = i+2;
		deg3[i] = (i + 3) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(coef1, deg1, 3);
	Poly B(coef2, deg2, 3);
	Poly C(coef3, deg3, 3);
	aaa.pol = &A;
	bbb.pol = &B;
	ccc.pol = &C;
	AA.Insert(aaa);
	AA.Insert(bbb);
	AA.Insert(ccc);
	EXPECT_EQ(C, *AA.Search(ccc.name));

}
TEST(Dorder, can_find_deleted_poly)
{
	Dorder AA;
	cell aaa, bbb, ccc;
	aaa.name = "P1";
	bbb.name = "P2";
	ccc.name = "P3";
	Poly A, B, C;
	aaa.pol = &A;
	bbb.pol = &B;
	ccc.pol = &C;
	AA.Insert(bbb);
	AA.Insert(aaa);
	AA.Insert(ccc);
	AA.Delete(bbb.name);
	EXPECT_EQ(NULL, AA.Search(bbb.name));

}
