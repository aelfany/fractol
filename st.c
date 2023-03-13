#include<stdio.h>
#include<stdlib.h>

int main(int ac , char **av)
{
	(void)ac;
	printf("%d\n", atoi(av[1]) + atoi(av[2]));
}
