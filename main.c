#include <stdio.h>
#include <stdlib.h>


#include "prime_check.h"

int main(void) {
    long long liczba = 641*175391;
    long long m = 20;
    int k = 0;

    printf("bbbLiczba %lld %s", liczba, ((is_prime_thr(liczba)) ? "jest pierwsza\n": "jest złożona\n") );
/*
    for(liczba = 0; liczba < m; liczba++) {
        printf("Liczba %lld %s", ((is_prime_thr(liczba)) ? "jest pierwsza\n": "jest złożona\n") );
    }
*/
    //for(int k = 1e4; k < 1e5; k += 1e4)
    //printf("Ilość liczb pierwszych <= %d wynosi %lld\n",k, pi(k));
    ull num = 5000000000000000005;
    printf("Następna liczba pierwsza po %llu to %llu\n",num, next_prime_thr(num) );
}

