#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void FRD(int x);
void RD(int x, int y);
int RollDice();

int D1, D2;
char status;

int main() {

	int i;
	int sum;
	int goal;

	char select = ' ';

	unsigned seed;
	srand(time(NULL));


	while (1) {

		printf("要不要來一局啊?(y/n)");
	Re:printf("\n");

		select = ' ';

		scanf_s("%c", &select);

		if (select == 'n') {
			printf("好難過喔QAQ\n\n");
			break;
		}
		else if (select == 'y') {

			printf("那準備要骰第一次囉~~~\n\n");
			system("pause");
			printf("\n");

			sum = RollDice();
			FRD(sum);
			if (status == 'W' || status == 'L')
				goto Re;

			else {
				goal = sum;

			DoRD:
				sum = RollDice();
				RD(sum, goal);
				if (status == 'W' || status == 'L')
					goto Re;
				else
					goto DoRD;

			}

		}

	}

}

int RollDice() {

	int Ftotal;

	D1 = 1 + rand() % 6;
	D2 = 1 + rand() % 6;

	Ftotal = D1 + D2;

	printf("你骰出的數字為[%d]和[%d]，共%d點\n\n", D1, D2, Ftotal);

	return Ftotal;
}

void FRD(int x, char z) {

	switch (x) {

	case 2:
	case 3:
	case 12:
		printf("你輸了哈\n\n重玩一次吧:)\n\n\n");
		status = 'L';
		break;

	case 7:
	case 11:
		printf("你贏了ㄟ，好棒棒\n\n\n");
		status = 'W';
		break;

	default:
		printf("你在骰到%d就贏了\n\n但在這之前你若骰到7的話，你就輸囉0.0\n\n", x);
		printf("準備好就可以再骰一次囉~~\n\n");
		system("pause");
		printf("\n");

	}

}
int RD(int x, int y) {

	if (x == y) {
		printf("你贏了ㄟ，好棒棒\n\n\n");
		status = 'W';
	}
	else {
		switch (x) {

		case 7:
			printf("你輸了哈\n\n重玩一次吧:)\n\n\n");
			status = 'L';
			break;
		default:
			printf("還是沒中請在骰一次:)\n\n");
			printf("準備好就可以再骰一次囉~~\n\n");
			system("pause");
			break;
		}
	}
}