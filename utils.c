/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:43:50 by jondeflo          #+#    #+#             */
/*   Updated: 2020/07/19 18:15:48 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_fr(char **s, int dif, char c, t_list *list)
{
	char	*a;
	char	*r;
	int		i;

	i = 0;
	if (!(a = malloc(sizeof(char) * (dif + 1))))
	{
		list->e = -1;
		return (0);
	}
	while (i < dif)
	{
		a[i] = c + 0;
		i++;
	}
	a[i] = '\0';
	r = join_mem(a, (*s), &(*list));
	free(a);
	free(*s);
	*s = NULL;
	return (r);
}

char	*add_end(char **s, int dif, char c, t_list *list)
{
	char	*a;
	char	*r;
	int		i;

	i = 0;
	if (!(a = malloc(sizeof(char) * (dif + 1))))
	{
		list->e = -1;
		return (0);
	}
	while (i < dif)
	{
		a[i] = c + 0;
		i++;
	}
	a[i] = '\0';
	r = join_mem((*s), a, &(*list));
	free(a);
	free(*s);
	*s = NULL;
	return (r);
}

char	*join_mem(char const *s1, char const *s2, t_list *list)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
	{
		list->e = -1;
		return (0);
	}
	if (!(res = malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1))))
	{
		list->e = -1;
		return (0);
	}
	while (s1[j] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*str_join(char **s, char const *s1, char const *s2, t_list *list)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if ((!s1 || !s2))
	{
		list->e = -1;
		return (0);
	}
	if (!(res = malloc(sizeof(char) * (ft_len(s1) + ft_len(s2) + 1))))
	{
		list->e = -1;
		return (0);
	}
	while (s1[j] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	free(*s);
	*s = NULL;
	return (res);
}

char	*make_zero(t_list *list)
{
	char	*res;

	if (!(res = malloc(sizeof(char) * 2)))
	{
		list->e = -1;
		return (0);
	}
	res[0] = '0';
	res[1] = '\0';
	return (res);
}
