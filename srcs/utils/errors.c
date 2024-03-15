/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 18:32:23 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/14 21:47:33 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_all(char **in)
{
	int	ctd;

	ctd = 0;
	while (in[ctd])
		free(in[ctd++]);
	free(in);
}

void	free_stack(t_stack **stack, char **av, bool flag)
{
	t_node  *tmp;
	t_node  *current;

	if (flag)
		free_all(av);
	if(!stack)
		return ;
	current = (*stack)->head;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	error_syntax(char *str_nbr)
{
	if(!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
			return (ft_putstr_fd("Error1\n", 2), 1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
			&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
			return (ft_putstr_fd("Error2\n", 2), 1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (ft_putstr_fd("Error3\n", 2), 1);
	}
	return (0);
} 

int	error_repetition(t_stack *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->head->value == nbr)
			return (ft_putstr_fd("Error\n", 2), 1);
		a->head = a->head->next;
	}
	return (0);
}
void	error_free(t_stack **a, char **argv, bool flag_argc_2)
{
	free_stack(a, argv - 1, flag_argc_2);
	exit(1);
}