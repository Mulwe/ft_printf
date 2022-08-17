#include "../includes/ft_printf.h"

void	ft_chk_input(t_data *d)
{
	int				number;
	static t_fmt	*func_arr[7] = {
	[e_c] = ft_chr,
	[e_s] = ft_str,
	[e_p] = ft_ptr,
	[e_dec_int] = ft_dec_int,
	[e_u_dec_int] = ft_uint,
	[e_u_hex_int] = ft_hex,
	[e_percent] = ft_percent};

	d->fmt++;
	ft_flag(d);
	ft_width(d);
	ft_precision(d);
	number = ft_choose_fmt(d);
	func_arr[number](d);
}
