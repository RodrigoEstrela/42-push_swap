/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:47 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/24 17:59:56 by rdas-nev         ###   ########.fr       */
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

	t_stack *fds = ft_calloc(len, sizeof *p);
	fds = p;
	int checkneg = 0;
	while (fds)
	{
		p->lislen += 1;
		if (fds->cnt < 0)
		{
			checkneg++;
		}
		fds = fds->next;
		
	}
	printf("dakfjhiokjl nwrgiuoier;tgkjmelktjhgtk\n");
	print_stacks(p,p);
	ft_printf("checkneg: %d\nlislen: %d\n", checkneg, p->lislen);
	if (checkneg == len - 1)
		p->lislen--;
	if (ft_lstindex(p->lislen - 2, p)->cnt < 0)
		p->lislen--;
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
	
	if (p->lislen == sup->elenum)
		exit(0);
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
	printf("dajwdmne gjekrfm ehjla .efhentgj n\n");
	print_stacks(sup->a, sup->b);
}

void	putinrightplace(t_supsta *sup, t_calccom   *fds)
{
	int a;

	a = ft_lstsize(sup->a);
//	printf("COISO\n");
//	printf("rot_a: %d\nrot_b: %d\n", fds->rot_a, fds->rot_b);
//	print_stacks(sup->a, sup->b);
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
//	printf("FINAL COISO\n\n");
//	print_stacks(sup->a, sup->b);
}

int	calc_e(t_stack *a, int e)
{
	int	min;
	t_stack	*fds;

	fds = a;
	min = fds->cnt;
	min = calc_min(fds, min);
//	printf("min = %d\n\n\n\n\n\n\n\n", min);
//	print_stacks(a, a);
	while (fds->cnt != min)
	{
		fds = fds->next;
		e++;
	}
//	print_stacks(a, a);
//	printf("SAIUUUUUUUUUUUUU\n\n");
	return(e);
}

t_stack	*putminonposition(t_stack *stack, int init)
{
//	printf("PUT POSITION\n");
//	print_stacks(stack, stack);
	while (stack->cnt != init)
		stack = rotater(stack);
	return(stack);
}

t_calccom	*get_fastest_nb(t_supsta *sup, t_calccom *cmds)
{
	t_buejeitodeseler	*d;
	int				flag;
	int				size;
	t_supsta		*test;
	t_supsta		*temp2;

	test = sup;
	temp2 = sup;
	d = malloc(sizeof(t_buejeitodeseler));
	d->i = 0;
	d->e = 0;
	d->rec = 236746;
	d->max = 0;
	d->initval = test->a->cnt;
	
		
	flag = 1;
	size = ft_lstsize(sup->b);
	d->max = calc_max(test->a, d->max);
	while (d->i < size)
	{
//		printf("STACKSSSSSSSSSS\n");
//		print_stacks(test->a, test->b);
		if (test->b->cnt > d->max)
		{
//			printf("CARALHO PAAAAAAAAAAA\n");
			d->e = calc_e(test->a, d->e);
			flag = 0;
		}
//		print_stacks(test->a, test->b);
		while((test->a->cnt < test->b->cnt || ft_lastindex(test->a)->cnt > test->b->cnt) && flag)
		{
			test->a = rotater(test->a);
			d->e++;
		}
//		printf("Ver bem numero\n\n");
//		printf("rot_a: %d\nrot_b: %d\n", d->e, d->i);
//		print_stacks(test->a, test->b);
		if (d->rec > d->e + d->i)
		{
			cmds->rot_a = d->e;
			d->rec = d->e + d->i;
			cmds->rot_b = d->i;
		}
		flag = 1;
		d->i++;
		d->e = 0;
//		print_stacks(test->a, test->b);
		test->a = putminonposition(test->a, d->initval);
		temp2->a = putminonposition(temp2->a, d->initval);
//		printf("initval: %d\n", d->initval);
		test->b = rotater(test->b);
	}
	return(cmds);
}
