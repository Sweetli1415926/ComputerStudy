#define MaxSize 50
typedef int ElemType;
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;
bool EmptyQueue(SqQueue &Q)
{
    if (Q.front == Q.rear == 0)//判断顺序队列是否为空,必须有==0,否则进队出队头尾指针会在尾指针出相等
        return true;
    else
        return false;
}
//由于队头队尾的位置会相对移动,所以会存在"假溢出"等现象,常用循环队列来解决

int main()
{
    return 0;
}