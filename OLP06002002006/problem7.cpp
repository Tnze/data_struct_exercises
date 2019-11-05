/*
实验题目七:用二叉查找树🌲实现一个动态查找表
1.目的:
    - 掌握二叉树的链式存储结构。
    - 掌握二叉查找树的构建。
2.要求:
    - 使用二叉树(BST)来实现
    - 二叉树使用链式结构(二叉链表)实现
    - 实现 BST 的构建，查找两个功能

编译：clang++ -std=c++11 problem7.cpp
*/
#include <iostream>

using namespace std;

class BTree
{
    BTree *lst, *rst; // subtrees
public:
    // 根节点的值
    int V;

    // 构造具有value的二叉树
    BTree(int value);

    // 插入数据
    void Insert(int value);

    // 查询数据是否存在
    bool Exist(int value);

    // 中序遍历
    void LNR(void visit(int v));
};

BTree::BTree(int value)
{
    V = value;
    lst = NULL;
    rst = NULL;
}

void BTree::Insert(int value)
{
    if (value == V)
        return;
    else if (value < V)
    {
        if (lst == NULL)
            lst = new BTree(value);
        else
            lst->Insert(value);
    }
    else if (value > V)
    {
        if (rst == NULL)
            rst = new BTree(value);
        else
            rst->Insert(value);
    }
}

void BTree::LNR(void visit(int v))
{
    if (lst != NULL)
        lst->LNR(visit);
    visit(V);
    if (rst != NULL)
        rst->LNR(visit);
}

bool BTree::Exist(int value)
{
    if (value == V)
        return true;
    if (value < V)
        return lst != NULL && lst->Exist(value);
    if (value > V)
        return rst != NULL && rst->Exist(value);
    else
        return false; // unreachable code
}

int main()
{
    // 构造
    int data[] = {9, 18, 6, 12, 17, 25, 1, 10};
    BTree tree(16);
    for (int i = 0; i != sizeof(data) / sizeof(data[0]); i++)
        tree.Insert(data[i]);

    // 查找
    for (int i = 0; i != 10; i++)
        cout << "value(" << i << ") is " << (tree.Exist(i) ? "exists" : "not exists") << endl;

    // 中序遍历输出
    cout << "tree: ";
    tree.LNR([](int v) { cout << v << ' '; });
    cout << endl;
}