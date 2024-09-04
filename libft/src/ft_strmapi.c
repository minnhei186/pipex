/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:58:31 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/21 16:23:27 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;
	char			*tmp;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_str == NULL)
		return (NULL);
	tmp = new_str;
	while (*s != '\0')
	{
		*new_str = f(i, *s);
		new_str++;
		s++;
		i++;
	}
	*new_str = '\0';
	return (tmp);
}
