#include <string>
#include <sstream>
#include <ostream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

//1.链表节点的结构定义
template <class T>
struct chainNode
{
    T element;
    chainNode<T> *next;

    chainNode() {}
    chainNode(const T &element){this->element = element} chainNode(const T &element, chainNode<T> *next) { this->element = element, this->next = next }
};
template <class T>
class chain
{
public:
    chain(int Capacity = 10) {} //链表其实不需要Capacity,这里只是为了和arrayList相容
    chain(const chain<T> &);
    ~chain();
    //ADT方法
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T &theElement);
    void output(ostream &out) const;

protected:
    chainNode<T> *firstNode; //指向链表的第一个元素
    //fisrtNode==null<=>链表为空
    int listSize; //链表的元素个数
};

template <class T>
chain<T>::chain(int initialCapacity)
{
    firstNode = NULL;
    listSize = 0;
}
template <class T>
chain<T>::chain(const chain<T> &theList)
{
    listSize = theList.size;
    if (listsize == 0)
    {
        firstNode == NUll;
        return;
    }
    chainNode<T> *sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);
    sourceNode = sourceNode->next;
    chainNode<T> *targetNode = firstNode;
    while (sourceNode != null)
    {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourcenode->next;
    }
}
int main() 
{
}