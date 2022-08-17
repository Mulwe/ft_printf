#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_data
{
	const char	*fmt;
	va_list		args;
	int			width;
	int			precision;
	int			total_len;
	int			ptr;
	char		flag[2];
}				t_data;

/** enum for func_arr from [0] to [6] **/

enum			e_send
{
	e_c,
	e_s,
	e_p,
	e_dec_int,
	e_u_dec_int,
	e_u_hex_int,
	e_percent
};

/** e_flag if minus or zero case **/

enum			e_flag
{
	e_minus,
	e_zero
};

/** primary func **/

int				ft_choose_fmt(t_data *data);
int				ft_handle_length(t_data *data, int addr, int addrlen);
void			ft_flag(t_data *data);
void			ft_precision(t_data *data);
void			ft_width(t_data *data);
void			ft_chk_input(t_data *d);

void			ft_chr_width(t_data *data);
void			ft_chr(t_data *data);
void			ft_str_width(t_data *data, int strlen);
void			ft_str(t_data *data);
void			ft_dec_int(t_data *data);

void			ft_ptr(t_data *d);
void			ft_uint(t_data *data);
void			ft_u_itoa_hex(unsigned long long nbr);
void			ft_hex(t_data *data);
void			ft_itoa_hex(unsigned long long n, char format);
void			ft_percent(t_data *info);
void			ft_perc_handle_width(t_data *info);

/** additional func **/

void			ft_putchar(char c);
void			ft_putnbr(long long nbr);
int				ft_nbrlen(long long nbr);

/** type def funct for func_arr **/

typedef void	t_fmt(t_data *d);

/**
 * os_flag if 1 then mac os
 * if 0 then another (linux)
 * */

# if __APPLE__
#  define OS_FLAG 1
# else
#  define OS_FLAG 0
# endif

#endif
