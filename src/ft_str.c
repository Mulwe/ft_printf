#include "../includes/ft_printf.h"

/**
 * update width
 * if width > len of str
 * totallen += width - strlen
 */

void	ft_str_width(t_data *data, int strlen)
{
	if (data->width > strlen)
	{
		data->total_len = data->total_len + (data->width - strlen);
		while (data->width > strlen)
		{
			ft_putchar(' ');
			data->width--;
		}
	}
}

/**
 * if minus = 1 
 *  update width
 *  
 **/

static void	ft_handle_str(t_data *data, char *str, int strlen)
{
	if (data->flag[e_minus] == '1' && data->ptr != 1)
		ft_putstr(str);
	ft_str_width(data, strlen);
	if (data->flag[e_minus] != '1' && data->ptr != 1)
		ft_putstr(str);
	data->total_len = data->total_len + strlen;
	data->fmt++;
	free(str);
}

/**
 * @param(OS_FLAG) => macros
 * 1 is MACos
 * 0 is another os
 * 
 * ft_strcpy copy from src to dst str
 * ft_strnew => new 'str' with 'size'
 * ft_strcmp => cmp str1 and str2
 * */

void	ft_str(t_data *data)
{
	char	*str;
	char	*tmp;
	int		strlen;

	tmp = va_arg(data->args, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (data->precision == 0)
	{
		str = ft_strnew(ft_strlen(tmp));
		ft_strcpy(str, tmp);
	}
	else
	{
		if (!OS_FLAG && (data->precision < 6 && data->precision >= 0) \
		&& (ft_strcmp(tmp, "(null)") == 0))
			data->precision = 0;
		str = ft_strnew(data->precision);
		ft_strncpy(str, tmp, data->precision);
	}
	if (data->ptr != 1)
		strlen = ft_strlen(str);
	else
		strlen = 0;
	ft_handle_str(data, str, strlen);
}
