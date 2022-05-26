/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:47 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/26 13:40:27 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkneg(t_stack *p, int len)
{
	t_stack	*fds;
	int		checkneg;

	fds = ft_calloc(len, sizeof(*p));
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
	free(fds);
	return (p->lislen);
}

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
	p->lislen = checkneg(p, len);
	free(n);
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

	c = malloc(sizeof(t_cenas));
	c->e_i = (int [2]){-1, 0};
	c->lst_size = sup->elenum;
	c->p = calloc(sizeof(*c->p), c->lst_size);
	c->p = lis(arr_lst, c->lst_size, c->p);
	c->fds = c->p->lislen;
	c->arr_lis = (int *)malloc(sizeof(int) * c->fds);
	if (c->p->lislen == sup->elenum)
		exit(0);
	while (c->p->next)
	{
		c->arr_lis[c->e_i[1]] = c->p->cnt;
		c->p = c->p->next;
		c->e_i[1]++;
	}
	c->arr_lis[c->e_i[1]] = c->p->cnt;
	c->e_i[1] = 0;
	nemsei(sup, c);
}
