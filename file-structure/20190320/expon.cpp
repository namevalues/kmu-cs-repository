#include <stdio.h>
#define MAX 10
typedef struct
{
    int degree;
    float coef[MAX];
} poly;

poly eqop(poly A, char op, poly B)
{
    poly C;
    int i;

    int idxA = 0, idxB = 0, idxC = 0, degA = A.degree, degB = B.degree;
    C.degree = (A.degree > B.degree) ? A.degree : B.degree;

    while (A.degree >= idxA && B.degree >= idxB)
    {
        if (degA == degB)
        {
            if (op == '+')
                C.coef[idxC++] = A.coef[idxA++] + B.coef[idxB++];
            else if (op == '-')
                C.coef[idxC++] = A.coef[idxA++] - B.coef[idxB++];
            degA--;
            degB--;
        }
        else if (degA > degB)
        {
            C.coef[idxC++] = A.coef[idxA++];
            degA--;
        }
        else
        {
            if (op == '+')
                C.coef[idxC++] = B.coef[idxB++];
            else if (op == '-')
                C.coef[idxC++] = B.coef[idxB++];
            degB--;
        }
    }
    return C;
}
void display(poly A)
{
    int i;
    for (i = 0; i < A.degree; i++)
    {
        printf("%.1f x^ %d ", A.coef[i], A.degree - i);
        if (A.coef[i + 1] >= 0)
            printf("+");
    }
    printf("%.1f ", A.coef[A.degree]);
}
int main()
{
    poly A = {3, {3, 0, 2, 4}};
    poly B = {3, {1, 3, 0, -3}};
    poly C;
    char op;
    scanf("%c", &op);
    C = eqop(A, op, B);
    printf("    ");
    display(A);
    printf("\n %c  ", op);
    display(B);
    printf("\n  = ");
    display(C);
    printf("\n");
}