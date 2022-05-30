/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:19:35 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/30 17:01:35 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

static void	check_same(t_supsta *sup)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	sup->elenum--;
	while (i < ft_lstsize(sup->a) - 1)
	{
		while (j < ft_lstsize(sup->a))
		{
			if (ft_lstindex(i, sup->a)->cnt == ft_lstindex(j, sup->a)->cnt)
				error_message();
			j++;
		}
		i++;
		j = i + 1;
	}
	return ;
}

void	error_input_check(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac < 2)
		exit(0);

	while (i < ac)
	{
		if (!is_number(av[i]))
			error_message();
		else if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)	
			error_message();
		i++;
	}
}

t_supsta	*input_reader(int ac, char **av, t_supsta *sup)
{
	int		i;

	i = 1;
	if (ft_strchr(av[i], 32))
	{
		ac = strcount(av[i], 32);
		av = ft_split(av[i], 32);
		i = 0;
	}
	error_input_check(ac, av);
	while (i < ac)
	{
		ft_lstadd_back(&sup->a, ft_lstnew(ft_atoi(av[i])));
		i++;
		sup->elenum++;
	}
	i++;
	check_same(sup);
	if (sup->elenum == 1)
		exit(0);
	hardcoded(sup);
	return (sup);
}

int	*input_to_arr(int *arr, t_supsta *sup)
{
	t_stack	*tmp;
	int		i;

	tmp = sup->a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->cnt;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}
