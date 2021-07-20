#include "../push_swap.h"

void	ss(t_stacks stacks)
{
	swap('a', stacks.stack_a);
	swap('b', stacks.stack_b);
	ft_putstr("ss");
}

void	rr(t_stacks stacks)
{
	rot('a', stacks.stack_a, stacks.c.c_a);
	rot('b', stacks.stack_b, stacks.c.c_b);
	ft_putstr("rr");
}

void	rrr(t_stacks stacks)
{
	r_rot('a', stacks.stack_a, stacks.c.c_a);
	r_rot('b', stacks.stack_b, stacks.c.c_b);
	ft_putstr("rrr");
}
