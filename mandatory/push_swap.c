/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wait-bab <wait-bab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 07:46:08 by wait-bab          #+#    #+#             */
/*   Updated: 2024/05/21 07:46:09 by wait-bab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int ac, char **av)
{
    t_var *var;

    if (ac <= 1)
        return 0;

    var = malloc(sizeof(t_var));
    if (var == NULL)
    {
        free(var);
        return 0;
    }
    var->stk_a = extra_spleted_v2(NULL, av, ac, var);
    if (var->stk_a == NULL) {
        free(var);
        return 0;
    }
    var->stk_b = NULL;
    index_fonc(var);
    if_sorted(var);
    sort(var);
    free_all(&var->stk_a ,var);
    return (0);
}