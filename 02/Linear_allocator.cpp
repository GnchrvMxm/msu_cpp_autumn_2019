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

class LinearAllocator
{
    char* base_pointer;
    size_t size;
    size_t offset;

public:
    LinearAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
    ~LinearAllocator();
};

LinearAllocator :: LinearAllocator(size_t maxSize)
{
    offset = 0;
    size = maxSize;
    base_pointer = (char*) malloc(maxSize*sizeof(char));
};

char* LinearAllocator :: alloc(size_t allocated_size)
{
    if (offset + allocated_size > size) return nullptr;
    char* pointer = base_pointer + offset;
    offset += allocated_size;
    return (char*) pointer;
};

void LinearAllocator :: reset()
{
    offset = 0;
};

LinearAllocator :: ~LinearAllocator()
{
    free(base_pointer);
};

int main(){

    Timer T;

    LinearAllocator heap(1024000*sizeof(char));

    for (int i = 0; i < 1000000; ++i){
        heap.alloc(1024000);
        heap.reset();
}
    
    cout << "1_000_000 allocs + resets by LinearAllocator:" << endl;
    return 0;
}