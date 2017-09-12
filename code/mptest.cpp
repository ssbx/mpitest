/*
 *   "Hello World" OpenMP Test Program
 */
#include <iostream>

int 
main(int argc, char **argv)
{
    int n;
    const int size = 256;
    double sintable[size];

    /* Compute some things with OpenMP */
#pragma omp parallel
    {
        std::cout << "hello world\n";
    }

    return 0;
}
