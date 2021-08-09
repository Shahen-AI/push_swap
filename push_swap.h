#ifndef PUSH_SWAP_H_
# define PUSH_SWAP_H_

# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

# define CHECK_ALLOWED_CHARS(c) (c != ' ' && !ft_isdigit(c) && c != '-')

typedef struct s_stack
{
    int num;
    int index;
	int rei;
	int check;
} t_stack;

typedef struct s_c {
	int c_a;
	int c_b;
} t_c;

typedef struct s_stacks {
	int ch_s;
	t_c c;
    t_stack *stack_a;
    t_stack *stack_b;
} t_stacks;

int 		check_all_num(int *args_count, char *arg);
int 		check_all_num_2d(int *args_count, char **arg);
int 		check_args(int *args_count, int argc, char **args);
int 		ft_error(char *text);
void 		ft_putstr(char *str);
t_stack 	*addToList(t_stack last, int new_num);
void 		fill_stacks(t_stacks *stacks, int pt, int ac, char **argv);
void 		printf_stacks(t_stacks *stacks, int args_count);
void		printf_index(t_stacks *stacks, int args_count);
void 		shift_up(t_stack *stack, int args_count);
void 		shift_down(t_stack *stack, int args_count);

int 		max_five(t_stacks *stacks);
int 		max_hundred(t_stacks *stacks, int ch_s);
int 		mad_max(t_stacks *stacks, int ch_s);
int 		check_stack(t_stacks stacks);
int			find_min_nu_ind(char s_t, t_stacks *stacks);
int			find_high_ind(char s_t, t_stacks *stacks);

void 		indexing(t_stacks *stacks);
int			find_min_nu_ind(char s_t, t_stacks *stacks);
int			in_chunck(int index, int chunck_num, int ch_s);

int 		find_min_nu_ind_new(t_stacks *stacks);
void 		swap(char s, t_stack *stack);
void 		push(char stack, t_stacks *stacks);
void 		rot(char s, t_stack *stack, int ac);
void		r_rot(char s, t_stack *stack, int ac);
void		ss(t_stacks stacks);
void		rr(t_stacks stacks);
void		rrr(t_stacks stacks);
int 		back_fill(t_stacks *stacks);

void		sort(t_stacks stacks);

#endif
