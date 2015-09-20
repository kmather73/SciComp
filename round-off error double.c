#include <stdio.h>
#include <cmath>

main(){
	for(int M = 10; M <=30; M += 10){
		printf("M = %d\n", M);
		printf(" n | %6s initial x |%23s final x |%16s absolute error | %15s relative error \n", "", "", "", "");
		
		for(int n = 1; n <= 10; ++n){
			double x = 1.0 / n;
			printf("%2d | %.14f |" , n, x);

			for(int i = 0; i < M; ++i)
				x = x * (n + 1.0) - 1.0;
		
			double absError = std::abs(x - 1.0/n);
			double relError = absError / (1.0/n);

			printf(" %30.14e | %30.14e | %30.14e\n", x, absError, relError);
		}
		printf("\n");

	}
}
