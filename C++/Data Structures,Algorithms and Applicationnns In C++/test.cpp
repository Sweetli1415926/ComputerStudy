#include <iostream>
#include <vector>
#include <string>

using namespace std;
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
    ~currency(){}
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
    f.add(g);
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
    long a1,a2,a3;
    currency result;
    a1=dollars*100+cents;
    if(sign==::minus){
        a1=-a1;
    }
    a2=x.dollars*100+cents;
    if(x.sign==::minus){
        a2=-a2;
    }
    a3=a1+a2;
    result.setValue(a3/100);
    return result;
}
int main()
{
    TestCurrency01();
    return 0;
}