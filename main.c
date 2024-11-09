#include "psh.h"

void	print_history()
{
	HIST_ENTRY **history;
	int			i;

	history = history_list();
	i = 0;
	if (history)
		while (history[i])
			printf("%s\n", (char *)history[i++]->line);
}

int	main()
{
	char		*prompt;

	while(TRUE)
	{
		using_history();
		prompt = readline("> ");
		if (!prompt)
			return -1;
		if (*prompt && strcmp(prompt, "history") != 0)
			add_history(prompt);
		if (strcmp(prompt, "exit") == 0)
			return 0;
		else if (strcmp(prompt, "history") == 0)
			print_history();
		else
			printf("%s\n", prompt);
		free(prompt);
	}
}