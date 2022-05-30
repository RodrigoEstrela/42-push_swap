/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:47 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/30 12:28:28 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkneg(t_stack *p, int len)
{
	t_stack	*fds;
	int		checkneg;

	fds = p;
	checkneg = 0;
	while (fds)
	{
		p->lislen += 1;
		if (fds->cnt < 0)
			checkneg++;
		fds = fds->next;
	}
	if (checkneg == len - 1)
		p->lislen--;
	if (ft_lstindex(p->lislen - 2, p)->cnt < 0)
		p->lislen--;
	return (p->lislen);
}

static t_stack	*lis(int *v, int len, t_stack *p)
{
	int			i;
	t_stack		*n;

	p->lislen = 0;
	i = -1;
	n = p;//ft_calloc(len, sizeof(*n));
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
	p->lislen = checkneg(p, len);
	return (p);
}

static int	check_if_dif_nb(int a, int b)
{
	if (a != b)
		return (1);
	return (0);
}

static void	nemsei(t_supsta *sup, t_cenas *c)
{
	while (c->e_i[1]++ < c->lst_size)
	{
		while (++c->e_i[0] < c->fds)
			if (!check_if_dif_nb(sup->a->cnt, c->arr_lis[c->e_i[0]]))
				break ;
		if (c->e_i[0] == c->fds)
			sup = pb(sup);
		else
		{
			sup->a = rotater(sup->a);
			ft_printf("ra\n");
		}
		c->e_i[0] = -1;
	}
}

void	notlis_gob(t_supsta *sup, int *arr_lst)
{
	t_cenas	*c;
	t_stack	*p;

	c = ft_calloc(sizeof(t_cenas), 1);
	c->e_i = (int [2]){-1, 0};
	c->lst_size = sup->elenum;
	p = malloc(sizeof(t_stack) * c->lst_size);
	free(p);
	p = lis(arr_lst, c->lst_size, p);
	c->fds = p->lislen;
	c->arr_lis = (int *)ft_calloc(sizeof(int), c->fds);
	if (p->lislen == sup->elenum)
		exit(0);
	while (c->e_i[1] < c->lst_size)
	{
		c->arr_lis[c->e_i[1]] = p->cnt;
		p = rotater(p);
		c->e_i[1]++;
	}
	c->arr_lis[c->e_i[1]] = p->cnt;
	c->e_i[1] = 0;
	nemsei(sup, c);
	free(c->arr_lis);
	free(c);
}
