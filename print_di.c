/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:53:49 by jondeflo          #+#    #+#             */
/*   Updated: 2020/07/20 13:07:35 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	proc_dec(t_list *list, char **ptr, char **s, int neg)
{
	if (list->e != -1 && neg < 0)
		(*ptr) = cut_str(&(*s), &(*list));
	if (neg > 0 && list->d && (list->w <= list->p))
		list->w = list->p;
	if (neg == 0 && list->d && (list->w <= list->p))
		list->w = list->p;
	if (neg < 0 && list->d && (list->w <= list->p))
		list->w = list->p + 1;
	if (neg != 0 && list->e != -1 && list->w <= ft_len((*s)))
		list->w = 0;
}

void	proc_dec_zero(t_list *list, char **ptr, char **s, int dec)
{
	if (list->e != -1 && dec == 0)
	{
		if (list->d && list->p == 0)
		{
			(*ptr) = strdup_empty(&(*s), &(*list));
			list->f = 0;
		}
		if (list->d && list->p > ft_len((*s)))
			*ptr = add_fr(&(*s), list->p - ft_len((*s)), '0', &(*list));
	}
	if (list->e != -1 && list->d && list->p > ft_len((*s)))
		(*ptr) = add_fr(&(*s), list->p - ft_len((*s)), '0', &(*list));
	if (list->d && (list->p == 0 || list->p < list->w))
		list->f = 0;
	if (list->e != -1 && list->w == 0 && list->p < ft_len((*s)))
		list->f = 1;
}

void	proc_dec_space(t_list *list, char **ptr, char **s, int neg)
{
	if (list->f == 1)
	{
		if (neg < 0)
			(*ptr) = str_join(&(*s), "-", (*s), &(*list));
		(*ptr) = add_end(&(*s), list->w - ft_len((*s)), ' ', &(*list));
	}
	if (list->f == 0)
	{
		if (neg < 0)
			(*ptr) = str_join(&(*s), "-", (*s), &(*list));
		(*ptr) = add_end(&(*s), list->w - ft_len((*s)), ' ', &(*list));
	}
}

void	proc_dec_front(t_list *list, char **ptr, char **s, int neg)
{
	if (list->f == 1)
	{
		if (neg < 0)
			(*ptr) = add_fr(&(*s), list->w - ft_len((*s)) - 1, '0', &(*list));
		if (neg < 0)
			(*ptr) = str_join(&(*s), "-", (*s), &(*list));
		(*ptr) = add_fr(&(*s), list->w - ft_len((*s)), '0', &(*list));
	}
	if (list->f == 0)
	{
		if (neg < 0)
			(*ptr) = str_join(&(*s), "-", (*s), &(*list));
		(*ptr) = add_fr(&(*s), list->w - ft_len((*s)), ' ', &(*list));
	}
}

int		print_decimal(va_list ap, t_list *list)
{
	int		neg;
	int		dec;
	char	*s;
	char	**ptr;

	ptr = &s;
	dec = va_arg(ap, int);
	neg = (dec < 0) ? -1 : 1;
	if (dec == 0)
		neg = 0;
	s = ft_itoa_err(dec, &(*list));
	proc_dec(&(*list), ptr, &s, neg);
	proc_dec_zero(&(*list), ptr, &s, dec);
	if (list->e != -1 && list->w > 0)
		if (ft_len(s) < list->w)
		{
			if (list->a == 1)
				proc_dec_space(&(*list), ptr, &s, neg);
			if (list->a == 0)
				proc_dec_front(&(*list), ptr, &s, neg);
		}
	if (list->e != -1 && neg == -1 && list->w == 0)
		*ptr = str_join(&s, "-", s, &(*list));
	return (write_out(&s, &(*list)));
}
