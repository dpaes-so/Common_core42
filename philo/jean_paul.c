/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jean_paul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:30:13 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/08/06 19:31:18 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_roundtable *table, int i)
{
	long	now;
	long	last_meal;

	pthread_mutex_lock(&table->philos[i].meal_mutex);
	last_meal = table->philos[i].time_from_last_meal;
	pthread_mutex_unlock(&table->philos[i].meal_mutex);
	now = current_timestamp();
	if (now - last_meal > table->time_to_die)
	{
		pthread_mutex_lock(&table->dead_mutex);
		table->dead = 1;
		pthread_mutex_unlock(&table->dead_mutex);
		pthread_mutex_lock(&table->print_mutex);
		printf("%ld %d died\n", current_timestamp() - table->start,
			table->philos[i].id);
		pthread_mutex_unlock(&table->print_mutex);
		return (0);
	}
	return (1);
}

int	check_full(t_roundtable *table)
{
	if (table->meals_lim > 0)
	{
		pthread_mutex_lock(&table->full_mutex);
		if (table->full == table->chairs)
		{
			pthread_mutex_lock(&table->dead_mutex);
			pthread_mutex_lock(&table->print_mutex);
			table->dead = 1;
			pthread_mutex_unlock(&table->dead_mutex);
			printf("All philos are Full\n");
			pthread_mutex_unlock(&table->full_mutex);
			pthread_mutex_unlock(&table->print_mutex);
			return (0);
		}
		pthread_mutex_unlock(&table->full_mutex);
	}
	return (1);
}

void	*monitor(void *arg)
{
	t_roundtable	*table;

	table = (t_roundtable *)arg;
	while (1)
	{
		if (!check_full(table))
			return (NULL);
		pthread_mutex_lock(&table->dead_mutex);
		if(table->dead == 1)
			return(pthread_mutex_unlock(&table->dead_mutex),NULL);
		pthread_mutex_unlock(&table->dead_mutex);
		usleep(100);
	}
	return (NULL);
}

void	pthread_life(t_roundtable *table)
{
	pthread_t	monitor_id;
	int			i;

	pthread_create(&monitor_id, NULL, monitor, table);
	pthread_join(monitor_id, NULL);
	i = 0;
	while (i < table->chairs)
	{
		pthread_join(table->philos[i].thread_id, NULL);
		i++;
	}
	i = 0;
	while (i < table->chairs)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->dead_mutex);
	pthread_mutex_destroy(&table->full_mutex);
	free(table->forks);
	free(table->philos);
}

int	main(int ac, char **av)
{
	t_roundtable	table;
	int				i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		if (parser(av))
		{
			if (dinner_setup(&table, ac, av) < 0)
				return (0);
			character_creation(&table);
			while (i < table.chairs)
			{
				pthread_create(&table.philos[i].thread_id, NULL, playthrough,
					&table.philos[i]);
				i++;
			}
			pthread_life(&table);
		}
		else
			printf("parser error\n");
	}
	else
		write(2, "Invalid input\n", 15);
}
