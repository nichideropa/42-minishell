The minishell did pass the evaluation and did it without any segfaults.
Now there are some segfaults at 'go wild' part of tims tester.

Issues found during the minishell evaluation:
	echo - doesn't display anything (no priority)
	echo hallo >testi
		(testi is a file with no permission, started in a simple
		command the bash quits)
	echo hallo >testi | hostname
		(we have a pointer being freed was not allocated)
	cat | cat | cat (control c not working as expected)
