#include "philo.h"

void	*philo_routine(void *pointer)
{
	t_philo *philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while(!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}

int	thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int					i;

	if (pthread_create(&observer, NULL, monitor, program->philos) != 0) // creat thread observer, start running monitor function
			destroy_all("Thread creation error", program, forks);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
					&program->philos[i]) != 0)
					destroy_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if(pthread_join(observer, NULL) != 0)
		destroy_all("Thread join error", program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_all("Thread join error", program, forks);
		i++;
	}
	return(0);
}

void	ft_usleep(unsigned long time)
{
	unsigned long start = get_current_time();
	while ((get_current_time() - start) < time)
		usleep(500);
}