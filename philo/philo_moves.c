/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         ###   */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:13:34 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/08/09 21:30:05 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_usleep(long duration, t_roundtable *table)
{
	long long	start;

	if (duration <= 0)
		return ;
	start = current_timestamp();
	while ((current_timestamp() - start) < duration)
	{
		pthread_mutex_lock(&table->dead_mutex);
		if (table->dead)
		{
			pthread_mutex_unlock(&table->dead_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->dead_mutex);
		usleep(100);
	}
}

void	philo_activity(t_philo *philo, char *s)
{
	long	time;

	pthread_mutex_lock(&philo->table->dead_mutex);
	pthread_mutex_lock(&philo->table->print_mutex);
	if (philo->table->dead)
	{
		pthread_mutex_unlock(&philo->table->dead_mutex);
		pthread_mutex_unlock(&philo->table->print_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->table->dead_mutex);
	time = current_timestamp() - philo->table->start;
	printf("%ld %d %s\n", time, philo->id, s);
	pthread_mutex_unlock(&philo->table->print_mutex);
}

int	pick_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->dead_mutex);
	if (philo->table->dead)
	{
		pthread_mutex_unlock(&philo->table->dead_mutex);
		return (0);
	}
	pthread_mutex_unlock(&philo->table->dead_mutex);
	if (philo->table->chairs == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		philo_activity(philo, "has taken a fork");
		philo_usleep(philo->table->time_to_die * 2, philo->table);
		return (pthread_mutex_unlock(philo->left_fork), 0);
	}
	if (philo->id % 2 != 0)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	philo_activity(philo, "has taken a fork");
	if (philo->id % 2 != 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	philo_activity(philo, "has taken a fork");
	return (1);
}

void	dinner_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->time_from_last_meal = current_timestamp();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	philo_activity(philo, "is eating");
	if (philo->table->meals_lim > 0
		&& philo->meals_eaten == philo->table->meals_lim)
	{
		pthread_mutex_lock(&philo->table->full_mutex);
		philo->table->full += 1;
		pthread_mutex_unlock(&philo->table->full_mutex);
	}
	philo_usleep(philo->table->time_to_eat, philo->table);
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	*playthrough(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0 && philo->table->chairs != 1)
		philo_usleep(philo->table->time_to_eat / 2, philo->table);
	while (1)
	{
		if (!pick_forks(philo))
			return (NULL);
		dinner_time(philo);
		pthread_mutex_lock(&philo->table->dead_mutex);
		if (philo->table->dead)
			return (pthread_mutex_unlock(&philo->table->dead_mutex), NULL);
		pthread_mutex_unlock(&philo->table->dead_mutex);
		philo_activity(philo, "is sleeping");
		philo_usleep(philo->table->time_to_sleep, philo->table);
		philo_activity(philo, "is thinking");
		if (philo->table->chairs % 2 != 0)
			philo_usleep((philo->table->time_to_eat * 2)
				- philo->table->time_to_sleep, philo->table);
		else
			philo_usleep(philo->table->time_to_eat
				- philo->table->time_to_sleep, philo->table);
	}
	return (NULL);
}
