/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:15:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/26 12:28:01 by rdas-nev         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_supsta	*sup;
	t_calccom	*cmds;
	int			*arr;

	sup = malloc(sizeof(t_supsta));
	if (!sup)
		exit(0);
	sup->elenum = 1;
	sup = input_reader(ac, av, sup);
	hardcoded(sup);
	sup->a = putminonstart(sup->a, sup->elenum);
	arr = malloc(sizeof(int) * sup->elenum);
	input_to_arr(arr, sup);
	notlis_gob(sup, arr);
	cmds = (t_calccom *)malloc(sizeof(t_calccom));
	while (sup->b != NULL)
	{
		cmds = get_fastest_nb(sup, cmds);
		putinrightplace(sup, cmds);
	}
	sup->a = putminonstart(sup->a, sup->elenum);
	exit(0);
}
