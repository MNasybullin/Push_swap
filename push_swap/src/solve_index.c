/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 21:09:17 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 19:25:27 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Do I need to do a swap_a ? index mode
** 1 - yes ||  0 - no
*/

int	sa_need_index(t_stack *a)
{
	size_t	markup_after;

	if (a && a->size >= 2)
	{
		swap_a_b(a);
		optimal_markup_index(a);
		markup_after = a->markup_size;
		swap_a_b(a);
		optimal_markup_index(a);
		if (markup_after > a->markup_size)
			return (1);
	}
	return (0);
}

/*
** From A stack to Stack B index markup mode
*/

void	from_a_to_b_index(t_stack *a, t_stack *b, t_stack *rules)
{
	while (a_has_false(a))
	{
		if (sa_need_index(a))
		{
			swap_a_b(a);
			stack_push(rules, SA, -1);
			optimal_markup_index(a);
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

t_stack	*solve_index(t_stack *a, t_stack *b)
{
	t_stack	*rules;

	rules = create_stack();
	from_a_to_b_index(a, b, rules);
	from_b_to_a(a, b, rules);
	sort_a(a, rules);
	return (rules);
}

void	sort_a(t_stack *a, t_stack *rules)
{
	t_stack_node	*tmp;
	size_t			ra_size;
	size_t			rra_size;

	ra_size = 0;
	rra_size = 0;
	if (a && a->head)
	{
		tmp = a->head;
		while (tmp && tmp->index != 0)
		{
			ra_size++;
			tmp = tmp->next;
		}
		tmp = a->head;
		if (tmp->index != 0)
			rra_size++;
		tmp = a->tail;
		while (tmp && tmp->index != 0)
		{
			rra_size++;
			tmp = tmp->previous;
		}
		while (a->head->index != 0 && (ra_size < rra_size))
		{
			rotate_a_b(a);
			stack_push(rules, RA, -1);
		}
		while (a->head->index != 0 && !(ra_size < rra_size))
		{
			rr_a_b(a);
			stack_push(rules, RRA, -1);
		}
	}
}

/*
** We are looking for a suitable element in stack A
*/

t_stack_node	*find_direct_in_a(t_stack *a, size_t index_b)
{
	t_stack_node	*tmp;
	t_stack_node	*one_back;

	tmp = a->markup_head;
	if (index_b < tmp->index)
	{
		while (tmp && tmp->previous && index_b < tmp->previous->index && tmp->index > tmp->previous->index)
		{
			tmp = tmp->previous;
		}
		if (!tmp->previous)
		{
			one_back = tmp;
			tmp = a->tail;
			if (one_back && tmp && index_b < tmp->index && one_back->index > tmp->index)
			{
				while (tmp && tmp->previous && index_b < tmp->previous->index && tmp->index > tmp->previous->index)
				{
					tmp = tmp->previous;
				}
			}
			else
			{
				tmp = one_back;
			}
		}
	}
	else
	{
		while (tmp && tmp->next && index_b > tmp->index && tmp->index < tmp->next->index)
		{
			tmp = tmp->next;
		}
		if (!tmp->next)
		{
			one_back = tmp;
			tmp = a->head;
			if (one_back && tmp && index_b > one_back->index && one_back->index < tmp->index)
			{
				while (tmp && tmp->next && index_b > tmp->index && tmp->index < tmp->next->index)
				{
					tmp = tmp->next;
				}
			}
			else
			{
				tmp = one_back;
			}
		}
		if (tmp->next)
		{
			if (tmp && tmp->next && index_b > tmp->index && tmp->index > tmp->next->index)
			{
				tmp = tmp->next;
			}
		}
		else
		{
			one_back = tmp;
			tmp = a->head;
			if (one_back && tmp && index_b > one_back->index && one_back->index > tmp->index)
			{
				tmp = a->head;
			}
			else
			{
				tmp = one_back;
			}
		}
	}
	return (tmp);
}
