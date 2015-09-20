//This is for the power series \sum_{n=0}^{\infty} \frac{2^n x^n}{n!^2}
#include <stdio.h>
#include <stdlib.h> 
#include <cmath>
double powerSeries(double, const double, int*);


main(){
	const double epsilon = std::pow(10, -10);
	int* iterations = (int*) malloc(sizeof(int));

	double x = 1.0;
	for(int i = 0; i < 8; ++i){
		double sum = powerSeries(x, epsilon, iterations);
		printf("f(%.1f) = %e and the number of terms used was %d\n", x, sum, *iterations);
		x *= 2.0;
	}
}

double powerSeries(double x, const double epsilon, int* iterations){
	double sum = 0.0;
	double tn = 1.0;
	*iterations = 0;
	while(tn >= sum * epsilon){
		sum += tn;
		++*iterations;
		tn = tn * 2.0 * x /(*iterations * *iterations);
	}
	return sum;
}
