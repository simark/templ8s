#include <stdio.h>
#include <pthread.h>

void *t1_func(void *arg) {
	return NULL;
}

void *t2_func(void *arg) {
	return NULL;
}

int main(int argc, char **argv) {
	pthread_t t1, t2;

	pthread_create(&t1, NULL, t1_func, NULL);
	pthread_create(&t2, NULL, t2_func, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}
