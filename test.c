#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int				t = 2;
pthread_mutex_t	lock;
int				j = 5;
pthread_mutex_t	lock2;

void	*t1(void *lock)
{
	for (int a = 0; a < 1000000; a++)
	{
		puts("bgha 2i d5ol");
		// pthread_mutex_lock((pthread_mutex_t *) lock);
		pthread_mutex_lock((pthread_mutex_t *)lock);
		puts("d5al");
		t++;
		// pthread_mutex_unlock((pthread_mutex_t *) lock);
	}
	return (NULL);
}

int	main(void)
{
	pthread_t a;
	pthread_t b;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&a, NULL, t1, &lock);
	pthread_create(&b, NULL, t1, &lock);
	pthread_join(a, NULL);
	pthread_join(b, NULL);
	printf("%d\n", t);
	return (0);
}