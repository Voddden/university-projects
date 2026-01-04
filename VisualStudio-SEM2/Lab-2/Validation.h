#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

double inputReal(const char* prompt);
double inputRealPositive(const char* prompt);
int inputInteger(const char* prompt);
int inputNatural(const char* prompt);
double Pow(long num, long deg);