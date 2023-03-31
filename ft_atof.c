#include <stdio.h>
#include "fractol.h"

double ft_atof(char *str)
{
    int a = 0;
    double res = 0.0;
    double r = 0.1;
    while(str[a] && (str[a] >= '0' && str[a] <= '9'))
    {
        if(str[a] == '.')
            break;
        res *= 10;
        res = res + str[a] - 48;
        a++;
    }
    a++;
    while(str[a])
    {
        res += (str[a] - 48) * r;
        r *= 0.1;
        a++;
    }
	printf("%f\n", res);
    return res;
}
int main(int ac, char **av)
{
	ft_atof(av[1]);
}
