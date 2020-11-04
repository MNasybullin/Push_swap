/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:41:17 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 16:57:38 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Initialization direction struct
*/

t_direction	*init_direction_struct(void)
{
	t_direction	*d;

	d = (t_direction *)mem(sizeof(t_direction));
	if (d == NULL)
		exit_print_err(MALER, EXIT_FAILURE);
	d->a_node = NULL;
	d->b_node = NULL;
	d->status = FALSE;
	d->size = 0;
	d->a_rule = ROTATE;
	d->b_rule = ROTATE;
	return (d);
}

void		set_direction(t_direction new_d, t_direction *d, size_t size)
{
	if (d->status == FALSE || size < d->size)
	{
		d->a_node = new_d.a_node;
		d->b_node = new_d.b_node;
		d->a_rule = new_d.a_rule;
		d->b_rule = new_d.b_rule;
		d->size = size;
		d->status = TRUE;
	}
}

/*
** Checking the correctness of the selected direction
** How many actions to rotate || reverse rotate
** needs to be done so that the selected number is at the beginning of the stack
*/

void		check_direction(t_stack *s, size_t index, size_t *r_size, size_t *rr_size)
{
	t_stack_node	*tmp;
	size_t			i;

	i = 0;
	if (s && s->head)
	{
		tmp = s->head;
		while (tmp->next && tmp->index != index)
		{
			(*r_size)++;
			tmp = tmp->next;
		}
		tmp = s->head;
		if (tmp && tmp->index != index)
			(*rr_size)++;
		if (tmp->index != index)
		{
			tmp = s->tail;
			while (tmp && tmp->index != index)
			{
				(*rr_size)++;
				tmp = tmp->previous;
			}
		}
	}
}

/*
** Find optimal directions in stacks
*/

void		find_direction(t_stack *a, t_stack *b, t_stack_node *current_b, t_direction *d)
{
	t_direction new_d;
	size_t		ra_size;
	size_t		rb_size;
	size_t		rra_size;
	size_t		rrb_size;

	ra_size = 0;
	rb_size = 0;
	rra_size = 0;
	rrb_size = 0;
	new_d.a_node = find_direct_in_a(a, current_b->index);
	new_d.b_node = current_b;
	check_direction(a, new_d.a_node->index, &ra_size, &rra_size);
	check_direction(b, current_b->index, &rb_size, &rrb_size);
	new_d.a_rule = ROTATE;
	new_d.b_rule = ROTATE;
	set_direction(new_d, d, FT_IS_MAX(ra_size, rb_size));
	new_d.a_rule = REVERSE;
	set_direction(new_d, d, rra_size + rb_size);
	new_d.b_rule = REVERSE;
	set_direction(new_d, d, FT_IS_MAX(rra_size, rrb_size));
	new_d.a_rule = ROTATE;
	set_direction(new_d, d, ra_size + rrb_size);
}

void		optimal_direction(t_stack *a, t_stack *b, t_direction *d)
{
	t_stack_node	*current;

	if (b)
	{
		current = b->head;
		while (current)
		{
			find_direction(a, b, current, d);
			current = current->next;
		}
	}
}
