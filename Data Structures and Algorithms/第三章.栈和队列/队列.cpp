#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;
bool EmptyQueue(SqQueue &Q)
{
    if (Q.front == Q.rear == 0) //判断顺序队列是否为空,必须有==0,否则进队出队头尾指针会在尾指针出相等
        return true;
    else
        return false;
}
//由于队头队尾的位置会相对移动,所以会存在"假溢出"等现象,常用循环队列来解决
//循环队列
void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;
}
bool isEmpty(SqQueue &Q)
{
    if (Q.rear == Q.front)
        return true;
    else
        return false;
}
bool EnQueue(SqQueue &Q, ElemType x)
{
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}
bool DeQueue(SqQueue &Q, ElemType &x)
{
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
int main()
{
    return 0;
}