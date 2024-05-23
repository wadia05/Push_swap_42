/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:45:43 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/21 07:49:22 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stk)
{
	t_stack	*tmp;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	tmp = *stk;
	*stk = (*stk)->next;
	tmp->next = (*stk)->next;
	(*stk)->next = tmp;
	tmp = NULL;
	write(1, "sa\n", 3);
}

void	rab(t_stack **stk, char k)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	tmp = *stk;
	*stk = (*stk)->next;
	last = *stk;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	tmp = NULL;
	last = NULL;
	if (k == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rrab(t_stack **stk, char k)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stk == NULL || (*stk)->next == NULL)
		return ;
	last = *stk;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *stk;
	*stk = last;
	tmp = NULL;
	last = NULL;
	if (k == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	pushb(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*tmp;

	if (*stk_a == NULL)
		return ;
	tmp = *stk_a;
	*stk_a = (*stk_a)->next;
	tmp->next = *stk_b;
	*stk_b = tmp;
	write(1, "pb\n", 3);
}

void	pusha(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*tmp;

	if (*stk_b == NULL)
		return ;
	tmp = *stk_b;
	*stk_b = (*stk_b)->next;
	tmp->next = *stk_a;
	*stk_a = tmp;
	write(1, "pa\n", 3);
}
