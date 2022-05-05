/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:02:09 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/05 13:45:55 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*ft_lstindex(int index, t_stack *stack)
{
	t_stack	*ret;
	int		c;

	ret = stack;
	c = 0;
	while ((c++ < index) && ret)
		ret = ret->next;
	return (ret);
}
