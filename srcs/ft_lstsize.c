/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:16:15 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/27 17:51:27 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_lstsize(t_stack *stck)
{
	int		i;
	t_stack	temp;

	temp.next = stck;
	i = 0;
	while (temp.next != NULL)
	{
		i++;
		temp.next = temp.next -> next;
	}
	return (i);
}
