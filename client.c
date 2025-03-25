/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 01:35:56 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/25 03:17:55 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

static int	g_flag;

void	ft_send(char c, __pid_t pid)
{
	int	byte;
	int	bit;
	int	ret_kill;

	byte = 7;
	while (byte >= 0)
	{
		bit = c >> byte & 1;
		if (bit == 0)
			ret_kill = kill(pid, SIGUSR1);
		else
			ret_kill = kill(pid, SIGUSR2);
		if (ret_kill == -1)
		{
			ft_putstr("PID is invalid\n", 2);
			exit(1);
		}
		byte--;
		while (g_flag == 0)
			;
		g_flag = 0;
	}
}
static void	signal_handler(int signum)
{
	(void) signum;
	g_flag = 1;
}

int main(int ac, char *av[])
{
	__pid_t	pid;
	int i;

	i = 0;
	if (ac != 3)
	{
		ft_putstr("Usage: ./client <PID> <STRING>\n", 2);
		return (1);
	}
	g_flag = 0;
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
		return (1);
	pid = ft_atoi(av[1]);
	if (pid == -1 || pid == 0)
		return (1);
	while (av[2][i])
	{
		ft_send(av[2][i], pid);
		i++;
	}
	ft_send('\0', pid);
	return (0);
}