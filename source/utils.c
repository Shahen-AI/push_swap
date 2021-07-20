#include "../push_swap.h"

void	ft_putstr(char *str)
{
    while (*str)
    {
        write(1, &(*str), 1);
        ++str;
    }
}

void	printf_stacks(t_stacks stacks, int args_count)
{
    int i = 0;

	printf("args count - %d\n", args_count);
    while (i < args_count)
    {
		if (stacks.c.c_a > i)
        	printf("%d", stacks.stack_a[i]);
		if (stacks.c.c_b > i)
        	printf("  %d", stacks.stack_b[i]);
		printf("\n");
        ++i;
    }
    printf("-  -\n");
    printf("a  b\n");
}

void	shift_up(int *stack, int args_count)
{
    int i = 0;

    while (i < args_count)
    {
        stack[i] = stack[i + 1];
        ++i;
    }
}

void	shift_down(int *stack, int args_count)
{
    int i = args_count;

    while (i > 0)
    {
        stack[i] = stack[i - 1];
        --i;
    }
}
