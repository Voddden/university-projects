#pragma once
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FILO {
	char* s;
	FILO* next;
};