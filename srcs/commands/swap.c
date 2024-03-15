/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:40:03 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/15 14:24:12 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!stack || !(stack)->head->next)
		return ;
	first = (stack)->head;
	second = (stack)->head->next;
	third = second->next;
	second->next = first;
	second->prev = third;
	first->next = third;
	first->prev = second;
	if (third)
		third->prev = first;
	(stack)->head = second;
}

void	sa(t_stack *a, bool print)
{
	swap(a);
	if (!print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b, bool print)
{
	swap(b);
	if (!print)
		ft_putstr_fd("sb\n", 1);
}