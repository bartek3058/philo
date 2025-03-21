#include "philo.h"

int dead_loop(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->dead == 1)
        return (pthread_mutex_unlock(philo->dead_lock), 1);
    pthread_mutex_unlock(philo->dead_lock);
    return (0);
}

int ft_strlen(char *s)
{
    int i;

    i = 0;
    if(s == NULL)
        return (0);
    while(s[i] != '\0')
        i++;
    return (i);
}
size_t  ft_atoi(char *str)
{
    size_t  ret;
    int             sign;
    int             i;

    ret = 0;
    sign = 1;
    i = 0;
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
            || str[i] == '\f' || str[i] == '\r')
            i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
            i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        ret = ret * 10 + (str[i] - '0');
        i++;
    }
    return(ret * sign);
}

void    destroy_all(char *str, t_program *program, pthread_mutex_t *forks)
{
    int i;

    i = 0;
    if (str)
    {
        write(2, str, ft_strlen(str));
        write(2, "\n", 1);
    }
    pthread_mutex_destroy(&program->write_lock);
    pthread_mutex_destroy(&program->dead_lock);
    pthread_mutex_destroy(&program->meal_lock);
    while(i < program->philos[0].num_of_philos)
    {
        pthread_mutex_destroy(&forks[i]);
        i++;
    }
}

size_t  get_current_time(void)
{
    struct timeval  time;

    if (gettimeofday(&time, NULL) == -1)
            write(2, "gettimeofday() error\n", 22);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}