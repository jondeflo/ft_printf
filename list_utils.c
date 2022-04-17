/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:08:03 by jondeflo          #+#    #+#             */
/*   Updated: 2020/07/19 17:03:31 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_precision(t_list *list, char ch)
{
	if (list->p == 0)
		list->p = ch - 48;
	else
		list->p = (list->p * 10 + (ch - 48));
}

void	edit_list(t_list *list)
{
	if (list->p < 0)
	{
		list->p = 0;
		list->d = 0;
	}
	if (list->w < 0)
	{
		list->w *= -1;
		list->a = 1;
	}
}

void	process_one(t_list *list, char **ptr, char **s)
{
	if (list->e != -1 && list->d && list->p > ft_len((*s)))
		(*ptr) = add_fr(&(*s), list->p - ft_len((*s)), '0', &(*list));
	if (list->d && (list->p == 0 || list->p < list->w))
		list->f = 0;
	if (list->e != -1 && list->w == 0 && list->p < ft_len((*s)))
		list->f = 1;
	if (ft_len((*s)) < list->w)
	{
		if (list->a == 1)
		{
			if (list->f == 1)
				(*ptr) = add_fr(&(*s), list->w - ft_len((*s)), '0', &(*list));
			if (list->f == 0)
				(*ptr) = add_end(&(*s), list->w - ft_len((*s)), ' ', &(*list));
		}
		if (list->a == 0)
		{
			if (list->f == 1)
				(*ptr) = add_fr(&(*s), list->w - ft_len((*s)), '0', &(*list));
			if (list->f == 0)
				(*ptr) = add_fr(&(*s), list->w - ft_len((*s)), ' ', &(*list));
		}
	}
}

void	process_list(t_list *list, char **ptr, char **str)
{
	if (list->e != -1 && list->d && list->p > ft_len((*str)))
		(*ptr) = add_fr(&(*str), list->p - ft_len((*str)), '0', &(*list));
	if (list->d && (list->p == 0 || list->p < list->w))
		list->f = 0;
	if (list->e != -1 && list->w == 0 && list->p < ft_len((*str)))
		list->f = 1;
}
