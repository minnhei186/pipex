/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:40:13 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/20 18:49:05 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0' && len >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}

//#include        <stdio.h>
//#include        <string.h>
//
//int main(void)
//{
//        char    s1[] = "abcdefghijklmn";        /* 検索対象文字列 */
//        char    s2[] = "defgh";                 /* 一致する場合 */
//        char    s3[] = "xyz";                   /* 一致しない場合 */
//        char    s4[] = "abcdefghijklmnopqr";    /* 検索対象文字列より長い場合 */
//        char    s5[] = "";                      /* \0 */
//        char    *sp;
//
//        sp = strnstr(s1,s2,7);
//        printf("一致する場合 : %s\n",sp);
//        sp = strstr(s1,s3);
//        printf("一致しない場合 : %s\n",sp);
//        sp = strstr(s1,s4);
//        printf("検索対象文字列より長い場合 : %s\n",sp);
//        sp = strstr(s1,s5);
//        printf("\\0 : %s\n",sp);
//
//        return (0);
//}
