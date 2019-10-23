#define SeqList

#ifdef SeqList
typedef struct
{
    int i;
    void *data;
} Elem;
typedef struct
{
    int length;
    Elem *data;
} List; // 顺序表
#else
// typedef struct ElemContainer
// {

// } ElemCont;
// typedef struct
// {
//     ElemCont *head;
// }  List; // 链表
#endif

typedef int (*CompareFunc)(Elem, Elem);
typedef int (*Visit)(Elem);