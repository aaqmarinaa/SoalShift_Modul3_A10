#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int lohan_stat = 100;
int kepiting_stat = 100;
int flag = 1;

void *lohan(void *arg) {
	while (1) {
		sleep(1);
		lohan_stat -= 15;
		if (lohan_stat <= 0 || lohan_stat > 100) {
			flag = 0;
			break;
		}
	}
}

void *kepiting(void *arg) {
	while (1) {
		sleep(1);
		kepiting_stat -= 10;
		if (kepiting_stat <= 0 || kepiting_stat > 100) {
			flag = 0;
			break;
		}
	}
}

void *menu(void *arg) {
	int pil;

	do {
		if ((lohan_stat <= 0 || lohan_stat > 100) ||
			(kepiting_stat <= 0 || kepiting_stat > 100)) {
			flag = 0;
			break;
		}

		system("clear");
		printf("Lohan's status: %d \t Kepiting's status %d\n\n", lohan_stat, kepiting_stat );
		printf("-= Menu =-\n\n");
		printf("1. Beri makan lohan\n");
		printf("2. Beri makan kepiting\n\n");
		printf("Masukkan pilihan: ");
		scanf("%d", &pil);

		switch (pil) {
			case 1:
				lohan_stat += 10;
				break;
			case 2:
				kepiting_stat += 10;
				break;
		}
	} while(1);
}

int main() {
	pthread_t tid[3];

	pthread_create(&(tid[0]), NULL, &lohan, NULL);
	pthread_create(&(tid[1]), NULL, &kepiting, NULL);
	pthread_create(&(tid[2]), NULL, &menu, NULL);

	int i;
	for (i = 0; i < 3; i++) {
		pthread_join(tid[i], NULL);
	}

	while (flag) {

	}

	system("clear");
	printf("Game Over\n");

	return 0;
}
