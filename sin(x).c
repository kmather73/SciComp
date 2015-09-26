#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

#define EPSILON 0.000000000001

#define K_TWO_PI 6.28318530717958623199592693708837
#define K_PI 3.14159265358979311599796346854419
#define K_PI_BY_TWO 1.57079632679489655799898173427209
#define K_PI_BY_FOUR 0.78539816339744827899949086713605

double mySin(double, int*), myCos(double, int*);

main(){
	int* iteration = (int*) malloc(sizeof(int));
	double values[] = {10.0, 15.7, 31.4, 47.1, 62.8, 78.5, 94.2};
	printf("%8s x | %10s mySin(x) | %12s sin(x) | num. of iterations\n", "", "", "");
	for(double x = 0.0; x < 1.61; x += .1){
		printf("  %8.6f | %19.16f | %19.16f", x, mySin(x,iteration), sin(x));
		printf(" | %d\n", *iteration);
		printf(" %8.6f | %19.16f | %19.16f", -x, mySin(-x,iteration), sin(-x));
		printf(" | %d\n", *iteration);
	}

	for(int i = 0; i < 7;++i){
		printf(" %8.6f | %19.16f | %19.16f | %d\n", values[i], mySin(values[i],iteration), sin(values[i]), *iteration);
		printf("%8.6f | %19.16f | %19.16f | %d\n", -values[i], mySin(-values[i],iteration), sin(-values[i]), *iteration);
	}
}

double mySin(double x, int* iteration){
	if(x < 0)
		return -mySin(-x, iteration);

	while(x > K_TWO_PI)
		x -= K_TWO_PI;
	if(x >= K_PI)
		return -mySin(x - K_PI, iteration);
	else if( x >= K_PI_BY_TWO)
		return mySin(K_PI - x, iteration);
	else if(x >= K_PI_BY_FOUR)
		return myCos(K_PI_BY_TWO - x, iteration);

	double sum = 0.0;
	double tn = x;
	*iteration = 0;
	
	while(tn > EPSILON || tn < -EPSILON){
		sum += tn;
		++*iteration;
		tn = -1.0* x * x * tn / ( (2 * *iteration) * (2 * *iteration + 1) );
	}
	return sum;
}

double myCos(double x, int* iteration){
	double sum = 0.0;
	double tn = 1;
	*iteration = 0;

	while(tn > EPSILON || tn < -EPSILON){
		sum += tn;
		++*iteration;
		tn = -1.0 * x * x * tn / ( (2 * *iteration - 1) * (2 * *iteration) );
	}
	return sum;
}
