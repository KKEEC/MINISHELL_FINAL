#include "../../../includes/executor.h"
#include <stdio.h>  // for printf

int	builtin_env(t_env *env_list, char **args)
{
	if (!args)
		return (1);
	if (args[1])
	{
		printf("env: too many arguments\n");
		return (1);
	}
	while (env_list)
	{
		if (env_list->value && env_list->key)
			printf("%s=%s\n", env_list->key, env_list->value);
		env_list = env_list->next;
	}
	return (0);
}
