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

		printf("�n���n�Ӥ@����?(y/n)");
	Re:printf("\n");

		select = ' ';

		scanf_s("%c", &select);

		if (select == 'n') {
			printf("�n���L��QAQ\n\n");
			break;
		}
		else if (select == 'y') {

			printf("���ǳƭn��Ĥ@���o~~~\n\n");
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

	printf("�A��X���Ʀr��[%d]�M[%d]�A�@%d�I\n\n", D1, D2, Ftotal);

	return Ftotal;
}

void FRD(int x, char z) {

	switch (x) {

	case 2:
	case 3:
	case 12:
		printf("�A��F��\n\n�����@���a:)\n\n\n");
		status = 'L';
		break;

	case 7:
	case 11:
		printf("�AĹ�F���A�n�δ�\n\n\n");
		status = 'W';
		break;

	default:
		printf("�A�b���%d�NĹ�F\n\n���b�o���e�A�Y���7���ܡA�A�N���o0.0\n\n", x);
		printf("�ǳƦn�N�i�H�A��@���o~~\n\n");
		system("pause");
		printf("\n");

	}

}
int RD(int x, int y) {

	if (x == y) {
		printf("�AĹ�F���A�n�δ�\n\n\n");
		status = 'W';
	}
	else {
		switch (x) {

		case 7:
			printf("�A��F��\n\n�����@���a:)\n\n\n");
			status = 'L';
			break;
		default:
			printf("�٬O�S���Цb��@��:)\n\n");
			printf("�ǳƦn�N�i�H�A��@���o~~\n\n");
			system("pause");
			break;
		}
	}
}