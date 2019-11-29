#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct HuffmanNode
{
    int value;
    struct HuffmanNode *lst, *rst;
};

struct HuffmanForest
{
    struct HuffmanNode *tree;
    struct HuffmanForest *next;
};

void insert(struct HuffmanForest *forest, struct HuffmanForest *node)
{
    for (struct HuffmanForest *i = forest;; i = i->next)
    {
        if (i->next == NULL || i->next->tree->value > node->tree->value)
        {
            node->next = i->next;
            i->next = node;
            break;
        }
    }
}

void printHuffmanTree(struct HuffmanNode *tree, int deep)
{
    if (tree->lst != NULL)
        printHuffmanTree(tree->lst, deep + 1);
    // 输出缩进
    for (int i = 0; i < deep; i++)
        printf("\t");
    printf("[%4d]\n", tree->value);

    if (tree->rst != NULL)
        printHuffmanTree(tree->rst, deep + 1);
}

void printHuffmanCode(struct HuffmanNode *tree, int perfix)
{
    if (tree->lst == NULL && tree->rst == NULL)
    {
        printf("%4d -> ", tree->value);
        int pre0 = 1;
        for (int i = 7; i >= 0; i--)
        {
            int c = (perfix >> i) & 1;
            pre0 = pre0 && !c;
            printf("%c", pre0&&i ? ' ' : c ? '1' : '0');
        }
        printf("\n");
    }
    if (tree->lst != NULL)
        printHuffmanCode(tree->lst, perfix << 1 | 0);
    if (tree->rst != NULL)
        printHuffmanCode(tree->rst, perfix << 1 | 1);
}

int main()
{
    int data[] = {45, 76, 87, 234, 8, 9, 23, 65};
    const int data_len = sizeof(data) / sizeof(data[0]);

    // 构造森林
    struct HuffmanForest forest;
    forest.next = NULL;
    for (int i = 0; i < data_len; i++)
    {
        struct HuffmanForest *node = malloc(sizeof(struct HuffmanForest));
        node->tree = malloc(sizeof(struct HuffmanNode));
        node->tree->lst = node->tree->rst = NULL;
        node->tree->value = data[i];

        insert(&forest, node);
    }

    // 输出森林
    for (struct HuffmanForest *i = forest.next; i != NULL; i = i->next)
        printf("%d\n", i->tree->value);

    for (int i = 0; i < data_len - 1; i++)
    {
        struct HuffmanForest *t1 = forest.next, *t2 = t1->next, *other = t2->next;
        struct HuffmanForest *node = malloc(sizeof(struct HuffmanForest));
        node->tree = malloc(sizeof(struct HuffmanNode));
        node->tree->value = t1->tree->value + t2->tree->value;
        node->tree->lst = t1->tree;
        node->tree->rst = t2->tree;
        free(t1);
        free(t2);
        forest.next = other; // 此时删去了前两个元素
        insert(&forest, node);
    }

    // 输出哈夫曼树
    printHuffmanTree(forest.next->tree, 0);

    // 输出哈夫曼编码
    printHuffmanCode(forest.next->tree, 0);

    return 0;
}
