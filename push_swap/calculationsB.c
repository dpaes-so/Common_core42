/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculationsB.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:22:29 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/02 15:29:48 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack **s)
{
	t_stack	*temp;
	int		n;

	n = (*s)->nbr;
	temp = (*s)->next;
	while (temp != NULL)
	{
		if (temp->nbr < n)
			n = temp->nbr;
		temp = temp->next;
	}
	temp = (*s);
	while (temp->nbr != n)
		temp = temp->next;
	return (temp);
}

void	find_target2(t_stack **a, t_stack **b)
{
	t_stack	*tempa;
	t_stack	*tempb;
	t_stack	*target;
	long	check;

	tempb = (*b);
	while (tempb != NULL)
	{
		check = LONG_MAX;
		tempa = (*a);
		while (tempa != NULL)
		{
			if ((tempa->nbr > tempb->nbr) && (tempa->nbr < check))
			{
				check = tempa->nbr;
				target = tempa;
			}
			tempa = tempa->next;
		}
		if (check != LONG_MAX)
			tempb->target = target;
		else
			tempb->target = find_min(a);
		tempb = tempb->next;
	}
}

void	push_swap2(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = (*b);
	if (temp->target->index > ft_stsize(a) / 2)
	{
		while ((*b)->target->nbr != (*a)->nbr)
			reverse_rotate(a, 'a');
	}
	else
	{
		while ((*b)->target->nbr != (*a)->nbr)
			rotate(a, 'a');
	}
	push(b, a, 'a');
}

void	calculations2(t_stack **A, t_stack **B)
{
	add_index(A);
	add_index(B);
	find_target2(A, B);
}
