/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:53:22 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/15 14:57:07 by dde-maga         ###   ########.fr       */
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