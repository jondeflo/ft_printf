/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:51:07 by jondeflo          #+#    #+#             */
/*   Updated: 2020/07/19 17:41:54 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len(const char *s)
{
	int res;

	res = 0;
	while (s[res] != '\0')
		res++;
	return (res);
}

int		seek_conv(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*str_capital(char **s, t_list *list)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * (ft_len(*s) + 1))))
	{
		list->e = -1;
		return (0);
	}
	while ((*s)[i])
	{
		if ((*s)[i] >= 'a' && (*s)[i] <= 'z')
			res[i] = (*s)[i] - 32;
		else
			res[i] = (*s)[i];
		i++;
	}
	res[i] = '\0';
	free(*s);
	*s = NULL;
	return (res);
}

int		write_out(char **s, t_list *list)
{
	int i;

	i = 0;
	while (list->e != -1 && (i < ft_len((*s)) && (*s)[i] != '\0'))
		write(1, &(*s)[i++], 1);
	if (list->e != -1)
	{
		free(*s);
		*s = NULL;
	}
	return (list->e < 0 ? -1 : i);
}

int		print_list(t_list *list, va_list ap)
{
	int res;

	res = 0;
	if (list->s == 's')
		res = print_str(ap, &(*list));
	if (list->s == 'c' || list->s == '%')
		res = print_char(ap, &(*list));
	if (list->s == 'd' || list->s == 'i')
		res = print_decimal(ap, &(*list));
	if (list->s == 'u')
		res = print_ui(ap, &(*list));
	if (list->s == 'X' || list->s == 'x')
		res = print_hex(ap, &(*list), list->s);
	if (list->s == 'p')
		res = print_ptr(ap, &(*list));
	return (res);
}
