#include "simpleshell.h"

/**
 * get_signal - function that not quit simple_shell when the user inputs ^C
 * @num: a variable ignore
 * Return: void
 */
void get_signal(int num)
{
	(void)num;
	_putstr("\n#cisfun$ ");
}
