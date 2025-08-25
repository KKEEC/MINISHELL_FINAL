#include "../../includes/env.h"
#include <stddef.h>  // for NULL
#include "../../includes/utils.h"  // for isstrequal

char	*get_env_value(t_env *env, const char *key)
{
	if (!key)
		return (NULL);
	while (env)
	{
		if (isstrequal(env->key, key))
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
