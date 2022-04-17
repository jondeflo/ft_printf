/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:45:30 by jondeflo          #+#    #+#             */
/*   Updated: 2020/12/19 11:49:21 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_dup(const char *s, t_list *list)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc((sizeof(char) * (ft_len(s) + 1)))))
	{
		list->e = -1;
		return (0);
	}
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*sub_str(char **s, int len, t_list *list)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc(sizeof(char) * len + 1)))
	{
		list->e = -1;
		return (0);
	}
	while (i < len && (*s)[i] != '\0')
	{
		res[i] = (*s)[i];
		i++;
	}
	res[i] = '\0';
	free(*s);
	*s = NULL;
	return (res);
}

char	*cut_str(char **s, t_list *list)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = malloc(sizeof(char) * ft_len(*s))))
	{
		list->e = -1;
		return (0);
	}
	while ((*s)[i + 1] != '\0')
	{
		res[i] = (*s)[i + 1];
		i++;
	}
	res[i] = '\0';
	free(*s);
	*s = NULL;
	return (res);
}

char	*strdup_empty(char **s, t_list *list)
{
	char	*res;

	if (!(res = malloc((sizeof(char) * (1)))))
	{
		list->e = -1;
		return (0);
	}
	res[0] = '\0';
	free(*s);
	*s = NULL;
	return (res);
}

int		print_ch(char ch, int cnt)
{
	int	res;

	res = 0;
	while (cnt > 0)
	{
		write(1, &ch, 1);
		cnt--;
		res++;
	}
	return (res);
}
