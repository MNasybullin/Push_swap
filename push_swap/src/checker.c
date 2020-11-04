/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 19:22:39 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 16:51:24 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		stack_loop(int argc, char *argv[], t_stack *a, t_stack *b)
{
	int param_len;

	param_len = 1;
	if (ft_dublicate(argc, (char **)argv, a, param_len) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	debug_print(a, b, 0);
	if (check_rules(a, b, argv, FALSE) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	three_argv(char *argv[], t_stack *a, t_stack *b)
{
	char	**str;
	int		len;

	str = ft_strsplit(argv[3], ' ');
	len = 0;
	while (str[len] != NULL)
		len++;
	if (ft_isdigit_one(len, (char **)str, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	if (ft_dublicate(len, (char **)str, a, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	a->debug = 2;
	debug_print(a, b, 0);
	if (check_rules(a, b, str, TRUE) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	str_free(str);
	del_memory();
}

void	two_argv(char *argv[], t_stack *a, t_stack *b)
{
	char	**str;
	int		len;

	str = ft_strsplit(argv[2], ' ');
	len = 0;
	while (str[len] != NULL)
		len++;
	if (ft_isdigit_one(len, (char **)str, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	if (ft_dublicate(len, (char **)str, a, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	a->debug = 1;
	debug_print(a, b, 0);
	if (check_rules(a, b, str, TRUE) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	str_free(str);
	del_memory();
}

void	one_argv(char *argv[], t_stack *a, t_stack *b)
{
	char	**str;
	int		len;

	str = ft_strsplit(argv[1], ' ');
	len = 0;
	while (str[len] != NULL)
		len++;
	if (ft_isdigit_one(len, (char **)str, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	if (ft_dublicate(len, (char **)str, a, 0) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	debug_print(a, b, 0);
	if (check_rules(a, b, str, TRUE) == EXIT_FAILURE)
		exit_print_err_and_free_str(ERROR, EXIT_FAILURE, str);
	str_free(str);
	del_memory();
}

int		main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;

	if (argc > 1)
	{
		a = create_stack();
		b = create_stack();
		if ((argc == 2 && ft_check_space(argv[1]) == 1))
			one_argv((char **)argv, a, b);
		else if ((argc == 3 && ft_strcmp(argv[1], "-v") == 0 &&
		ft_check_space(argv[2]) == 1))
			two_argv((char **)argv, a, b);
		else if ((argc == 4 && ft_strcmp(argv[1], "-v") == 0 &&
		ft_strcmp(argv[2], "-c") == 0 && ft_check_space(argv[3]) == 1))
			three_argv((char **)argv, a, b);
		else
		{
			if (ft_isdigit(argc, (char **)argv, a, 1) == EXIT_FAILURE)
				exit_print_err(ERROR, EXIT_FAILURE);
			if (stack_loop(argc, (char **)argv, a, b) == EXIT_FAILURE)
				exit_print_err(ERROR, EXIT_FAILURE);
			del_memory();
		}
	}
	return (EXIT_SUCCESS);
}
