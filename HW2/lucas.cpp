#include "lucas.h"

void lucasNumbers(int n, int *sequence, int *timeList)
/**
 * Calculates and prints the lucas numbers.
 * @param   n           Integer to calculate to.
 * @param   sequence    An n long array that will be filled with the lucas number series.
 * @param   timeList    An n long array that will be filled with the time to calculate each lucas number.
 */
{
    clock_t time = clock();
    if (n > 1)
    {
        lucasNumbers(n - 1, sequence, timeList);         // Recursivley find all previous lucas numbers
        sequence[n] = sequence[n - 1] + sequence[n - 2]; // Find the current lucas number.
    }
    // Base cases
    else if (n == 1)
    {
        sequence[1] = 1;
    }
    else if (n == 0)
    {
        sequence[0] = 2;
    }
    time = clock() - time;
    timeList[n] = time;
    std::cout << "L(" << n << ") = " << sequence[n] << ", " << (float)time << " s" << std::endl;
}

int main()
{
    int n = 30;
    int *lucasList = new int[n + 1];
    int *timeList = new int[n + 1];
    lucasNumbers(n, lucasList, timeList);
    // Print timeList
    for (int i = 1; i < n; i++)
    {
        std::cout << i << " - " << (float)timeList[i + 1] / (float)timeList[i] << std::endl;
    }
    return 0;
}