#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "max_salary.h"

void simple_test(int N, int M){
  srand(time(NULL));


}

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
    printf("To run: test <1> <N> <M> or test <2> <N> <M>\n");
    return 0;
   }
   
  if (atoi(argv[1]) == 2){
   int N = atoi(argv[2]);
   int M = atoi(argv[3]);
   
   if (N < 9){
   stress_test(N, M);
   } else{
    printf("Invalid input. Try smaller input.");
   }
   
   return 0;
  }
}
