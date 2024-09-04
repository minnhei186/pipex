/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 15:00:24 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:45:27 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n)
	{
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
		if (c1 == '\0' && c2 == '\0')
			return (0);
		if ((c1 == '\0' || c2 == '\0') || c1 != c2)
		{
			return (c1 - c2);
		}
		s1++;
		s2++;
		i++;
	}
	return (0);
}

//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//    char str[] = "ABC";
//    printf("ABC: ABD   = %d\n", ft_strncmp(str, "ABD", 2));
//    printf("ABC: ABC   = %d\n", ft_strncmp(str, "ABC", 2));
//    printf("ABC: AAA   = %d\n", ft_strncmp(str, "AAA", 2));
//    printf("ABC: ABCD  = %d\n", ft_strncmp(str, "ABCD", 2));
//    printf("ABC: AB    = %d\n", ft_strncmp(str, "AB", 2));
//    printf("ABC: B     = %d\n", ft_strncmp(str, "B", 2));
//    printf("ABC: A     = %d\n", ft_strncmp(str, "A", 2));
//    return (0);
//}
