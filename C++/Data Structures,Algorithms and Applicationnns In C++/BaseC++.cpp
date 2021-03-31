#include <iostream>
using namespace std;
//1.利用模板进行计算
template <class T>
T abc(T a, T b, T c)
{
    return a + b * c;
}
//2.传递参数的别名，引用传参
template <class T>
T abc(T &a, T &b, T &c)
{
    return a + b * c;
}
//3.常量引用参数,引用参数不能被函数修改
template <class T>
T abc(const T &a, const T &b, const T &c)
{
    return a + b * c;
}
//4.通用版本
template <class Ta, class Tb, class Tc>
Ta abc(const Ta &a, const Tb &b, const Tc &c)
{
    return a + b * c;
}
//5.引用返回
template <class T>
T &mystery(int i, T &z)
{
    return z;
}
//6.如果加上const 则返回值必须赋给const常量
template <class T>
const T &mystery(int i, T &z)
{
    return z;
}
//7.异常
int main()
{
    try
    {
        cout << "something" << endl;
    }
    catch (exception &e) //捕捉异常类型为exception及其所有派生类型的异常
    {
    }
}
//8.动态分配存储空间操作符new和删除符Delete
void NewAndDelete()
{
    int n=10;
    int *y = new int(10);    //y是一个指针，*y=10
    delete y;                //释放空间
    float *x = new float[n]; //中括号表示创建一个数组
    delete[] x;              //释放数组x
}
//9.创建二维数组时必须制定第二维的大小
//利用动态创建数组
template <class T>
bool make2dArray(T ** &x,int numberOfRows, int numberOfColumns)
{
    try{
        x=new T*[numberOfRows];
        for (int i = 0; i < numberOfRows; i++)
        {
            x[i]=new int [numberOfColumns];
        }
        return true;
    }
    catch(bad_alloc){
        return false;
    }
}