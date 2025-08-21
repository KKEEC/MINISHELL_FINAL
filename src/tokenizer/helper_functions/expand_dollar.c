/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeec <kkeec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by kkeec            #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by kkeec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/tokenizer.h"

char	*expanddollar(const char *str, t_env *env_list, int *status)
{
	char	*result;
	char	*temp;
	char	*tstr;

	tstr = (char *)str;
	result = ft_strdup("");
	while (*tstr)
	{
		if (*tstr == '$')
		{
			temp = handle_dollar(result, &tstr, status, env_list);
			free(result);
			result = temp;
		}
		else
		{
			temp = append_char(result, *tstr);
			free(result);
			result = temp;
			tstr++;
		}
	}
	return (result);
}
