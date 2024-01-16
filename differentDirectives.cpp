#include <iostream> // std::cout
#include <omp.h>    // OpenMP header


// Open MP gives us different directives to control the parallel region
// 1. #pragma omp parallel
// 2. #pragma omp parallel num_threads(4)
// 3. #pragma omp parallel for
// 4. #pragma omp parallel for num_threads(4)

int main(){

    #pragma omp parallel // automatically creates a team of threads
    {
        int ID = omp_get_thread_num();  // Get thread number
        std::cout << "hello world from thread " << ID << std::endl;
    }   // End of parallel region

    std :: cout << "====================================================================================" << std::endl;

    #pragma omp parallel num_threads(4) // creates a team of 4 threads
    {
        int ID = omp_get_thread_num();  // Get thread number
        std::cout << "hello world from thread " << ID << std::endl;
    }   // End of parallel region

    std :: cout << "====================================================================================" << std::endl;

    #pragma omp parallel for  // creates a team of threads and distributes the for loop iterations among them
    for (int i = 0; i < 10; i++){
        std::cout << "hello world from thread " << omp_get_thread_num() << std::endl;
    }   // End of parallel region

    std :: cout << "====================================================================================" << std::endl;

    #pragma omp parallel for num_threads(4) // creates a team of 4 threads and distributes the for loop iterations among them
    for (int i = 0; i < 10; i++){
        std::cout << "hello world from thread " << omp_get_thread_num() << std::endl;
    }   // End of parallel region

}