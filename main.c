#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stacks stacks;
    int parse_type;

    stacks.c.c_a = 0;
    stacks.c.c_b = 0;
    parse_type = check_args(&stacks.c.c_a, argc, argv);

    if (!(stacks.stack_a = (t_stack *)malloc((stacks.c.c_a + 1) * sizeof(t_stack)))
    	|| !(stacks.stack_b = (t_stack *)malloc((stacks.c.c_a + 1) * sizeof(t_stack))))
        ft_error("Something went wrong.");

    fill_stacks(&stacks, parse_type, stacks.c.c_a, argv);
	sort(stacks);
    free(stacks.stack_a);
    free(stacks.stack_b);
	// printf_stacks(&stacks, (stacks.c.c_a + stacks.c.c_b));
    return (0);
}
