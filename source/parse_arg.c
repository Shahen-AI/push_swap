#include "../push_swap.h"

int is_digit_string(char *num)
{
    while (*num)
    {
        if (CHECK_ALLOWED_CHARS(*num))
            return (0);
        ++num;
    }
    return (1);
}

int to_space_atoi(char *string)
{
    int num = 0;

    while (*string && *string != ' ')
    {
        num += 10 * (*string - '0');
        (*string)++;
    }
    return (num);
}

// "1 2 3"
int check_all_num(int *args_count, char *arg)
{
    int i;
    int num = 0;

    i = 0;
    while (arg[i])
    {
        if (CHECK_ALLOWED_CHARS(arg[i]))
            ft_error("Error, non-digits detected");
        while (arg[i] && (ft_isdigit(arg[i]) || arg[i] == '-'))
        {
            num += ((arg[i + 1] == ' ') ? 1 : 10) * (arg[i] - '0');
            ++i;
        }
            (*args_count)++;
        if (CHECK_ALLOWED_CHARS(arg[i]) && arg[i])
            ft_error("Error, non-digits detected");
        else if (arg[i])
            i++;
    }
    return (1);
}

// 1 2 3
int check_all_num_2d(int *args_count, char **arg)
{
    int i;

    i = 1;
    while (arg[i])
    {
        if (!is_digit_string(arg[i]))
            ft_error("Error, non-digits detected");
        (*args_count)++;
        i++;
    }
    return (2);
}

int check_args(int *args_count, char argc, char **args)
{
    int ret;

    ret = 0;
    if (argc == 2)
        ret = check_all_num(&(*args_count), args[1]);
    else if (argc > 2)
        ret = check_all_num_2d(&(*args_count), args);
    else if (argc)
        ft_error("No any digits.");
    return (ret);
}
