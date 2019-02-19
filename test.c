#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "max_salary.h"

void short_test (char *arr){
  int result1 = 0;
  int n = sizeof arr/ sizeof arr[0];
  int m = 0;
  int *a = malloc(sizeof n);
  for (int i = 0; i < n; i++){
      a[i] = atoi(arr[i]);
      m += floor(log10((a[i])));
      printf("%d\n",a[i]);
      printf("%c\n",arr[i]);
  }
  if (m*n > 9){
    printf("Invalid input. Try smaller input.");
  } else{
  heap_permutation(a, n, n, &result1);
  int result2 = max_salary_fast(a,n);
  printf("Max salary is %d according to naive method\n Max salary is %d according to greedy method\n", result1, result2);
  }
  free(a);
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
  if (argc < 3){
    printf("To run: test <1> <arr> or test <2> <N> <M>\n");
    return 0;
   }
  
  if (atoi(argv[1]) == 1){
    short_test(argv[2]);
  }

  if (atoi(argv[1]) == 2){
   int N = atoi(argv[2]);
   int M = atoi(argv[3]);
   
   if (N * log10(M) < 9){
   stress_test(N, M);
   } else{
    printf("Invalid input. Try smaller input.\n");
   }
   
   return 0;
  }
}
