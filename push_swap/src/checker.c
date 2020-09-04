/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 19:22:39 by sdiego            #+#    #+#             */
/*   Updated: 2020/08/29 11:45:26 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_loop(int argc, char *argv[], t_stack *a, t_stack *b, int param_len)
{
	if (ft_dublicate(argc, (char **) argv, a, param_len) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	debug_print(a, b, 0);
	/*if (check_sort(a, b) == EXIT_SUCCESS)
			exit_print_err(OK, EXIT_SUCCESS);*/
	if (check_rules(a, b) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	three_argv(int argc, char *argv[], t_stack *a, t_stack *b)
{
	char **str = ft_strsplit(argv[3], ' '); // Обязательно очистить память !!!!
	int	len = 0;
	while (str[len] != NULL)
		len++;
	if (ft_isdigit_one(len, (char **) str, a, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);

	if (ft_dublicate(len, (char **) str, a, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	a->debug = 2;
	debug_print(a, b, 0);
	/*if (check_sort(a, b) == EXIT_SUCCESS)
			exit_print_err(OK, EXIT_SUCCESS);*/
	if (check_rules(a, b) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	str_free(str);
	del_memory();
}

void	two_argv(int argc, char *argv[], t_stack *a, t_stack *b)
{
	char **str = ft_strsplit(argv[2], ' '); // Обязательно очистить память !!!!
	int	len = 0;
	while (str[len] != NULL)
		len++;
	if (ft_isdigit_one(len, (char **) str, a, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);

	if (ft_dublicate(len, (char **) str, a, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	a->debug = 1;
	debug_print(a, b, 0);
	/*if (check_sort(a, b) == EXIT_SUCCESS)
			exit_print_err(OK, EXIT_SUCCESS);*/
	if (check_rules(a, b) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	str_free(str);
	del_memory();
}

void	one_argv(int argc, char *argv[], t_stack *a, t_stack *b)
{
	char **str = ft_strsplit(argv[1], ' '); // Обязательно очистить память !!!!
	int	len = 0;
	while (str[len] != NULL)
		len++;
	if (ft_isdigit_one(len, (char **) str, a, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	if (stack_loop(len, (char **) str, a, b, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	str_free(str);
	del_memory();
}

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
		return (EXIT_FAILURE);
	else
	{
		a = create_stack();
		b = create_stack();
		if ((argc == 2 && ft_check_space(argv[1]) == 1))
			one_argv(argc, (char **) argv, a, b);
		else if ((argc == 3 && ft_strcmp(argv[1], "-v") == 0 && ft_check_space(argv[2]) == 1))
			two_argv(argc, (char **) argv, a, b);
		else if ((argc == 4 && ft_strcmp(argv[1], "-v") == 0 && ft_strcmp(argv[2], "-c") == 0 && ft_check_space(argv[3]) == 1))
			three_argv(argc, (char **) argv, a, b);
		else
		{
			if (ft_isdigit(argc, (char **) argv, a, 1) == EXIT_FAILURE)
				exit_print_err(ERROR, EXIT_FAILURE);
			if (stack_loop(argc, (char **) argv, a, b, 1) == EXIT_FAILURE)
				exit_print_err(ERROR, EXIT_FAILURE);
			del_memory();
		}
	}
	return (EXIT_SUCCESS);
}
