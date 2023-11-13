#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - function that makes a simple shell
 * @argc: number of arguments
 * @agv: array of strings containing arguments
 * @env: environment of the function
 * Return: success
 */
int main(int argc, char **agv, char **env)
{
	char **argv, *store = NULL;
	int i = 1, analyse = 0;
	size_t num = 0;
	pid_t child_pid;
	struct stat st;

	while (1 < 2)
	{
	printf("cisfun# ");
	getline(&store, &num, stdin);
	argv = malloc(sizeof(char) * 1024);

	if (*store == '\n')
	{
	store = agv[0];
	continue;
	}

	argv[0] = strtok(store, "\t\n");

	if (argv[0][0] == 'e' && argv[0][1] == 'x'
	&& argv[0][2] == 'i' && argv[0][3] == 't')
	{
	break;
	_exit;
	}

	if (stat(argv[0], &st) == -1)
	{
	printf("%s: No such file or directory\n", agv[0]);
	continue;
	}

	else
	while (strtok(NULL, "\t\n") != NULL)
	{
	argv[i] = strtok(NULL, "\t\n");
	i++;
	}
	argv[i] = NULL;
	child_pid = fork();

	if (child_pid == 0)
	execve(argv[0], argv, env);

	else
	wait(&analyse);
	}
	free(argv);
	return (0);
}
