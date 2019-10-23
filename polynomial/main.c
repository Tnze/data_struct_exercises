#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int coefficient;
    int index;
    struct Item *next;
};
typedef struct Item *Polynomial;

Polynomial NewPolynomial()
{
    Polynomial p = malloc(sizeof(Polynomial));
    p->coefficient = 0;
    p->index = 0;
    p->next = NULL;
    return p;
}

void Polynomial_insert(Polynomial p, int c, int i)
{
    // 找到相应指数的位置
    while (p->next != NULL && p->next->index <= i)
        p = p->next;

    if (p->index < i) // 该系数是否已存在
    {
        // 创建该项
        struct Item *item = malloc(sizeof(struct Item));
        item->coefficient = c;
        item->index = i;

        // 插入
        item->next = p->next;
        p->next = item;
    }
    else
    {
        // 系数相加
        p->coefficient += c;
    }
}

void Polynomial_input(Polynomial p)
{
    int c, i;
    while (scanf("+%dx^%d", &c, &i))
        Polynomial_insert(p, c, i);
    getchar(); //吸收分号
}

void Polynomial_output(Polynomial p)
{
    do
    {
        if (p->coefficient)
            printf(" +%dx^%d", p->coefficient, p->index);
        p = p->next;
    } while (p != NULL);
    printf("\n");
}

Polynomial Polynomial_merge(Polynomial p, Polynomial q)
{
    Polynomial R = NewPolynomial();
    while (p != NULL && q != NULL)
    {
        if (p->index > q->index)
        {
            Polynomial_insert(R, q->coefficient, q->index);
            q = q->next;
        }
        else if (p->index < q->index)
        {
            Polynomial_insert(R, p->coefficient, p->index);
            p = p->next;
        }
        else
        {
            Polynomial_insert(R, p->coefficient + q->coefficient, p->index);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        Polynomial_insert(R, p->coefficient, p->index);
        p = p->next;
    }
    while (q != NULL)
    {
        Polynomial_insert(R, q->coefficient, q->index);
        q = q->next;
    }
    return R;
}

int main()
{
    Polynomial P = NewPolynomial();
    Polynomial Q = NewPolynomial();
    printf("请输入多项式P：");
    Polynomial_input(P);
    printf("请输入多项式Q：");
    Polynomial_input(Q);

    Polynomial R = Polynomial_merge(P, Q);
    printf("P+Q=");
    Polynomial_output(R);
}