/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:30:16 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/27 17:58:58 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sa(t_stack *a)
{
	int	hold;
	
	if (ft_lstsize(a) < 3)
		return ;
	hold = ft_lstindex(0, a)->cont;
	ft_lstindex(0, a)->cont = ft_lstindex(1, a)->cont;
	ft_lstindex(1, a)->cont = hold;
}

void	sb(t_stack *b)
{
	int	hold;
	
	if (ft_lstsize(b) < 3)
		return ;
	hold = ft_lstindex(0, b)->cont;
	ft_lstindex(0, b)->cont = ft_lstindex(1, b)->cont;
	ft_lstindex(1, b)->cont = hold;
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
