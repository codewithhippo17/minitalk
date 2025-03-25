/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:38:22 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/25 03:04:04 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str, int fd);
void	ft_putnbr(int n);
int     ft_atoi(const char *nptr);

#endif
