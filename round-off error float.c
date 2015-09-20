#include <stdio.h>
#include <cmath>

main(){
	for(int M = 10; M <=30; M += 10){
		printf("M = %d\n", M);
		printf(" n | initial x |%23s final x |%16s absolute error | %16s relative error \n", "", "", "");
		
		for(int n = 1; n <= 10; ++n){
			float x = 1.0f / n;
			printf("%2d | %.7f |" , n, x);

			for(int i = 0; i < M; ++i)
				x = x * (n + 1.0f) - 1.0f;
		
			float absError = std::abs(x - 1.0f/n);
			float relError = absError / (1.0f/n);

			printf(" %30.5e | %30.5e | %31.5e\n", x, absError, relError);
		}
		printf("\n");

	}
}
