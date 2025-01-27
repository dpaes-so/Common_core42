/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:28:59 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/07 10:51:44 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **A, t_stack **B)
{
	int	size;

	size = ft_stsize(A);
	if (size-- > 3 && !is_sorted(A))
		push(A, B, 'b');
	if (size-- > 3 && !is_sorted(A))
		push(A, B, 'b');
	while (size-- > 3 && !is_sorted(A))
	{
		calculations1(A, B);
		push_swapa(A, B);
		push(A, B, 'b');
	}
	small_stack(A);
	while (*B)
	{
		calculations2(A, B);
		push_swap2(A, B);
	}
	finalrotate(A);
}

void	start_sort(t_stack **A, t_stack **B)
{
	int	size;

	size = ft_stsize(A);
	if (size <= 3)
		small_stack(A);
	else if (size > 3)
		sort_stacks(A, B);
}

int	start_stack(t_stack **A, char **av)
{
	int		n;
	int		i;
	t_stack	*node;

	i = -1;
	while (av[++i])
	{
		if (!checkstring(av[i]) || !is_number_valid(av[i]) || !*av[i])
			return (0);
		n = ft_atoi(av[i]);
		node = malloc(sizeof(t_stack));
		if (!node)
			return (0);
		node->nbr = n;
		node->next = NULL;
		if (!checkdup(A, node))
		{
			free(node);
			return (0);
		}
		ft_stadd_back(A, node);
	}
	if (i == 0)
		return (0);
	return (1);
}

int	is_sorted(t_stack **A)
{
	t_stack	*temp;
	int		f;
	int		s;

	temp = (*A);
	while (temp->next != NULL)
	{
		f = temp->nbr;
		s = temp->next->nbr;
		if (f > s)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		f;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (ac == 2)
		{
			av = ft_split(av[1], ' ');
			f = start_stack(&a, av);
		}
		else
			f = start_stack(&a, av + 1);
		if (f && !is_sorted(&a))
			start_sort(&a, &b);
		else if (!f)
			writeerror();
	}
	free_stack(a);
	free_stack(b);
	if (ac == 2)
		free_array(av);
}
