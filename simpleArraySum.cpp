#include <iostream>
#include <omp.h>

void reset(int *a, int n){
    for (int i = 0; i < n; i++){
        a[i] = 0;
    }
}

int main(){
    int n = 100;
    int num_threads = 8;
    int a[n];

    int sum[num_threads];

    for (int i = 0; i < n; i++){
        a[i] = i;
    }

    reset(sum, num_threads);

    // Serial
    double start = omp_get_wtime();

    for (int i = 0; i < n; i++){
        sum[0] += a[i];
    }

    double duration = omp_get_wtime() - start;
    std::cout << "Sum: " << sum[0] << std::endl;
    std::cout << "Time taken: " << duration << std::endl;

    reset(sum, num_threads);

    // Parallel
    start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < n; i++){
        sum[0] += a[i];
    }

    duration = omp_get_wtime() - start;
    std::cout << "Time taken: " << duration << std::endl;

}