/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:52:19 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/15 15:10:39 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	append_node(t_stack *stack, int n)
{
	t_node *node;
	
	if(!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->value = n;
	node->next = NULL;
	node->prev = stack->tail;
	if (!stack->head)
		stack->head = node;
	else
		stack->tail->next = node;
	stack->tail = node;
	stack->size++;
}

int	stack_len(t_stack *stack)
{
	int		i;
	t_node	*current;
	
	if (!stack || !(stack->head))
		return (0);
	i = 0;
	current = stack->head;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
	return (i);
}

bool	stack_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !(stack->head))
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (false);
		current = current->next;
	}
	return (true);
}