#include <iostream> // std::cout
#include <omp.h>    // OpenMP header


int main(){


    // CODE IN A BLOCK RUN PARALLELY
    #pragma omp parallel    // Directive to start parallel region
    // The line (or) block RIGHT after the directive is the parallel region
    {   // Start of parallel region
        int ID = omp_get_thread_num();  // function to get thread number
        std::cout << "hello world from thread " << ID << std::endl;
    }   // End of parallel region

    // CODE RIGHT AFTER THE DIRECTIVE IS RUN PARALLELY
    #pragma omp parallel    // Directive to start parallel region
    std :: cout << "line after the directive" << std::endl;
    std :: cout << "2nd line after the directive" << std::endl;

    // CODE OUTSIDE THE BLOCK RUN SEQUENTIALLY
    std::cout << "hello world, me am not parrallel and hence single" << std::endl;


}

