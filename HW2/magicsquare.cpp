#include "magicsquare.h"

int **magicSquareCombinations()
/**
 * Calculates the occurance of all possible sums with all possible combination lengths.
 * 
 * @return  A 17 x 133 array where the rows represent a combination length and the columns  
 */
{
    int sum;                    // Sum of permuation
    int count;                  // Length of permuation combination
    int combination;            // permuation number
    int **sums = new int *[17]; // Returned Array

    // Initialize array
    for (int i = 0; i < 17; i++)
    {
        sums[i] = new int[133];
        for (int j = 0; j < 133; j++)
        {
            sums[i][j] = 0;
        }
    }
    int magicSquare[16] = {
        1, 14, 14, 4,
        11, 7, 6, 9,
        8, 10, 10, 5,
        13, 2, 3, 15};

    // Loop through all permutations
    for (int i = 0; i < (pow(2, 16) + 1); i++)
    {
        combination = i;
        sum = 0;
        count = 0;

        // Loop through indvidual permuation
        for (int j = 0; j < 16; j++)
        {
            if (combination & 0x01)
            {
                sum += magicSquare[j];
                count++;
            }
            combination = combination >> 1;
        }
        sums[count][sum]++;
    }
    return sums;
}

int main()
{
    int **sums = magicSquareCombinations();
    std::cout << "1) Number of 4 number combinations that sum to 33: " << sums[4][33] << std::endl;
    int sumCount = 0;
    for (int i = 0; i < 8; i++)
    {
        sumCount += sums[i][33];
    }
    std::cout << "2) Number of any number combinations that sum to 33: " << sumCount << std::endl;
    sumCount = 0;
    for (int i = 0; i < 17; i++)
    {
        for (int j = 0; j < 133; j++)
        {
            sumCount += sums[i][j];
        }
    }
    std::cout << "3) Number of possible sums: " << sumCount << std::endl;
    int greatestCombos = -1;
    int greatestCombosSum = -1;
    for (int i = 0; i < 133; i++)
    {
        sumCount = 0;
        for (int j = 0; j < 17; j++)
        {
            sumCount += sums[j][i];
        }
        if (sumCount > greatestCombos)
        {
            greatestCombos = sumCount;
            greatestCombosSum = i;
        }
    }
    std::cout << "4) The sum " << greatestCombosSum << " has the most possible combinations at " << greatestCombos << " possible combinations." << std::endl;
}