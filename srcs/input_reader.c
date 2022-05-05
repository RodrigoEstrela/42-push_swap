/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:19:35 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/05 12:50:00 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	error_message(void)
{
	ft_printf("Error\n");
	exit(0);
}

static void	check_same(t_stack *stck)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ft_lstsize(stck) - 1)
	{
		while (j < ft_lstsize(stck))
		{
			if (ft_lstindex(i, stck)->cnt == ft_lstindex(j, stck)->cnt)
				error_message();
			j++;
		}
		i++;
		j = i + 1;
	}
	return ;
}

static void	error_input_check(int ac, char **av)
{
	int		i;
	int		j;
	char	**inp;

	i = 1;
	j = 0;
	if (ac < 2)
		exit(0);
	while (i < ac)
	{
		inp = ft_split(av[i], 32);
		while (inp[j])
		{
			if (!is_number(inp[j]) || ft_atoi(inp[j]) == ft_atoi("-"))
				error_message();
			else if (ft_atoi(inp[j]) > INT_MAX || ft_atoi(inp[j]) < INT_MIN)
				error_message();
			j++;
		}
		j = 0;
		i++;
	}
}

t_supsta	*input_reader(int ac, char **av, t_supsta *sup)
{
	int		i;
	int		j;
	char	**inputs;

	i = 1;
	j = 0;
	error_input_check(ac, av);
	while (i < ac)
	{
		inputs = ft_split(av[i], 32);
		while (inputs[j])
		{
			ft_lstadd_back(&sup->a, ft_lstnew(ft_atoi(inputs[j])));
			j++;
		}
		j = 0;
		i++;
	}
	check_same(sup->a);
	return (sup);
}
