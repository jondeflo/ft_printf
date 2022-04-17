/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jondeflo <jondeflo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:46:20 by jondeflo          #+#    #+#             */
/*   Updated: 2020/07/19 18:16:03 by jondeflo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	int			f;
	int			d;
	int			a;
	char		s;
	int			p;
	int			w;
	int			e;
}				t_list;

int				ft_printf(const char *s, ...);
t_list			ft_initlist(t_list list);
int				ft_fill_list(t_list *list, const char *s, int i, va_list ap);
int				parse_str(const char *s, va_list ap, int i, int *pres);
int				seek_conv(const char *s, int c);

int				print_ch(char ch, int cnt);
int				print_char(va_list ap, t_list *list);
int				print_decimal(va_list ap, t_list *list);
int				print_str(va_list ap, t_list *list);
int				print_ui(va_list ap, t_list *list);
int				print_hex(va_list ap, t_list *list, char ch);
int				print_ptr(va_list ap, t_list *list);

int				ft_len(const char *s);
char			*strdup_empty(char **s, t_list *list);
char			*sub_str(char **s, int len, t_list *list);
char			*add_end(char **s, int dif, char c, t_list *list);
char			*add_fr(char **s, int dif, char c, t_list *list);
char			*str_dup(const char *s, t_list *list);
char			*itoa_b(size_t num, int base, t_list *list);
char			*itoa_b_rev(char *str, t_list *list);
int				itoa_b_len(size_t num, int base);
char			*str_capital(char **s, t_list *list);
char			*str_join(char **s, char const *s1, char const *s2,
				t_list *list);
char			*join_mem(char const *s1, char const *s2, t_list *list);
char			*ft_itoa_err(int n, t_list *list);
int				itoa_cnt_char(int n);
char			*make_zero(t_list *list);
char			*cut_str(char **s, t_list *list);

int				write_out(char **s, t_list *list);
int				print_list(t_list *list, va_list ap);
void			fill_precision(t_list *list, char ch);
void			edit_list(t_list *list);
void			write_char(char ch, int *pres);
void			process_list(t_list *list, char **ptr, char **str);
void			process_one(t_list *list, char **ptr, char **s);
void			proc_dec(t_list *list, char **ptr, char **s, int neg);
void			proc_dec_zero(t_list *list, char **ptr, char **s, int dec);
void			proc_dec_space(t_list *list, char **ptr, char **s, int neg);
void			proc_dec_front(t_list *list, char **ptr, char **s, int neg);
#endif
