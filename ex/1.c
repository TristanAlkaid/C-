#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MaxSize 100

typedef int DataType;

typedef struct
{
    DataType list[MaxSize];
    int size;
} List;

void Initiate(List *L) /*初始化顺序表L*/
{
    L->size = 0; /*定义初始数据元素个数*/
}

int ListLength(List L) /*返回顺序表L的当前数据元素个数*/
{
    return L.size;
}

int ListInsert(List *L, int i, DataType x)
/*在顺序表L的位置i（0 ≤ i ≤ size）前插入数据元素值x*/
/*插入成功返回1，插入失败返回0*/
{
    int j;
    if (L->size >= MaxSize)
    {
        printf("顺序表已满无法插入! \n");
        return 0;
    }
    else if (i < 0 || i > L->size)
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    {
        //此段程序有一处错误
        for (j = L->size; j > i; j--)
            L->list[j] = L->list[j]; /*为插入做准备*/
        L->list[i] = x; /*插入*/
        L->size++; /*元素个数加1*/
        return 1;
    }
}

int GetElem(List L, int i, DataType *x)
/*取顺序表L中第i个数据元素的值存于x中，成功则返回1，失败返回0*/
{
    if (i < 0 || i > L.size - 1)
    {
        printf("参数i不合法! \n");
        return 0;
    }
    else
    {
        *x = L.list[i];
        return 1;
    }
}

void MergeList(List La, List Lb, List *Lc) //合并两个有序线性表为一个新的有序线性表
{
    int i = 0, j = 0, k = 0;
    DataType ai, bj;
    int La_len = ListLength(La), Lb_len = ListLength(Lb);
    while ((i < La_len) && (j < Lb_len))
    {
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);
        if (ai <= bj)
        {
            ListInsert(Lc, k++, ai);
            ++i;
        }
        else
        {
            ListInsert(Lc, k++, bj);
            ++j;
        }
    }
    while (i < La_len)
    {
        GetElem(La, i++, &ai);
        ListInsert(Lc, k++, ai);
    }
    while (j < Lb_len)
    {
        GetElem(Lb, j++, &bj);
        ListInsert(Lc, k++, bj);
    }
}

int main()
{
    List La, Lb, Lc;
    int i, x;
    Initiate(&Lc);
    La.size = 10;
    Lb.size = 10;
    for (i = 0; i <= 10; i++)
    {
        La.list[i] = 2 * i;
        Lb.list[i] = 2 * i + 1;
    }
    MergeList(La, Lb, &Lc);
    printf("La:");
    for (i = 0; i < ListLength(La); i++)
    {
        GetElem(La, i, &x); //此段程序有一处错误
        printf("%d ", x);
    }
    printf("\nLb:");
    for (i = 0; i < ListLength(Lb); i++)
    {
        GetElem(Lb, i, &x);
        printf("%d ", x);
    }
    printf("\nLc:");
    for (i = 0; i < ListLength(Lc); i++)
    {

        GetElem(Lc, i, &x);
        printf("%d ", x);
    }
    printf("\n周绪洋 2021212778");
    return 0;
}
