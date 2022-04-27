/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:02:09 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/27 16:45:38 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*ft_lstindex(int index, t_stack *stack)
{
	t_stack	*ret;
	int c;

	ret = stack;
	c = 0;
	while ((c++ < index + 1) && ret)
		ret = ret->next;
	return (ret);
}
