/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:46:25 by jondeflo          #+#    #+#             */
/*   Updated: 2020/07/19 18:15:41 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		itoa_b_len(size_t num, int base)
{
	int len;

	len = 0;
	if (num == 0)
		len++;
	while (num > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

char	*itoa_b_rev(char *str, t_list *list)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_len(str);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
	{
		list->e = -1;
		return (0);
	}
	while (i < ft_len(str))
		res[i++] = str[--len];
	res[i] = '\0';
	free(str);
	return (res);
}

char	*itoa_b(size_t num, int base, t_list *list)
{
	int		i;
	int		len;
	size_t	left;
	char	*res;

	i = 0;
	len = itoa_b_len(num, base);
	if (num == 0)
		return (str_dup("0", &(*list)));
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
	{
		list->e = -1;
		return (0);
	}
	while (num != 0)
	{
		left = num % base;
		res[i++] = (left > 9) ? ((left - 10) + 'a') : (left + '0');
		num = num / base;
	}
	res[i] = '\0';
	return (itoa_b_rev(res, &(*list)));
}

char	*ft_itoa_err(int n, t_list *list)
{
	char	*res;
	int		len;
	int		neg;

	neg = (n < 0 ? 1 : 0);
	len = itoa_cnt_char(n);
	if (n == 0 || n == -0)
		return (make_zero(&(*list)));
	if (!(res = malloc(sizeof(char) * len + 1)))
	{
		list->e = -1;
		return (0);
	}
	if (n < 0)
		res[0] = '-';
	res[len] = '\0';
	len--;
	while (len >= neg)
	{
		res[len] = (n < 0 ? (-1 * (n % 10) + 48) : ((n % 10) + 48));
		n = n / 10;
		len--;
	}
	return (res);
}

int		itoa_cnt_char(int n)
{
	int	res;

	res = 0;
	if (n < 0)
		res++;
	while (n)
	{
		n = n / 10;
		res++;
	}
	return (res);
}
