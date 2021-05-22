#include "../includes/ft_printf.h"

void	ft_chr_width(t_data *data)
{
	if (data->width > 1)
	{
		data->total_len = data->total_len + (data->width - 1);
		data->width++;
		if (data->flag[e_zero] == '1' && data->flag[e_minus] != '1')
			while (--data->width > 1)
				ft_putchar('0');
		else
			while (--data->width > 1)
				ft_putchar(' ');
	}
}

void	ft_chr(t_data *data)
{
	char	c;

	c = va_arg(data->args, int);
	if (data->flag[e_minus] == '1')
		ft_putchar(c);
	ft_chr_width(data);
	if (data->flag[e_minus] != '1')
		ft_putchar(c);
	data->total_len++;
	data->fmt++;
}
