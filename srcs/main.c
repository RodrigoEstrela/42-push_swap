/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:15:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/03 16:05:07 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	print_stacks(t_stack *stck_a, t_stack *stck_b)
{
	while (stck_a || stck_b)
	{
		if (stck_a)
			ft_printf("%d", stck_a->cnt);
		ft_printf("      ");
		if (stck_b)
			ft_printf("%d\n", stck_b->cnt);
		else
			ft_printf("\n");
		if (stck_a)
			stck_a = stck_a->next;
		if (stck_b)
			stck_b = stck_b->next;
	}
	ft_printf("-      -\na      b\n");
	ft_printf("################\n");
}

int main(int ac, char **av)
{
	int	i = 0;
	int	nb = 0;
	t_supsta *sup;
	
	error_input_check(ac, av);	
	sup = malloc(sizeof(t_supsta));
	ft_printf("ac: %d\n", ac);
	i = 0;
	while (++i < ac)
	{
		nb = ft_atoi(av[i]);
		ft_lstadd_back(&sup->a, ft_lstnew(nb));
	}
	check_same(ac, sup->a);
//	mvmnts_tester(sup);
	exit(0);
}
