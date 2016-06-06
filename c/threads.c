#include <stdio.h>
#include <pthread.h>

static pthread_barrier_t barrier;

void *t1_func(void *arg) {
	int i;

	pthread_barrier_wait (&barrier);

	for (i = 0; i < 100; i++) {
		sleep (1);
	}

	return NULL;
}

void *t2_func(void *arg) {
	int i;

	pthread_barrier_wait (&barrier);

	for (i = 0; i < 100; i++) {
		sleep (1);
	}

	return NULL;
}

void all_threads_started (void)
{
}

int main(int argc, char **argv) {
	pthread_t t1, t2;

	pthread_barrier_init (&barrier, NULL, 3);

	pthread_create(&t1, NULL, t1_func, NULL);
	pthread_create(&t2, NULL, t2_func, NULL);

	pthread_barrier_wait (&barrier);

	all_threads_started ();

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}
