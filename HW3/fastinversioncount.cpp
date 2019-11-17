#include "fastinversioncount.h"

int fastinversioncount(int *A, int n){
    int *count;
    *count = 0;
    int *B = new int [n];
    for (int h =0; h < n; h++){
        B[h] = A[h];
    }
    helperinversioncount(B, 0, n, count);
    return *count; 
}

void helperinversioncount(int *A, int start, int n, int *count){
    if (n > 1){
        int mindex = (n+1)/2;
        helperinversioncount(A, start, mindex, count); 
        helperinversioncount(A, mindex + 1, n, count);

        int end1 = mindex - start + 1;
        int end2 = n - mindex;
        int *left = new int [end1];
        int *right = new int [end2];
        
        for (int l = 0; l < end1; l++){
            left[l] = A[l];
        }
        for (int r = 0; r < end2; r++)
        {
            right[r] = A[r];
        }

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < end1 && j < end2)
        {
            if (left[i] <= right[j]) {
                A[k++] = left[i++];
            }
            else{
                A[k++] = right[j++];
            }
            *count++;
        }
        while (i < end1)
        {
            A[k++] = left[i++];
        }
        while (j < end2)
        {
            A[k++] = right[j++];
        }
    }
}


int main(){
    int *U = new int [3,2,1];
    std::cout << fastinversioncount(U, 3) << std::endl;
    std::cout << "I am Batman !" << std::endl;
}