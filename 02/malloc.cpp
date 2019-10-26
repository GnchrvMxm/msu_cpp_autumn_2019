#include <iostream>
#include <chrono>

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

    Timer T;

    for (int i = 0; i < 10000; ++i){
        char* c = (char*) malloc(1024000*sizeof(char));
        free(c);
    }

    cout <<  "10_000 allocs + resets by malloc+free:" << endl;
    return 0;
}