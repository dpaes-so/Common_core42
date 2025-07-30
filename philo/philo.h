#ifndef PHILO_H

#define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
#include <time.h>

typedef struct t_philo t_philo;

typedef struct t_roundtable
{
    int chairs;
    long time_to_die;
    int time_to_day;
    int time_to_eat;
    int time_to_sleep;
    int meals_lim;
    long start;
    int dead;

    pthread_mutex_t *forks;
    pthread_mutex_t print_mutex;
    pthread_mutex_t dead_mutex;
    t_philo *philos;

} t_roundtable;

typedef struct t_philo
{
    int id;
    int totals_meals;
    long time_from_last_meal;
    int meals_eaten;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t meal_mutex;
    pthread_t thread_id;
    t_roundtable *table;

} t_philo;

int	ft_atoi(const char *str);
void	*ft_calloc(size_t num, size_t size);
long current_timestamp(void);
int parser(char **av);

#endif