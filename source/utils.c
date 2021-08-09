#include "../push_swap.h"

void	ft_putstr(char *str)
{
    while (*str)
    {
        write(1, &(*str), 1);
        ++str;
    }
}

void	printf_stacks(t_stacks *stacks, int args_count)
{
    int i = 0;

	printf("args count - %d\n", args_count);
    while (i < args_count)
    {
		if (stacks->c.c_a > i)
        	printf("%d", stacks->stack_a[i].num);
		if (stacks->c.c_b > i)
        	printf("  %d", stacks->stack_b[i].num);
		printf("\n");
        ++i;
    }
    printf("-  -\n");
    printf("a  b\n");
}

void	printf_index(t_stacks *stacks, int args_count)
{
    int i = 0;

	printf("args count - %d\n", args_count);
    while (i < args_count)
    {
		if (stacks->c.c_a > i)
        	printf("%d", stacks->stack_a[i].index);
		if (stacks->c.c_b > i)
        	printf("  %d", stacks->stack_b[i].index);
		printf("\n");
        ++i;
    }
    printf("-  -\n");
    printf("a  b\n");
}

void	shift_up(t_stack *stack, int args_count)
{
    int i = 0;

    while (i < args_count)
    {
        stack[i] = stack[i + 1];
        ++i;
    }
}

void	shift_down(t_stack *stack, int args_count)
{
    int i = args_count;

    while (i > 0)
    {
        stack[i] = stack[i - 1];
        --i;
    }
}

int check_stack(t_stacks stacks)
{
	t_stack temp;
	int i = 0;

	temp = stacks.stack_a[i];
	while (i < stacks.c.c_a)
	{
		if (temp.num > stacks.stack_a[i].num)
			return (0);
		temp = stacks.stack_a[i];
		++i;
	}
	return (1);
}