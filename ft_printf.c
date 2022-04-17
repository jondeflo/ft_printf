/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:01:55 by jondeflo          #+#    #+#             */
/*   Updated: 2020/07/22 10:48:42 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	ft_initlist(t_list list)
{
	list.f = 0;
	list.d = 0;
	list.a = 0;
	list.s = '0';
	list.p = 0;
	list.w = 0;
	list.e = 1;
	return (list);
}

void	write_char(char ch, int *pres)
{
	write(1, &ch, 1);
	(*pres)++;
}

int		ft_fill_list(t_list *list, const char *s, int i, va_list ap)
{
	while (!(seek_conv("cspdiuxX%", s[i])))
	{
		if (s[i] == '-' && list->a == 0)
			list->a = 1;
		if (s[i] == '0' && list->f == 0 && list->w == 0 && list->p == 0)
			list->f = 1;
		if (s[i] >= 48 && s[i] <= 57 && list->d == 0)
			list->w = (list->w == 0) ? s[i] - 48 : list->w * 10 + s[i] - 48;
		if (s[i] == '.' && list->d == 0)
			list->d = 1;
		if (s[i] == '*' && list->d == 0)
			list->w = va_arg(ap, int);
		if (s[i] == '*' && list->d)
			list->p = va_arg(ap, int);
		if (s[i] >= 48 && s[i] <= 57 && list->d)
			fill_precision(&(*list), s[i]);
		i++;
	}
	if (seek_conv("cspdiuxX%", s[i]))
		list->s = s[i++];
	edit_list(&(*list));
	return (i);
}

int		parse_str(const char *s, va_list ap, int i, int *pres)
{
	t_list	list;
	int		b;

	while (s[i])
	{
		if (s[i] != '%')
			write_char(s[i++], &(*pres));
		else
		{
			i++;
			if (s[i] != '%')
			{
				list = ft_initlist(list);
				i = ft_fill_list(&list, s, i, ap);
				b = print_list(&list, ap);
				if (b < 0)
					return (-1);
				else
					(*pres) += b;
			}
			else
				write_char(s[i++], &(*pres));
		}
	}
	return (i);
}

int		ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		res;
	int		*pres;
	int		b;

	count = 0;
	res = 0;
	pres = &res;
	if (!s)
		return (-1);
	va_start(ap, s);
	while (s[count] != '\0')
	{
		b = parse_str(s, ap, count, pres);
		if (b > 0)
			count = count + b;
		else
			return (-1);
	}
	va_end(ap);
	return (res);
}
