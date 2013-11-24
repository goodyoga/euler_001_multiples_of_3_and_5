/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <unistd.h>   /* getopt */

///
/// @startuml "euler_001_multiples_of_3_and_5.png"
/// title euler_001_multiples_of_3_and_5
/// participant defaults
/// participant i
/// participant sum
/// 
/// note over defaults,sum: [multiples of 3 and 5] means [add if mul of 3 or mul of 5]
/// 
/// break h option
/// defaults->defaults: PRINT(usage)
/// defaults->defaults: exit(EXIT_SUCCESS)
/// end
/// defaults->defaults:below = 1000
/// opt b option
/// defaults->defaults: below = value by cmdline
/// end
/// 
/// defaults->i: i = 1
/// defaults->sum: sum = 0
/// loop i < below
/// alt multiples of 3 or 5
/// note left of sum: !(i % x) means (mod(i,x) == 0) 
/// i->sum: sum.add(i)
/// end alt
/// 
/// i->i: i++
/// end loop
/// 
/// sum->sum: PRINT(sum)
/// @enduml
/// 

void usage(void);

int main(int argc __attribute__((unused)), char **argv)
{
    int i;
    int sum;
    int opt, below = 1000;
    while ( -1 != (opt = getopt(argc, argv, "hb:")) )
    {
        if('h' == opt)
        {
            usage();
            exit(EXIT_SUCCESS);
        }
        else if ('b' == opt)
        {
            below = atoi(optarg);
        }
    }
    for ( i = 1,sum = 0 ; i < below ; i++)
    {
        if ( !( i % 3 ) || !( i % 5 ) )
        {
            sum += i;
            printf("%s: add:%d, sum:%d\n", argv[0], i, sum);
        }
    }
    return EXIT_SUCCESS;
}


void usage(void)
{
    printf("    http://projecteuler.net/problem=1\n");
    printf("    [Problem 1] Multiples of 3 and 5\n");
    printf("    If we list all the natural numbers below 10 \n"
           "    that are multiples of 3 or 5, we get 3, 5, 6 and 9.\n"
           "    The sum of these multiples is 23.\n"
           "    Find the sum of all the multiples of 3 or 5 below 1000.\n\n");
    printf("    -h: show this help\n"
           "    -b <number>: solve this between 1 and below <number>\n");
    return;
}
