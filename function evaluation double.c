#include <stdio.h>
#include <cmath>

double f(double x), g(double x);

main(){
	const double stepSize = 0.005f;
	double x = -0.1f;

	printf("%19s x | %15s f(x) | %15s g(x) | %10sf(x) - g(x)\n", "", "", "", "", "");
	for( ; x <= 0.1f; x += stepSize){
		double fx = f(x);
		double gx = g(x);

		printf("%16.14e | %16.14e | %16.14e | %16.14e \n", x, fx, gx, fx - gx);
	}
}

double f(double x){
	return std::pow(1.0f - x, 8);
}

double g(double x){
	double coef[] = {1.0, -8.0, 28.0, -56.0, 70.0, -56.0, 28.0, -8.0, 1.0};
	double sum = 0;

	for(int i = 0; i < 9; ++i){
		sum = sum * x + coef[i];
	}
	return sum;
}
