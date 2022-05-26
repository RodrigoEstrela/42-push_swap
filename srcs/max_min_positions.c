/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:31:39 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/26 12:54:00 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	calc_min(t_stack *stack, int min)
{
	t_stack	*tmp;

	tmp = stack;
	min = tmp->cnt;
	while (tmp)
	{
		if (min > tmp->cnt)
			min = tmp->cnt;
		tmp = tmp->next;
	}
	return (min);
}

int	calc_max(t_stack *stack, int max)
{
	t_stack	*tmp;

	tmp = stack;
	max = tmp->cnt;
	while (tmp)
	{
		if (max < tmp->cnt)
			max = tmp->cnt;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*putminonstart(t_stack *stack, int size)
{
	int		*i_a;
	t_stack	*tmp;

	i_a = (int [3]){0, 544, calc_min(stack, 544)};
	tmp = stack;
	while (tmp->cnt != i_a[2] && ++i_a[0])
		tmp = tmp->next;
	if (i_a[0] <= size / 2)
	{
		while (i_a[0]-- > 0)
		{
			stack = rotater(stack);
			ft_printf("ra\n");
		}
		return (stack);
	}
	i_a[1] = size - i_a[0];
	while (i_a[1]-- > 0)
	{
		stack = reverse_rotater(stack);
		ft_printf("rra\n");
	}
	return (stack);
}

t_stack	*putmaxonstart(t_stack *stack, int size)
{
	int		*i_a;
	t_stack	*tmp;

	i_a = (int [3]){0, 544, calc_max(stack, 544)};
	tmp = stack;
	while (tmp->cnt != i_a[2] && ++i_a[0])
		tmp = tmp->next;
	if (i_a[0] <= size / 2)
	{
		while (i_a[0]-- > 0)
		{
			stack = rotater(stack);
			ft_printf("ra\n");
		}
		return (stack);
	}
	i_a[1] = size - i_a[0];
	while (i_a[1]-- > 0)
	{
		stack = reverse_rotater(stack);
		ft_printf("rra\n");
	}
	return (stack);
}
