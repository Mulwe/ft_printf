#include "../includes/ft_printf.h"

void	ft_width(t_data *data)
{
	data->width = 0;
	if (*data->fmt == '*')
	{
		data->width = va_arg(data->args, int);
		if (data->width < 0)
		{
			data->width = data->width * -1;
			data->flag[e_minus] = '1';
		}
		data->fmt++;
	}
	if (*data->fmt >= '0' && *data->fmt <= '9')
		data->width = ft_atoi(data->fmt);
	while (*data->fmt >= '0' && *data->fmt <= '9')
		data->fmt++;
}
