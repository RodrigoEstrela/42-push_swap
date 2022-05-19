/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:50:44 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/19 14:43:00 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*lis(int *v, int len, t_stack *p)
{
	int			i;
	t_stack		*n;

	p->lislen = 0;
	i = -1;
	n = ft_calloc(len, sizeof(*n));
	while (++i < len)
		n[i].cnt = v[i];
	while (i--)
	{
		p = n + i;
		while (p++ < n + len)
		{
			if (p->cnt > n[i].cnt && p->len >= n[i].len)
			{
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
	}
	p = n;
	while (++i < len)
		if (n[i].len > p->len)
		{
			p = n + i;
		}
	t_stack *fds = calloc(len, sizeof *p);
	fds = p;
	while (fds)
	{
		p->lislen += 1;
		fds = fds->next;
	}
	return (p);
}

static int	check_if_dif_nb(int a, int b)
{
	if (a != b)
		return 1;
	return 0;
}

void	notlis_gob(t_supsta *sup, int *arr_lst)
{
	int	lst_size = sup->elenum;
	t_stack  *p;
	p = calloc(sizeof(*p), lst_size);
	p = lis(arr_lst, lst_size, p);
	int e;
	int	*arr_lis;
	int fds = p->lislen;
	arr_lis = (int *)malloc(sizeof(int) * fds);
	int i = 0;
	
	while (p->next)
	{
		arr_lis[i] = p->cnt;
		p = p->next;
		i++;
	}
	arr_lis[i] = p->cnt;
	i = 0;
	e = -1;
	while (i++ < lst_size)
	{
		while (++e < fds)
		{
			if (!check_if_dif_nb(sup->a->cnt, arr_lis[e]))
			{
				break;
			}
		}
		if (e == fds)
		{
			sup = pb(sup);
			ft_printf("pb\n");
		}
		else
		{
			sup->a = rotater(sup->a);
			ft_printf("ra\n");
		}
		e = -1;
	}
}

void	putinrightplace(t_supsta *sup)
{
	int max;

	max = 0;
	max = calc_max(sup->a, max);
 
	if (sup->b->cnt >= max)
	{
		sup->a = putminonstart(sup->a);
		pa(sup);
		ft_printf("pa\n");
		return ;
	}
	while(sup->a->cnt < sup->b->cnt || ft_lastindex(sup->a)->cnt > sup->b->cnt)
	{
		sup->a = rotater(sup->a);
		ft_printf("ra\n");
	}
	pa(sup);
	ft_printf("pa\n");
}
