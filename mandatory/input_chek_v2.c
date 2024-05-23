/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_chek_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:45:11 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/21 07:45:17 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_var(t_var *var)
{
	var->i = 1;
	var->j = 0;
	var->nega = 1;
	var->num = 0;
}

long	validation_input(char bf, char af, char cur, t_var *v)
{
	if ((bf >= '0' && bf <= '9') && (cur == '-' || cur == '+'))
		free_err(&v->head,v);
	else if ((cur == '-' || cur == '+') && (af >= '0' && af <= '9'))
	{
		if (cur == '-')
			v->nega = -1;
	}
	else if ((cur == '-' || cur == '+') && (af != '-' || af != '+'))
		free_err(&v->head,v);
	else if ((cur == '-' || cur == '+') && (af == ' ' || af == '\0'))
		free_err(&v->head,v);
	else if (cur == ' ' || cur == '+' || cur == '-')
		return (v->num);
	else if (cur >= '0' && cur <= '9')
		v->num = v->num * 10 + (cur - '0');
	else
	{

		free_err(&v->node,v);
	}
	return (v->num);
}

void	process_string(char *str, t_var *v, t_stack **header, t_stack **tmp)
{

	while (str[v->j] == ' ')
		v->j++;
	if (str[v->j] == '\0')
		free_err(&*header,v);
	while (str[v->j] != '\0')
	{
		v->num = validation_input(str[v->j - 1], str[v->j + 1], str[v->j], v);
		if (str[v->j] != ' ' && (str[v->j + 1] == ' ' || str[v->j + 1] == '\0'))
		{
			v->node = create_stack_node(v->num, v, tmp);
			if (*header == NULL)
			{
				*header = v->node;
				v->head = v->node;
			}
			v->num = 0;
			v->nega = 1;
		}
		v->j++;
	}
	v->j = 0;
}

t_stack	*extra_spleted_v2(t_stack *header, char **av, int ac, t_var *v)
{
	t_stack	*tmp;

	tmp = NULL;
	int_var(v);
	header = NULL;
	while (v->i < ac)
	{
		process_string(av[v->i], v, &header, &tmp);
		v->i++;
	}

	return (header);
}


