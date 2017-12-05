#include "21sh.h"

void   sig_exe(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, sig_exe);
	}
}

void   sig_init(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr("\n\033[34;1m$> \033[0m");
		signal(SIGINT, sig_init);
	}
}
