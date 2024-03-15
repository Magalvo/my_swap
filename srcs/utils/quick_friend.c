/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_friend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:04 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/14 23:18:37 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	quick_friend(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	
	(*a)->max = find_max(*a);
	(*a)->min = find_min(*a);
	max = (*a)->max->value;
	min = (*a)->min->value;
	while(!stack_sorted(*a))
	{
		if (stack_len(*a) <= 10 || max - min < 10)
		{
			sort_ten(a, b);
			break;
		}
		(*a)->median = max - min / 2;
		(*a)->quarter = ((*a)->median + min) / 2;
		(*a)->tail = find_last(*a);
		(*a)->size = stack_len(*a);
		ranking(a);
		while (stack_len(*a) > (*a)->size - (*a)->median && stack_len(*a) > 0)
		{
			if ((*a)->head->rank <= (*a)->median)
			{
				pb(b, a, false);
				if((*b)->head->rank <= (*a)->quarter && stack_len(*b) >= 2)
					rb(b, false);	
			}
			else
				ra(a, false);
		}	
	}
}