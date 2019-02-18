#include "max_salary.h"
#include "math.h"
#include "stdlib.h"

int add_int(int a, int b){
    int digit = floor(log10(b))+1;
    // printf("%d\n",digit);
    return (a*(int)pow(10, digit)+b);
}

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}


// Generating permutation using Heap Algorithm 
void heap_permutation(int a[], int size, int n, int *maximum) { 
    // if size becomes 1 then do something with the obtained permutation

    if (size == 1) { 
        //TO DO - instead of printing, insert your code for evaluating the next candidate array
        //print_array(a, n); 
        int max_so_far = 0;
        for (int i = 0; i < n; i++){
            max_so_far = add_int(max_so_far,a[i]); 
            // printf("%d\n", max_so_far);
        }
        // printf("%d\n", max_so_far);
        if (max_so_far > *maximum){
            *maximum = max_so_far;
        }
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heap_permutation(a,size-1,n, maximum); 
  
        // if size is odd, swap first and last element 
        if (size%2==1) {
            SWAP(a[0], a[size-1]); 
		}
        // If size is even, swap ith and last element 
        else{
            SWAP(a[i], a[size-1]);
		}			
    } 
}

// Code to test permutations
int main() { 
    int a[] = {2, 12, 35, 46}; 
    int n = sizeof a/sizeof a[0]; 
    int maximum = 0;
    //heap_permutation(a, n, n); 
    heap_permutation(a, n, n, &maximum);
    printf("%d\n", maximum);
    return 0; 
} 
