#include <malloc.h>
//1.线性表(静态分配)
#define MaxSize 50 //顺序表的最大长度
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int length; //顺序表的当前长度
} SqlList;
//2.线性表(动态分配)
#define InitSize 100
typedef struct
{
    ElemType *data;
    int MaxSize2, length;
} SeqList;

int main()
{
    SeqList L;
    //3.C的初始动态分配语句为
    L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    //4.C++的初始动态分配语句为
    L.data = new ElemType[InitSize];
    return 0;
}
bool ListInsert(SqlList &L, int i, ElemType e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i, j--;)
    {
        L.data[j] = L.data[j - 1]; //L.data[j]是a(j+1)
                                   //L.data[从0开始]
    }
    L.data[i - 1] = e; //插到第i个位置 就是插入数组第[i-1]个位置
    L.length++;
    return true;
}
bool ListDelete(SqlList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length - 1; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}
int LocateElem(SqlList L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i+1;
    }
    return 0;
}