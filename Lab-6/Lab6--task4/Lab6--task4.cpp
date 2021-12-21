//Ћабораторна€ 6, задача 4 ¬ыполнена: ¬однев ƒ. ».

/*
1 апрел€ 20?? года будет проведена реформа английского €зыка,
позвол€юща€ облегчить его освоение иностранцами и английскими
школьниками. ¬о-первых,
- из алфавита уберут четыре буквы C, Q, W и X (на
клавиатуре компьютера вместо них будут клавиши, вызывающие программы
Word, eXcel и другие).
1) ¬место 'c' перед буквами 'e', 'i', 'y' нужно будет писать
букву 's' (sivil)
а в остальных случа€х Ц букву 'k' (klear)
2) ¬место буквы 'q' нужно будет писать букву 'k' (kuikk)
3) вместо сочетани€ 'qu' Ц 'kv' (kvikk)
4) вместо 'x' Ц 'ks'
5) вместо 'w' Ц 'v'
¬о-вторых,
6) сочетание букв 'ph' будет
записыватьс€ как 'f',
7) 'you' и 'oo' Ц как 'u'
8) 'ee' Ц как 'i',
9) 'th' Ц как 'z'.
 роме того,
10) все двойные согласные (включа€ образовавшиес€ после замен), вызывающие
большие трудности у учащихс€, станут одинарными,
например, apple после реформы нужно писать как aple.
¬ св€зи с реформой нужно переработать огромное количество текстов.
Ќапишите программу, выполн€ющую эту работу.
*/

using namespace std;
#include <iostream>
#include <string>

int main() {
/*
- Input:
Too swift for Theex, too quick for Gallow,
Too strong for young Prince Joseph to follow.
- Output:
Tu svift for Ziks, tu kvik for Galov,
Tu strong for ung Prinse Josef to folov.
*/
	cout << "Enter the string:\n";
	string s;
	getline(cin, s, '$');
	if (s.length() > 100) {
		cout << "The string cannot contain more than 100 characters\n";
		return 0;
	}
	//// -- 1)
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'c' && (s[i + 1] == 'e' || s[i + 1] == 'i' || s[i + 1] == 'y')) {
			s[i] = 's';
		}
		else if (s[i] == 'c') {
			s[i] = 'k';
		}
	}
	// 
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '—' && (s[i + 1] == 'E' || s[i + 1] == 'I' || s[i + 1] == 'Y')) {
			s[i] = 'S';
		}
		else if (s[i] == 'C') {
			s[i] = 'K';
		}
	}
	//// -- 3)
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'q' && s[i + 1] == 'u')
			s.replace(i, 2, "kv");
	}
	//
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'Q' && s[i + 1] == 'u')
			s.replace(i, 2, "Kv");
	}
	//// -- 2)
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'q')
			s[i] = 'k';
	}
	//
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'Q')
			s[i] = 'K';
	}
	//// -- 4)
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'x')
			s.replace(i, 1, "ks");
	}
	//
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'X')
			s.replace(i, 1, "Ks");
	}
	//// -- 5)
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'w')
			s[i] = 'v';
	}
	//
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'W')
			s[i] = 'V';
	}
	//// -- 6) ph -> f
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'p' && s[i + 1] == 'h')
			s.replace(i, 2, "f");
	}
	//
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'P' && s[i + 1] == 'h')
			s.replace(i, 2, "F");
	}
	//// -- 7) 'you' и 'oo' - как 'u'
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'y' && s[i + 1] == 'o' && s[i + 2] == 'u')
			s.replace(i, 3, "u");
	}
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'o' && s[i + 1] == 'o')
			s.replace(i, 2, "u");
	}
	//
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'Y' && s[i + 1] == 'o' && s[i + 2] == 'u')
			s.replace(i, 3, "U");
	}
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'O' && s[i + 1] == 'o')
			s.replace(i, 2, "U");
	}
	//// -- 8) 'ee' Ц как 'i'
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'e' && s[i + 1] == 'e')
			s.replace(i, 2, "i");
	}
	//
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'E' && s[i + 1] == 'e')
			s.replace(i, 2, "I");
	}
	////-- 9) 'th' Ц как 'z'
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 't' && s[i + 1] == 'h')
			s.replace(i, 2, "z");
	}
	//
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'T' && s[i + 1] == 'h')
			s.replace(i, 2, "Z");
	}
	////-- 10)
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == s[i + 1])
			s.erase(i + 1, 1);
	}
	////--
	cout << "Result:\n";
	cout << s << endl;
	return 0;
}