/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:31:19 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/02 15:38:12 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_cases(int f, int s, int t, t_stack **A)
{
	if (f > s && s > t && t < f)
	{
		rotate(A, 'a');
		swap(A, 'a');
	}
	else if (f > s && s < t && t < f)
		rotate(A, 'a');
	else if (f < s && s > t && t > f)
	{
		swap(A, 'a');
		rotate(A, 'a');
	}
	else if (f < s && s > t && t < f)
		reverse_rotate(A, 'a');
	else if (f > s && s < t && t > f)
		swap(A, 'a');
}

void	small_stack(t_stack **A)
{
	int	first;
	int	second;
	int	third;

	if (!(*A) || !(*A)->next)
		return ;
	first = (*A)->nbr;
	second = (*A)->next->nbr;
	if (!(*A)->next->next)
	{
		if (first > second)
			swap(A, 'a');
		return ;
	}
	third = (*A)->next->next->nbr;
	small_cases(first, second, third, A);
}
