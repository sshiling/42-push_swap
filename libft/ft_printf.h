/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:59:23 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/24 15:59:26 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "./libft/libft.h"
# include <stdarg.h>
# define S1(x) (x == 'c' || x == 'C' || x == 's' || x == 'S' || x == 'p')
# define S2(x) (x == 'd' || x == 'D' || x == 'i' || x == 'o' || x == 'O')
# define S3(x) (x == 'u' || x == 'U' || x == 'x' || x == 'X' || x == 'y')
# define S4(x) (x == 'n' || x == 'b' || x == 'w' || x == 'm')
# define SPECIFIER(x) (S1(x) || S2(x) || S3(x) || S4(x))
# define N1(a) (a == '1' || a == '2' || a == '3' || a == '4' || a == '5')
# define N2(a) (a == '6' || a == '7' || a == '8' || a == '9' || a == '0')
# define NUM(a) (N1(a) || N2(a))
# define A1(b) (b == '0' || b == '-' || b == '+' || b == ' ' || b == 'h')
# define A2(b) (b == 'l' || b == 'j' || b == 'z' || (b >= '1' && b <= '9'))
# define A3(b) (b == '.' || b == '#' || b == '*' || b == 't')
# define ALL(b) (A1(b) || A2(b) || A3(b))
# define ON 1
# define OFF 0
# define ZERO tmp->spec[0]
# define DOT tmp->spec[1]
# define MINUS tmp->spec[2]
# define PLUS tmp->spec[3]
# define SHARP tmp->spec[4]
# define SPACE tmp->spec[5]
# define MOD_HH tmp->spec[6]
# define MOD_H tmp->spec[7]
# define MOD_LL tmp->spec[8]
# define MOD_L tmp->spec[9]
# define MOD_J tmp->spec[10]
# define MOD_Z tmp->spec[11]
# define LOWER tmp->spec[12]
# define UPPER tmp->spec[13]
# define WIDTH tmp->width
# define PREC tmp->precision
# define EOC "\e[0m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define MAGENTA "\e[1;35m"
# define CYAN "\e[1;36m"
# define WHITE "\e[1;37m"

typedef struct		s_res
{
	int				*spec;
	void			*data;
	char			c;
	int				width;
	int				precision;
	int				i;
	void			*result;
	int				length;
	struct s_res	*next;
}					t_res;
int					ft_printf(const char *format, ...);
t_res				*tmp_result(const char *format, t_res *tmp, size_t i,
	va_list list);
t_res				*new_res(void);
char				*add_one_char(char *tmp, char c);
t_res				*save_prcnt(t_res *tmp, int i);
t_res				*pre_res(t_res *tmp, const char *format, size_t i,
	va_list list);
void				result_creator(va_list list, t_res *tmp);

char				*create_c(va_list list, t_res *tmp);
char				*create_b_d(va_list list);
char				*create_b_u(va_list list);
char				*create_i_d(va_list list, t_res *tmp);
char				*create_s(va_list list, t_res *tmp);
char				*create_u(va_list list, t_res *tmp);
char				*create_o(va_list list, t_res *tmp);
char				*ft_itoa_max(ssize_t nbr);
char				*ft_itoa_base(size_t nb, int base, t_res *tmp);
char				*create_x(va_list list, t_res *tmp);
char				*ft_itoa_u_max(size_t nbr);
char				*create_b_c(va_list list, t_res *tmp);
char				*create_b_s(va_list list, t_res *tmp);
char				*fill_mask(char *dst, char *src, int len);
char				*find_mask(int len);
char				make_num_from_bi(char *src, int len);
int					ft_pow(int nb, int power);
size_t				*create_n(va_list list, t_res *tmp);
size_t				find_dot(t_res *tmp, const char *format, size_t i);
size_t				wildcard_precision(t_res *tmp, va_list list, size_t i);
size_t				find_precision(t_res *tmp, const char *format,
	size_t i, va_list list);
size_t				wildcard_width(t_res *tmp, va_list list, size_t i);
size_t				find_width(t_res *tmp, const char *format, size_t i,
	va_list list);
size_t				find_minus(t_res *tmp, const char *format, size_t i);
size_t				find_plus(t_res *tmp, const char *format, size_t i);
size_t				find_sharp(t_res *tmp, const char *format, size_t i);
size_t				find_space(t_res *tmp, const char *format, size_t i);
size_t				find_zero(t_res *tmp, const char *format, size_t i);
size_t				find_h(t_res *tmp, const char *format, size_t i);
size_t				find_l(t_res *tmp, const char *format, size_t i);
size_t				find_j(t_res *tmp, const char *format, size_t i);
size_t				find_z(t_res *tmp, const char *format, size_t i);
ssize_t				mod_int_i_d(va_list list, t_res *tmp);
char				*find_prefix_i_d(int key, t_res *tmp);
char				*num_first_i_d(int len, char *src, t_res *tmp);
char				filler_finder(t_res *tmp);
char				*num_after_i_d(int len, char *src, t_res *tmp);
size_t				mod_int_uox(va_list list, t_res *tmp);
char				*create_precision_x(char *prefix, char *src, t_res *tmp);
char				*create_result_x(char *dst, t_res *tmp);
char				*fill_zero_x(char *prefix, char *src, char *dst,
	t_res *tmp);
char				*fill_minus_x(char *prefix, char *src, char *dst,
	t_res *tmp);
char				*fill_space_x(char *prefix, char *src, char *dst,
	t_res *tmp);
int					ft_putstr_new(char const *s);
int					ft_putstr_res(char *s, t_res *tmp);
int					result_printer(t_res *res);
void				t_res_del(t_res *src);
char				*create_binary(va_list list, t_res *tmp);
size_t				find_t(t_res *tmp, const char *format, size_t i);
char				*color_setter(char *s);
char				*color_finder(char *s);
char				*create_final_color(char *finder, char *s);
int					ft_putstr_data(char *s);
extern int			g_fd;

#endif
