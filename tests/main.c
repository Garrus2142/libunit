#include <stdlib.h>
#include "libunit.h"
#include "launchers.h"

int	main(void)
{
	t_unit_tests		*tests;

	tests = unit_init("Example of tests");
	unit_register_launcher(tests, "STRLEN", strlen_launcher);
	unit_register_launcher(tests, "PUTSTR", putstr_launcher);
	if (!unit_launch_tests(tests))
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
