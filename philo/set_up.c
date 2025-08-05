#include "philo.h"

int	dinner_setup(t_roundtable *table, int ac, char **av)
{
	int	i;

	i = -1;
	table->chairs = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->dead = 0;
	table->full = 0;
	if (ac == 6)
		table->meals_lim = ft_atoi(av[5]);
	else
		table->meals_lim = -1;
	table->forks = ft_calloc(table->chairs, sizeof(pthread_mutex_t));
	if (!table->forks)
		fmalloc(table,"Malloc Failed",1);
	while (++i < table->chairs)
		pthread_mutex_init(&table->forks[i], NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	pthread_mutex_init(&table->dead_mutex, NULL);
	pthread_mutex_init(&table->full_mutex, NULL);
	table->start = current_timestamp();
	return (1);
}

void	character_creation(t_roundtable *table)
{
	int id;

	table->philos = ft_calloc(table->chairs,sizeof(t_philo));
    if(!table->philos)
        fmalloc(table,"Malloc Failed",2);
	id = 0;
	while (id < table->chairs)
	{
		table->philos[id].id = id + 1;
		table->philos[id].table = table;
		table->philos[id].left_fork = &table->forks[id];
		table->philos[id].right_fork = &table->forks[(id + 1) % table->chairs];
		table->philos[id].totals_meals = 0;
		table->philos[id].time_from_last_meal = table->start;
		table->philos[id].meals_eaten = 0;
		pthread_mutex_init(&table->philos[id].meal_mutex, NULL);
        id++;
	}
}

void fmalloc(t_roundtable *table, char *str,int code)
{
    int i;

    i = 0;
    while(i < table->chairs &&  code > 2)
    {
        pthread_mutex_destroy(&table->forks[i]);
        pthread_mutex_destroy(&table->philos[i].meal_mutex);
        i++;
    }
    if(code > 1)
    {
        pthread_mutex_destroy(&table->print_mutex);
        pthread_mutex_destroy(&table->dead_mutex);
        pthread_mutex_destroy(&table->full_mutex);
        free(table->forks);
        free(table->philos);
    }
    while(*str)
        write(2,str++,1);
    exit(1);
}
