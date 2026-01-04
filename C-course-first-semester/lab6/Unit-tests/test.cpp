#include "pch.h"
using namespace std;

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

// ---
int task5(double L, int m, string s, string s2) {
	int p;
	if (s2.length() == L || s.length() == L)return 0;
	p = L - s2.length() - s.length();
	if (p < 0) return 1;
	return fmod(pow(26, p) * 2, m);
}

TEST(TestTask5, Test1) {
	EXPECT_EQ(task5(14, 1000, "asa", "asasas"), 752);
	EXPECT_TRUE(true);
}
TEST(TestTask5, Test2) {
	EXPECT_EQ(task5(7, 123, "russian", "codecup"), 0);
	EXPECT_TRUE(true);
}

TEST(TestTask5, Test3) {
	EXPECT_EQ(task5(7, 15, "codec", "decup"), 1);
	EXPECT_TRUE(true);
}

// ---
int rec(string& st, int d, int& i) {
	if (st[i] != st[i + 1]) return 1;
	int b = 0;
	if (st[i] == st[i + 1]) b++;
	i++;
	return b + rec(st, d, i);
}

double fact(int a) {
	if (a == 1) return 1;
	return a * fact(a - 1);
}

int task6(string st) {
	int d, q1;
	double an;
	char min;

	d = st.length();
	//сортировка
	for (int i = 0; i < d; i++) {
		min = st[i];
		q1 = i;
		for (int q = i; q < d; q++)
			if (min > st[q]) {
				min = st[q];
				q1 = q;
			}
		swap(st[i], st[q1]);
	}

	an = fact(d);
	for (int i = 0; i < d; i++)
		an /= fact(rec(st, d, i));

	return an;
}

TEST(TestTask6, Test1) {
	EXPECT_EQ(task6("SOLO"), 12);
	EXPECT_TRUE(true);
}

TEST(TestTask6, Test2) {
	EXPECT_EQ(task6("asdf"), 24);
	EXPECT_TRUE(true);
}

TEST(TestTask6, Test3) {
	EXPECT_EQ(task6("reghfsdh"), 20160);
	EXPECT_TRUE(true);
}

// ---
int  task7(string st) {
	string buf, buf2, buf3;
	bool t = 0;
	int d, q, q1, r = 0, w = 0;

	while (st.find(' ') != -1) st.erase(st.find(' '), 1);

	buf3 = st;
	buf2 = st;
	d = st.length();
	for (q1 = 1; q1 < d; q1++) {
		for (q = 1; q < st.length(); q++) {
			buf = st;
			buf.erase(q + 1, st.length());
			w = 0;

			for (r = 1; r < buf.length(); r++)
				if (buf[r] == buf[buf.length() - 1 - r]) w++;

			if (w == buf.length() - 1) {
				st.erase(0, w / 2 + w % 2 - 1);
				buf2[w / 2 + w % 2 + q1 - 1] = ' ';
				break;
			}
		}
		st.erase(0, 1);
	}

	for (int f = 0; f < buf2.length(); f++)
		if (buf2[f] == buf2[f + 1]) {
			buf2.erase(f, 1);
			f = -1;
		}

	buf2 += ' ';
	if (buf2.length() == 3) {
		r = -1;
	}
	else
		for (;;) {
			d = buf2.find(' ');
			if (d == -1) break;
			if (d + 1 > r) r = d + 1;
			buf2.erase(0, d + 1);
		}
	if (r > buf3.length()) r = buf3.length();
	return r;
}

TEST(TestTask7, Test1) {
	EXPECT_EQ(task7("asa"), 2);
	EXPECT_TRUE(true);
}

TEST(TestTask7, Test2) {
	EXPECT_EQ(task7("asdfds"), 4);
	EXPECT_TRUE(true);
}

TEST(TestTask7, Test3) {
	EXPECT_EQ(task7("asdfghjkl"), 9);
	EXPECT_TRUE(true);
}

// ---
void search_r(string s, string t, int q, int r, int& y, int i) {
	if (q + 1 < s.length() && q >= 0 && !i && s[q + 1] == t[r]) {
		q++;
		r++;
		y++;
		return search_r(s, t, q, r, y, i);
	}
	else {
		if (q < s.length() && q - 1 >= 0 && s[q - 1] == t[r]) {
			q--;
			r++;
			y++;
			i++;
			return search_r(s, t, q, r, y, i);
		}
		else return;
	}
}
void search_l(string s, string t, int q, int r, int& y, int i) {
	if (q < s.length() && q - 1 >= 0 && s[q - 1] == t[r] && !i) {
		q--;
		r++;
		y++;
		return search_l(s, t, q, r, y, i);
	}
	else {
		if (q + 1 < s.length() && q >= 0 && s[q + 1] == t[r]) {
			q++;
			r++;
			y++;
			i++;
			return search_l(s, t, q, r, y, i);
		}
		else return;
	}
}

int task8(string s, string t) {
	int q, r = 0, y = 0, y1;

	y1 = 0;
	for (q = 0; q < s.length(); q++) {
		if (s[q] == t[r]) {
			r++;
			y = 1;
			search_r(s, t, q, r, y, 0);
			if (y > y1) y1 = y;
			r = 1;
			y = 1;
			search_r(s, t, q, r, y, 0);
			if (y > y1) y1 = y;
			r = 0;
		}
	}

	int ret;
	if (y1 == t.length())ret = 1;
	else ret = 0;
	return ret;
}

TEST(TestTask8, Test1) {
	EXPECT_EQ(task8("abcdef", "cdedcb"), 1);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test2) {
	EXPECT_EQ(task8("aaa", "aaaaa"), 1);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test3) {
	EXPECT_EQ(task8("aab", "baaa"), 0);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test4) {
	EXPECT_EQ(task8("ba", "baa"), 0);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test5) {
	EXPECT_EQ(task8("ab", "b"), 1);
	EXPECT_TRUE(true);
}

TEST(TestTask8, Test6) {
	EXPECT_EQ(task8("abcdef", "abcdef"), 1);
	EXPECT_TRUE(true);
}

// ---
int task9(string s) {
	int i, u, q, g, o = 1;
	double sum, t, sum1 = 0;

	//замена "лишнего" на пробел
	for (i = 0; i < s.length(); i++)
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-')
			s[i] = ' ';
	s += ' ';
	for (i = 0; i < s.length(); i++)
		if (s[i] == '-' && s[i + 1] == ' ')
			s[i] = ' ';
	for (i = 0; i < s.length(); i++)
		if (s[i] == '-' && s[i - 1] != ' ' && s[i + 1] != ' ')
			s.insert(i, " ");

	for (i = 0; i < s.length();) {
		while (s[i] == ' ' && i + 1 < s.length()) i++;
		if (i + 1 == s.length()) break;
		u = 1;
		g = i;
		while (s[i + 1] != ' ' && s[i + 1] != '-' && i + 1 < s.length()) {
			i++;
			u++;
		}
		i = g;
		t = 1;
		sum = 0;
		if (s[i] == '-') {
			i++;
			o = -1;
			u--;
		}
		for (q = u + i - 1; q >= i; q--) {
			sum += (s[q] - '0') * t;
			t *= 10;
			if (u > 250) {
				sum = 0;
				break;
			}
		}
		sum1 += sum * o;
		o = 1;
		i += u + 1;
	}
	return sum1;
}

TEST(TestTask9, Test1) {
	EXPECT_EQ(task9("6h54jg63hj6f63f3k6hj"), 201);
	EXPECT_TRUE(true);
}

TEST(TestTask9, Test2) {
	EXPECT_EQ(task9("1324-1234klgf4"), 94);
	EXPECT_TRUE(true);
}

TEST(TestTask9, Test3) {
	EXPECT_EQ(task9("ijhi435uh-234234dfd9732"), -224067);
	EXPECT_TRUE(true);
}
// ---