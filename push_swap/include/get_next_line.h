/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:23:53 by sdiego            #+#    #+#             */
/*   Updated: 2020/07/20 17:58:35 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../include/push_swap.h"

int		get_next_line(const int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memalloc(size_t size);
void	ft_strdel(char **as);
char	*ft_strchr(const char *s, int c);
int		ft_getnbr(char *str);
void	ft_putstr(char const *s);
void	ft_putendl(char const *s);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);

#endif
