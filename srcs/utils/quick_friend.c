/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_friend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:04 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/18 22:22:06 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_ranks(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		printf("Value: %d\n", current->rank);
		current = current->next;
	}
}

void	quick_friend(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	//int	i;
	int	start_len;
	
	min_max(a, &min, &max);
	while(!stack_sorted(a))
	{
		if (stack_len(a) <= 10 || max - min < 10)
		{
			sort_ten(a, b);
			break;
		}
		start_len = stack_len(a);
		(a)->median = (start_len / 2);
		(a)->quarter = (a->median / 2);
		ranking(a);
		print_ranks(a);
		while (stack_len(a) > (start_len - (a)->median) && stack_len(a) > 0)
		{
			if (a->head->rank <= a->median)
			{
				pb(b, a, false);
				if(b->head->rank <= a->quarter && stack_len(b) >= 2)
					rb(b, false);	
			}
			else
				ra(a, false);
		}
		//min = find_min(a);
	}
	while(b)
	{
		
	}
}