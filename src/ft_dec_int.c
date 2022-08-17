#include "../includes/ft_printf.h"

void	ft_putnbr(long long nbr)
{
	if (nbr < 0)
		ft_putnbr(nbr * -1);
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar('0' + nbr);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

static void	ft_dec_int_width(t_data *data, long long n, int nl, int df)
{
	if (data->flag[e_zero] == '1' && df == 0)
	{
		if (data->ptr != 0)
			while (--data->width > nl)
				ft_putchar(' ');
		if (n < 0)
			ft_putchar('-');
		if (data->ptr == 0)
			while (--data->width > nl)
				ft_putchar('0');
	}
	else
	{
		while (--data->width > (nl + df))
			ft_putchar(' ');
		if (n < 0)
			ft_putchar('-');
	}
	ft_putnchar('0', df);
	if (data->ptr != 1 || n != 0)
		ft_putnbr(n);
}

static void	ft_dec_int_flag(t_data *data, int nbr, int nbrlen, int diff)
{
	if (data->flag[e_minus] == '1')
	{
		if (nbr < 0)
			ft_putchar('-');
		ft_putnchar('0', diff);
		if (data->ptr != 1 || nbr != 0)
			ft_putnbr(nbr);
		if (data->width > nbrlen)
			while (--data->width > nbrlen + diff)
				ft_putchar(' ');
	}
	else
	{
		if (data->width > nbrlen)
			ft_dec_int_width(data, nbr, nbrlen, diff);
		else
		{
			if (nbr < 0)
				ft_putchar('-');
			ft_putnchar('0', diff);
			if (data->ptr != 1 || nbr != 0)
				ft_putnbr(nbr);
		}
	}
}

void	ft_dec_int(t_data *data)
{
	long long		nbr;
	int				nbrlen;
	int				diff;

	nbr = (int)(va_arg(data->args, long long));
	nbrlen = ft_nbrlen(nbr);
	diff = data->precision - nbrlen;
	if (data->ptr == 1 && nbr == 0)
		nbrlen--;
	if (nbr < 0)
		nbrlen++;
	if (diff < 0)
		diff = 0;
	if (data->width <= data->precision)
		data->total_len = data->total_len + diff;
	if (data->width > nbrlen && data->width > data->precision)
	{
		data->total_len = data->total_len + (data->width - nbrlen);
		data->width++;
	}
	ft_dec_int_flag(data, nbr, nbrlen, diff);
	data->total_len = data->total_len + nbrlen;
	data->fmt++;
}
