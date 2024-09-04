/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhosokaw <dhosokaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:31:33 by dhosokaw          #+#    #+#             */
/*   Updated: 2024/01/18 15:04:27 by dhosokaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

int		ft_c_output(va_list *args);
int		ft_s_output(va_list *args);
int		ft_p_output(va_list *args);
int		ft_d_output(va_list *args);
int		ft_i_output(va_list *args);
int		ft_u_output(va_list *args);
int		ft_x_output(va_list *args);
int		ft_xx_output(va_list *args);
int		ft_percent_output(void);

int		ft_printf(const char *format, ...);

#endif
