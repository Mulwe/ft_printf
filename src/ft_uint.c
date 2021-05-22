#include "../includes/ft_printf.h"

void	ft_u_itoa_hex(unsigned long long nbr)
{
	if (nbr > 9)
	{
		ft_u_itoa_hex(nbr / 10);
		ft_putchar(nbr % 10 + '0');
	}
	else
		ft_putchar(nbr + '0');
}

static void	ft_u_wdt(t_data *data, unsigned long long n, int nl, int df)
{
	if (data->flag[e_zero] == '1' && (data->flag[e_minus] != 1 && df == 0))
	{
		if (data->ptr != 0)
			while (--data->width > nl)
				ft_putchar(' ');
		else
			while (--data->width > nl)
				ft_putchar('0');
	}
	else
	{
		if (data->ptr != 1 || n != 0)
			while (--data->width > nl + df)
				ft_putchar(' ');
		else
			while (--data->width > 0)
				ft_putchar(' ');
	}
}

static void	ft_handle_u(t_data *data, unsigned long long n, int nl, int df)
{
	if (data->flag[e_minus] == '1' && (data->ptr != 1 || n != 0))
	{
		ft_putnchar('0', df);
		ft_u_itoa_hex(n);
	}
	if (data->width > nl)
	{
		data->width++;
		ft_u_wdt(data, n, nl, df);
	}
	if (data->flag[e_minus] != '1' && (data->ptr != 1 || n != 0))
	{
		ft_putnchar('0', df);
		ft_u_itoa_hex(n);
	}
}

void	ft_uint(t_data *data)
{
	unsigned long long	nbr;
	unsigned long long	tmp;
	int					nbrlen;
	int					diff;

	nbrlen = 0;
	nbr = (unsigned int)(va_arg(data->args, long long));
	tmp = nbr;
	if (tmp == 0 && data->ptr != 1)
		nbrlen++;
	while (tmp > 0)
	{
		nbrlen++;
		tmp /= 10;
	}
	diff = data->precision - nbrlen;
	if (diff < 0)
		diff = 0;
	if (data->width <= data->precision)
		data->total_len = data->total_len + diff;
	if (data->width > nbrlen && data->width > data->precision)
		data->total_len = data->total_len + (data->width - nbrlen);
	ft_handle_u(data, nbr, nbrlen, diff);
	data->total_len = data->total_len + nbrlen;
	data->fmt++;
}
