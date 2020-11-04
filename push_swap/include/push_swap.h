/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <sdiego@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 19:22:45 by sdiego            #+#    #+#             */
/*   Updated: 2020/11/04 16:20:12 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../include/mem_lst.h"
# include "../include/get_next_line.h"
# include "../ft_printf/include/ft_printf.h"

/*
** Messages
*/
# define ERROR	"Error"
# define MALER	"Malloc error"
# define OK		"OK"
# define KO		"KO"

# define FALSE	0
# define TRUE	1

# define FT_IS_MAX(A, B) (((A) > (B)) ? (A) : (B))

/*
** colors for ft_printf
*/
# define RESET    "\033[0m"
# define YELLOW_D "\033[2;33m"
# define GREEN_N  "\033[5;32m"

/*
** Rules
*/
typedef enum	e_rules
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	ROTATE,
	REVERSE
}				t_rules;

/*
** Define the list item
*/
typedef struct			s_stack_node
{
	int					nbr;
	size_t				index;
	int					keep;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}						t_stack_node;

/*
** Define the list itself
** Debug :
**  0 - no options | 1 - option -v | 2 - option -v && -c
*/
typedef struct			s_stack
{
	int					debug;
	size_t				size;
	size_t				markup_size;
	t_stack_node		*markup_head;
	t_stack_node		*head;
	t_stack_node		*tail;
}						t_stack;

/*
** Direction helper
*/
typedef struct			s_direction
{
	t_stack_node		*a_node;
	t_stack_node		*b_node;
	int					status;
	size_t				size;
	int					a_rule;
	int					b_rule;

}						t_direction;

/*
** Functions for working with errors
*/
void					exit_err(int error);
void					exit_print_err(char *s, int error);
void					exit_print_err_and_free_str(char *s, int error,
char **str);
void					str_free(char **str);
void					ft_putendl(char const *s);
void					ft_putstr(char const *s);

/*
** Validating Arguments
*/
int						ft_isdigit(int argc, char *argv[], t_stack *a,
int debug);
int						ft_isdigit_one(int argc, char *argv[], t_stack *a,
int param_len);
int						ft_dublicate(int argc, char *argv[], t_stack *a,
int param_len);
int						ft_atoi(const char *str);
int						ft_isoverflow(char *c, int i, int a);
int						ft_dubl_search(t_stack *node, int nbr);
char					**ft_strsplit(char const *s, char c);
int						ft_check_space(char *str);

/*
** Rule and stack checking functions
*/
int						check_rules(t_stack *a, t_stack *b);
int						check_sort(t_stack *a, t_stack *b);
void					do_rules(t_stack *a, t_stack *b, char *line, int *rule);

/*
** Functions for working with stack
*/
t_stack					*create_stack();
void					stack_push(t_stack *s, int nbr, size_t index);
int						stack_pop(t_stack *s, int *nbr, size_t *index);
void					stack_push_start(t_stack *s, int nbr, size_t index);
int						stack_pop_back(t_stack *s, int *nbr, size_t *index);

/*
** Rules
*/
int						swap_a_b(t_stack *a);
int						ss(t_stack *a, t_stack *b);
int						push_a(t_stack *a, t_stack *b);
int						push_b(t_stack *a, t_stack *b);
int						rotate_a_b(t_stack *s);
int						rr(t_stack *a, t_stack *b);
int						rr_a_b(t_stack *s);
int						rrr(t_stack *a, t_stack *b);

/*
** Visual Debug functions in terminal
*/
int						debug_print(t_stack *a, t_stack *b, int rule);
int						debug_c(t_stack_node *ad, t_stack_node *bd, int rule);
void					debug_c_helper(int	rule, int *a, int *b);
int						debug_v(t_stack_node *ad, t_stack_node *bd);
int						check_debug_option(char *argv[], t_stack *a);

/*
** Index assignment functions
*/
void					give_index(t_stack *a);
t_stack_node			*find_min_num(t_stack *a);

/*
** Markup functions
*/
void					optimal_markup_gt(t_stack *a);
size_t					gt_markup(t_stack *a, t_stack_node *tmp);
void					clear_keep(t_stack *a);
void					optimal_markup_index(t_stack *a);
size_t					index_markup(t_stack *a, t_stack_node *tmp);

/*
** Solve
*/
t_stack					*solve_index(t_stack *a, t_stack *b);
t_stack					*solve_gt(t_stack *a, t_stack *b);
int						a_has_false(t_stack *a);
void					from_b_to_a(t_stack *a, t_stack *b, t_stack *rules);
void					sort_a(t_stack *a, t_stack *rules);
void					from_b_to_a(t_stack *a, t_stack *b, t_stack *rules);

/*
** Direction
*/
t_direction				*init_direction_struct();
void					optimal_direction(t_stack *a, t_stack *b,
t_direction *d);
t_stack_node			*find_direct_in_a(t_stack *a, size_t index_b);

#endif
