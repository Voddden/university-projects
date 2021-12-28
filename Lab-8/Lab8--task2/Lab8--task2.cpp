//Лабораторная 8, задача 2 Выполнена: Воднев Д. И.

#include<iostream>
#include<string>
#include <list>
#include<cstdio>
#pragma warning(disable : 4996)

using namespace std;

struct Team
{
    string dolznost;
    string firstName;
    string lastName;
    int number;
    int age;
};


void Uiuiui(int n, Team mass[])
{
    int i, j, step, tmp, tr = 0;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i].age;
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step].age)
                    mass[j].age = mass[j - step].age;
                else
                    break;
            }
            mass[j].age = tmp;
        }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << mass[i].dolznost << " " << mass[i].lastName << mass[i].firstName << " " << mass[i].age << " let";
        for (int j = 0; j < n - 1; j++)
            cout << ", ";
        tr++;
    }
}
int main() {
    //int* Participant  = new int ();

    int numb, k;
    string s;
    cerr << "vvod chi vivod?(1, 2)"; cin >> k;
    if (k == 1) {
        freopen("output.txt", "w", stdout);
        freopen("output.txt", "w", stdin);
    }
    else if (k == 2) {
        freopen("output.txt", "r", stdout);
        freopen("output.txt", "r", stdin);
    }
    else {
        cout << "ti durak< cifru vvedi 1 chi 2, balbes... no uje pozdno, davai po novoi:(";
        return 0;
    }
    cout << "set numb of sotrudnikov: "; cin >> numb;
    getline(cin, s);
    Team* a;
    a = new Team[numb];
    for (int i = 0; i < numb; i++) {
        cerr << "\nset dolznost of " << i + 1 << " sotrudnika: ";
        while (std::cin.fail()) {
            std::cerr << "incorrect input data";
            return 0;
        }
        getline(cin, a[i].dolznost);
    }
    for (int i = 0; i < numb; i++) {
        cerr << "\nset firstName of " << i + 1 << " sotrudnika: ";
        while (std::cin.fail()) {
            std::cerr << "incorrect input data";
            return 0;
        }
        getline(cin, a[i].firstName);
    }
    for (int i = 0; i < numb; i++) {
        cerr << "\nset LastName of " << i + 1 << " sotrudnika: ";
        while (std::cin.fail()) {
            std::cerr << "incorrect input data";
            return 0;
        }
        getline(cin, a[i].lastName);
    }
    for (int i = 0; i < numb; i++) {
        cerr << "\nset data nachala raboti of " << i + 1 << " sotrudnika: ";
        while (std::cin.fail()) {
            std::cerr << "incorrect input data";
            return 0;
        }
        cin >> a[i].number;
    }
    cerr << "stop?(1(y),2(n))"; cin >> k;
    if (k == 1) {
        return 0;
    }
    for (int i = 0; i < numb; i++) {
        cerr << "\nset staj of " << i + 1 << " sotrudnika: ";
        while (std::cin.fail()) {
            std::cerr << "incorrect input data";
            return 0;
        }
        cin >> a[i].age;
    }
    Uiuiui(numb, a);
}