/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaes-so <dpaes-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:31:54 by dpaes-so          #+#    #+#             */
/*   Updated: 2025/01/02 15:30:20 by dpaes-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "limits.h"
# include "string.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				cost;
	int				cheap;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;
// after calc
t_stack				*find_max(t_stack **s);
void				double_rot(t_stack **a, t_stack **b, int moves_a,
						int moves_b);
void				single_rot(t_stack **a, t_stack **b);
void				push_swapa(t_stack **a, t_stack **b);
// calculationsA
void				add_index(t_stack **s);
void				find_target1(t_stack **a, t_stack **b);
void				cost_calc1(t_stack **A, t_stack **B);
void				find_cheap(t_stack **a);
void				calculations1(t_stack **A, t_stack **B);
// calculationsB
t_stack				*find_min(t_stack **s);
void				find_target2(t_stack **a, t_stack **b);
void				push_swap2(t_stack **a, t_stack **b);
void				calculations2(t_stack **A, t_stack **B);
// func aux
void				free_stack(t_stack *stack);
int					checkstring(char *str);
int					checkdup(t_stack **A, t_stack *node);
void				printlst(t_stack **lst);
void				free_array(char **arr);
// main
void				sort_stacks(t_stack **A, t_stack **B);
void				start_sort(t_stack **A, t_stack **B);
int					start_stack(t_stack **A, char **av);
int					is_sorted(t_stack **A);
int					main(int ac, char **av);
// operations aux
t_stack				*delete_lastnode(t_stack **stack);
t_stack				*delete_1stnode(t_stack **stack);
// --used on main no more space
void				finalrotate(t_stack **s);
// --used on main no more space
void				rotate_both(t_stack **a, t_stack **b);
// operations
void				swap(t_stack **s, char c);
void				push(t_stack **s1, t_stack **s2, char c);
void				rotate(t_stack **s, char c);
void				reverse_rotate(t_stack **s, char c);
void				reverse_rotate_both(t_stack **a, t_stack **b);
// small sort
void				small_cases(int f, int s, int t, t_stack **A);
void				small_stack(t_stack **A);
// stack_func
void				ft_stadd_back(t_stack **lst, t_stack *new);
int					ft_stsize(t_stack **lst);
void				ft_stadd_front(t_stack **lst, t_stack *new);
// main aux
void				writeerror(void);
int					is_number_valid(char *str);
// extra stuff is from my libft
#endif
