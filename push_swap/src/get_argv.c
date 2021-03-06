/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:09:29 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 19:14:59 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Int overflow check
*/

int	ft_isoverflow(char *c, int i)
{
	if (c[i] == '+' || c[i] == '-')
		i++;
	if (c[i] < '3' && c[i] > '1'
	&& c[i + 1] < '2' && c[i + 1] > '0'
	&& c[i + 2] < '5' && c[i + 2] > '3'
	&& c[i + 3] < '8' && c[i + 3] > '6'
	&& c[i + 4] < '5' && c[i + 4] > '3'
	&& c[i + 5] < '9' && c[i + 5] > '7'
	&& c[i + 6] < '4' && c[i + 6] > '2'
	&& c[i + 7] < '7' && c[i + 7] > '5'
	&& c[i + 8] < '5' && c[i + 8] > '3')
	{
		if (c[i + 9] < '8')
			return (EXIT_SUCCESS);
		if (c[0] == '-' && c[i + 9] == '8')
			return (EXIT_SUCCESS);
		return (EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
}

/*
** Validation of numbers
*/

int	ft_isdigit_one(int argc, char *argv[], int param_len)
{
	int	i;
	int	j;

	i = param_len;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (j == 0 && (argv[i][j] == '+' || argv[i][j] == '-'))
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (EXIT_FAILURE);
			j++;
		}
		if (argv[i][j] == '\0' && j == 0)
			return (EXIT_FAILURE);
		if (j > 11 || (j > 9 && ft_isoverflow((char *)argv[i], 0) == 1))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
** Validation of numbers
*/

int	ft_isdigit(int argc, char *argv[], t_stack *a, int debug)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (i == 1 && argc >= 2 && debug == 1)
			i += check_debug_option((char **)argv, a);
		while (argv[i][j] != '\0')
		{
			if (j == 0 && (argv[i][j] == '+' || argv[i][j] == '-'))
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (EXIT_FAILURE);
			j++;
		}
		if (argv[i][j] == '\0' && j == 0)
			return (EXIT_FAILURE);
		if (j > 11 || (j > 9 && ft_isoverflow((char *)argv[i], 0) == 1))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
** Check numbers for dublicate
*/

int	ft_dubl_search(t_stack *node, int nbr)
{
	t_stack_node	*tmp;

	if (node->size == 0)
	{
		stack_push(node, nbr, -1);
		return (EXIT_SUCCESS);
	}
	else
	{
		tmp = node->head;
		while (tmp != NULL)
		{
			if (nbr == tmp->nbr)
				return (EXIT_FAILURE);
			tmp = tmp->next;
		}
	}
	stack_push(node, nbr, -1);
	return (EXIT_SUCCESS);
}

/*
** Check numbers for dublicate
** If no matches are found, the number is written to the stack A
*/

int	ft_dublicate(int argc, char *argv[], t_stack *a, int param_len)
{
	t_stack *node;
	int		i;
	int		nbr;

	node = create_stack();
	i = param_len + a->debug;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (ft_dubl_search(node, nbr) == EXIT_FAILURE)
		{
			return (EXIT_FAILURE);
		}
		stack_push(a, nbr, -1);
		i++;
	}
	return (EXIT_SUCCESS);
}
