#include <iostream>
#define MAX_TERMS 100

using namespace std;

typedef struct
{
    float coef;
    int expon;
} Polynomial;

Polynomial terms[MAX_TERMS];

int avail = 0;

void attach(float coefficient, int exponent)
{
    if (avail >= MAX_TERMS)
    {
        cout << "too many elements" << endl;
    }
    else
    {
        terms[avail].coef = coefficient;
        terms[avail].expon = exponent;
        avail++;
    }
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{
    float coefficient;
    *startd = avail;

    while (starta <= finisha && startb <= finishb)
    {
        if (terms[starta].expon < terms[startb].expon)
        {
            attach(terms[startb].coef, terms[startb].expon);
            startb++;
        }
        else if (terms[starta].expon == terms[startb].expon)
        {
            coefficient = terms[starta].coef + terms[startb].coef;
            if (coefficient)
            {
                attach(coefficient, terms[starta].expon);
                starta++;
                startb++;
            }
        }
        else
        {
            attach(terms[starta].coef, terms[starta].expon);
            starta++;
        }
    }

    for (; starta <= finisha; starta++)
    {
        attach(terms[starta].coef, terms[starta].expon);
    }

    for (; startb <= finishb; startb++)
    {
        attach(terms[startb].coef, terms[startb].expon);
    }
    *finishd = avail - 1;
}

int main()
{
    int startd, finishd;
    terms[0].coef = 2;
    terms[0].expon = 1000;
    terms[1].coef = 1;
    terms[1].expon = 0;
    terms[2].coef = 1;
    terms[2].expon = 4;
    terms[3].coef = 10;
    terms[3].expon = 3;
    terms[4].coef = 3;
    terms[4].expon = 2;
    terms[5].coef = 1;
    terms[5].expon = 0;
    avail = 6;

    padd(0, 1, 2, 5, &startd, &finishd);

    for (int i = startd; i <= finishd; i++)
    {
        cout << terms[i].coef << " + " << terms[i].expon << endl;
    }
    return 0;
}