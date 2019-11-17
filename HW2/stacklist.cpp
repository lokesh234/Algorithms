#include "stacklist.h"

template <typename T>
StackList<T>::StackList(int n)
{
    ptr = new T[n];
    size = n;
    index = -1;
}

template <typename T>
StackList<T>::~StackList()
{
    delete ptr;
}

template <typename T>
T StackList<T>::pop()
/**
 * Pops an item off the stack
 * @return The item from the top of the stack.
 */
{
    if (index < 0)
    {
        throw "Stack is empty";
    }
    return ptr[index--];
}

template <typename T>
T StackList<T>::top()
/**
 * Gets the top of the stack.
 * @return  The item on the top of the stack.
 */
{
    if (index < 0)
    {
        throw "Stack is empty";
    }
    return ptr[index];
}

template <typename T>
void StackList<T>::push(T item)
/**
 * Pushes an item to the stack.
 * @param   item    The item to push
 */
{
    if (index == size - 1)
    {
        throw "Stack is full";
    }
    ptr[++index] = item;
}

template <typename T>
int StackList<T>::getSize()
/**
 * Returns the amount of items in the stack.
 */
{
    return index + 1;
}

template <typename T>
bool StackList<T>::inStack(T item)
/**
 * Checks if an item is in the stack
 * @param   item    Item to check.
 * @return          Bool indicating if item is in the stack.
 */
{
    bool inStack = false;
    for (int i = 0; i <= index; i++)
    {
        if (item == ptr[i])
        {
            inStack = true;
            break;
        }
    }
    return inStack;
}

template <typename T>
T StackList<T>::sum()
/**
 * Sums all elements in the list
 * @return  Sum of all elements.
 */
{
    T sumList = 0;
    for (int i = 0; i <= index; i++)
    {
        sumList += ptr[i];
    }
    return sumList;
}

template <typename T>
T *StackList<T>::getList()
{
    T *list = new T[index + 1];
    for (int i = 0; i <= index; ++i)
    {
        list[i] = ptr[i];
    }
    return list;
}

int runTestCases()
{
    // Validation Code
    StackList<int> stack = StackList<int>(5);
    stack.push(5);
    assert(stack.top() == 5);
    stack.push(4);
    assert(stack.top() == 4);
    assert(stack.getSize() == 2);
    assert(stack.inStack(4) == true);
    assert(stack.sum() == 9);
    assert(stack.pop() == 4);
    assert(stack.top() == 5);
    assert(stack.getSize() == 1);
    assert(stack.inStack(4) == false);
    assert(stack.sum() == 5);
    stack.push(6);
    assert(stack.pop() == 6);
    std::cout << "All tests pass." << std::endl;
    return 0;
}