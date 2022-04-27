/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:15:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/27 18:33:43 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	main(int ac, char **av)
{
	int	i;
	int	nb;
	t_stack	*a;
	t_stack *b;

	i = 0;
	nb = 0;
	a = ft_lstnew(nb);
	b = ft_lstnew(nb);
	while (++i < ac)
	{
		nb = ft_atoi(av[i]);
		ft_lstadd_back(&a, ft_lstnew(nb));
		ft_lstadd_back(&b, ft_lstnew(0));
	}
	ft_printf("\nInitial stage, for testing b is equal to a, instead of empty\n");
	i = -1;
	while (++i < ac - 1)
		ft_printf("%d	%d\n", ft_lstindex(i, a)->cont, ft_lstindex(i, b)->cont);
	ft_printf("-	-\na	b\n\n");
	
	ft_printf("\nSwap a=============\n");
	sa(a);
	i = -1;
	while (++i < ac - 1)
		ft_printf("%d	%d\n", ft_lstindex(i, a)->cont, ft_lstindex(i, b)->cont);
	ft_printf("-	-\na	b\n\n");
	
	ft_printf("\nSwap b=============\n");	
	sb(b);
	i = -1;
	while (++i < ac - 1)
		ft_printf("%d	%d\n", ft_lstindex(i, a)->cont, ft_lstindex(i, b)->cont);
	ft_printf("-	-\na	b\n\n");

	ft_printf("\nSwap both=============\n");	
	ss(a, b);
	i = -1;
	while (++i < ac - 1)
		ft_printf("%d	%d\n", ft_lstindex(i, a)->cont, ft_lstindex(i, b)->cont);
	ft_printf("-	-\na	b\n\n");
	
	ft_printf("\nPush b=============\n");
	pb(&a, &b);
	i = -1;
	while(++i < ac - 1)
		ft_printf("%d	%d\n", ft_lstindex(i, a)->cont, ft_lstindex(i, b)->cont);
	ft_printf("-	-\na	b\n\n");
}
