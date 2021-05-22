#include "../includes/ft_printf.h"

void	ft_flag(t_data *data)
{
	data->flag[e_minus] = '0';
	data->flag[e_zero] = '0';
	while (*data->fmt == '-' || *data->fmt == '0')
	{
		if (*data->fmt == '-')
			data->flag[e_minus] = '1';
		if (*data->fmt == '0')
			data->flag[e_zero] = '1';
		data->fmt++;
	}
}
