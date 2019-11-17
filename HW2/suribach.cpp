#include "suribach.h"

/*
    ---Psuedo Code---
square[16]
count
stack[4] 

dfs(index, square, stack){
	for (int n = index+1, n < 16){
		if (n not in stack)
			stack.add(n)
			if (stack.sum = 33)
				count++
				stack.pop
				return
			else (stack.sum > 33)
				stack.pop
				retur
			dfs(square, stack)
	}
}
*/

int squareSum(int *square, int *indicies, int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += square[indicies[i]];
    }
    return sum;
}

/*
    for (int i = startingIndex; i < 16; ++i)
    {
        if (!stack->inStack(i))
        {
            stack->push(i);
            if (stack->getSize() == 4 && squareSum(arr, stack->getList(), stack->getSize()) == 33)
            {
                (*count)++;
                stack->pop();
            }
            else if (stack->getSize() == 4 || squareSum(arr, stack->getList(), stack->getSize()) > 33)
            {
                stack->pop();
            }
            dfsCountHelper(++startingIndex, count, arr, stack);
            stack->pop();
        }
    }
*/
/*
for (int i = startingIndex; i < 16; i++)
    {
        if (!stack->inStack(i))
        {
            stack->push(i);
            if (stack->getSize() >= 4 && squareSum(arr, stack->getList(), stack->getSize()) == 33)
            {
                (*count)++;
                stack->pop();
            }
            else if (stack->getSize() == 4 || squareSum(arr, stack->getList(), stack->getSize()) > 33)
            {
                stack->pop();
            }
            if (i == 15)
            {
                dfsCountHelper(startingIndex + 1, count, arr, stack);
                //stack->pop();
            }
            if (stack->getSize() > 1 && i == 15)
            {
                stack->pop();
            }
        }
    }
*/
/*
MOST RESENT
void dfsCountHelper(int startingIndex, int *count, int arr[16], StackList<int> *stack)
{
    for (int i = startingIndex; i < 16; i++)
    {
        if (!stack->inStack(i))
        {
            stack->push(i);
            if (stack->getSize() >= 4 && squareSum(arr, stack->getList(), stack->getSize()) == 33)
            {
                (*count)++;
                stack->pop();
                return;
            }
            else if (stack->getSize() == 4 || squareSum(arr, stack->getList(), stack->getSize()) > 33)
            {
                stack->pop();
                return;
            }
            dfsCountHelper(startingIndex + 1, count, arr, stack);
            stack->pop();
        }
    }
}

int dfsCount(int arr[16])
{
    StackList<int> *stack = new StackList<int>(4);
    int sum = arr[0] + arr[1] + arr[2] + arr[3];
    int count = 0;
    dfsCountHelper(0, &count, arr, stack);
    / *
    for (int i = 0; i < 16; i++)
    {
        for (int j = i + 1; j < 16; j++)
        {
            for (int k = j + 1; k < 16; k++)
            {
                for (int w = k + 1; w < 16; w++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[w] == 33)
                    {
                        count++;
                    }
                }
            }
        }
    }
    * /
    return count;
}
*/

int main()
{
    int magicSquare[16] = {
        1, 14, 14, 4,
        11, 7, 6, 9,
        8, 10, 10, 5,
        13, 2, 3, 15};
    Graph *square = new Graph(16);
    square->makeComplete();
    std::vector<bool> visited(16, false);
    std::cout << "Number of 4 Element Sums of 33: " << square->dfsIndexCount(0, 4, magicSquare, 16, visited) << std::endl;
}