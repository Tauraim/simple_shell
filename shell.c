#include "shell.h"

/**
 * main - function that makes a simple shell
 * @argc: number of arguments
 * @agv: array of strings containing arguments
 * @env: environment of the function
 * Return: success
 */
int main(int argc, char **agv, char **env)
{
	char *argv[100], *store, bin[100], *tok = NULL;
	int analyse = 0;
	size_t num = 0;
	pid_t child_pid;
	struct stat st;
	(void)argc;

	while (1)
	{
	printf("cisfun# ");
	getline(&store, &num, stdin);

	argv[0] = strtok(store, "\t\n");
	argv[1] = NULL;

	empty_line(store, agv);
	exit_shell(argv);
	_env(argv, env);
	_stat(st, argv, bin, tok, store);
	child_pid = fork();

	if (child_pid == 0)
	{
	execve(argv[0], argv, env);
	}

	else
	wait(&analyse);
	}

	return (0);
}
