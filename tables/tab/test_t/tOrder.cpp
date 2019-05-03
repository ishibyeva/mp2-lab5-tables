
#include "../gtest/gtest.h"
#include "../tab/tables/Order.h"

TEST(Order, can_create)
{
	ASSERT_NO_THROW(Order A);
}

TEST(Order, can_insert)
{
	Poly A;
	Order AA;
	cell aaa;
	aaa.name = "P1";
	aaa.pol = &A;
	ASSERT_NO_THROW(AA.Insert(aaa));
}
TEST(Order, can_delete)
{
	Order AA;
	cell aaa, bbb;
	aaa.name = "P1";
	bbb.name = "P2";
	int* deg1 = new int[3];
	int* deg2 = new int[3];
	double* coef1 = new double[3];
	double* coef2 = new double[3];
	for (int i = 0; i < 3; i++)
	{
		coef1[i] = i;
		deg1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
		coef2[i] = i + 1;
		deg2[i] = (i + 2) * 100 + (i + 1) * 10 + i + 1;
		
	}
	Poly A(coef1, deg1, 3);
	Poly B(coef2, deg2, 3);
	aaa.pol = &A;
	bbb.pol = &B;
	AA.Insert(aaa);
	AA.Insert(bbb);
	ASSERT_NO_THROW(AA.Delete(aaa.name));
}
TEST(Order, can_check_counter)
{
	Order AA;
	cell aaa, bbb, ccc;
	aaa.name = "P1";
	bbb.name = "P2";
	ccc.name = "P3";
	
	
	Poly A, B, C;
	
	aaa.pol = &A;
	bbb.pol = &B;
	ccc.pol = &C;
	AA.Insert(aaa);
	AA.Insert(bbb);
	AA.Insert(ccc);
	EXPECT_EQ(8, AA.GetCount());

}
TEST(Order, can_find_poly)
{
	Order AA;
	cell aaa, bbb, ccc;
	aaa.name = "P1";
	bbb.name = "P2";
	ccc.name = "P3";
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
		coef2[i] = i + 1;
		deg2[i] = (i + 2) * 100 + (i + 1) * 10 + i + 1;
		coef3[i] = i + 2;
		deg3[i] = (i + 3) * 100 + (i + 1) * 10 + i + 1;
	}
	Poly A(coef1, deg1, 3);
	Poly B(coef2, deg2, 3);
	Poly C(coef3, deg3, 3);
	aaa.pol = &A;
	bbb.pol = &B;
	ccc.pol = &C;
	AA.Insert(bbb);
	AA.Insert(aaa);
	AA.Insert(ccc);
	EXPECT_EQ(C, *AA.Search(ccc.name));

}
TEST(Order, can_find_unknown_poly)
{
	Order AA;
	cell aaa, bbb, ccc;
	aaa.name = "P1";
	bbb.name = "P2";
	ccc.name = "P3";
	int* deg1 = new int[3];
	int* deg2 = new int[3];
	double* coef1 = new double[3];
	double* coef2 = new double[3];
	for (int i = 0; i < 3; i++)
	{
		coef1[i] = i;
		deg1[i] = (i + 1) * 100 + (i + 1) * 10 + i + 1;
		coef2[i] = i + 1;
		deg2[i] = (i + 2) * 100 + (i + 1) * 10 + i + 1;
	
	}
	Poly A(coef1, deg1, 3);
	Poly B(coef2, deg2, 3),C;
	aaa.pol = &A;
	bbb.pol = &B;
	ccc.pol = &C;
	AA.Insert(bbb);
	AA.Insert(aaa);
	EXPECT_EQ(NULL, AA.Search(ccc.name));

}
TEST(Order, can_find_deleted_poly)
{
	Order AA;
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