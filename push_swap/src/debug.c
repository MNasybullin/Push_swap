/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:09:21 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 19:39:58 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Check for Debug option -v || -c
*/

int		check_debug_option(char *argv[], t_stack *a)
{
	if (argv[1][0] == '-' && argv[1][1] == 'v')
	{
		if (argv[2][0] == '-' && argv[2][1] == 'c')
		{
			a->debug = 2;
			return (2);
		}
		a->debug = 1;
		return (1);
	}
	a->debug = 0;
	return (0);
}

/*
** Debug option -v
*/

int		debug_v(t_stack_node *ad, t_stack_node *bd)
{
	while (ad != NULL || bd != NULL)
	{
		if (ad != NULL)
		{
			ft_printf("|%11i|", ad->nbr);
			ad = ad->next;
		}
		else
			ft_printf("|           |");
		if (bd != NULL)
		{
			ft_printf("%11i|\n", bd->nbr);
			bd = bd->next;
		}
		else
			ft_printf("           |\n");
	}
	return (EXIT_SUCCESS);
}

/*
** 1 - paint the first element
** 2 - the first two are painted
** 9 - last element paint
*/

void	debug_c_helper(int rule, int *a, int *b)
{
	if (rule == 0)
	{
		*a = 0;
		*b = 0;
	}
	*a = rule / 10;
	*b = rule % 10;
	if (*a == 5)
		*a = 0;
	if (*b == 5)
		*b = 0;
}

/*
** Debug option -v && -c
*/

int		debug_c(t_stack_node *ad, t_stack_node *bd, int rule)
{
	int	i;
	int	a;
	int	b;

	i = 1;
	debug_c_helper(rule, &a, &b);
	while (ad != NULL || bd != NULL)
	{
		if (ad != NULL)
		{
			if ((a == 2 && (i == 1 || i == 2)) || (a == 1 && i == 1) || (a == 9 && ad->next == NULL))
				ft_printf("|%s%11i%s|", GREEN_N, ad->nbr, YELLOW_D);
			else
				ft_printf("|%11i|", ad->nbr);
			ad = ad->next;
		}
		else
			ft_printf("|           |");
		if (bd != NULL)
		{
			if ((b == 2 && (i == 1 || i == 2)) || (b == 1 && i == 1) || (b == 9 && bd->next == NULL))
				ft_printf("%s%11i%s|\n", GREEN_N, bd->nbr, YELLOW_D);
			else
				ft_printf("%11i|\n", bd->nbr);
			bd = bd->next;
		}
		else
			ft_printf("           |\n");
		i++;
	}
	return (EXIT_SUCCESS);
}

/*
** Displays stacks in the terminal
*/

int		debug_print(t_stack *a, t_stack *b, int rule)
{
	t_stack_node	*ad;
	t_stack_node	*bd;

	if (a->debug != 0)
	{
		ad = a->head;
		bd = b->head;
		ft_printf("%s|-----A-----|-----B-----|\n", YELLOW_D);
		if (a->debug == 1)
			debug_v(ad, bd);
		if (a->debug == 2)
			debug_c(ad, bd, rule);
		ft_printf("|-----------|-----------|%s\n", RESET);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
