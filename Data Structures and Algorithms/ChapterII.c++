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
            return i + 1;
    }
    return 0;
}
//综合应用题
//1.删除表中唯一的最小元素，并返回元素的值
bool Del_Min(SqlList &L, ElemType &value)
{
    if (L.length == 0)
        return false;
    int MinIndex = 0;
    for (int i = i; i < L.length; i++)
    {
        if (L.data[i] < L.data[MinIndex])
            MinIndex = i;
    }
    L.data[MinIndex] = L.data[L.length - 1];
    value = L.data[MinIndex];
    return false;
}
//2.将顺序表L的所有元素逆置，且算法空间复杂度为1
void Reverse(SqlList &L)
{
    for (int i = 0; i < L.length / 2; i++)
    {
        int temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}
//3.长度为n的顺序表L,删除线性表中所有值为x的数据元素,要求时间复杂度O(n),空间复杂度O(1)
void Del_ValueX(SqlList &L, ElemType x)
{
    int j = 0;
    for (int i = 0; i < L.length i++;)
    {
        if (L.data[i] != x)
        {
            L.data[j++] = L.data[i];
        }
    }
    L.length = j;
}
//4.有序表中删除值s与t之间的值(包含s和t,s<t),若st不合理或顺序表为空,显示错误
bool Del_Bet_st(SqlList &L, ElemType s, ElemType t)
{
    if (s >= t)
        return false;
    if (L.length == 0)
        return false;
    int j = 0;
    for (int i = 0; i < L.length; i++;)
    {
        if (L.data[i] < s || L.data[i] > t)
        {
            L.data[j++] = L.data[i];
        }
    }
    L.length = j;
}
//5.可以同上啊
//6.从有序表中删除重复值
void Del_Duplicate(SqlList &L)
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (L.data[i] == L.data[j])
            {
                break;
            }
        }
        L.data[k++] = L.data[i];
    }
    L.length = k;
}
//7.将两个有序表顺序表合并为一个新的有序顺序表,并由函数返回结果顺序表
void Merge(SqlList &La, SqlList &Lb, SqlList &result)
{
    int k = 0;
    for (int i = 0, j = 0; i < La.length || L < Lb.length)
    {
        if (La.data[i] < La.data[j])
            result.data[k++] = La.data[i++];
        else
            result.data[k++] = Lb.data[j++];
    }
    result.length = k;
}
//8.将数组A[m+n]转换为A[n+m] 即(a1,a2...am,b1,b2...bn)转换为(b1,b2...bn,a1,a2...an)
void ReverseMn(SqlList &L)
{
   Reverse()
}
//9,10,11,12看完后做