#include "simpleshell.h"

/**
 * get_signal - function that not quit simple_shell when the user inputs ^C
 */
void get_signal(int num)
{
	(void)num;
	_putstr("\n#cisfun$ ");
}
