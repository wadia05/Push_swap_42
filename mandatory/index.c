/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:44:26 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/21 07:47:45 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack **st, int n)
{
	int		i;
	t_stack	*k;

	i = 0;
	k = *st;
	while (k != NULL)
	{
		if (n > (k)->data)
			i++;
		k = (k)->next;
	}
	k = NULL;
	return (i);
}

void	index_fonc(t_var *v)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = v->stk_a;
	while (v->stk_a != NULL)
	{
		v->stk_a->index = i;
		i++;
		v->stk_a->sort_index = get_index(&tmp, v->stk_a->data);
		v->stk_a = v->stk_a->next;
	}
	v->stk_a = tmp;
	tmp = NULL;
}

void	if_sorted(t_var *v)
{
	t_stack *tmp;

	tmp = v->stk_a;
	while (tmp != NULL)
	{
		if (tmp->index != tmp->sort_index)
			return ;
		tmp = tmp->next;
	}
	free_all(&v->stk_a,v);
	exit(0);
}

int	position_min(t_stack *stk, int size)
{
	while (stk != NULL && size >= 0)
	{
		if (stk->data == ft_min(stk))
			return (1);
		size--;
		stk = stk->next;
	}
	return (0);
}
