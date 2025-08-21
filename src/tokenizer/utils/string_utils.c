/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeec <kkeec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by kkeec            #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by kkeec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tokenizer.h"
#include "../../../includes/env.h"

char	*append_var(char *result, char **tstr, t_env *env_list)
{
	char	*start;
	char	*key;
	char	*value;
	char	*tmp;

	start = *tstr;
	while (**tstr && (ft_isalnum(**tstr) || **tstr == '_'))
		(*tstr)++;
	key = ft_strndup(start, *tstr - start);
	value = get_env_value(env_list, key);
	free(key);
	if (!value)
	{
		tmp = ft_strdup(result);
		return (tmp);
	}
	tmp = ft_strjoin(result, value);
	return (tmp);
}

char	*handle_dollar(char *result, char **tstr, int *status, t_env *env_list)
{
	(*tstr)++;
	if (!**tstr)
		return (append_char(result, '$'));
	if (**tstr == '$')
	{
		(*tstr)++;
		return (append_pid(result));
	}
	else if (**tstr == '?')
	{
		(*tstr)++;
		return (append_status(result, status));
	}
	else if (ft_isalpha(**tstr) || **tstr == '_')
		return (append_var(result, tstr, env_list));
	return (append_char(result, '$'));
}
