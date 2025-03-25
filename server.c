/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:41:34 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/25 03:17:43 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void    ft_hanler(int signum, siginfo_t *info, void *context)
{
	(void) context;
	static int		bit_idx;
	static char		c;
	static __pid_t	pid;

	if (pid != info->si_pid)
	{
		c = 0;
		bit_idx = 7;
		pid = info->si_pid;
	}
	if (signum == SIGUSR2)
		c = c | (1 << bit_idx);
	bit_idx--;
	if (bit_idx == -1)
	{
		if (c == '\0')
			write(1, "\n", 1);
		write(1, &c, 1);
		c = 0;
		bit_idx = 7;
	}
	if (kill(pid, SIGUSR2) == -1)
		exit(1);
}

int main(void)
{
	struct sigaction	act;
	
	act.sa_sigaction = ft_hanler;
	act.sa_flags = SA_SIGINFO;
	if (sigemptyset(&act.sa_mask) == -1)
		return (1);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		return (1);
	ft_putstr("server's pid : ", 1);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}