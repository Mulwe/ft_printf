/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joctopus <joctopus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:05:09 by joctopus          #+#    #+#             */
/*   Updated: 2021/04/26 14:02:39 by joctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	char			*pstr;
	unsigned int	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(len + 1);
	if (!str)
		return (NULL);
	pstr = str;
	while (*s1)
		*pstr++ = *s1++;
	while (*s2)
		*pstr++ = *s2++;
	*pstr = '\0';
	return (str);
}
