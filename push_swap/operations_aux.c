/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:56:40 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/02 15:36:16 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*delete_lastnode(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*removed_node;

	if (*stack == NULL)
		return (NULL);
	if ((*stack)->next == NULL)
	{
		removed_node = *stack;
		*stack = NULL;
		return (removed_node);
	}
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	removed_node = temp->next;
	temp->next = NULL;
	return (removed_node);
}

t_stack	*delete_1stnode(t_stack **stack)
{
	t_stack	*removed_node;

	if (*stack == NULL)
		return (NULL);
	removed_node = *stack;
	*stack = (*stack)->next;
	removed_node->next = NULL;
	return (removed_node);
}

// not quite but no more space(used on main)
void	finalrotate(t_stack **s)
{
	t_stack	*min;
	t_stack	*temp;
	int		size;

	size = ft_stsize(s);
	temp = (*s);
	min = find_min(s);
	add_index(&temp);
	while (temp->nbr != min->nbr)
		temp = temp->next;
	if (temp->index > size / 2)
	{
		while ((*s)->nbr != min->nbr)
			reverse_rotate(s, 'a');
	}
	else
	{
		while ((*s)->nbr != min->nbr)
			rotate(s, 'a');
	}
}

void	rotate_both(t_stack **a, t_stack **b)
{
	t_stack	*node;
	t_stack	*node2;

	node = delete_1stnode(a);
	ft_stadd_back(a, node);
	node2 = delete_1stnode(b);
	ft_stadd_back(b, node2);
	write(1, "rr", 2);
	write(1, "\n", 1);
}
