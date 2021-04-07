#include <string>
#include <sstream>
#include <ostream>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;
//1.抽象类
template <class T>
class linearList
{ //抽象类包含着没有实现的代码，成员函数为纯虚函数(pure virtual funnction)
public:
    virtual ~linearList();
    virtual bool empty() const = 0;                             //当线性表为空，返回true
    virtual int size() const = 0;                               //返回线性表的元素个数
    virtual T &get(int theIndex) const = 0;                     //返回索引为theIndex的元素
    virtual int indexOf(const T &theElement) const = 0;         //返回元素theElement第一次出现时的索引
    virtual void erase(int theIndex) = 0;                       //删除索引为theIndex的元素
    virtual void insert(int theIndex, const T &theElement) = 0; //把theElement插入线性表中索引为theIndex的位置上
    virtual void output(ostream &out) const = 0;                //把线性表插入输出流out
};

//2.改变一个一位数组的长度
template <class T>
void changLength1D(T *&a, int oldLength, int newLength)
{
    if (newLength > 0)
    {
        T *temp = new T[newLength];
        int number = min(oldLength, newLength);
        copy(a, a + number, temp);
        delete[] a;
        a = temp;
    }
}
//3.arrayList类
template <class T>
class arrayList : linearList<T>
{
public:
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &);
    ~arrayList() { delete[] element; }
    //ADT方法
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T &get(int theINdex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(ostream &out) const;
    int capacity() const { return arrayLength; }

protected:
    void checkIndex(int theIndex) const; //若索引theIndex无效，则抛出异常
    T *element;                          //存储线性表元素的一维数组
    int arrayLength;                     //一维数组的容量
    int listSize;                        //线性表元素的个数
};
template <class T>
arrayList<T>::arrayList(int initialCpacity)
{
    if (initialCpacity < 1)
    {
        ostringstream s;
        s << "Initial capacity=" << initialCpacity << "must be >0";
    }
    else
    {
        arrayLength = initialCpacity;
        element = new T[arrayLength];
        listSize = 0;
    }
}
template <class T>
arrayList<T>::arrayList(const arrayList<T> &theList)
{
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
}
template <class T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if (theIndex > 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index=" << theIndex << " size =" << listSize;
    }
}
template <class T>
T &arrayList<T>::get(int theIndex) const
{
    //返回元素 theElement第一次出现时的索引
    //若该元素不存在，则返回-1
    checkIndex(theIndex);
    return element[theIndex];
}
template <class T>
int arrayList<T>::indexOf(const T &theElement) const
{
    //确定索引theIndex在0和listSize-1之间
    int theIndex = (int)(find(element, element + listSize, theElement) - element);
    if (theIndex == listSize)
        return -1;
    else
        return theIndex;
};
template <class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    element[--listSize].~T();
}
template <class T>
void arrayList<T>::insert(int theIndex, const T &theElement)
{
    if (theIndex <= 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index =" << theIndex << "size =" << listSize;
    }
    if (listSize == arrayLength)
    {
        changLength1D(theElement, arrayLength, arrayLength * 2);
        arrayLength *= 2;
    }
    copy_backward(element + theIndex, element + listSize, element + listSize + 1); //使用copy_backward是从后往前拷贝，这样才能顺利拷贝到原来位置
    //如果拷贝到其他内存地址，可以使用copy
    element[theIndex] = theElement;
    listSize++;
};
template <class T>
void arrayList<T>::output(ostream &out) const
{
    copy(element, element + listSize, ostream_iterator<T>(cout, " "));
}

template <class T>
ostream &operator<<(ostream &out, const arrayList<T> &x)
{
    x.output(out);
    return out;
}
//迭代器
template <class T>
class iterator
{
public:
    typedef bidirectional_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;
    iterator(T *thePosition = 0)
    {
        position = thePosition;
    }
    T &
    operator*() const { return *position; }
    T *operator->() const { return &*position; }

protected:
    T *position;
};
int main()
{
    return 0;
}