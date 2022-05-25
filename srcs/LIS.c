/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:47 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/25 16:20:29 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*lis(int *v, int len, t_stack *p)
{
	int			i;
	t_stack		*n;
	t_stack		*fds;
	int			checkneg;

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
			p = n + i;
	fds = ft_calloc(len, sizeof(*p));
	fds = p;
	checkneg = 0;
	while (fds)
	{
		p->lislen += 1;
		if (fds->cnt < 0)
		{
			checkneg++;
		}
		fds = fds->next;
	}
	if (checkneg == len - 1)
		p->lislen--;
	if (ft_lstindex(p->lislen - 2, p)->cnt < 0)
		p->lislen--;
	return (p);
}

static int	check_if_dif_nb(int a, int b)
{
	if (a != b)
		return (1);
	return (0);
}

void	notlis_gob(t_supsta *sup, int *arr_lst)
{
	t_stack	*p;
	int		*arr_lis;
	int		*e_i;
	int		lst_size;
	int		fds;

	e_i = (int [2]){-1, 0};
	lst_size = sup->elenum;
	p = calloc(sizeof(*p), lst_size);
	p = lis(arr_lst, lst_size, p);
	fds = p->lislen;
	arr_lis = (int *)malloc(sizeof(int) * fds);
	if (p->lislen == sup->elenum)
		exit(0);
	while (p->next)
	{
		arr_lis[e_i[1]] = p->cnt;
		p = p->next;
		e_i[1]++;
	}
	arr_lis[e_i[1]] = p->cnt;
	e_i[1] = 0;
	while (e_i[1]++ < lst_size)
	{
		while (++e_i[0] < fds)
		{
			if (!check_if_dif_nb(sup->a->cnt, arr_lis[e_i[0]]))
			{
				break ;
			}
		}
		if (e_i[0] == fds)
		{
			sup = pb(sup);
			ft_printf("pb\n");
		}
		else
		{
			sup->a = rotater(sup->a);
			ft_printf("ra\n");
		}
		e_i[0] = -1;
	}
}

void	putinrightplace(t_supsta *sup, t_calccom *fds)
{
	int	a;

	a = ft_lstsize(sup->a);
	if (fds->rot_a < a / 2)
	{
		while (fds->rot_a && fds->rot_b)
		{
			sup = super_rotater(sup);
			ft_printf("rr\n");
			fds->rot_a--;
			fds->rot_b--;
		}
		while (fds->rot_a)
		{
			sup->a = rotater(sup->a);
			ft_printf("ra\n");
			fds->rot_a--;
		}
	}
	else
	{
		while (a - fds->rot_a > 0)
		{
			sup->a = reverse_rotater(sup->a);
			ft_printf("rra\n");
			a--;
		}
	}
	while (fds->rot_b)
	{
		sup->b = rotater(sup->b);
		ft_printf("rb\n");
		fds->rot_b--;
	}
	sup = pa(sup);
	ft_printf("pa\n");
}

int	calc_e(t_stack *a, int e)
{
	int		min;
	t_stack	*fds;

	fds = a;
	min = fds->cnt;
	min = calc_min(fds, min);
	while (fds->cnt != min)
	{
		fds = fds->next;
		e++;
	}
	return (e);
}

t_stack	*putminonposition(t_stack *stack, int init)
{
	while (stack->cnt != init)
		stack = rotater(stack);
	return (stack);
}

t_calccom	*get_fastest_nb(t_supsta *sup, t_calccom *cmds)
{
	t_buejeitodeseler	*d;
	int					flag;
	int					size;
	t_supsta			*t;
	t_supsta			*temp2;

	t = sup;
	temp2 = sup;
	d = malloc(sizeof(t_buejeitodeseler));
	d->i = 0;
	d->e = 0;
	d->rec = 236746;
	d->max = 0;
	d->initval = t->a->cnt;
	flag = 1;
	size = ft_lstsize(sup->b);
	d->max = calc_max(t->a, d->max);
	while (d->i < size)
	{
		if (t->b->cnt > d->max)
		{
			d->e = calc_e(t->a, d->e);
			flag = 0;
		}
		while ((t->a->cnt < t->b->cnt || l_indx(t->a)->cnt > t->b->cnt) && flag)
		{
			t->a = rotater(t->a);
			d->e++;
		}
		if (d->rec > d->e + d->i)
		{
			cmds->rot_a = d->e;
			d->rec = d->e + d->i;
			cmds->rot_b = d->i;
		}
		flag = 1;
		d->i++;
		d->e = 0;
		t->a = putminonposition(t->a, d->initval);
		temp2->a = putminonposition(temp2->a, d->initval);
		t->b = rotater(t->b);
	}
	return (cmds);
}
