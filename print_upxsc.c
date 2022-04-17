/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_upxsc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:52:10 by jondeflo          #+#    #+#             */
/*   Updated: 2020/07/22 10:56:01 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_ui(va_list ap, t_list *list)
{
	size_t	ui;
	char	*s;
	char	**ptr;

	ptr = &s;
	ui = va_arg(ap, unsigned int);
	s = itoa_b(ui, 10, &(*list));
	if (list->e != -1 && ui > 0 && list->w <= ft_len(s))
		list->w = 0;
	if (list->e != -1 && ui == 0)
	{
		if (list->d && list->p == 0)
		{
			*ptr = strdup_empty(&s, &(*list));
			list->f = 0;
		}
		if (list->d && list->p > ft_len(s))
			*ptr = add_fr(&s, list->p - ft_len(s), '0', &(*list));
	}
	process_one(&(*list), ptr, &s);
	return (write_out(&s, &(*list)));
}

int		print_ptr(va_list ap, t_list *list)
{
	char	*s;
	char	**ptr;
	size_t	pnvalue;

	ptr = &s;
	pnvalue = va_arg(ap, size_t);
	s = itoa_b(pnvalue, 16, &(*list));
	*ptr = str_join(&s, "0x", s, &(*list));
	if (list->e != -1 && list->w <= ft_len(s))
		list->w = 0;
	if (list->e != -1 && pnvalue == 0)
	{
		if (list->d && list->p == 0)
		{
			*ptr = str_join(&s, "0x", "", &(*list));
			list->f = 0;
		}
		if (list->d && list->p > ft_len(s))
			*ptr = add_fr(&s, list->p - ft_len(s), '0', &(*list));
	}
	process_one(&(*list), ptr, &s);
	return (write_out(&s, &(*list)));
}

int		print_hex(va_list ap, t_list *list, char ch)
{
	char	*s;
	char	**ptr;
	size_t	hex;

	ptr = &s;
	hex = va_arg(ap, unsigned int);
	s = itoa_b(hex, 16, &(*list));
	if (list->e != -1 && ch == 'X')
		*ptr = str_capital(&s, &(*list));
	if (list->e != -1 && hex > 0 && list->w <= ft_len(s))
		list->w = 0;
	if (list->e != -1 && hex == 0)
	{
		if (list->d && list->p == 0)
		{
			*ptr = strdup_empty(&s, &(*list));
			list->f = 0;
		}
		if (list->d && list->p > ft_len(s))
			*ptr = add_end(&s, list->p - ft_len(s), '0', &(*list));
	}
	process_one(&(*list), ptr, &s);
	return (write_out(&s, &(*list)));
}

int		print_char(va_list ap, t_list *list)
{
	char	ch;
	int		i;

	i = 0;
	if (!(ch = va_arg(ap, int)))
		ch = 0;
	if (list->s == '%')
		ch = '%';
	if (list->a == 1)
		i += print_ch(ch, 1);
	if (list->w > 0 && list->f == 0)
		i += print_ch(' ', list->w - 1);
	if (list->w > 0 && list->f == 1 && list->a == 0)
		i += print_ch('0', list->w - 1);
	if (list->w > 0 && list->f == 1 && list->a == 1)
		i += print_ch(' ', list->w - 1);
	if (list->a == 0)
		i += print_ch(ch, 1);
	return (i);
}

int		print_str(va_list ap, t_list *list)
{
	char	*str;
	char	**ptr;

	ptr = &str;
	str = va_arg(ap, char*);
	*ptr = (str) ? str_dup(str, &(*list)) : str_dup("(null)", &(*list));
	if (list->d && list->e > 0)
		*ptr = sub_str(&str, list->p, &(*list));
	if (list->w > 0 && list->e > 0)
		if (str && ft_len(str) < list->w)
			*ptr = (list->a > 0) ?
			add_end(&str, list->w - ft_len(str), ' ', &(*list)) :
			add_fr(&str, list->w - ft_len(str), ' ', &(*list));
	return (write_out(&str, &(*list)));
}
