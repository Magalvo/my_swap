/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:29:10 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/15 15:31:37 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

typedef	struct s_stack t_stack;
typedef struct s_node t_node;

struct s_node
{
	int				value;
	int				rank;
	int				cost;
	int				index;
	bool			cheapest;	
	bool			above_median;
	struct s_node	*prev;
	struct s_node	*next;
};

struct	s_stack
{
	int		size;
	int		median;
	int		quarter;
	t_node	*head;
	t_node	*tail;
	t_node	*target;
};


//=============================== Errors ===============================//
void	free_all(char **in);
void	free_stack(t_stack *stack, char **av, bool flag);
int		error_syntax(char *str_nbr);
int		error_repetition(t_stack *a, int nbr);
void	error_free(t_stack *a, char **argv, bool flag_argc_2);

bool	stack_sorted(t_stack *stack);
int		stack_len(t_stack *stack);

void	sort_three(t_stack *a);
void	sort_ten(t_stack *a, t_stack *b);
int		ranking(t_stack *stack);
void	min_max(t_stack *stack, int *min, int *max);

void	pa(t_stack *a, t_stack *b, bool print);
void	pb(t_stack *b, t_stack *a, bool print);

void	sa(t_stack *a, bool print);
void	sb(t_stack *b, bool print);

void	ra(t_stack *a, bool print);
void	rb(t_stack *b, bool print);

void	append_node(t_stack *stack, int n);

t_node	*find_min(t_stack *stack);
t_node	*find_max(t_stack *stack);
t_node	*find_last(t_stack *stack);

void	quick_friend(t_stack *a, t_stack *b);

void	rra(t_stack *a, bool print);
void	rrb(t_stack *b, bool print);
void	rrr(t_stack *a, t_stack *b, bool print);

void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strdup(char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
long			ft_atol(const char *str);

void	init_a(t_stack *a, char **argv, bool flag);

#endif