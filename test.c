#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "max_salary.h"

void stress_test(int N, int M){
  srand(time(NULL));   
  
  while (1) {
    int n = rand() % (N-2) + 2;      // Returns a pseudo-random integer between 0 and RAND_MAX.
  
    int *arr = malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
      arr[i] = rand() % M + 1; 
    }
    print_array(arr, n);
    
    int result1 = 0;
    heap_permutation(arr, n, n, &result1);
    //int result2 = max_salary_fast(arr,n);
    
    // if (result1==result2){
    //   printf("OK\n");
    // } else{
    //   printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);
    //   break;  
    // }
    free(arr);
  }  
}

int main(int argc, char **argv ){
  if (argc < 3){
    printf("To run: test <N> <M>\n");
    return 0;
   }
   
   printf("What the hack");
   int N = atoi(argv[1]);
   int M = atoi(argv[2]);
   
   stress_test(N, M);
   
   return 0;
  
}
