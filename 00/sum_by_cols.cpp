#include <chrono>
#include <iostream>

using namespace std;

class Timer
{
    using clock_t = chrono::high_resolution_clock;
    using microseconds = chrono::microseconds;
public:
    Timer()
        : start_(clock_t::now())
    {
    }

    ~Timer()
    {
        const auto finish = clock_t::now();
        const auto us = 
            chrono::duration_cast<microseconds>
                (finish - start_).count();
        cout << us << " us" << endl;
    }

private:
    const clock_t::time_point start_;
};


int main(){

    int max_rows = 1000, max_cols = 1000;
    int summ = 0;
    
    int array[max_rows][max_cols];

    for (int i = 0; i < max_rows; ++i){
        for (int j = 0; j < max_cols; ++j){
            array[i][j] = (i + j) % 3;
        }
    }

    Timer t;

    for (int i = 0; i < max_cols; ++i){
        for (int j = 0; j < max_rows; ++j){
            summ += array[j][i];
        }
    }

    cout << "sum = " << summ << endl;

    return 0;
}