#include<stdio.h>
#include<stdlib.h>

int main() {
	int i;
	unsigned seed;

	while (1)
	{
		printf("Enter seed(-1 to end): ");
		scanf_s("%u", &seed);

		if (seed == -1)
			break;

		srand(seed);

		for (i = 1; i <= 10; i++) {

			printf("%10d", 1 + rand() % 6);

			if (i % 5 == 0)
				printf("\n");

		}
	}
	system("pause");
	return 0;
}