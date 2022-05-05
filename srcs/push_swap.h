/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:11:18 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/05/05 13:55:55 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"ft_printf.h"
# include"libft.h"
# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

typedef struct s_stacks
{
	int				cnt;
	struct s_stacks	*next;
}					t_stack;

typedef struct s_superstack
{
	t_stack			*a;
	t_stack			*b;
}					t_supsta;

t_stack				*ft_lstlast(t_stack *stck);

t_stack				*ft_lstnew(int content);

void				ft_lstadd_front(t_stack **stck, t_stack *novo);

void				ft_lstadd_back(t_stack **stck, t_stack *novo);

int					ft_lstsize(t_stack *stck);

void				ft_lstdelone(t_stack *stck, void (*del)(void *));

t_stack				*ft_lstindex(int index, t_stack *stack);

void				swap(t_stack *st);

void				super_swaper(t_stack *a, t_stack *b);

t_supsta			*pb(t_supsta *sup);

t_supsta			*pa(t_supsta *sup);

t_stack				*rotater(t_stack *stck);

void				*super_rotater(t_supsta *sup);

t_stack				*reverse_rotater(t_stack *stck);

t_supsta			*sup_rev_rot(t_supsta *sup);

void				print_stacks(t_stack *stck_a, t_stack *stck_b);

void				mvmnts_tester(t_supsta *sup);

bool				is_number(char number[]);

t_supsta			*input_reader(int ac, char **av, t_supsta *sup);

#endif
