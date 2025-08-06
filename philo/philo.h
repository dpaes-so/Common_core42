/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:15:23 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/08/06 18:28:55 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct t_philo	t_philo;

typedef struct t_roundtable
{
	int					chairs;
	long				time_to_die;
	int					time_to_day;
	int					time_to_eat;
	int					time_to_sleep;
	int					meals_lim;
	int					full;
	long				start;
	int					dead;

	pthread_mutex_t		*forks;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		dead_mutex;
	pthread_mutex_t		full_mutex;
	t_philo				*philos;

}						t_roundtable;

typedef struct t_philo
{
	int					id;
	int					totals_meals;
	long				time_from_last_meal;
	int					meals_eaten;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		meal_mutex;
	pthread_t			thread_id;
	t_roundtable		*table;

}						t_philo;

long					ft_atol(const char *nptr);
void					*ft_calloc(size_t num, size_t size);
long					current_timestamp(void);
int						parser(char **av);
void					*playthrough(void *arg);
int						dinner_setup(t_roundtable *table, int ac, char **av);
void					character_creation(t_roundtable *table);
void					fmalloc(t_roundtable *table, char *str, int code);

#endif