#include "../includes/ft_printf.h"

void	ft_precision(t_data *data)
{
	data->precision = 0;
	data->ptr = 0;
	if (*data->fmt == '.')
	{
		data->ptr = 1;
		data->fmt++;
		if (*data->fmt == '*')
		{
			data->precision = va_arg(data->args, int);
			if (data->precision < 0)
			{
				data->precision = 0;
				data->ptr = 0;
			}
			data->fmt++;
		}
		if (*data->fmt >= '0' && *data->fmt <= '9')
			data->precision = ft_atoi(data->fmt);
		while (*data->fmt >= '0' && *data->fmt <= '9')
			data->fmt++;
		if (data->precision > 0)
			data->ptr = 2;
	}
}
