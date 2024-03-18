/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:53:22 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/18 23:16:19 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node *get_best_friend(t_stack *a, int value)
{
	int		temp;
	t_node	*temp_node;

	temp = INT_MAX;
	while (a)
	{
		if (a->head->value > value && a->head->value < temp)
		{
			temp = a->head->value;
			temp_node = a->head;
		}
		a->head = a->head->next;
	}
	return (temp_node);
} 

void	set_target_b(t_stack *a, t_stack *b)
{
	t_node	*current;

	current = b->head;
	while (current)
	{
		current->target = get_best_friend(a, current->value);
		current = current->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	int	cheapest_value;
	t_node	*cheapest_node;
	t_node	*current;

	if (!stack || !(stack->head))
		return ;
	cheapest_value = INT_MAX;
	current = stack->head;
	while(current)
	{
		if (current->cost < cheapest_value)
		{
			cheapest_value = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	stack->cheapest_node = cheapest_node;
	cheapest_node->cheapest = true;
}

void	cost_analysis_b(t_stack *a, t_stack *b)
{
	int		len_a;
	int		len_b;
	t_node	*current;

	len_a = stack_len(a);
	len_b = stack_len(b);
	current = b->head;
	while (current)
	{
		current->cost = current->index;
		if (!(current->above_median))
			current->cost = len_b - (current->index);
		if (current->target->above_median)
			current += current->target->index;
		else
			current->cost += len_a - (current->target->index);
		current = current->next;
	}
}

void	move_b_to_a(t_stack *a, t_stack *b)
{
	t_node	*cheapest_node;
	
	cheapest_node = b->cheapest_node;
	if (cheapest_node->above_median && cheapest_node->target->above_median)
}