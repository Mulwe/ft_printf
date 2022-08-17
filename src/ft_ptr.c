#include "../includes/ft_printf.h"

/**
 * 
 */

static void	ft_itoa_hex_ptr(unsigned long long nbr)
{
	if (nbr > 15)
	{
		ft_itoa_hex_ptr(nbr / 16);
		ft_itoa_hex_ptr(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
			ft_putchar(nbr - 10 + 'a');
	}
}

static void	ft_ptr_handle_width(t_data *d, int addrlen, int diff)
{
	if (d->width > addrlen && d->width > d->precision)
	{
		d->total_len = d->total_len + d->width - addrlen;
		d->width++;
		if (d->flag[e_zero] == '1' && d->flag[e_minus] \
		!= '1' && diff != 0)
			while (--d->width > addrlen)
				ft_putchar('0');
		else
			while (--d->width > addrlen + diff)
				ft_putchar(' ');
	}
}

static void	ft_ptr_handle(t_data *d, unsigned long long ad, int adl, int diff)
{
	if (d->flag[e_minus] == '1' || (d->flag[e_zero] == '1' && diff == 0))
	{
		ft_putstr("0x");
		ft_putnchar('0', diff);
	}
	if (d->flag[e_minus] == '1' && (ad != 0 || d->ptr != 1))
		ft_itoa_hex_ptr(ad);
	if (!OS_FLAG && ad > 0)
		ft_ptr_handle_width(d, adl, diff);
	if (OS_FLAG)
		ft_ptr_handle_width(d, adl, diff);
	if (d->flag[e_minus] != '1' && (d->flag[e_zero] != '1' || diff != 0))
	{
		if (!OS_FLAG && ad == 0)
			ft_putstr("(nil)");
		else
		{
			ft_putstr("0x");
			if (OS_FLAG && ad == 0)
				diff = 1;
			ft_putnchar('0', diff);
		}
	}
	if (d->flag[e_minus] != '1' && (ad != 0 && d->ptr != 1))
		ft_itoa_hex_ptr(ad);
}

/**
 * 
 * */

void	ft_ptr(t_data *d)
{
	unsigned long long	addr;
	unsigned long long	tmp;
	int					addrlen;
	int					diff;

	addr = (unsigned long long)va_arg(d->args, void *);
	addrlen = 2;
	addrlen = ft_handle_length(d, addr, addrlen);
	tmp = addr;
	while (tmp > 0)
	{
		addrlen++;
		tmp /= 16;
	}
	diff = d->precision - addrlen + 2;
	if (diff < 0)
		diff = 0;
	if (d->width <= d->precision && diff != 0)
		d->total_len = d->total_len + diff;
	ft_ptr_handle(d, addr, addrlen, diff);
	d->total_len = d->total_len + addrlen;
	d->fmt++;
}
