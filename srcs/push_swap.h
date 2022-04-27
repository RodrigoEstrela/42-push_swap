/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:11:18 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/04/27 18:33:46 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include"libft.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct	s_stacks
{
	int				cont;
	struct s_stacks *next;
}					t_stack;


t_stack				*ft_lstlast(t_stack *stck);

t_stack				*ft_lstnew(int content);

void				ft_lstadd_front(t_stack **stck, t_stack *new);

void				ft_lstadd_back(t_stack **stck, t_stack *new);

int					ft_lstsize(t_stack *stck);

void    			ft_lstdelone(t_stack *stck, void (*del)(void *));

t_stack				*ft_lstindex(int index, t_stack *stack);

void				sa(t_stack *a);

void				sb(t_stack *b);

void				ss(t_stack *a, t_stack *b);

void				pa(t_stack **a, t_stack **b);

void				pb(t_stack **a, t_stack **b);
