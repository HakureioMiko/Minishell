#include "../src/minishell.h"

int	main(void)
{
	t_pwd	*pwd;
	char	cdw[1024];

	pwd = malloc(sizeof(pwd));
	if (getcwd(cdw, sizeof((cdw))) != NULL)
	{
		pwd->pwd = cdw;
		printf("%s\n", cdw);
		printf("%s\n", pwd->pwd);
	}
	else
		perror("getwcd");

	return (0);
}
