#include "max_salary.h"

int add_int(int a, int b){
    int digit = floor(log10(b))+1;
    // printf("%d\n",digit);
    return (a*(int)pow(10, digit)+b);
}

int comparator(const void *a, const void *b){
	int a_val = *(const int *)a;
	int b_val = *(const int *)b;

	if (add_int(a_val,b_val) < add_int(b_val,a_val)){
		return 1;
	} else if (add_int(a_val,b_val) > add_int(b_val,a_val)){
		return -1;
	} return 0;
}

int max_salary_fast(int a[], int size){
	int maximum = 0;
	qsort(a, size, sizeof(a[0]), comparator);
	for (int i = 0; i < size; i++){
		maximum = add_int(maximum, a[i]);
	}
	return maximum;
}

// int main(){
// 	int a[] = {3,23,34,56};
// 	int n = sizeof a/sizeof a[0];
// 	int maximum = max_salary_fast(a, n);
// 	printf("%d\n", maximum);
// 	return 0;
// }