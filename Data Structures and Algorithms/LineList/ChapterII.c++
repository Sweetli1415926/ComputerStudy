#include <malloc.h>
#include "stdio.h"
//1.线性表(静态分配)
#define MaxSize 12 //顺序表的最大长度
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
    return true;
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
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] != x)
        {
            L.data[j++] = L.data[i];
        }
    }
    L.length = j;
}
void Del_ValueX_2(SqlList &L, ElemType x)
{
    int i = 0, k = 0;
    while (i < L.length)
    {
        if (L.data[i] == x)
        {
        }
        else
        {
            L.data[i - k] = L.data[i];
        }
        i++;
    }
    L.length = L.length - k;
}
//4.有序表中删除值s与t之间的值(包含s和t,s<t),若st不合理或顺序表为空,显示错误
bool Del_Bet_st(SqlList &L, ElemType s, ElemType t)
{
    if (s >= t)
        return false;
    if (L.length == 0)
        return false;
    int j = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] < s || L.data[i] > t)
        {
            L.data[j++] = L.data[i];
        }
    }
    L.length = j;
    return true;
}
//5.可以同上啊
//6.从有序表中删除重复值
void Del_Duplicate(SqlList &L)
{
    int j = 0;
    for (int i = 1; i < L.length; i++)
    {
        if (L.data[i] != L.data[j])
        {
            L.data[++j] = L.data[i];
        }
    }
    L.length = j + 1;
}
void Del_Duplicate_2(SqlList &L) //能成功但是不好的方法
{
    int k = 0;
    for (int i = 0; i < L.length; i++)
    {
        for (int j = 0; j < i; j++)
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
    for (int i = 0, j = 0; i < La.length || j < Lb.length;)
    {
        if (La.data[i] < La.data[j])
            result.data[k++] = La.data[i++];
        else
            result.data[k++] = Lb.data[j++];
    }
    result.length = k;
}
//8.将数组A[m+n]转换为A[n+m] 即(a1,a2...am,b1,b2...bn)转换为(b1,b2...bn,a1,a2...an)
void ReverseBO(SqlList &L, int Begin, int Over)
{
    for (int i = 1; i < (Over - Begin + 1) / 2; i++)
    {
        int temp = L.data[i - 1];
        L.data[i] = L.data[Over - i];
        L.data[Over - i] = temp;
    }
}
void ReverseMn(SqlList &L)
{
    int m = 5;
    int n = 10;
    ReverseBO(L, 1, m);
    ReverseBO(L, m + 1, n);
    ReverseBO(L, 1, m + n);
}

//9,10,11,12看完后做

//2.单链表节点类型的描述
typedef struct LNode
{
    ElemType data;      //数据域
    struct LNode *next; //指针域
} LNode, *LinkList;

//头插法建立单链表
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}
//尾插法建立链表
LinkList List_TailInsert(LinkList &L)
{

    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}
//按序号查找结点值
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;
    LNode *s = L;
    while (i != 0)
    {
        s = s->next;
        i--;
    }
    return s;
}
LNode *GetElem_2(LinkList L, int i)
{
    int j = 1; //计数器
    LNode *p = L->next;
    if (i < 0)
        return NULL;
    if (i == 0)
        return NULL;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
//按值查找结点
LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}
//插入结点操作
void InsertElem(LinkList &L, int i, ElemType e)
{
    LNode *p = GetElem(L, i - 1); //查到插入结点的前驱结点

    LNode *s; //构造新结点
    s->data = e;
    s->next = p->next;

    p->next = s;
}
void DeleteElem(LinkList &L, int i)
{
    LNode *p = GetElem(L, i - 1);
    LNode *q = p->next;
    p->next = q->next;
    free(q);
}
typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//双链表查找

//双链表的插入操作
void InsertDElem()
{
    //s->next=p->next
    //s->prior=p
    //s->next->prior=p
    //p-next=s
}
void DeleteDElem()
{
    //q=p->next
    //p->next=q->next
    //q->next->prior=p
    //free(q);
}

//静态链表的结构
typedef struct
{
    ElemType data;
    int next;
} SLinkList[MaxSize];
//应用题
//1.设计递归算法,删除不带头结点的单链表L中所有值为x的结点
void Del_X(LinkList &L, ElemType x)
{
    LNode *p;
    if (L == NULL)
        return;
    if (L->data == x)
    {
        p = L;
        L = L->next;
        free(p);
        Del_X(L, x);
    }
    else
        Del_X(L->next, x);
}
//2.在带头结点的单链表L中,删除所有值为x的结点
void Del_X_2(LinkList &L, ElemType x)
{
    LNode *p = L->next, *q, *pre = L;

    while (p != NULL)
    {
        if (p->data == x)
        {
            pre->next = p->next;
            q = p;
            pre = p;
            p = p->next;
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}
//3.L为带头结点的单链表,反向输出每个结点的值
void Show_reverse(LinkList &L)
{
    LNode *p = L->next, *q, *pre = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        q->next = pre;
        pre = q;
    }
    L->next = pre;
    while (L->next != NULL)
    {
        L = L->next;
        printf("%d", L->data);
    }
}
//4.带头结点的单链表L中删除最小值的高效算法(最小值唯一)
void Del_Min(LinkList &L)
{
    LNode *pre = L, *q = L->next, *preMin;
    ElemType Min = q->data;
    while (q->next != NULL)
    {
        pre = q;
        q = q->next;
        if (Min > q->data)
        {
            preMin = pre;
            Min = q->data;
        }
    }
    LNode *s=preMin->next;
    preMin->next=s->next;
    free(s);
}
int main()
{
    LinkList L = (LinkList)malloc(sizeof(LNode));
    List_HeadInsert(L);
    Del_Min(L);
    Show_reverse(L);
    return 0;
    //SeqList L;
    //3.C的初始动态分配语句为
    //L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
    //4.C++的初始动态分配语句为
    //L.data = new ElemType[InitSize];

    //SqlList L2 = {{1, 1, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6}, 12};
    //Del_Duplicate(L2);
}