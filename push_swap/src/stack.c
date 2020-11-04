/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 20:46:39 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 15:57:39 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** initialization stack
*/

t_stack	*create_stack(void)
{
	t_stack	*s;

	s = (t_stack *)mem(sizeof(t_stack));
	if (s == NULL)
		exit_print_err(MALER, EXIT_FAILURE);
	s->size = 0;
	s->debug = 0;
	s->markup_size = 0;
	s->markup_head = NULL;
	s->head = NULL;
	s->tail = NULL;
	return (s);
}

/*
** Add element
*/

void	stack_push(t_stack *s, int nbr, size_t index)
{
	t_stack_node *node;
	t_stack_node *tmp;

	node = (t_stack_node *)mem(sizeof(t_stack_node));
	if (node == NULL)
		exit_print_err(MALER, EXIT_FAILURE);
	node->nbr = nbr;
	node->index = index;
	node->keep = -1;
	node->next = NULL;
	node->previous = NULL;
	if (s->size == 0)
	{
		s->head = node;
		s->tail = node;
	}
	else
	{
		tmp = s->head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
		s->tail = node;
		node->previous = tmp;
	}
	s->size += 1;
}

/*
** Add element in start stack
*/

void	stack_push_start(t_stack *s, int nbr, size_t index)
{
	t_stack_node *node;

	node = (t_stack_node *)mem(sizeof(t_stack_node));
	if (node == NULL)
		exit_print_err(MALER, EXIT_FAILURE);
	node->nbr = nbr;
	node->index = index;
	node->keep = -1;
	node->previous = NULL;
	node->next = s->head;
	//if (s->head != NULL)
	s->head->previous = node;
	//node->next = s->head;
	s->head = node;
	s->size += 1;
}

/*
** Extract element from start stack
*/

int		stack_pop(t_stack *s, int *nbr, size_t *index)
{
	t_stack_node *node;

	if (s->size == 0)
		return (EXIT_FAILURE);
	node = s->head;
	*nbr = node->nbr;
	*index = node->index;
	s->size -= 1;
	if (s->size == 0)
	{
		s->head = NULL;
		s->tail = NULL;
	}
	else
	{
		s->head = node->next;
		s->head->previous = NULL;
	}
	//free(node);
	return (EXIT_SUCCESS);
}

/*
** Extract element from finish stack
*/

int		stack_pop_back(t_stack *s, int *nbr, size_t *index)
{
	t_stack_node	*node;
	t_stack_node	*tmp;

	if (s->size == 0)
		return (EXIT_FAILURE);
	tmp = s->tail->previous;
	node = s->tail;
	*nbr = node->nbr;
	*index = node->index;
	s->size -= 1;
	if (s->size == 0)
	{
		s->head = NULL;
		s->tail = NULL;
	}
	else
	{
		tmp->next = NULL;
		s->tail = tmp;
	}
	return (EXIT_SUCCESS);
}
