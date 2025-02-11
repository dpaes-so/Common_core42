/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:00 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/10 18:19:17 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
void pipex()
{
    ft_printf("IM ACCESIBLE");
    
}
int main(int ac,char **av)
{
    if(ac == 5)
    {
        if(access(av[1],F_OK))
            exit(0);
        pipex();
    }
    ft_printf("\n");
}
