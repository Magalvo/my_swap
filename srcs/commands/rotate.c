/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:17:24 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/14 21:46:32 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_node	*first;
	t_node	*last;

	if (!(*stack)->head || !(*stack)->head->next)
		return ;
	first = (*stack)->head;
	(*stack)->head = (*stack)->head->next;
	(*stack)->head->prev = NULL;
	last = first;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **a, bool print)
{
	rotate(a);
	if (!print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		ft_putstr_fd("rb\n", 1);
}