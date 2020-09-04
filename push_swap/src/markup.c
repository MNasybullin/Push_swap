/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 17:27:11 by sdiego            #+#    #+#             */
/*   Updated: 2020/09/01 10:12:55 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** greater than markup mode
*/
size_t	gt_markup(t_stack *a, t_stack_node *markup_head)
{
	size_t			markup_size;
	t_stack_node	*tmp;
	size_t			index;

	markup_size = 0;
	if (!a || !markup_head)
		return (0);
	index = markup_head->index;
	markup_head->keep = TRUE;
	tmp = markup_head->next;
	while (tmp && tmp != markup_head)
	{
		if (tmp->index > index)
		{
			markup_size++;
			tmp->keep = TRUE;
			index = tmp->index;
		}
		else
		{
			tmp->keep = FALSE;
		}
		tmp = tmp->next;
	}
	tmp = a->head;
	while (tmp && tmp != markup_head)
	{
		if (tmp->index > index)
		{
			markup_size++;
			tmp->keep = TRUE;
			index = tmp->index;
		}
		else
		{
			tmp->keep = FALSE;
		}
		tmp = tmp->next;
	}
	return (markup_size);
}

/*
** Clear value keep in stack
*/
void	clear_keep(t_stack *a)
{
	t_stack_node	*tmp;

	tmp = a->head;
	while(tmp != NULL)
	{
		tmp->keep = FALSE;
		tmp = tmp->next;
	}
}

/*
** Find optimal direction (markup_head) in stack
*/
void	optimal_markup_gt(t_stack *a)
{
	t_stack_node	*tmp;
	size_t			mark_size;

	if (a)
	{
		tmp = a->head;
		a->markup_size = 0;
		while (tmp)
		{
			mark_size = gt_markup(a, tmp);
			if (mark_size > a->markup_size)
			{
				a->markup_head = tmp;
				a->markup_size = mark_size;
			}
			else if (mark_size == a->markup_size && (!a->markup_head || tmp->nbr < a->markup_head->nbr))
				a->markup_head = tmp;
			tmp = tmp->next;
		}
	}
	gt_markup(a, a->markup_head);
}


/*
** index markup mode
*/
size_t	index_markup(t_stack *a, t_stack_node *markup_head)
{
	size_t			markup_size;
	t_stack_node	*tmp;
	size_t			index;

	markup_size = 0;
	if (!a || !markup_head)
		return (0);
	index = markup_head->index;
	markup_head->keep = TRUE;
	tmp = markup_head->next;
	while (tmp && tmp != markup_head)
	{
		if (tmp->index == index + 1)
		{
			markup_size++;
			tmp->keep = TRUE;
			index++;
		}
		else
		{
			tmp->keep = FALSE;
		}
		tmp = tmp->next;
	}
	tmp = a->head;
	while (tmp && tmp != markup_head)
	{
		if (tmp->index == index + 1)
		{
			markup_size++;
			tmp->keep = TRUE;
			index++;
		}
		else
		{
			tmp->keep = FALSE;
		}
		tmp = tmp->next;
	}
	return (markup_size);
}

/*
** Find optimal direction (markup_head) in stack
*/
void	optimal_markup_index(t_stack *a)
{
	t_stack_node	*tmp;
	size_t			mark_size;

	if (a)
	{
		tmp = a->head;
		a->markup_size = 0;
		while (tmp)
		{
			mark_size = index_markup(a, tmp);
			if (mark_size > a->markup_size)
			{
				a->markup_head = tmp;
				a->markup_size = mark_size;
			}
			else if (mark_size == a->markup_size && (!a->markup_head || tmp->nbr < a->markup_head->nbr))
				a->markup_head = tmp;
			tmp = tmp->next;
		}
	}
	index_markup(a, a->markup_head);
}
