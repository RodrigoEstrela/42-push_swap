/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:15:06 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/25 14:43:23 by rdas-nev         ###   ########.fr       */
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

int	calc_min(t_stack *stack, int min)
{
	t_stack	*tmp;
	
	tmp = stack;
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

t_stack *putminonstart(t_stack *stack, int size)
{
	int min;
	int i;
	t_stack *tmp;

	i = 0;
	tmp = stack;
	min = stack->cnt;
	min = calc_min(stack, min);
	while (tmp->cnt != min)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size / 2)
	{	
		while (i > 0)
		{
			stack = rotater(stack);
			ft_printf("ra\n");
			i--;
		}
		return (stack);
	}
	int a = size - i;	
	while (a > 0)
	{
		stack = reverse_rotater(stack);
		ft_printf("rra\n");
		a--;
	}
	return (stack);
}

t_stack *putmaxonstart(t_stack *stack, int size)
{
	int max;
	int i;
	t_stack *tmp;

	i = 0;
	tmp = stack;
	max = stack->cnt;
	max = calc_max(stack, max);
	while (tmp->cnt != max)
	{
		i++;
		tmp = tmp->next;
	}
	if (i <= size / 2)
	{	
		while (i > 0)
		{
			stack = rotater(stack);
			ft_printf("ra\n");
			i--;
		}
		return (stack);
	}
	int a = size - i;	
	while (a > 0)
	{
		stack = reverse_rotater(stack);
		ft_printf("rra\n");
		a--;
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

t_supsta	*gen_gator(t_supsta *sup, char *size, char *big)
{
	int	i = -1;
	int	nb = atoi(size);
	int	cap = atoi(big);
	int	max = nb;
	int	rando = 0;
	int	sign;
	int	lst[nb];
	sup->elenum = 0;
	srand(time(0));
	while (++i < max)
	{
		sign = rand()%2;
		if (sign == 0)
			sign = -1;
		rando = rand()%cap * sign;
		while (check_same(lst, rando, i))
			rando = rand()%cap * sign;
		lst[i] = rando;
		ft_lstadd_back(&sup->a, ft_lstnew(rando));
		sup->elenum++;
	}
	return (sup);
}
t_stack	*only_three(t_stack *stack)
{
	int min;

	min = stack->cnt;
	min = calc_min(stack, min);
	if (ft_lstindex(0, stack)->cnt == min)
	{
		stack = rotater(stack);
		ft_printf("ra\n");
	}
	else if (ft_lstindex(1, stack)->cnt == min)
	{
		stack = reverse_rotater(stack);
		ft_printf("rra\n");
	}

	if (ft_lstindex(0, stack)->cnt > ft_lstindex(1, stack)->cnt)
	{
		swap(stack);
		ft_printf("sa\n");
		stack = reverse_rotater(stack);
		ft_printf("rra\n");
		return (stack);
	}
	stack = reverse_rotater(stack);
	ft_printf("rra\n");
	return (stack);
}
void	only_four(t_supsta *sup)
{
	sup->a = putmaxonstart(sup->a, sup->elenum);
	sup = pb(sup);
	ft_printf("pb\n");
	sup->a = only_three(sup->a);
	sup = pa(sup);
	sup->a = rotater(sup->a);
	ft_printf("pa\n");
	ft_printf("ra\n");
}
void	only_five(t_supsta *sup)
{
	sup->a = putmaxonstart(sup->a, sup->elenum);
	sup = pb(sup);
	ft_printf("pb\n");
	sup->a = putminonstart(sup->a, sup->elenum -1);
	sup = pb(sup);
	ft_printf("pb\n");
	sup->a = only_three(sup->a);
	sup = pa(sup);
	sup = pa(sup);
	sup->a = rotater(sup->a);
	ft_printf("pa\n");
	ft_printf("pa\n");
	ft_printf("ra\n");
}

int	main(int ac, char **av)
{
	t_supsta	*sup;
	
//	(void)ac;
	sup = malloc(sizeof(t_supsta));
	if (!sup)
		exit(0);
	sup = input_reader(ac, av, sup);
//	sup = gen_gator(sup, av[1], av[2]);
//	print_stacks(sup->a, sup->b);
//	printf("elenum: %d\n", sup->elenum);
	if (sup->elenum == 2)
	{
		if (sup->a->next->cnt < sup->a->cnt)
		{
			swap(sup->a);
			ft_printf("sa\n");
		}
		exit(0);
	}
	if (sup->elenum == 3)
	{
		only_three(sup->a);
		exit(0);
	}
	if (sup->elenum == 4)
	{
		only_four(sup);
		exit(0);
	}
	if (sup->elenum == 5)
	{
		only_five(sup);
//		print_stacks(sup->a, sup->b);
		exit(0);
	}

	sup->a = putminonstart(sup->a, sup->elenum);

	int *arr;
	arr = malloc(sizeof(int) * sup->elenum);
	input_to_arr(arr, sup);
//	print_stacks(sup->a, sup->b);
	notlis_gob(sup, arr);

	t_calccom	*fds;

	fds = (t_calccom *)malloc(sizeof(t_calccom));
//	print_stacks(sup->a, sup->b);
	while (sup->b != NULL)
	{
		fds = get_fastest_nb(sup, fds);
		putinrightplace(sup, fds);
	}
	
	sup->a = putminonstart(sup->a, sup->elenum);
//	print_stacks(sup->a, sup->b);
	exit(0);
}
