/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:45:49 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/02 15:35:24 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s, char c)
{
	int	swap;

	swap = (*s)->nbr;
	(*s)->nbr = (*s)->next->nbr;
	(*s)->next->nbr = swap;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push(t_stack **s1, t_stack **s2, char c)
{
	t_stack	*node;

	if (!s1)
		return ;
	node = delete_1stnode(s1);
	ft_stadd_front(s2, node);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate(t_stack **s, char c)
{
	t_stack	*node;

	node = delete_1stnode(s);
	ft_stadd_back(s, node);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_stack **s, char c)
{
	t_stack	*node;

	node = delete_lastnode(s);
	ft_stadd_front(s, node);
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*node2;

	node = delete_lastnode(a);
	ft_stadd_front(a, node);
	node2 = delete_lastnode(b);
	ft_stadd_front(b, node2);
	write(1, "rrr", 3);
	write(1, "\n", 1);
}
