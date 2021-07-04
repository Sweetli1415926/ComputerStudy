typedef int ElemType;
#define MaxSize 50
typedef struct
{
    ElemType data[MaxSize];
    int top;
} SqStack;
void InitStack(SqStack &S)
{
    S.top = -1;
}
bool StackEmpty(SqStack &S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}
bool Push(SqStack &S, ElemType x)
{
    if (S.top == MaxSize - 1)
        return false;
    S.data[++S.top] = x;
    return true;
}
bool Pop(SqStack &S, ElemType &x)
{
    if (StackEmpty(S))
        return false;
    x = S.data[S.top--];
    return true;
}
bool GetTop(SqStack S, ElemType &x)
{
    if (StackEmpty(S))
        return false;
    x = S.data[S.top];
    return true;
}

//栈的链式存储
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
} * LinkStack;

int main()
{
    return 0;
}