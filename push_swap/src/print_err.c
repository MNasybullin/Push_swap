/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:18:57 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 15:50:39 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i++], 1);
		}
	}
}

void	ft_putendl(char const *s)
{
	if (s)
	{
		ft_putstr(s);
		write(2, "\n", 1);
	}
}

void	str_free(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	exit_print_err_and_free_str(char *s, int error, char **str)
{
	str_free(str);
	ft_putendl(s);
	del_memory();
	exit(error);
}

void	exit_print_err(char *s, int error)
{
	ft_putendl(s);
	del_memory();
	exit(error);
}

void	exit_err(int error)
{
	del_memory();
	exit(error);
}
