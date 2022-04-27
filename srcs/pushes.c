/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:41:23 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/27 18:33:40 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	ft_lstadd_front(a, ft_lstnew(ft_lstindex(0, *b)->cont));
//	ft_lstdelone(ft_lstindex(0, b), );
}

void	pb(t_stack **a, t_stack **b)
{
	int	hold;

	hold = ft_lstindex(0, *a)->cont;
	ft_lstadd_front(b, ft_lstnew(hold));
//	ft_lstdelone(ft_lstindex(0, a), );
}
