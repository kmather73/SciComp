#include <stdio.h>
#include <cmath>

float f(float x), g(float x);

main(){
	const float stepSize = 0.005f;
	float x = -0.1f;

	printf("%7s x | %3s f(x) | %3s g(x) | f(x) - g(x)\n", "", "", "", "");
	for( ; x <= 0.1f; x += stepSize){
		float fx = f(x);
		float gx = g(x);

		printf("%f | %f | %f |%f \n", x, fx, gx, fx - gx);
	}
}

float f(float x){
	return std::pow(1.0f - x, 8);
}

float g(float x){
	float coef[] = {1.0f, -8.0f , 28.0f, -56.0f, 70.0f, -56.0f, 28.0f, -8.0f, 1.0f};
	float sum = 0;

	for(int i = 0; i < 9; ++i){
		sum = sum * x + coef[i];
	}
	return sum;
}
