/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 14:49:34 by sdiego            #+#    #+#             */
/*   Updated: 2020/09/02 08:47:16 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_rules(t_stack *rule)
{
	t_stack_node *tmp;

	tmp = rule->head;
	while (tmp != NULL)
	{
		if (tmp->nbr == SA && write(1, "sa\n", 3));
		else if (tmp->nbr == SB && write(1, "sb\n", 3));
		else if (tmp->nbr == SS && write(1, "ss\n", 3));
		else if (tmp->nbr == PA && write(1, "pa\n", 3));
		else if (tmp->nbr == PB && write(1, "pb\n", 3));
		else if (tmp->nbr == RA && write(1, "ra\n", 3));
		else if (tmp->nbr == RB && write(1, "rb\n", 3));
		else if (tmp->nbr == RR && write(1, "rr\n", 3));
		else if (tmp->nbr == RRA && write(1, "rra\n", 4));
		else if (tmp->nbr == RRB && write(1, "rrb\n", 4));
		else if (tmp->nbr == RRR && write(1, "rrr\n", 4))
		;
		tmp = tmp->next;
	}
}


int	loop(t_stack *a_in, t_stack *b_in, t_stack *a_gt, t_stack *b_gt)
{
	t_stack	*gt_rules;
	t_stack	*index_rules;

	give_index(a_gt);
	optimal_markup_gt(a_gt);
	gt_rules = solve_gt(a_gt, b_gt);

	give_index(a_in);
	optimal_markup_index(a_in);
	index_rules = solve_index(a_in, b_in);

	if (gt_rules->size < index_rules->size)
		print_rules(gt_rules);
	else
		print_rules(index_rules);
	return (EXIT_SUCCESS);
}

int		main(int argc, char *argv[])
{
	t_stack	*a_index;
	t_stack	*b_index;
	t_stack	*a_gt;
	t_stack	*b_gt;

	if (argc > 1)
	{
		a_index = create_stack();
		b_index = create_stack();
		if ((argc == 2 && ft_check_space(argv[1]) == 1))
		{
			char **str = ft_strsplit(argv[1], ' '); // Обязательно очистить память !!!!
			int	len = 0;
			while (str[len] != NULL)
				len++;
			if (ft_isdigit_one(len, (char **) str, a_index, 0) == EXIT_FAILURE)
				exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
			if (ft_dublicate(len, (char **) str, a_index, 0) == EXIT_FAILURE)
				exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
			if (check_sort(a_index, b_index) == EXIT_SUCCESS)
			{
				str_free(str);
				exit_err(EXIT_SUCCESS);
			}
			a_gt = create_stack();
			b_gt = create_stack();
			if (ft_dublicate(len, (char **) str, a_gt, 0) == EXIT_FAILURE)
				exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
			if (loop(a_index, b_index, a_gt, b_gt) == EXIT_FAILURE)
				exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
			str_free(str);
			del_memory();
		}
		else
		{

			if (ft_isdigit(argc, (char **) argv, a_index, 0) == EXIT_FAILURE)
				exit_print_err(ERROR, EXIT_FAILURE);
			if (ft_dublicate(argc, (char **) argv, a_index, 1) == EXIT_FAILURE)
				exit_print_err(ERROR, EXIT_FAILURE);
			if (check_sort(a_index, b_index) == EXIT_SUCCESS)
				exit_err(EXIT_SUCCESS);
			a_gt = create_stack();
			b_gt = create_stack();
			if (ft_dublicate(argc, (char **) argv, a_gt, 1) == EXIT_FAILURE)
				exit_print_err(ERROR, EXIT_FAILURE);
			if (loop(a_index, b_index, a_gt, b_gt) == EXIT_FAILURE)
				exit_print_err(ERROR, EXIT_FAILURE);
			del_memory();
		}
	}
	return (0);
}
