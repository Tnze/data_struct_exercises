/*
实验题目十一：背包问题
1.目的:
    - 能用程序设计语言实现求解背包问题的算法。
    - 掌基本掌握动态规划法的原理方法。
2.要求:
	有不同价值、不同重量的物品n件，求从这n件物品中选取一部分物品的选择方案，
    使选中物品的总重量不超过指定的限制重量W，但选中物品的价值之和最大。
*/
#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main()
{
    const int V = 5;                                  //背包容量
    int values[] = {2, 4, 4, 5};                      //物品的价值
    const int n = sizeof(values) / sizeof(values[0]); //物品个数                  //物品数量n
    int weights[n] = {1, 2, 3, 4};                    //物品的重量

    int F[V] = {0}; //可以获得的最大价值

    for (int i = 0; i < n; i++)
        for (int v = V - 1; v + 1 >= weights[i]; v--)
            F[v] = max(F[v], F[v - weights[i]] + values[i]);

    for (int i = 0; i < V; i++)
        printf("%3d,", F[i]);
    printf("\n");
    return 0;
}