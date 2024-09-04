/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:30:10 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/06/03 12:54:25 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c_output(va_list *args)
{
	ft_pf_putchar(va_arg(*args, int));
	return (1);
}

// int main(void)
// {

// 	ft_printf("%c %c",'h','e');

// 		i=ft_printf("%c\n",c);
//  printf("%d\n",i);
// 	return (0);
// }
