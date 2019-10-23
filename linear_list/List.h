#include "type.h"

void InitList(List *l);
void DestroyList(List *l);
void ClearList(List *l);
void ListEmpty(List l);
int ListLength(List l);
Elem GetElem(List l, int i);
int LocateElem(List l, Elem e, CompareFunc comp);
Elem PriorElem(List l, Elem e);
Elem NextElem(List l, Elem e);
void ListInsert(List *l, int i, Elem e);
Elem ListDelete(List *l, int i);
int ListTraverse(List l, Visit visit);