/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:05:05 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/21 15:03:27 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*new_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	new_str = ft_substr(s1, start, len);
	return (new_str);
}

//static char	*trim_str(char const *s1, char const *set, char *new_str)
//{
//	char	*tmp;
//
//	tmp = new_str;
//	while (*s1 != '\0')
//	{
//		if (!is_in_set(*s1, set))
//		{
//			*new_str = *s1;
//			new_str++;
//		}
//		s1++;
//	}
//	*new_str = '\0';
//	return (tmp);
//}
//
//char	*ft_strtrim(char const *s1, char const *set)
//{
//	int		len;
//	char	*new_str;
//
//	len = ft_strlen(s1);
//	new_str = (char *)ft_calloc(len + 1, 1);
//	return (trim_str(s1, set, new_str));
//}

//#include <stdio.h>
//
//int	main(void)
//{
//	char	*str;
//	char	*set;
//	char	*dest;
//
//	str = "abcdefg";
//	set = "bdf";
//	dest = ft_strtrim(str, set);
//	printf("%s\n", dest);
//	return (0);
//}

//static char	*ft_del_dec(char const *s1, char const *set, char *new_str)
//{
//	int		i;
//	int		j;
//	int		s1len;
//	int		setlen;
//	int		count;
//	char	*tmp;
//
//	count = 0;
//	i = 0;
//	j = 0;
//	s1len = ft_strlen(s1);
//	setlen = ft_strlen(set);
//	tmp = new_str;
//	while (i < s1len)
//	{
//		j = 0;
//		count = 0;
//		while (j < setlen)
//		{
//			if (s1[i] == set[j])
//				count++;
//			j++;
//		}
//		if (count == 0)
//		{
//			*new_str = s1[i];
//			new_str++;
//		}
//		i++;
//	}
//	*new_str = '\0';
//	return (tmp);
//}
//
