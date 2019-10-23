#include <stdlib.h>
#include "List.h"

#ifdef SeqList

void InitList(List *l)
{
    const int initlen = 10;

    List new = (List)malloc(sizeof(List));
    new->length = initlen;
    new->data = (Elem *)malloc(initlen * sizeof(Elem));
    *l = new;
}

void DestroyList(List l)
{
    l->length = 0;
    free(l->data);
    free(l);
}
void ClearList(List l)
{
}
void ListEmpty(List l);
int ListLength(List l);
Elem GetElem(List l, int i);
int LocateElem(List l, Elem e, CompareFunc comp);
Elem PriorElem(List l, Elem e);
Elem NextElem(List l, Elem e);
void ListInsert(List l, int i, Elem e);
Elem ListDelete(List l, int i);
int ListTraverse(List l, Visit visit);

#endif