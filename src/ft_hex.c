#include "../includes/ft_printf.h"

void	ft_itoa_hex(unsigned long long n, char fmt)
{
	if (n > 15)
	{
		ft_itoa_hex(n / 16, fmt);
		ft_itoa_hex(n % 16, fmt);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (fmt == 'x')
				ft_putchar(n - 10 + 'a');
			else
				ft_putchar(n - 10 + 'A');
		}
	}
}

static void	ft_x_flag(t_data *data, unsigned long long n, int ln, int df)
{
	data->width++;
	if (data->flag[e_minus] == '1')
	{
		ft_putnchar('0', df);
		if (data->ptr != 1 || n != 0)
			ft_itoa_hex(n, *data->fmt);
		if (data->width > ln)
			while (--data->width > ln + df)
				ft_putchar(' ');
	}
	else
	{
		if (data->width > ln && (data->flag[e_zero] != '1' || data->ptr != 0))
			while (--data->width > ln + df)
				ft_putchar(' ');
		if (data->width > ln && data->flag[e_zero] == '1' && data->ptr == 0)
			while (--data->width > ln + df)
				ft_putchar('0');
		ft_putnchar('0', df);
		if (data->ptr != 1 || n != 0)
			ft_itoa_hex(n, *data->fmt);
	}
}

void	ft_hex(t_data *data)
{
	unsigned long long	nbr;
	unsigned long long	tmp;
	int					nbrlen;
	int					diff;

	nbr = (unsigned int)(va_arg(data->args, unsigned long long));
	tmp = nbr;
	nbrlen = 0;
	if (tmp == 0 && data->ptr != 1)
		nbrlen++;
	while (tmp > 0)
	{
		nbrlen++;
		tmp = tmp / 16;
	}
	diff = data->precision - nbrlen;
	if (diff < 0)
		diff = 0;
	if (data->width <= data->precision)
		data->total_len = data->total_len + diff;
	if (data->width > nbrlen && data->width > data->precision)
		data->total_len = data->total_len + (data->width - nbrlen);
	ft_x_flag(data, nbr, nbrlen, diff);
	data->total_len = data->total_len + nbrlen;
	data->fmt++;
}
