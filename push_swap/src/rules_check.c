/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 16:15:28 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 16:48:25 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Do rules
** return	0 - error
**			1 - success
** "rule" needed for debug option -c
*/

void	do_rules(t_stack *a, t_stack *b, char *line, int *rule)
{
	if (ft_strequ(line, "sa") && (a->debug == 0 || ft_printf("sa\n")))
		*rule = 24 + swap_a_b(a);
	else if (ft_strequ(line, "sb") && (a->debug == 0 || ft_printf("sb\n")))
		*rule = 51 + swap_a_b(b);
	else if (ft_strequ(line, "ss") && (a->debug == 0 || ft_printf("ss\n")))
		*rule = 21 + ss(a, b);
	else if (ft_strequ(line, "pa") && (a->debug == 0 || ft_printf("pa\n")))
		*rule = 14 + push_a(a, b);
	else if (ft_strequ(line, "pb") && (a->debug == 0 || ft_printf("pb\n")))
		*rule = 50 + push_b(a, b);
	else if (ft_strequ(line, "ra") && (a->debug == 0 || ft_printf("ra\n")))
		*rule = 94 + rotate_a_b(a);
	else if (ft_strequ(line, "rb") && (a->debug == 0 || ft_printf("rb\n")))
		*rule = 58 + rotate_a_b(b);
	else if (ft_strequ(line, "rr") && (a->debug == 0 || ft_printf("rr\n")))
		*rule = 98 + rr(a, b);
	else if (ft_strequ(line, "rra") && (a->debug == 0 || ft_printf("rra\n")))
		*rule = 14 + rr_a_b(a);
	else if (ft_strequ(line, "rrb") && (a->debug == 0 || ft_printf("rrb\n")))
		*rule = 50 + rr_a_b(b);
	else if (ft_strequ(line, "rrr") && (a->debug == 0 || ft_printf("rrr\n")))
		*rule = 10 + rrr(a, b);
}

/*
** Check if the stack is sorted
*/

int		check_sort(t_stack *a, t_stack *b)
{
	t_stack_node	*tmp;
	int				num;
	int				i;

	if (b->head != NULL)
		return (EXIT_FAILURE);
	i = 0;
	tmp = a->head;
	while (tmp != NULL)
	{
		if (i == 0)
		{
			num = tmp->nbr;
		}
		else
		{
			if (num > tmp->nbr)
				return (EXIT_FAILURE);
			num = tmp->nbr;
		}
		tmp = tmp->next;
		i++;
	}
	return (EXIT_SUCCESS);
}

void	final_check(t_stack *a, t_stack *b, char *argv[], int free_param)
{
	if (check_sort(a, b) == EXIT_SUCCESS)
	{
		if (free_param == TRUE)
			exit_print_err_and_free_str(OK, EXIT_SUCCESS, argv);
		exit_print_err(OK, EXIT_SUCCESS);
	}
	else
	{
		if (free_param == TRUE)
			exit_print_err_and_free_str(KO, EXIT_FAILURE, argv);
		exit_print_err(KO, EXIT_FAILURE);
	}
}

/*
** Checking incoming instructions (rules)
*/

int		check_rules(t_stack *a, t_stack *b, char *argv[], int free_param)
{
	char	*line;
	int		len;
	int		rule;

	rule = 0;
	while (get_next_line(0, &line) > 0)
	{
		len = ft_strlen(line);
		if (len < 2 || len > 3)
		{
			ft_strdel(&line);
			return (EXIT_FAILURE);
		}
		do_rules(a, b, line, &rule);
		if (rule == 0)
		{
			ft_strdel(&line);
			return (EXIT_FAILURE);
		}
		debug_print(a, b, rule);
		ft_strdel(&line);
	}
	final_check(a, b, argv, free_param);
	return (EXIT_SUCCESS);
}
