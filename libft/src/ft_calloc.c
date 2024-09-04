/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:22:09 by dhosokaw          #+#    #+#             */
/*   Updated: 2023/06/21 16:04:24 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*headp;

	i = 0;
	if (size && count > SIZE_MAX / size)
		return (0);
	p = malloc(count * size);
	if (p == NULL)
		return (0);
	headp = p;
	while (i < count * size)
	{
		*p = 0;
		p++;
		i++;
	}
	return (headp);
}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main(void)
//{
//   int *ptr,*p;
//   int i;
//
//   /* 500個のintサイズのメモリを確保 */
//   ptr = (int *)ft_calloc(42,4);
//   if(ptr == NULL) {
//      printf("メモリが確保できません\n");
//      exit(EXIT_FAILURE);
//   }
//
//   p = ptr;
//   for (i=0; i<42; i++) {
//      printf("%d ",p[i]);
//   }
//
//   /* メモリの開放 */
//   free(ptr);
//
//   return (0);
//}
//
//
//
