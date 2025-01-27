/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:30:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/02 15:38:19 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*buffer;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	buffer = *lst;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = new;
	new->prev = buffer;
}

int	ft_stsize(t_stack **lst)
{
	int		i;
	t_stack	*buffer;

	if (lst == NULL)
		return (0);
	i = 0;
	buffer = *(lst);
	while (buffer != NULL)
	{
		buffer = buffer->next;
		i++;
	}
	return (i);
}

void	ft_stadd_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}
