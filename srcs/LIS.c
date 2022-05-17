/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:50:44 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/17 16:38:31 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lis	*lis(int *v, int len)
{
	int			i;
	t_superlis	*sl;

	i = -1;
	sl = ft_calloc(len, sizeof(*sl->p));
	sl->p = ft_calloc(len, sizeof(*sl->p));
	sl->n = ft_calloc(len, sizeof(*sl->n));
	while (++i < len)
		sl->n[i].val = v[i];
	while (i--)
	{
		sl->p = sl->n + i;
		while (sl->p++ < sl->n + len)
		{
			if (sl->p->val > sl->n[i].val && sl->p->len >= sl->n[i].len)
			{
				sl->n[i].next = sl->p;
				sl->n[i].len = sl->p->len + 1;
			}
		}
	}
	sl->p = sl->n;
	while (++i < len)
		if (sl->n[i].len > sl->p->len)
			sl->p = sl->n + i;
	sl->p->len++;
	// so para o print
	t_lis *fds = calloc(len, sizeof *sl->p);
	fds = sl->p;
	do printf(" %d", fds->val); while ((fds = fds->next));
	putchar('\n');
	/////////////////////
	free(sl->n);
	return(sl->p);
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
	t_lis  *p;
	p = (t_lis *)malloc(sizeof(t_lis));
	p = lis(arr_lst, lst_size);
	int e;
	int	*arr_lis;
	arr_lis = (int *)malloc(sizeof(int) * p->len);
	int i = 0;
	int fds = p->len;
	while (p)
	{
		arr_lis[i] = p->val;
		p = p->next;
		i++;
	}
	i = 0;
	e = -1;
	printf("Stack A\n");
	print_stacks(sup->a, sup->b);
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
			sup = pb(sup);
		else
			sup->a = rotater(sup->a);
		e = -1;
	}
	print_stacks(sup->a, sup->b);
	free(arr_lis);
	free(arr_lst);
}

void	putinrightplace(t_supsta *sup)
{
	while(!(sup->a->cnt > sup->b->cnt && ft_lastindex(sup->a)->cnt < sup->b->cnt))
	{
		sup->a = rotater(sup->a);
	}
	pa(sup);
}
