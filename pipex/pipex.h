/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:23:36 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/02/12 15:19:10 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "includes/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// aux
void	freetrix(char **matrix);
char	**path_finder(char **av, char **envp);
#endif