#include "../includes/ft_printf.h"

void	ft_perc_handle_width(t_data *info)
{
	if (info->width > 1)
	{
		info->total_len = info->total_len + info->width - 1;
		info->width++;
		if (info->flag[e_zero] == '1' && info->flag[e_minus] != '1')
			while (--info->width > 1)
				ft_putchar('0');
		else
			while (--info->width > 1)
				ft_putchar(' ');
	}
}

void	ft_percent(t_data *info)
{
	if (OS_FLAG)
	{
		if (info->flag[e_minus] == '1')
			ft_putchar('%');
		ft_perc_handle_width(info);
		if (info->flag[e_minus] != '1')
			ft_putchar('%');
		info->total_len++;
		info->fmt++;
	}
	else
	{
		ft_putchar_fd('%', 1);
		info->total_len++;
		info->fmt++;
	}
}
