/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 17:27:02 by sdiego            #+#    #+#             */
/*   Updated: 2020/08/01 19:46:19 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack_node	*find_min_num(t_stack *a)
{
	t_stack_node	*tmp;
	t_stack_node	*min;
	int				min_num;

	tmp = a->head;
	min_num = FALSE;
	min = NULL;

	while (tmp != NULL)
	{
		if (tmp->index == -1 && (min_num == FALSE || tmp->nbr < min->nbr))
		{
			min_num = TRUE;
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

/*
** Give each number on the stack its own index
*/
void	give_index(t_stack *a)
{
	size_t	index;
	t_stack_node	*tmp;

	index = 0;
	while ((tmp = find_min_num(a)))
	{
		tmp->index = index;
		index++;
	}
}
