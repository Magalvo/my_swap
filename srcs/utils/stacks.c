/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:52:19 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/14 23:20:55 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	append_node(t_stack **stack, int n)
{
	t_node *node;
	t_node *last_node;

	if(!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->value = n;
	if (!(*stack))
	{
		(*stack)->head = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_len(t_stack *stack)
{
	int	i;
	
	if (!stack)
		return (0);
	i = 0;
	while ((stack)->head->next)
	{
		stack->head->index = i;
		stack->head = stack->head->next;
		i++;
	}
	return (i);
}

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->head->next)
	{
		if (stack->head->value > stack->head->next->value)
			return (false);
		stack->head = stack->head->next;
	}
	return (true);
}