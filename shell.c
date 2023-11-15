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
	char *argv[100], *store, bin[100], *tok;
	int i = 1, analyse = 0, n = 0;
	size_t num = 0;
	pid_t child_pid;
	struct stat st;
	(void)argc;

	while (1)
	{
	printf("cisfun# ");
	getline(&store, &num, stdin);

	if (*store == '\n')
	{
	store = agv[0];
	continue;
	}
	argv[0] = strtok(store, "\t\n");
	argv[1] = NULL;

	if (argv[0][0] == 'e' && argv[0][1] == 'x' && argv[0][2] == 'i' && argv[0][3] == 't')
	{
	break;
	_exit(98);	
	}

	if (argv[0][0] == 'e' && argv[0][1] == 'n' && argv[0][2] == 'v')
	{
	while(env[n] != NULL)
	{
	printf("%s\n", env[n]);
	n++;
	}
	continue;
	}

	if (stat(argv[0], &st) == -1)
        {
	strcpy(bin, "/bin/");
	argv[0] = strtok(store, " \t\n");
	strcat(bin, argv[0]);
	argv[0] = bin;

	tok = strtok(NULL, " \t\n");
	i = 1;
	while(tok != NULL)
	{
	argv[i] = tok;
	tok = strtok(NULL, " \t\n");
	i++;
	}
	argv[i] = NULL;
	}
     
	if(stat(argv[0], &st) == -1)
	{
        printf("%s: No such file or directory\n", store);
	continue;
	}

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
