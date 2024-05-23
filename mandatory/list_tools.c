/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:45:24 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/21 07:45:26 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*double_num(t_stack *stk, t_var *v)
{
	t_stack	*tmp;

	tmp = stk;
	while (tmp != NULL)
	{
		if (tmp->data == (v->num * v->nega))
		{
			free_err(&stk,v);
		}
		tmp = tmp->next;
	}
	return (stk);
}

t_stack	*create_stack_node(int data_num, t_var *var, t_stack **hed)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!hed || var->num * var->nega > INT_MAX || var->num
		* var->nega < INT_MIN)
	{
		free_err(&*hed,var);
		exit(write(2, "Error\n", 6));
	}
	tmp = *hed;
	double_num(tmp, var);
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->data = data_num * var->nega;
	node->next = NULL;
	if (*hed == NULL)
		*hed = node;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (node);
}

void	free_all(t_stack **hed,t_var *v)
{	
	t_stack	*current;
	t_stack	*next;

	current = *hed;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*hed = NULL;
	free(v);
}

void free_err(t_stack **hed, t_var *v)
{
	t_stack	*current;
	t_stack	*next;

	current = *hed;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*hed = NULL;
    free(v);
    exit(write(2, "Error\n", 6));
}

