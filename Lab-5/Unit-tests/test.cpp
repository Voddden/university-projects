#include "pch.h"

// task-4
int F(int n) {
	if (n % 10 > 0) {
		return n % 10;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		return F(n / 10);
	}
}

int S(int p, int q) {
	long long result = 0;
	for (int i = p; i <= q; ++i) {
		result += F(i);
	}
	return result;
}
//task-5

long long recurse(long long x, long long y, long long n) {
	if (y == 0)
		return 1;
	if (y % 2 == 1)
		return x * recurse(x * x % n, y / 2, n) % n;
	return recurse(x * x % n, y / 2, n);
}

long long recursResult(long long k, long long n, long long t) {
	long long m = pow(10, t), l = k % m;
	return recurse(l, n, m);
}

//task-6
long long f(long long n) {
	if (n % 2 == 1) {
		return n;
	}
	if (n % 2 == 0) {
		long long ntemp = n;
		while (ntemp > 0 && ntemp % 2 == 0) {
			ntemp = ntemp / 2;
		}
		return ntemp;
	}
}

long long sum(long long n) {
	long long s = 0;
	for (int i = 1; i <= n; ++i) {
		s += f(i);
	}
	return s;
}

// tests
TEST(task4_1, Lab5) {
  EXPECT_EQ(46, S(1,10));
  EXPECT_TRUE(true);
}

TEST(task4_2, Lab5) {
	EXPECT_EQ(48, S(10, 20));
	EXPECT_TRUE(true);
}

TEST(task4_3, Lab5) {
	EXPECT_EQ(52, S(30, 40));
	EXPECT_TRUE(true);
}

TEST(task5_1, Lab5) {
	EXPECT_EQ(736, recursResult(1234, 1234, 4));
	EXPECT_TRUE(true);
}

TEST(task5_2, Lab5) {
	EXPECT_EQ(39087387, recursResult(2323, 99999999999, 8));
	EXPECT_TRUE(true);
}

TEST(task5_3, Lab5) {
	EXPECT_EQ(494777344, recursResult(4, 99999, 9));
	EXPECT_TRUE(true);
}

TEST(task5_4, Lab5) {
	EXPECT_EQ(91255296, recursResult(888, 888, 8));
	EXPECT_TRUE(true);
}

TEST(task6_1, Lab5) {
	EXPECT_EQ(21, sum(7));
	EXPECT_TRUE(true);
}

TEST(task6_2, Lab5) {
	EXPECT_EQ(1, sum(1));
	EXPECT_TRUE(true);
}

TEST(task6_3, Lab5) {
	EXPECT_EQ(201537, sum(777));
	EXPECT_TRUE(true);
}