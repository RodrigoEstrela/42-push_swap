/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:15:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/19 14:47:55 by rdas-nev         ###   ########.fr       */
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

int	calc_min(t_stack *stack)
{
	t_stack	*tmp;
	int min;
	
	tmp = stack;
	min = tmp->cnt;
	while (tmp)
	{
		if (min > tmp->cnt)
			min = tmp->cnt;
		tmp = tmp->next;
	}	
	return (min);
}

int	calc_max(t_stack *stack, int max)
{
	t_stack	*tmp;
	
	tmp = stack;
	max = tmp->cnt;
	while (tmp)
	{
		if (max < tmp->cnt)
			max = tmp->cnt;
		tmp = tmp->next;
	}	
	return (max);
}

t_stack *putminonstart(t_stack *stack)
{
	int min;

	min = calc_min(stack);
	while (stack->cnt != min)
	{
		stack = rotater(stack);
		ft_printf("ra\n");
	}
	return (stack);
}

int	check_same(int *lst, int rando, int max)
{
	int	i = -1;
	while (++i < max)
		if (rando == lst[i])
			return (1);
	return (0);
}

t_supsta	*gen_gator(t_supsta *sup, char *size)
{
	int	i = -1;
	int	nb = atoi(size);
	int	max = nb;
	int	rando = 0;
	int	lst[nb];
	srand(time(0));
	while (++i < max)
	{
		rando = rand()%1000;
		while (check_same(lst, rando, i))
			rando = rand()%1000;
		lst[i] = rando;
		ft_lstadd_back(&sup->a, ft_lstnew(rando));
	}
	return (sup);
}

int	main(int ac, char **av)
{
	t_supsta	*sup;
	
	(void)ac;
	sup = malloc(sizeof(t_supsta));
	if (!sup)
		exit(0);
	sup = input_reader(ac, av, sup);
//	sup = gen_gator(sup, av[1]);
//	print_stacks(sup->a, sup->b);
	sup->a = putminonstart(sup->a);

	int *arr;
	int	i = 0;
	arr = malloc(sizeof(int) * sup->elenum);
	input_to_arr(arr, sup);
	while (i < sup->elenum)
		i++;
	notlis_gob(sup, arr);
	while (sup->b)
		putinrightplace(sup);
	sup->a = putminonstart(sup->a);
	ft_printf("\n\n");
	//print_stacks(sup->a, sup->b);
	exit(0);
}
