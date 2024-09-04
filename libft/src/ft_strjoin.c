/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:54:35 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/10 15:33:47 by hosokawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	total_len(const char *s1, const char *s2)
{
	int	s1len;
	int	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	return (s1len + s2len);
}

static void	join(const char *s1, const char *s2, char *new_str)
{
	int	s1len;
	int	s2len;
	int	i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	while (i < s1len)
	{
		*new_str = *s1;
		new_str++;
		s1++;
		i++;
	}
	i = 0;
	while (i < s2len)
	{
		*new_str = *s2;
		new_str++;
		s2++;
		i++;
	}
	*new_str = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		all_len;
	char	*new_str;
	char	*tmp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return ((char *)s2);
	if (s2 == NULL)
		return ((char *)s1);
	all_len = 0;
	all_len = total_len(s1, s2);
	new_str = (char *)malloc(sizeof(char) * (all_len + 1));
	if (new_str == NULL)
		return (NULL);
	tmp = new_str;
	join(s1, s2, new_str);
	return (tmp);
}

//#include <stdio.h>
//
//int	main(void)
//{
//	char	*s1;
//	char	*s2;
//	char	*all_str;
//
//	s1 = "abcd";
//	s2 = "efgh";
//	all_str = ft_strjoin(s1, s2);
//	printf("%s\n", all_str);
//	return (0);
//}
