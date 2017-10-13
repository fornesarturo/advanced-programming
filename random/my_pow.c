#include <stdio.h>

double my_pow(double x, int n) {
    double number = 1;
    int i;
    if (n < 0) {
		printf("Negative\n");
        for (i = 0; i > n; i--) {
            number /= x;
        }
    } 
    else {
        for( i = 0; i < n; i++) {
            number *= x;
        }    
    } 
    return number;
}

int main() {
	double x = 34.00515;
	int n = -3;
	double result = my_pow(x, n);
	printf("Result = %lf\n", result);
}
