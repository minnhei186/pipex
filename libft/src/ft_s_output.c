/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:57:08 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/03 12:57:05 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s_output(va_list *args)
{
	char	*s;

	s = (char *)va_arg(*args, int *);
	if (s == NULL)
	{
		ft_pf_putstr("(null)");
		return (6);
	}
	return (write(STDOUT_FILENO, s, ft_pf_strlen(s)));
}

// int main(void)
//{
//	char *s="abc";
//	int count;
//
//	count=printf("%s\n",s);
//	printf("%d\n",count);
//	count=ft_printf("%s\n",s);
//	printf("%d\n",count);
//
//}
