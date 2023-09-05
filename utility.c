#include "main.h"
/**
 * parse_ln - parse line for opcode
 * @ln: line to parse
 * @return opcode
 */
char *parse_ln(char *ln)
{
	char *op_code = NULL;

	op_code = strtok(ln, " \n\t");
	if (op_code == NULL)
		return (NULL);

	return (op_code);
}

/**
 * get_op_code - select opcode
 * @str: opcode
 * Return: pointer to function
*/
sel_op_code get_op_code(char *str)
{
	instruction_t op_codes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};
	int i = 0;
	/* Go down the function list and return function if zero*/
	while (op_codes[i].f != NULL)
	{
		if (strcmp(op_codes[i].opcode, str) == 0)
			return (op_codes[i].f);
		i++;
	}
	return (NULL);
}