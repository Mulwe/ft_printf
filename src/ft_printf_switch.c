#include "../includes/ft_printf.h"

int	ft_choose_fmt(t_data *data)
{
	int	nbr;

	nbr = 0;
	if (*data->fmt == 'c')
		nbr = e_c;
	else if (*data->fmt == 's')
		nbr = e_s;
	else if (*data->fmt == 'p')
		nbr = e_p;
	else if (*data->fmt == 'd' || *data->fmt == 'i')
		nbr = e_dec_int;
	else if (*data->fmt == 'u')
		nbr = e_u_dec_int;
	else if (*data->fmt == 'x' || *data->fmt == 'X')
		nbr = e_u_hex_int;
	else if (*data->fmt == '%')
		nbr = e_percent;
	else
		ft_putstr_fd(" { ERROR } -> ", 1);
	return (nbr);
}

/** if macos return addrlen + 1 
 * else addrlen = addrlen + 3 
 * 
 ***/

int	ft_handle_length(t_data *data, int addr, int addrlen)
{
	if (OS_FLAG)
	{
		if (addr == 0 && data->ptr != 1)
			addrlen++;
	}
	else
	{
		if (addr == 0 && data->ptr != 1)
			addrlen = addrlen + 3;
	}
	return (addrlen);
}
