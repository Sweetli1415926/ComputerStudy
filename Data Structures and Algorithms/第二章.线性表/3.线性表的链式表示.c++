#include <malloc.h>
#include "stdio.h"
#define MaxSize 12
typedef int ElemType;

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