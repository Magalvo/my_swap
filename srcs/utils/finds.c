/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:25:41 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/14 22:03:54 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*find_min(t_stack *stack)
{
	t_node	*min_node;
	int		min;
	
	min = INT_MAX;
	if (!stack)
		return (NULL);
	min_node = stack->head;
	while(stack->head->next)
	{
		if(stack->head->value < min)
		{
			min = stack->head->value;
			min_node = stack->head;
		}
		stack->head = stack->head->next;
	}
	return (min_node);
}

t_node	*find_max(t_stack *stack)
{
	t_node	*max_node;
	int		max;
	
	max = INT_MIN;
	if (!stack)
		return (NULL);
	max_node = stack->head;
	while(stack->head->next)
	{
		if(stack->head->value > max)
		{
			max = stack->head->value;
			max_node = stack->head;
		}
		stack->head = stack->head->next;
	}
	return (max_node);
}

t_node	*find_last(t_stack *stack)
{
	t_node	*last;

	if (!stack)
		return (NULL);
	while(stack->head->next)
		last = stack->head->next;
	return (last);
}