/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_friend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:36:04 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/15 15:37:38 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	quick_friend(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	i;
	int	start_len;
	
	min_max(a, &min, &max);
	while(!stack_sorted(a))
	{
		if (stack_len(a) <= 10 || max - min < 10)
		{
			sort_ten(a, b);
			break;
		}
		(a)->median = (max - min) / 2;
		(a)->quarter = (a->median + min) / 2;
		ranking(a);
		start_len = stack_len(a);
		i = 0;
		while (i < start_len)
		{
			if (a->head && a->head->rank <= a->median)
			{
				pb(b, a, false);
				if(b->head->rank <= a->quarter && stack_len(b) >= 2)
					rb(b, false);	
			}
			else
				ra(a, false);
			i++;
		}	
		min_max(a, &min, &max);
	}
}