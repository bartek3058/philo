#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 300

typedef struct s_philo
{
    pthread_t       thread;
    int                     id;
    int                     eating;
    int                     meals_eaten;
    size_t          last_meal;
    size_t          time_to_die;
    size_t          time_to_eat;
    size_t          time_to_sleep;
    size_t          start_time;
    int                     num_of_philos;
    int                     num_times_to_eat;
    int                     *dead;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *write_lock;
    pthread_mutex_t *dead_lock;
    pthread_mutex_t *meal_lock;
}                               t_philo;
typedef struct s_program
{
    int                         dead_flag;
    pthread_mutex_t dead_lock;
    pthread_mutex_t meal_lock;
    pthread_mutex_t write_lock;
    t_philo                 *philos;
}                                   t_program;

int main(int argc, char **argv);
int check_valid_args(char **argv);
int check_arg_number(char *str);
void init_philo(t_philo *philos, t_program *program, pthread_mutex_t *forks, char **argv);
size_t  get_current_time(void);
void    destroy_all(char *str, t_program *program, pthread_mutex_t *forks);
size_t  ft_atoi(char *str);
int ft_strlen(char *s);

