/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculationsA.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:58:33 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/02 15:28:57 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index(t_stack **s)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = (*s);
	while (temp != NULL)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	find_target1(t_stack **a, t_stack **b)
{
	t_stack	*tempa;
	t_stack	*tempb;
	t_stack	*target;
	long	check;

	tempa = (*a);
	while (tempa != NULL)
	{
		check = LONG_MIN;
		tempb = (*b);
		while (tempb != NULL)
		{
			if ((tempa->nbr > tempb->nbr) && (tempb->nbr > check))
			{
				check = tempb->nbr;
				target = tempb;
			}
			tempb = tempb->next;
		}
		if (check != LONG_MIN)
			tempa->target = target;
		else
			tempa->target = find_max(b);
		tempa = tempa->next;
	}
}

void	cost_calc1(t_stack **A, t_stack **B)
{
	t_stack	*tempa;
	int		lena;
	int		lenb;

	lena = ft_stsize(A);
	lenb = ft_stsize(B);
	tempa = (*A);
	while (tempa != NULL)
	{
		if (tempa->index > lena / 2)
			tempa->cost = lena - tempa->index;
		else
			tempa->cost = tempa->index;
		if (tempa->target->index > 0)
		{
			if (!(tempa->target->index > lenb / 2))
				tempa->cost += tempa->target->index;
			else
				tempa->cost += lenb - tempa->target->index;
		}
		tempa = tempa->next;
	}
}

void	find_cheap(t_stack **a)
{
	t_stack	*tempa;
	t_stack	*cheap;
	int		best;

	tempa = (*a);
	cheap = tempa;
	best = tempa->cost;
	while (tempa != NULL)
	{
		tempa->cheap = 0;
		tempa = tempa->next;
	}
	tempa = (*a);
	while (tempa != NULL)
	{
		if (best > tempa->cost)
		{
			best = tempa->cost;
			cheap = tempa;
		}
		tempa = tempa->next;
	}
	cheap->cheap = 1;
}

void	calculations1(t_stack **A, t_stack **B)
{
	add_index(A);
	add_index(B);
	find_target1(A, B);
	cost_calc1(A, B);
	find_cheap(A);
}
