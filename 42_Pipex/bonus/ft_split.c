/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdas-nev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:08:58 by rdas-nev          #+#    #+#             */
/*   Updated: 2022/06/20 15:51:15 by rdas-nev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strndup(const char *s1, int start, int end)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	while (s1[start] && start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

static	int	strcount(char *s, char c)
{
	int	i;
	int	count;
	int	flag;

	count = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
		{	
			i++;
			flag = 1;
		}
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			flag = 0;
		}
		count++;
	}
	if (flag == 1)
		count--;
	return (count);
}

static	char	**nome(char **strarray, char *s, char c, int i)
{
	int	start;
	int	end;
	int	a;

	start = 0;
	end = 0;
	a = 0;
	while (i < strcount((char *)s, c))
	{
		while (s[a] == c && s[a++])
		{
			end++;
			start++;
		}
		while (s[a] != c && s[a++])
			end++;
		strarray[i] = ft_strndup(s, start, end);
		a++;
		start = a;
		i++;
		end++;
	}
	strarray[i] = NULL;
	return (strarray);
}

char	**ft_split(char const *s, char c)
{
	char	**strarray;
	int		i;

	i = 0;
	strarray = NULL;
	if (!s)
		return (NULL);
	strarray = (char **)malloc(strcount((char *)s, c) * sizeof(char *) + 1);
	if (!strarray)
		return (0);
	strarray = nome(strarray, (char *)s, c, i);
	return (strarray);
}
