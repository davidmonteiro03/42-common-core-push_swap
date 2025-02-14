/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:55:58 by dcaetano          #+#    #+#             */
/*   Updated: 2025/02/14 16:09:56 by dcaetano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>

enum
{
	RA,
	RB,
	RRA,
	RRB,
	RR,
	RRR,
};

typedef struct s_rotate
{
	int		ops[6];
}			t_rotate;

typedef struct s_element
{
	int		number;
	int		target;
}			t_element;

// ----- Parse ----- //
long int	ft_atol(const char *nptr);
char		*ft_joinfree(char *s1, char *s2);
char		**ft_acumulate(char **args);
void		ft_check(char *arg, bool *flag);
void		ft_parse(char **argv);
void		ft_checkdups(t_list *list);
bool		ft_smaller(void *cont1, void *cont2, int mode);
bool		ft_greater(void *cont1, void *cont2, int mode);
bool		ft_equal(void *cont1, void *cont2, int mode);

// ----- Free ------ //
void		ft_free(char **ptr);
void		free_strs(char **strs);
void		free_content(void *content);

// ----- Error ----- //
void		ft_error(void);

// ----- Fill ------ //
void		ft_fill(t_list **list, char **args);

// ----- Init ------ //
t_element	*new_element(int number);

// ---- Display ---- //
void		ft_display_content(void *content);
void		ft_display(t_list *list);

// -- Operations --- //
bool		ft_swap(t_list **list);
bool		ft_push(t_list **list_from, t_list **list_to);
bool		ft_rotate(t_list **list, int mode);

// ---- Execute ---- //
bool		ft_execute(char *op, t_list **list_a, t_list **list_b, bool print);
void		ft_multiexecute(t_list **list_a, t_list **list_b, t_rotate *rot);

// ---- Sortlist --- //
void		ft_sort3(t_list **list_a);
void		ft_sort(t_list **list_a, t_list **list_b);
void		ft_sortlist(t_list **list_a, t_list **list_b);

// ---- Utils 1 ---- //
int			ft_strcmp(const char *s1, const char *s2);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_countmoves(t_list *list, t_list *target);

// ---- Utils 2 ---- //
t_list		*ft_gettarget(t_list *list, bool (*compare)(void *, void *, int));
void		ft_set_targets_b(t_list **list_a, t_list **list_b);
void		ft_set_targets_a(t_list **list_a, t_list **list_b);
void		ft_push_best_to_b(t_list **list_a, t_list **list_b, t_rotate *rot);
void		ft_push_best_to_a(t_list **list_a, t_list **list_b, t_rotate *rot);

// ---- Utils 3 ---- //
bool		ft_issorted(t_list *list);
void		ft_optimize_moves_a(t_list **list_a, t_list **list_b, t_rotate *rot,
				t_list *node);
void		ft_optimize_moves_b(t_list **list_a, t_list **list_b, t_rotate *rot,
				t_list *node);
void		ft_optimize(t_list **list_a, t_list **list_b, t_rotate *rot,
				bool pos);

// ---- Utils 4 ---- //
void		ft_setmoves_ultimate(t_rotate *rot, int *rotate);
void		ft_setmoves(t_rotate *rot, int *rotate, bool fill);
t_list		*ft_findsecmin(t_list *list);

#endif
