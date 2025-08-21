#include "../../includes/parser.h"
#include "../../includes/utils.h"

t_ast	*parse_command_segment(t_token **tokens)
{
	t_ast	*cmd;
	t_ast	*command_node;

	cmd = new_command_node();
	if (!cmd)
		return (NULL);
	command_node = cmd;
	while (*tokens && (*tokens)->type != TOKEN_PIPE)
	{
		if (is_redirection((*tokens)->type))
			cmd = handle_redirection_token(cmd, tokens);
		else if ((*tokens)->type == TOKEN_WORD)
		{
			add_arg_to_command(command_node, (*tokens)->value);
			*tokens = (*tokens)->next;
		}
	}
	return (cmd);
}

t_ast	*parse_tokens(t_token *tokens)
{
	t_ast	*left;
	t_ast	*right;

	left = NULL;
	right = NULL;
	if (!tokens)
		return (NULL);
	left = parse_command_segment(&tokens);
	while (tokens && tokens->type == TOKEN_PIPE)
	{
		tokens = tokens->next;
		right = parse_command_segment(&tokens);
		left = new_pipe_node(left, right);
	}
	return (left);
}
