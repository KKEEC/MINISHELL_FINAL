#ifndef PARSER_H
# define PARSER_H

#include "tokenizer.h"

typedef enum    e_node_type
{
    NODE_COMMAND,
    NODE_PIPE,
    NODE_REDIR,
} t_node_type;
typedef struct s_ast
{
    t_node_type    type;
    struct s_ast    *left;
    struct s_ast    *right;
    char    **args;
    t_token_type redir_type;
    char *filename;
    int is_quoted_delimiter;
}   t_ast;

t_ast   *parse_tokens(t_token *tokens);
t_ast	*parse_command_segment(t_token **tokens);

// AST Node constructors
t_ast *new_command_node(void);
t_ast *new_pipe_node(t_ast *left, t_ast *right);
t_ast *new_redir_node(int redir_type, const char *filename, t_ast *cmd);

// Parser utilities
int add_arg_to_command(t_ast *cmd, const char *arg);
t_ast	*handle_redirection_token(t_ast *cmd, t_token **tokens);
int is_syntax_error(t_token *token);
int is_redirection(t_token_type type);

// Syntax error utilities
int	handle_pipe_redir_error(t_token *token);
void	write_token_error(t_token *token);
void	write_pipe_in_error(t_token *token);

// Debug utilities
void print_indent(int depth);
void print_ast(t_ast *node, int depth);

// Memory management
void    free_ast(t_ast *node);




# endif