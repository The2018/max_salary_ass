#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void print_array(int *arr, int size);
void heap_permutation(int a[], int size, int n, int *maximum);
int add_int(int a, int b);
int add_string(int a, int b, int size_a, int size_b);
int max_salary_fast(int a[], int size);

#endif