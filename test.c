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

    int result2 = max_salary_fast(arr,n);
    
    if (result1==result2){
      printf("OK\n");
    } else{
      printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);
      break;  
    }
    free(arr);
  }  
}

int main(int argc, char **argv ){
  if (argc < 4){
    printf("To run: test <1> <..> <..> <..>(array of integers separated by space) or test <2> <N> <M>\n");
    return 0;
   }
  
  if (atoi(argv[1]) == 1){
    
    int result1 = 0;
    int n = argc - 2;
    int * arr = malloc(n*sizeof(int));
    int m = 0;
    for (int i = 0; i < n; i++){
        arr[i] = atoi(argv[i+2]);
        m += floor(log10((arr[i])));
    }

    if (m*(n-2) > 9){
      printf("Invalid input. Try smaller input.\n");
    } else{
    heap_permutation(arr, n, n, &result1);
    int result2 = max_salary_fast(arr,n);
    printf("Max salary is %d according to naive method\nMax salary is %d according to greedy method\n", result1, result2);
    }
    free(arr);
  }

  if (atoi(argv[1]) == 2){
   int N = atoi(argv[2]);
   int M = atoi(argv[3]);
   
   if (N * log10(M) < 7){
   stress_test(N, M);
   } else if (N * log10(M) >= 7) {
    printf("Invalid input. Try smaller input.\n");
   }
   
   else{
    printf("Invalid input. To run: test <1> <..> <..> <..>(array of integers separated by space) or test <2> <N> <M>\n");
   }
   return 0;
  }
}
