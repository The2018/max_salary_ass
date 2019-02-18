#include "max_salary.h"

int add_int(int a, int b){
    int digit = floor(log10(b))+1;
    // printf("%d\n",digit);
    return (a*(int)pow(10, digit)+b);
}

int comparator(int a, int b){
	
}

int max_salary_fast(int a[], int size){
	int *max_so_far = malloc(size);
	for (i = 0; i < size; i++){
		if ((a[i] % 10) > max_so_far){
			max_so_far = a[i];
		}
	}

}