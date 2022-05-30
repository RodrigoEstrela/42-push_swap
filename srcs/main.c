/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:15:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/27 16:03:02 by rdas-nev         ###   ########.fr       */
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

static t_supsta	*sup_initializer(t_supsta *sup, int ac, char **av)
{
	sup->elenum = 1;
	sup = input_reader(ac, av, sup);
	sup->a = putminonstart(sup->a, sup->elenum);
	return (sup);
}

static void	do_array_things(int *arr, t_supsta *sup)
{
	input_to_arr(arr, sup);
	notlis_gob(sup, arr);
}

static void	do_cmds_things(t_calccom *cmds, t_supsta *sup)
{
	while (sup->b != NULL)
	{
		cmds = get_fastest_nb(sup, cmds);
		putinrightplace(sup, cmds);
	}
}

int	main(int ac, char **av)
{
	t_supsta	*sup;
	t_calccom	*cmds;
	int			*arr;

	sup = ft_calloc(sizeof(t_supsta), 1);
	sup = sup_initializer(sup, ac, av);
	arr = ft_calloc(sizeof(int), sup->elenum);
	do_array_things(arr, sup);
	cmds = ft_calloc(sizeof(t_calccom), 1);
	do_cmds_things(cmds, sup);
	sup->a = putminonstart(sup->a, sup->elenum);
	while (sup->a)
	{
		free(sup->a);
		sup->a = sup->a->next;
	}
	free(sup);
	exit(0);
}
// use system("leaks push_swap"); before exit to check mem leaks
// https://github.com/lmalki-h/push_swap_tester
// git clone to root of pushswap dir
// put checker from subject page on tester
// bash ./push_swap_tester/tester.sh ./ 100 100
// execute from root of pushswap dir
