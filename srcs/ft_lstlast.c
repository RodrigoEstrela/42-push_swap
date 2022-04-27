/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:30:36 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/27 14:39:01 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*ft_lstlast(t_stack *stck)
{
	t_stack	temp;

	if (!stck)
		return (NULL);
	temp.next = stck;
	while (temp.next -> next != NULL)
	{
		temp.next = temp.next -> next;
	}
	return (temp.next);
}
