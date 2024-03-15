/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:10 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/15 14:23:02 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack *dst, t_stack *src)
{
	t_node	*push_node;

	if (!src)
		return ;
	push_node = (src)->head;
	(src)->head = (src)->head->next;
	if (src)
		(src)->head->prev = NULL;
	push_node->prev = NULL;
	if (!dst)
	{
		(dst)->head = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = (dst)->head;
		(dst)->head->prev = push_node;
		(dst)->head = push_node;
	}
}

void	pa(t_stack *a, t_stack *b, bool print)
{
	push(a, b);
	if (!print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *b, t_stack *a, bool print)
{
	push(a, b);
	if (!print)
		ft_putstr_fd("pa\n", 1);
}
