/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:13:34 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/08/06 19:09:45 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	bedtime(long duration, t_philo *philo)
{
	long long	start;
	long		last;

	if (duration < 0)
		return (1);
	start = current_timestamp();
	while ((current_timestamp() - start) < duration)
	{
		usleep(100);

		/* read last meal under meal_mutex */
		pthread_mutex_lock(&philo->meal_mutex);
		last = philo->time_from_last_meal;
		pthread_mutex_unlock(&philo->meal_mutex);

		/* check and set dead under dead_mutex, but don't hold dead_mutex while printing */
		pthread_mutex_lock(&philo->table->dead_mutex);
		if ((current_timestamp() - last > philo->table->time_to_die) && philo->table->dead == 0)
		{
			philo->table->dead = 1;
			pthread_mutex_unlock(&philo->table->dead_mutex);

			pthread_mutex_lock(&philo->table->print_mutex);
			printf("%ld %d died\n", current_timestamp() - philo->table->start, philo->id);
			pthread_mutex_unlock(&philo->table->print_mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo->table->dead_mutex);
	}
	return (1);
}

void	philo_usleep(long duration, t_roundtable *table)
{
	long long	start;

	if (duration < 0)
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
	int dead;
	long time;

	pthread_mutex_lock(&philo->table->dead_mutex);
	dead = philo->table->dead;
	pthread_mutex_unlock(&philo->table->dead_mutex);

	if (dead)
		return;

	pthread_mutex_lock(&philo->table->print_mutex);
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
		/* single philosopher will die waiting for second fork — simulate wait then release */
		bedtime(philo->table->time_to_die * 2, philo);
		pthread_mutex_unlock(philo->left_fork);
		return (0);
	}

	/* lock forks in an order that avoids contention: odd picks left then right, even picks right then left */
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

int	dinner_time(t_philo *philo)
{
	/* update last meal under meal_mutex */
	pthread_mutex_lock(&philo->meal_mutex);
	philo->time_from_last_meal = current_timestamp();
	pthread_mutex_unlock(&philo->meal_mutex);

	philo->meals_eaten++;
	philo_activity(philo, "is eating");

	if (philo->meals_eaten == philo->table->meals_lim && philo->table->meals_lim > 0)
	{
		pthread_mutex_lock(&philo->table->full_mutex);
		philo->table->full += 1;
		pthread_mutex_unlock(&philo->table->full_mutex);
	}

	/* sleep while checking for death */
	if (!bedtime(philo->table->time_to_eat, philo))
	{
		/* ensure forks unlocked before returning */
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
		return (0);
	}

	/* release forks after eating */
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
	return (1);
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
		if(!dinner_time(philo))
			return (NULL);
		philo_activity(philo, "is sleeping");
		// printf("Before mf go sleep id = %d\n", philo->id);
		if (!bedtime(philo->table->time_to_sleep,philo))
			return (NULL);
		// printf("after sleep philo id = %d\n", philo->id);
		philo_activity(philo, "is thinking");
		if (philo->table->chairs % 2 != 0)
			if(!bedtime((philo->table->time_to_eat * 2)- philo->table->time_to_sleep, philo))
				return (NULL);
		else
			if(!bedtime(philo->table->time_to_eat- philo->table->time_to_sleep, philo))
				return (NULL);
	}
	return (NULL);
}
