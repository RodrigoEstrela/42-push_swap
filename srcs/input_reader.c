/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:19:35 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/27 16:01:49 by rdas-nev         ###   ########.fr       */
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
		inp = ft_calloc(strcount(av[i], 32), sizeof(**inp));
		inp = ft_split(av[i], 32, inp);
		while (inp[j])
		{
			if (!is_number(inp[j]))
				error_message();
			else if (ft_atoi(inp[j]) > INT_MAX || ft_atoi(inp[j]) < INT_MIN)
				error_message();
			free(inp[j]);
			j++;
		}
		free(inp);
		j = 0;
		i++;
	}
}

t_supsta	*input_reader(int ac, char **av, t_supsta *sup)
{
	int		*i_j;
	char	**inputs;

	i_j = (int [2]){1, 0};
	error_input_check(ac, av);
	while (i_j[0] < ac)
	{
		inputs = ft_calloc(strcount(av[i_j[0]], 32), sizeof(**inputs));
		inputs = ft_split(av[i_j[0]], 32, inputs);
		while (inputs[i_j[1]])
		{
			ft_lstadd_back(&sup->a, ft_lstnew(ft_atoi(inputs[i_j[1]])));
			free(inputs[i_j[1]]);
			i_j[1]++;
			sup->elenum++;
		}
		free(inputs);
		i_j[1] = 0;
		i_j[0]++;
	}
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
