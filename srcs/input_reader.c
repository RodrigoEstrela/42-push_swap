/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:19:35 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/02 15:50:48 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	check_same(int ac, t_stack *stck)
{
	int	i;
	int	hold;

	i = 1;
	hold = stck[0].cnt;
	while (++i < ac)
		if (hold == stck[i].cnt)
		{
			ft_printf("Error\n");
			exit(0);
		}
	return ;
}

void	error_input_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		exit(0);
	while(++i < ac)
	{
		if (ft_isdigit(ft_atoi(av[i])) == 0)
		{
			ft_printf("%i\n", ft_atoi(av[i]));
			ft_printf("Error\n");
			exit(0);
		}
		else if (ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
		{
			ft_printf("Error\n");
			exit(0);
		}
	}

}

/*t_supsta	*input_reader(int ac, char **av, t_supsta *sup)
{
	error_input_check(ac, av);

}*/
