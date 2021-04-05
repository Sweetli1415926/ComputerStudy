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
int TryCatch()
{
    try
    {
        cout << "something" << endl;
    }
    catch (exception &e) //捕捉异常类型为exception及其所有派生类型的异常
    {
    }
    return 0;
}
//8.动态分配存储空间操作符new和删除符Delete
void NewAndDelete()
{
    int n = 10;
    int *y = new int(10);    //y是一个指针，*y=10
    delete y;                //释放空间
    float *x = new float[n]; //中括号表示创建一个数组
    delete[] x;              //释放数组x
}
//9.创建二维数组时必须制定第二维的大小
//动态创建二维数组
template <class T>
bool make2dArray(T **&x, int numberOfRows, int numberOfColumns)
{
    x = new T *[numberOfRows];
    for (int i = 0; i < numberOfRows; i++)
    {
        x[i] = new T[numberOfColumns];
    }
    return true;
}
//10.删除二维数组
template <class T>
void delete2dArray(T **&x, int numberOfRows)
{
    for (int i = 0; i < numberOfRows; i++) //删除行组
    {
        delete[] x[i];
    }
    delete[] x; //删除指针
    x = NULL;
}
//11.创建一个异常类
class illegalParameterValue
{
public:
    illegalParameterValue() : message("Illegal parameter value") {}
    illegalParameterValue(char *theMessage)
    {
        message = theMessage;
    }

private:
    string message;
};
enum signType
{
    plus,
    minus
};
//12.currency类举例说明
class currency
{
public:
    currency(signType theSign = ::plus,
             unsigned long theDollars = 0,
             unsigned int theCents = 0);
    ~currency(){};
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const { return sign; } //常量函数：类的成员函数后面加const，表明这个函数不会改变调用对象的值。
    unsigned long getDollars() const { return dollars; }
    unsigned int getCents() const { return cents; }
    currency add(const currency &) const;
    currency &increment(const currency &);
    void output() const;

private:
    signType sign;
    unsigned long dollars;
    unsigned int cents;
};
void TestCurrency01()
{
    currency f, g(::plus, 3, 45), h(::minus, 10); //三种实例化的方式,使用参数默认值
    currency *m = new currency(::plus, 8, 12);
    h.add(g);
}
//13.在类声明体外实现函数,类名:函数
currency::currency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    setValue(theSign, theDollars, theCents);
}
void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    if (theCents > 99)
    {
        //throw illegalParameterValue("Cents should be <100");
    }
    sign = theSign;
    dollars = theDollars;
    cents = theCents;
}
void currency::setValue(double theAmount)
{
    if (theAmount < 0)
    {
        sign = ::minus;
        theAmount = -theAmount;
    }
    else
        sign = ::plus;
    dollars = (unsigned long)theAmount;
    cents = (unsigned int)(theAmount - dollars) * 100;
}
currency currency::add(const currency &x) const
{
    long a1, a2, a3;
    currency result;
    a1 = dollars * 100 + cents;
    if (sign == ::minus)
    {
        a1 = -a1;
    }
    a2 = x.dollars * 100 + x.cents;
    if (x.sign == ::minus)
    {
        a2 = -a2;
    }
    a3 = a1 + a2;
    result.dollars = a3 / 100; //只保留整数部分
    result.cents = a3 - result.dollars * 100;
    return result;
}
//14.add返回对象的值，而increment返回对象的引用
currency &currency::increment(const currency &x)
{
    *this = add(x);
    return *this;
}

void currency::output() const
{
    if (sign == ::minus)
        cout << '-';
    cout << '$' << dollars << '.';
    cout << cents;
}

#include <iostream>
int TestCurrency02()
{
    currency g, h(::plus, 3, 50), i, j;
    g.setValue(::minus, 2, 25);
    i.setValue(-6.45);
    j = h.add(g);
    h.output();
    cout << "+";
    g.output();
    cout << "=";
    j.output();
    cout << endl;
    j = i.add(g).add(h);
    j = i.increment(g).add(h);
    cout << "Attempmting to initialize with cents 152" << endl;
    try
    {
        i.setValue(::plus, 3, 152);
    }
    catch (illegalParameterValue e)
    {
        cout << "Caught thrown exception" << endl;
        //e.outputMessage();
    }
    return 0;
}
//15.新currency，类内部实现更多细节，外部调用更简单

class Newcurrency
{
public:
    Newcurrency(signType theSign = ::plus, unsigned long theDollars = 0, unsigned int theCents = 0);
    ~Newcurrency();
    void setValue(signType, unsigned long, unsigned int);
    void setValue(double);
    signType getSign() const
    {
        if (Amount < 0)
            return ::minus;
        else
            return ::plus;
    }
    unsigned long getDollars() const
    {
        if (Amount < 0)
            return -Amount / 100;
        else
            return Amount / 100;
    };
    unsigned int getCents() const
    {
        if (Amount < 0)
            return -Amount - getDollars() * 100;
        else
            return Amount - getDollars() * 100;
    }

    Newcurrency add(const Newcurrency &) const; //add相当于是+，increment相当于是+=
    Newcurrency &increment(const Newcurrency &x)
    {
        Amount += x.Amount;
        return *this;
    }
    void output() const;
    Newcurrency operator+(const Newcurrency &) const;
    Newcurrency &operator+=(const Newcurrency &x)
    {
        Amount += x.Amount;
        return *this;
    }

private:
    long Amount;
};
Newcurrency::Newcurrency(signType theSign, unsigned long theDollars, unsigned int theCents)
{
    setValue(theSign, theDollars, theCents);
}
void Newcurrency::setValue(signType, unsigned long, unsigned int)
{
}
//16.操作符重载 扩大C++操作符的使用范围 使得对象也可以用+符号来相加
Newcurrency Newcurrency::operator+(const Newcurrency &x) const
{
    Newcurrency result;
    result.Amount = Amount + x.Amount;
    return result;
}
//17.#ifndef
//#ifndef currrency.h //防止头文件重复引用编译，如果没定义
//#define currency .h //那么定义
//#endif              //结束

//18.递归函数
//n!
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}
//累加
template <class T>
T sum(T a[], int n)
{
    T result;
    for (int i = 0; i < n; i++) //返回的是a[0,n-1]数组元素的和
    {
        result += a[i];
    }
    return result;
}
//递归求和
template <class T>
T rSum(T a[], int n)
{
    if (n > 0)
    {
        return rSum(a, n - 1) + a[n];
    }
    return 0;
}
//19.使用递归函数生成排列
#include <iterator>
template <class T>
void permutations(T list[], int k, int m)
{
    if (k == m) //仅有一个排列，输出它
    {
        copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
        cout << endl;
    }
    else
    {
        for (int i = k; i <= m; i++)
        {
            swap(list[k], list[i]);
            permutations(list, k + 1, m);
            swap(list[k], list[i]);
        }
    }
}
//20.STL模板
//accumulate累加
template <class T>
T STL_sum(T a[], int n)
{
    T theSum = 0;
    return accumulate(a, a + n, theSum);
}
//累乘
template <class T>
T product(T a[], int n)
{
    T theProduct = 1;
    return accumulate(a, a + n, theProduct, multiplies<T>());
}
//拷贝顺序表，求排列
template <class T>
void  STL_permutations(T list[], int k, int m)
{
    //生成list[k:m]的所有排列 元素个数为m-k+1;
    //假设k<=m;
    do
    {
        copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
        cout << endl;
    }
    while(next_permutation(list, list + m + 1));
}
int main()
{
    string a[3] = {"a", "b", "c"};
    //TestCurrency01();
    permutations(a, 0, 2);
    return 0;
}