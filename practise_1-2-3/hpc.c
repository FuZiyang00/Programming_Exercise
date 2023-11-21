#include <stdio.h>
#include <omp.h> 

#pragma omp parallel 
{
int my_thread_id = omp_get_thread_num();
printf( "greetings from thread num %d\n", my_thread_id );
}