//Ћабораторна€ 6, задача 7 ¬ыполнена: 

/*
¬ заданной строке S найти максимальную по длине подстроку, котора€
не €вл€етс€ палиндромом.
*/

using namespace std;
#include <iostream>
#include <string>

string input(int min, int max) {
	string text;
	while (true) {
		cin >> text;
		if (text.length() < max && text.length() > min)
			return text;
		cin.clear();
		cin.ignore(32676, '\n');
		text = "";
		cout << "Incorrect data has been entered, please try again:" << endl;
	}
}

bool Pol(const string& word) {
	for (int i = 0; i < word.length() / 2; i++) {
		if (word[i] != word[word.length() - i - 1])
			return false;
	}
	return true;
}

int PolLine(const string& word) {
	int PolLine = 0;
	string nonePolindromLine;
	for (int i = 0; i < word.length(); i++) {
		nonePolindromLine += word[i];
		if (!Pol(nonePolindromLine) || i == 0)
			PolLine++;
		else
			break;
	}
	if (PolLine == 1)
		return -1;
	else
		return PolLine;
}

int main() {
	cout << "Enter the string:\n";
	cout << PolLine(input(0, 106));
	return 0;
}