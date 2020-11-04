/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:36:53 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 15:53:41 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_a_b_stacks(t_stack *a, t_stack *b, t_direction *d, t_stack *rules)
{
	if (d->a_rule == ROTATE)
	{
		rr(a, b);
		stack_push(rules, RR, -1);
	}
	else
	{
		rrr(a, b);
		stack_push(rules, RRR, -1);
	}
}

void	move_a_stack(t_stack *a, t_direction *d, t_stack *rules)
{
	if (d->a_rule == ROTATE)
	{
		rotate_a_b(a);
		stack_push(rules, RA, -1);
	}
	else
	{
		rr_a_b(a);
		stack_push(rules, RRA, -1);
	}
}

void	move_b_stack(t_stack *b, t_direction *d, t_stack *rules)
{
	if (d->b_rule == ROTATE)
	{
		rotate_a_b(b);
		stack_push(rules, RB, -1);
	}
	else
	{
		rr_a_b(b);
		stack_push(rules, RRB, -1);
	}
}

/*
** We put the previously selected numbers at the beginning of the stack a and stack b
*/

void	move_stacks(t_stack *a, t_stack *b, t_direction *d, t_stack *rules)
{
	while (d->a_node->nbr != a->head->nbr || d->b_node->nbr != b->head->nbr)
	{
		if (d->a_rule == d->b_rule && d->a_node->nbr != a->head->nbr && d->b_node->nbr != b->head->nbr)
			move_a_b_stacks(a, b, d, rules);
		else if (d->a_node->nbr != a->head->nbr)
			move_a_stack(a, d, rules);
		else if (d->b_node->nbr != b->head->nbr)
			move_b_stack(b, d, rules);
	}
}

/*
** From Stack B to Stack A
*/

void	from_b_to_a(t_stack *a, t_stack *b, t_stack *rules)
{
	t_direction	*d;

	d = init_direction_struct();
	while (b->size > 0)
	{
		d->status = FALSE;
		optimal_direction(a, b, d);
		move_stacks(a, b, d, rules);
		push_a(a, b);
		stack_push(rules, PA, -1);
	}
}
