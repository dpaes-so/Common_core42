/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_calcA.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:39:20 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/02 15:10:48 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_max(t_stack **s)
{
	t_stack	*temp;
	int		n;

	n = (*s)->nbr;
	temp = (*s)->next;
	while (temp != NULL)
	{
		if (temp->nbr > n)
			n = temp->nbr;
		temp = temp->next;
	}
	temp = (*s);
	while (temp->nbr != n)
		temp = temp->next;
	return (temp);
}

void	double_rot(t_stack **a, t_stack **b, int moves_a, int moves_b)
{
	t_stack	*temp;

	temp = (*a);
	while (temp->cheap != 1)
		temp = temp->next;
	if (temp->index > ft_stsize(a) / 2)
		moves_a = ft_stsize(a) - temp->index;
	else
		moves_a = temp->index;
	if (temp->target->index > ft_stsize(b) / 2)
		moves_b = ft_stsize(b) - temp->target->index;
	else
		moves_b = temp->target->index;
	while (moves_a > 0 && moves_b > 0)
	{
		if (temp->index > ft_stsize(a) / 2 && temp->target->index > ft_stsize(b)
			/ 2)
			reverse_rotate_both(a, b);
		else if (temp->index < ft_stsize(a) / 2
			&& temp->target->index < ft_stsize(b) / 2)
			rotate_both(a, b);
		moves_a--;
		moves_b--;
	}
}

void	single_rot(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = (*a);
	while (temp->cheap != 1)
		temp = temp->next;
	if (temp->index > ft_stsize(a) / 2)
	{
		while ((*a)->cheap != temp->cheap)
			reverse_rotate(a, 'a');
	}
	else
	{
		while ((*a)->cheap != temp->cheap)
			rotate(a, 'a');
	}
	if (temp->target->index > ft_stsize(b) / 2)
	{
		while ((*a)->target->nbr != (*b)->nbr)
			reverse_rotate(b, 'b');
	}
	else
	{
		while ((*a)->target->nbr != (*b)->nbr)
			rotate(b, 'b');
	}
}

void	push_swapa(t_stack **a, t_stack **b)
{
	int	moves_a;
	int	moves_b;

	moves_a = 0;
	moves_b = 0;
	double_rot(a, b, moves_a, moves_b);
	single_rot(a, b);
}
