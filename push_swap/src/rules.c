/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:17:50 by sdiego            #+#    #+#             */
/*   Updated: 2020/09/02 09:13:16 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Swaps the first two elements (sa) || (sb)
*/
int	swap_a_b(t_stack *a)
{
	t_stack_node	*next_tmp;
	t_stack_node	*previous_tmp;
	t_stack_node	*one;
	t_stack_node	*two;

	if (a->size < 2)
		return (1);
	one = a->head;
	two = one->next;
	next_tmp = two->next;
	previous_tmp = two->previous;
	two->previous = one->previous;
	two->next = one;
	one->next = next_tmp;
	one->previous = previous_tmp;
	a->head = two;
	return (1);
}

/*
** Do (swap_a) && (swap_b)
*/
int	ss(t_stack *a, t_stack *b)
{
	swap_a_b(a);
	swap_a_b(b);
	return (1);
}

void	fixed_previous(t_stack *s)
{
	t_stack_node *tmp;
	t_stack_node *previous;

	if (s && s->head && s->head->next)
	{
		tmp = s->head->next;
		previous = s->head;
		while (tmp != NULL)
		{
			tmp->previous = previous;
			tmp = tmp->next;
			previous = previous->next;
		}
	}
}

void	fixedMarkupHead(t_stack *a)
{
	t_stack_node *tmp;

	if (a && a->head && a->markup_head)
	{
		tmp = a->head;
		while (tmp && a->markup_head->nbr != tmp->nbr)
		{
			tmp = tmp->next;
		}
		a->markup_head = tmp;
	}
	fixed_previous(a);
}

/*
** Takes the first item from "B" and inserts the first into "A"
*/
int	push_a(t_stack *a, t_stack *b)
{
	int	nbr;
	size_t	index;

	if (stack_pop(b, &nbr, &index) == EXIT_SUCCESS)
	{
		if (a->size == 0)
			stack_push(a, nbr, index);
		else
			stack_push_start(a, nbr, index);
		fixedMarkupHead(a); ///
	}
	return (1);
}
/*
int	push_a(t_stack *a, t_stack *b)
{
	t_stack_node *tmp;
	t_stack_node *a_one;

	if (b && b->head)
	{
		tmp = b->head;
		a_one = a->head;
		tmp->next = a_one;
		tmp->previous = a_one->previous;
		a_one->previous = tmp;
		a->head = tmp;
		a->size += 1;
		if (b->head->next)
		{
			b->head->next->previous = NULL;
			b->head = b->head->next;
		}
		else
		{
			b->head = NULL;
		}
		b->size -= 1;
	}
	return (1);
}
*/

/*
** Takes the first item from "A" and inserts the first into "B"
*/
int	push_b(t_stack *a, t_stack *b)
{
	int nbr;
	size_t	index;

	if (stack_pop(a, &nbr, &index) == EXIT_SUCCESS)
	{
		if (b->size == 0)
			stack_push(b, nbr, index);
		else
			stack_push_start(b, nbr, index);
		fixedMarkupHead(a); ///
	}
	return (1);
}

/*
** The first item from the stack becomes the last (ra) || (rb)
*/
int	rotate_a_b(t_stack *s)
{
	int		nbr;
	size_t	index;

	if (s->size < 2)
		return (1);

	if (stack_pop(s, &nbr, &index) == EXIT_SUCCESS)
	{
		stack_push(s, nbr, index);
		fixedMarkupHead(s); ///
	}

	return (1);
}

/*
** Do (rotate_a) && (rotate_b)
*/
int	rr(t_stack *a, t_stack *b)
{
	rotate_a_b(a);
	rotate_a_b(b);

	return (1);
}

/*
** Reverse rotate a || b
** Last item becomes first
*/
int	rr_a_b(t_stack *s)
{
	int		nbr;
	size_t	index;

	nbr = 0;
	if (s->size < 2)
		return (1);
	if (stack_pop_back(s, &nbr, &index) == EXIT_SUCCESS)
	{
		if (s->size == 0)
			stack_push(s, nbr, index);
		else
			stack_push_start(s, nbr, index);
		fixedMarkupHead(s); ///
	}

	return (1);
}

/*
** Do reverse rotate a && reverse rotate b
*/
int	rrr(t_stack *a, t_stack *b)
{
	rr_a_b(a);
	rr_a_b(b);

	return (1);
}
