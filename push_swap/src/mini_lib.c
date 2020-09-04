/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:20:08 by sdiego            #+#    #+#             */
/*   Updated: 2020/07/21 16:24:33 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	s2 = (char *)malloc(sizeof(*s1) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (len >= 0)
	{
		s2[len] = s1[len];
		len--;
	}
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	len = 0;
	while (len < i)
	{
		str[len] = s1[len];
		len++;
	}
	while (len < i + j)
	{
		str[len] = s2[len - i];
		len++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_strnew(size_t size)
{
	void	*str;

	if (size + 1 == 0)
		return (0);
	str = (void *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (len + 1 == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
