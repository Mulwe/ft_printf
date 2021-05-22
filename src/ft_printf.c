#include "../includes/ft_printf.h"
#include "../libft/libft.h"

/**
 * int ft_printf(const char *, ...);
 * ? malloc memory for data
 * ? write va_args to data
 * */

int	ft_printf(const char *fmt, ...)
{
	t_data	*data;
	int		bytes;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	va_start(data->args, fmt);
	data->fmt = fmt;
	while (*data->fmt)
	{
		while (*data->fmt && *data->fmt != '%')
		{
			ft_putchar(*data->fmt);
			data->total_len++;
			data->fmt++;
		}
		if (*data->fmt && *data->fmt == '%')
			ft_chk_input(data);
	}
	va_end(data->args);
	bytes = data->total_len;
	free(data);
	return (bytes);
}
