#include "philo.h"

void init_forks(pthread_mutex_t *forks, int philo_num)
{
    int i;

    i = 0;
    while (i < philo_num)
    {
        pthread_mutex_init(&forks[i], NULL);
        i++;
    }
}

void init_program(t_program *program, t_philo *philos)
{
    program->dead_flag = 0;
    program->philos = philos;
    pthread_mutex_init(&program->write_lock, NULL);
    pthread_mutex_init(&program->dead_lock, NULL);
    pthread_mutex_init(&program->meal_lock, NULL);
}

int check_arg_number(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if(!(str[i] >= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

int check_valid_args(char **argv)
{
    if(ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
            || check_arg_number(argv[1]) == 1)
            return (write(2, "Invalid philosophers number\n", 29), 1);
    if(ft_atoi(argv[2]) <= 0 || check_arg_number(argv[2]) == 1)
            return (write(2, "Invalid time to die\n", 21), 1);
    if(ft_atoi(argv[3]) <= 0 || check_arg_number(argv[3]) == 1)
            return (write(2, "Invalid time to eat\n", 21), 1);
    if(ft_atoi(argv[4]) <= 0 || check_arg_number(argv[4]) == 1)
            return (write(2, "Invalid time to sleep\n", 23), 1);
    if(argv[5] && (ft_atoi(argv[5]) <= 0 
            || check_arg_number(argv[5]) == 1))
            return (write(2, "Invalid number philo must eat\n", 30), 1);
    return (0);
}

int main(int argc, char **argv)
{
    t_program   program;
    t_philo     philos[PHILO_MAX];
    pthread_mutex_t forks[PHILO_MAX];

    if(argc != 5 && argc != 6)
        return(write(2, "Wrong argument count\n", 22), 1);
    if (check_valid_args(argv) == 1)
        return(1);
    init_program(&program, philos);
    init_forks(forks, ft_atoi(argv[1]));
    init_philo(philos, &program, forks, argv);
    thread_create(&program, forks);
    destroy_all(NULL, &program, forks);
    return (0);
}