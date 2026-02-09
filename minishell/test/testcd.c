#include "../src/minishell.h"

int	main(void)
{
	char	cdw[1024];

	if (chdir("/home") != -1)
		printf("success\n");
	else
		printf("directory doesnt exist\n");
	if (getcwd(cdw, sizeof((cdw))) != NULL)
	{
		printf("%s\n", cdw);
	}
	else
		perror("getwcd\n");
}
