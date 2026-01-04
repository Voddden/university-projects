#define _CRT_SECURE_NO_WARNINGS
#include "lib-header.h"
#include<stdio.h>

//#ifdef KOSTIL
/*
_Bool put_i(long long* y)
{
    _Bool f=0,ff=0;
    long long x=0;
    char a[2],b[2],d[2],c=0;
    a[0]=0;
    b[0]=0;
    c=0;
    d[0]=0;
    scanf("%1[-]", a);
    scanf("%1[\n]", b);
    if(*b=='\n')
    {
        if(*a=='-')
            printf("Incorrect input\n");
        else
            printf("Number is not entered\n");
        return 0;
    }
    ff=scanf("%1[0]", b);
    scanf("%*[0]");
    f=scanf("%1[\n]", d);
    if(ff && f)
    {
        *y=0;
        return 1;
    }
    f=scanf("%19lld", &x);
    scanf("%*[\040]");
    scanf("%c", &c);
    if(c=='\n' && x>0)
    {
        if(*a=='-')
            x=x*-1;
        *y=x;
        return 1;
    }
    scanf("%*[0-9]");
    scanf("%*[\040]");
    scanf("%1[\n]", d);
    rewind(stdin);
    if(c<'0' || c>'9' || *d!='\n')
    {
        printf("Incorrect input\n");
        return 0;
    }
    printf("Number must be lower than 9223372036854775808 and bigger than -9223372036854775808\n");
    return 0;
}
*/
//#endif

//#ifndef KOSTIL
_Bool put_i(long long* x)
{
    _Bool f = 0, ff = 0, _f = 0, f0 = 0;
    int i = -1;
    long long y = 0;
    char s[20];
    scanf("%c", s);
    if (s[0] == '\n')
    {
        printf("Please, enter something\n");
        return 0;
    }
    if (s[0] == ' ')
    {
        rewind(stdin);
        printf("Please don't enter space as a first symbol\n");
        return 0;
    }
    if (s[0] == '-' || s[0] == '+')
    {
        f = s[0] == '-';
        scanf("%1[0]", s);
        if (scanf_s("%1[\n]", s + 1))
        {
            printf("Incorrect input\n");
            return 0;
        }
    }
    else
        if (s[0] < '0' || s[0]>'9')
        {
            rewind(stdin);
            printf("Incorrect input\n");
            return 0;
        }
        else
            i = 0;
    if (s[0] == '0')
    {
        i = -1;
        scanf("%*[0]");
    }
    while (i < 19)
    {
        i++;
        scanf("%c", s + i);
        if (s[i] < '0' || s[i]>'9')
        {
            if (s[i] == '\n' || s[i] == ' ')
                break;
            rewind(stdin);
            printf("Incorrect input\n");
            return 0;
        }
    }
    for (int ii = 0; ii < i; ii++)
        y = y * 10 - '0' + s[ii];
    if (s[i] >= '0' && s[i] <= '9')
    {
        ff = 1;
        scanf("%*[0-9]");
        scanf("%c", s + i);
    }
    if (s[i] == ' ')
    {
        scanf("%*[\040]");
        scanf("%c", s + i);
    }
    if (s[i] == '\n')
        if (y >= 0 && !ff)
        {
            if (f)
                y *= -1;
            *x = y;
            return 1;
        }
        else
        {
            printf("Number must be lower than 9223372036854775808 and bigger than -9223372036854775808\n");
            return 0;
        }
    rewind(stdin);
    printf("Incorrect input\n");
    return 0;
}
//#endif
_Bool put_f(double* y)
{
    double x, mi = -1e310, ma = 1e310;
    int n = 0;
    char s[2], a = 0;
    s[0] = 0;
    scanf("%1[\n]", s);
    if (s[0] == '\n')
    {
        printf("Number is not entered\n");
        return 0;
    }
    n = scanf("%lf", &x);
    scanf("%*[\040]");
    scanf("%c", &a);
    rewind(stdin);
    if (n == 0 || a != '\n')
    {
        printf("Incorrect input\n");
        return 0;
    }
    if (x == ma)
    {
        printf("Number is too big\n");
        return 0;
    }
    if (x == mi)
    {
        printf("Number is too small\n");
        return 0;
    }
    *y = x;
    return 1;
}
_Bool putI(long long* x, long long l, long long r)
{
    _Bool f;
    if (!put_i(x))
        return 0;
    if (*x >= l && *x <= r)
        return 1;
    printf("You are out of range. Number must be bigger than %lli and lower than %lli\n", l - 1, r + 1);
    return 0;
}
_Bool putF(double* x, double l, double r)
{
    _Bool f;
    if (!put_f(x))
        return 0;
    if (*x >= l && *x <= r)
        return 1;
    printf("You are out of range. Number must be bigger than %lf and lower than %lf\n", l, r);
    return 0;
}
double binPow(double q, long long n)
{
    if (n == 1)
        return q;
    if (n % 2)
        return binPow(q, n - 1) * q;
    double buf = binPow(q, n / 2);
    return buf * buf;
}
void merge(void* arr, void* arrA, void* arrB, int aSize, int bSize, size_t unitSize, _Bool (*comp123)(void*, void*))
{
    int itA, itB, itArr;
    itArr = 0;
    itA = 0;
    itB = 0;
    while (itA < aSize && itB < bSize)
    {
        if (comp123(arrA, arrB))
        {
            itA++;
            memcpy(arr, arrA, unitSize);
            arrA = ((char*)arrA) + unitSize;
        }
        else
        {
            itB++;
            memcpy(arr, arrB, unitSize);
            arrB = ((char*)arrB) + unitSize;
        }
        itArr++;
        arr = ((char*)arr) + unitSize;
    }
    if (itA < aSize)
        memcpy(arr, arrA, (aSize - itA) * unitSize);
    if (itB < bSize)
        memcpy(arr, arrB, (bSize - itB) * unitSize);
}
void realMergeSort(void* mainArr, void* arr, int left, int right, size_t unitSize, _Bool (*comp123)(void*, void*)) //left -> leftBound right -> rightBound
{
    if (right - left == 0)
    {
        memcpy(arr, (char*)mainArr + left * unitSize, unitSize);
        return;
    }
    int mid = (left + right) / 2; //mid -> middlePoint
    void* arrA = malloc((mid - left + 1) * unitSize);
    void* arrB = malloc((right - mid) * unitSize);
    realMergeSort(mainArr, arrA, left, mid, unitSize, comp123);
    realMergeSort(mainArr, arrB, mid + 1, right, unitSize, comp123);
    merge(arr, arrA, arrB, mid - left + 1, right - mid, unitSize, comp123);
    return;
}
void mergeSort(void* arr, size_t unitSize, int size, _Bool (*comp123)(void*, void*))
{
    realMergeSort(arr, arr, 0, size - 1, unitSize, comp123);
}
/*
double sqrt(double x)
{
    double sum=1;
    long long i,f=1,f2=1,some=1,st4=1;
    x--;
    for(i=1;i<10;i++)
    {
        f2*=i*2*(2*i-1);
        f*=i;
        st4*=4;
        some-=2;
        if(i%2)
            sum-=(f2*x)/(some*f*f*st4);
        else
            sum+=(f2*x)/(some*f*f*st4);
        x*=x;
    }
    return sum;
}
*/
//#define KOSTIL
