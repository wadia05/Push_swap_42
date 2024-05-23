/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:44:05 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/21 07:48:41 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stk)
{
	int	first;
	int	second;
	int	third;

	first = (*stk)->data;
	second = (*stk)->next->data;
	third = (*stk)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stk);
	else if (first > second && second > third)
	{
		sa(stk);
		rrab(stk, 'a');
	}
	else if (first > second && second < third && first > third)
		rab(stk, 'a');
	else if (first < second && second > third && first < third)
	{
		sa(stk);
		rab(stk, 'a');
	}
	else if (first < second && second > third && first > third)
		rrab(stk, 'a');
}

int	ft_min(t_stack *stack)
{
	t_stack	*temp;
	int		min;

	temp = stack;
	min = temp->data;
	while (temp != NULL)
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return (min);
}

void	sort_5(t_stack **a, t_stack **b, int k)
{
	while (k > 3 && *a)
	{
		if (1 == position_min(*a, k / 2))
			rab(&(*a), 'a');
		else
			rrab(&(*a), 'a');
		if ((*a)->data == ft_min(*a))
		{
			pushb(a, b);
			k--;
		}
	}
	sort_3(a);
	pusha(a, b);
	pusha(a, b);
}

void	sort_2(t_stack **stk)
{
	sa(stk);
}

void	sort(t_var *v)
{
	int		i;
	t_stack	*tmp;

	tmp = v->stk_a;
	i = 0;
	while (tmp != NULL)
	{
		i++;
		v->stk_a->index = i;
		tmp = tmp->next;
	}
	if (i <= 1)
	{
		free_all(&v->stk_a,v);
		exit(0);
	}
	else if (i == 2)
		sort_2(&v->stk_a);
	else if (i == 3)
		sort_3(&(v->stk_a));
	else if (i <= 5)
		sort_5(&(v->stk_a), &(v->stk_b), i);
	else
		big_sort(v, i);
}
