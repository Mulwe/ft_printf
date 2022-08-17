/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joctopus <joctopus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 20:25:06 by joctopus          #+#    #+#             */
/*   Updated: 2021/04/26 14:01:48 by joctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*p;

	ptr = (char *)malloc(sizeof(*ptr) * (ft_strlen(s1) + 1));
	p = ptr;
	if (!ptr)
		return (NULL);
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (ptr);
}
