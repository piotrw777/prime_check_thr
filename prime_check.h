#ifndef __HEADER
#define __HEADER

#define false 0
#define true 1

typedef unsigned long long ull;
typedef int bool;

struct args {
    ull liczba;   //kandydat do testu
    ull max_d;    //maksymalny dzielnik
    int thread_nr;      //który wątek w kolejności
    int start;          //od którego dzielnika startujemy
    int step;
    int *w;             //tablica z id wątków do zamknięcia
};


typedef struct args args;

bool is_prime_thr(ull n);

#endif // __HEADER
