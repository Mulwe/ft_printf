#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * size + 1);
	ft_bzero(new, sizeof(char) * size + 1);
	return (new);
}
