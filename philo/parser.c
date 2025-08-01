#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}

int parser(char **av)
{
    int i;
    int j;

    i = 0;
    while(av[++i])
    {
        j = 0;
        if(ft_atoi(av[i]) <= 0)
            return (0);
        while(av[i][j])
        {
            if(ft_isdigit(av[i][j]))
                j++;
            else
                return(0);
        }
    }
    return(1);
}