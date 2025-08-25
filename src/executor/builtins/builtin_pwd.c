#include "../../../includes/executor.h"
#include <unistd.h> // for getcwd
#include <stdio.h>  // for printf

int	builtin_pwd(void)
{
	char	*currentdir;

	currentdir = getcwd(NULL, 0);
	if (!currentdir)
	{
		perror("pwd");
		return (1);
	}
	printf("%s\n", currentdir);
	free(currentdir);
	return (0);
}
