/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_gt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:05:06 by sdiego            #+#    #+#             */
/*   Updated: 2020/09/01 09:58:48 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Is there a "FALSE" on stack A
** 1 - yes || 0 - no
*/
int	a_has_false(t_stack *a)
{
	t_stack_node	*tmp;
	if (a)
	{
		tmp = a->head;
		while (tmp != NULL)
		{
			if (tmp->keep == FALSE)
				return (1);
			tmp = tmp->next;
		}
	}
	return (0);
}

/*
** Do I need to do a swap_a ? gt mode
** 1 - yes ||  0 - no
*/
int	sa_need_gt(t_stack *a)
{
	size_t	markup_after;

	if (a && a->size >= 2)
	{
		swap_a_b(a);
		optimal_markup_gt(a);
		markup_after = a->markup_size;
		swap_a_b(a);
		optimal_markup_gt(a);
		if (markup_after > a->markup_size)
			return (1);
	}
	return (0);
}

/*
** From A stack to Stack B gt markup mode
*/
void	from_a_to_b_gt(t_stack *a, t_stack *b, t_stack *rules)
{
	while (a_has_false(a))
	{
		if (sa_need_gt(a))
		{
			swap_a_b(a);
			stack_push(rules, SA, -1);
			optimal_markup_gt(a);
		}
		else if (a->head->keep == FALSE)
		{
			push_b(a, b);
			stack_push(rules, PB, -1);
		}
		else
		{
			rotate_a_b(a);
			stack_push(rules, RA, -1);
		}
	}
}

t_stack	*solve_gt(t_stack *a, t_stack *b)
{
	t_stack	*rules;

	rules = create_stack();
	from_a_to_b_gt(a, b, rules);
	from_b_to_a(a, b, rules);
//	debug_print(a, b, 0);
	sort_a(a, rules);
//	debug_print(a, b, 0);
	return (rules);
}
