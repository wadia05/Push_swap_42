/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:46:24 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/21 07:56:58 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
#include <stdio.h>
#include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				sort_index;
	struct s_stack	*next;
}					t_stack;
typedef struct s_var
{
	int				i;
	int				j;
	long			num;
	int				nega;

	t_stack			*node;

	t_stack			*temp;
	t_stack			*head;

	t_stack			*stk_a;
	t_stack			*stk_b;
}					t_var;
// creat stack and chek error fonction
t_stack				*create_stack_node(int data_num, t_var *var, t_stack **hed);
void	free_all(t_stack **hed,t_var *v);
void				free_err(t_stack **hed,t_var *v);
t_stack				*extra_spleted_v2(t_stack *header, char **av, int ac,
						t_var *v);
// moves fonction
void				sa(t_stack **stk);
void				rab(t_stack **stk, char k);
void				rrab(t_stack **stk, char k);
void				pusha(t_stack **stk_a, t_stack **stk_b);
void				pushb(t_stack **stk_a, t_stack **stk_b);
//
void				sort(t_var *v);
void				sort_3(t_stack **stk);
void				sort_5(t_stack **a, t_stack **b, int k);
void				big_sort(t_var *v, int size);
void				index_fonc(t_var *v);
void				back_sort(t_var *v, int size);
int					ft_max(t_stack *stack);
int					ft_min(t_stack *stack);
int					position_min(t_stack *stk, int size);
void				if_sorted(t_var *v);
int					position(t_stack *stk, int size);

#endif
