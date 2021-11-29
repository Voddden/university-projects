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