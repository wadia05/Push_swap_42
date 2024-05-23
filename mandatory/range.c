/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:46:38 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/21 07:47:29 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_range(int size)
{
	int	range;

	range = (0.05 * size) + 10.5;
	return (range);
}

int	ft_max(t_stack *stack)
{
	t_stack	*temp;
	int		max;

	temp = stack;
	max = temp->data;
	while (temp != NULL)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	return (max);
}

void	big_sort(t_var *v, int size)
{
	int	max_range;
	int	min_range;

	min_range = 0;
	max_range = best_range(size);
	while (v->stk_a != NULL)
	{
		if (v->stk_a->sort_index < min_range)
		{
			pushb(&v->stk_a, &v->stk_b);
			rab(&v->stk_b, 'b');
			min_range++;
		}
		else if (v->stk_a->sort_index <= min_range + max_range)
		{
			pushb(&v->stk_a, &v->stk_b);
			min_range++;
		}
		else
			rab(&v->stk_a, 'a');
	}
	back_sort(v, size);
}

int	position(t_stack *stk, int size)
{
	while (stk != NULL && size >= 0)
	{
		if (stk->data == ft_max(stk))
			return (1);
		size--;
		stk = stk->next;
	}
	return (0);
}

void	back_sort(t_var *v, int size)
{
	while (v->stk_b != NULL)
	{
		v->j = position(v->stk_b, size / 2);
		while (v->stk_b->data != ft_max(v->stk_b))
		{
			if (v->j == 1)
				rab(&v->stk_b, 'b');
			else if (v->j == 0)
				rrab(&v->stk_b, 'b');
		}
		pusha(&v->stk_a, &v->stk_b);
		size--;
	}
}
