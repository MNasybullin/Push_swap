/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_lst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:05:51 by aannara           #+#    #+#             */
/*   Updated: 2020/06/07 20:22:42 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_LST_H
# define MEM_LST_H

# include "../include/push_swap.h"

typedef struct	s_mem
{
	void		*p;
	void		*next;
	void		*last;
}				t_mem;

t_mem			g_m;

void			set_m(void);
void			new_m(void *pointer);
void			del_m(void);
void			del_memory(void);
void			*mem(size_t size);

#endif
