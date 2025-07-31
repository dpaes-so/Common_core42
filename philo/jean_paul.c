#include "philo.h"

int dinner_setup(t_roundtable *table,int ac,char **av)
{
    int i;

    i = -1;
    table->chairs = ft_atoi(av[1]);
    table->time_to_die = ft_atoi(av[2]);
    table->time_to_eat = ft_atoi(av[3]);
    table->time_to_sleep = ft_atoi(av[4]);
    table->dead = 0;
    table->full = 0;
    if(ac == 6)
        table->meals_lim = ft_atoi(av[5]);
    else
        table->meals_lim = -1;
    table->forks = ft_calloc(table->chairs,sizeof(pthread_mutex_t));
    if (!table->forks)
        return (0);
    while(++i < table->chairs)
        pthread_mutex_init(&table->forks[i],NULL);
    pthread_mutex_init(&table->print_mutex,NULL);
    pthread_mutex_init(&table->dead_mutex, NULL);
    pthread_mutex_init(&table->full_mutex, NULL);
    table->start = current_timestamp();
    return(1);
}

void character_creation(t_roundtable *table)
{
    int id;

    table->philos = ft_calloc(table->chairs,sizeof(t_philo));
    id = -1;
    while(++id < table->chairs)
    {
        table->philos[id].id = id;
        table->philos[id].table = table;
        table->philos[id].left_fork = &table->forks[id];
        table->philos[id].right_fork = &table->forks[(id + 1) % table->chairs];
        table->philos[id].totals_meals = 0;
        table->philos[id].time_from_last_meal = table->start;
        table->philos[id].meals_eaten = 0;
        pthread_mutex_init(&table->philos[id].meal_mutex, NULL);

    }
}

// void print_philos(t_roundtable table)
// {
//     int i;

//     i = -1;
//     printf("Philosophers: %d\n", table.chairs);
//     printf("Time to die: %ld\n", table.time_to_die);
//     printf("Time to eat: %d\n", table.time_to_eat);
//     printf("Time to sleep: %d\n", table.time_to_sleep);
//     if (table.meals_lim > 0)
//         printf("Meals limit: %d\n", table.meals_lim);
//     else
//         printf("No meals limit set\n");
//     while(++i < table.chairs)
//     {
//         printf("id = %d\n",table.philos[i].id);
//     }
// }

void philo_usleep(long duration, t_roundtable *table)
{
    long long start = current_timestamp();

    while ((current_timestamp() - start) < duration)
    {
        pthread_mutex_lock(&table->dead_mutex);
        if (table->dead)
        {
            pthread_mutex_unlock(&table->dead_mutex);
            break;
        }
        pthread_mutex_unlock(&table->dead_mutex);
        usleep(100);
    }
}
void philo_activity(t_philo *philo, char *s)
{
    long time;

    pthread_mutex_lock(&philo->table->print_mutex);
    pthread_mutex_lock(&philo->table->dead_mutex);
    if (philo->table->dead)
    {
        pthread_mutex_unlock(&philo->table->dead_mutex);
        pthread_mutex_unlock(&philo->table->print_mutex);
        return;
    }
    pthread_mutex_unlock(&philo->table->dead_mutex);
    time = current_timestamp() - philo->table->start;
    printf("%ld %d %s\n", time, philo->id + 1, s);
    pthread_mutex_unlock(&philo->table->print_mutex);
}


void *playthrough(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    // printf("playtrough");
    if (philo->id % 2 != 0)
        philo_usleep(philo->table->time_to_eat / 2, philo->table);

    while (1)
    {
        // Check if someone is dead
        pthread_mutex_lock(&philo->table->dead_mutex);
        if (philo->table->dead)
        {
            pthread_mutex_unlock(&philo->table->dead_mutex);
            return NULL;
        }
        pthread_mutex_unlock(&philo->table->dead_mutex);
        if (philo->id % 2 != 0)
        {
            pthread_mutex_lock(philo->left_fork);
            philo_activity(philo, "has picked up a fork");
            pthread_mutex_lock(philo->right_fork);
            philo_activity(philo, "has picked up a fork");
        }
        else
        {
            pthread_mutex_lock(philo->right_fork);
            philo_activity(philo, "has picked up a fork");
            pthread_mutex_lock(philo->left_fork);
            philo_activity(philo, "has picked up a fork");
        }
        // Eat
        pthread_mutex_lock(&philo->meal_mutex);
        philo->time_from_last_meal = current_timestamp();
        philo->meals_eaten++;
        pthread_mutex_unlock(&philo->meal_mutex);
        philo_activity(philo, "is eating");
        if(philo->meals_eaten == philo->table->meals_lim)
        {
            pthread_mutex_lock(&philo->table->full_mutex);
            philo->table->full +=1;
            pthread_mutex_unlock(&philo->table->full_mutex);
        }
        philo_usleep(philo->table->time_to_eat, philo->table);
        // Put down forks
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
        // Sleep
        philo_activity(philo, "is sleeping");
        philo_usleep(philo->table->time_to_sleep, philo->table);
        // Think
        philo_activity(philo, "is thinking");
        if(philo->table->chairs % 2 != 0)
            philo_usleep(500,philo->table);
    }
    return NULL;
}

void *monitor(void *arg)
{
    int i;
    t_roundtable *table;
    long now;
    long last_meal;

    table = (t_roundtable *)arg;
    while (1)
    {
        i = 0;
        while (i < table->chairs)
        {
            if(table->meals_lim > 1)
            {
                pthread_mutex_lock(&table->full_mutex);
                if(table->full == table->chairs)
                {
                    pthread_mutex_lock(&table->dead_mutex);
                    table->dead = 1;
                    pthread_mutex_unlock(&table->dead_mutex);
                    pthread_mutex_unlock(&table->full_mutex);
                    return(NULL);
                }
                pthread_mutex_unlock(&table->full_mutex);
            }
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
                printf("%ld %d died\n", current_timestamp() - table->start, table->philos[i].id + 1);
                pthread_mutex_unlock(&table->print_mutex);
                return (NULL);
            }
            i++;
        }
        usleep(1000);
    }
    return NULL;
}

int main(int ac,char **av)
{
    t_roundtable table;
    pthread_t monitor_id;
    int i;

    i = 0;
    if (ac == 5 || ac == 6) 
    {
        if(parser(av))
        {
            if(dinner_setup(&table,ac,av) < 0)
                return(0);
            character_creation(&table);
            while(i < table.chairs)
            {
                pthread_create(&table.philos[i].thread_id,NULL,playthrough,&table.philos[i]);
                i++;
            }
            pthread_create(&monitor_id,NULL,monitor,&table);
            pthread_join(monitor_id, NULL);
            i = 0;
            while(i < table.chairs)
            {
                pthread_join(table.philos[i].thread_id,NULL);
                i++;
            }
            i = 0;
            while(i < table.chairs)
            {
                pthread_mutex_destroy(&table.forks[i]);
                i++;
            }
            pthread_mutex_destroy(&table.print_mutex);
            pthread_mutex_destroy(&table.dead_mutex);
            pthread_mutex_destroy(&table.full_mutex);
            free(table.forks);
            free(table.philos);
        }
        else
            printf("sadge\n");
    }
    else
        write(2,"Invalid input\n",15);
}
