/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:30:24 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/03 13:51:17 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	checkdup(t_stack **A, t_stack *node)
{
	t_stack	*temp;

	temp = (*A);
	while (temp != NULL)
	{
		if (node->nbr == temp->nbr)
		{
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int	checkstring(char *str)
{
	int	i;

	i = 0;
	while (((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
		&& str[i] != '\0')
	{
		i++;
	}
	if (str[0] == '-' && str[1])
	{
		return (1);
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}
// void	printlst(t_stack **lst)
// {
// 	t_stack	*temp;

// 	temp = (*lst);
// 	while (temp != NULL)
// 	{
// 		printf("NBR =%d \n", temp->nbr);
// 		temp = temp->next;
// 	}
// }
void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	while (i--)
		free(arr[i]);
	free(arr);
}
