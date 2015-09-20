#include <stdio.h>
main(){
	float x = 1.0f;

	while(x +1.0f > 1.0f)
			x *= 0.5f;
	printf("machine precision for floats is = %.23f\n", x * 2.0f);

	double y = 1.0;

	while(y + 1.0 > 1.0)
		y *= 0.5;
	printf("machine precision for doubles is = %.42f\n", y * 2.0f);
}
