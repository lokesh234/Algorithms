#include <iostream>
#include <cassert>

template <typename T>
class StackList
{
private:
    T *ptr;
    int size;
    int index;

public:
    StackList(int size);
    ~StackList();
    T pop();
    T top();
    void push(T item);
    T sum();
    bool inStack(T item);
    int getSize();
    T* getList();
};

int main();