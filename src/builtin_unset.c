#include "../inc/minishell.h"

extern t_minishell	g_msh;
int		is_valid_identifier2(char *argument, int *id_len);
void	remove_variable(char *argument, int *id_len);

int	unset_builtin(char **arguments)
{
	int		i;
	int		id_len;
	int		exit_status;

	if (arguments == NULL || arguments[0] == NULL)
		return (EXIT_SUCCESS);
	i = 0;
	exit_status = 0;
	while (arguments[i] != NULL)
	{
		if (is_valid_identifier2(arguments[i], &id_len) == 1)
		{
			put_stderr(SHELL, "unset_builtin", arguments[i],
				"not a valid identifier");
			exit_status = EXIT_FAILURE;
		}
		else
			remove_variable(arguments[i], &id_len);
		i++;
	}
	return (exit_status);
}

int	is_valid_identifier2(char *argument, int *id_len)
{
	if (!ft_isalpha(argument[0]) && argument[0] != '_')
		return (1);
	*id_len = 1;
	while (argument[*id_len] != '\0')
	{
		if (!ft_isalnum(argument[*id_len]) && argument[*id_len] != '_')
			return (1);
		*id_len += 1;
	}
	return (0);
}

void	remove_variable(char *argument, int *id_len)
{
	int		i;

	i = 0;
	if (g_msh.env == NULL)
		return ;
	while (g_msh.env[i] != NULL)
	{
		if (ft_strncmp(g_msh.env[i], argument, *id_len) == 0)
		{
			g_msh.env = rm_array_element(g_msh.env, g_msh.env[i]);
			break ;
		}
		i++;
	}
}
