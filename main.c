#include <stdio.h>
#include <stdlib.h>


#include "prime_check.h"





int main(void) {
    long long liczba = 5;
    long long m = 20;
    int k = 0;

    printf("Liczba %lld %s", liczba, ((is_prime_thr(liczba)) ? "jest pierwsza\n": "jest złożona\n") );
/*
    for(liczba = 0; liczba < m; liczba++) {
        printf("Liczba %lld %s", ((is_prime_thr(liczba)) ? "jest pierwsza\n": "jest złożona\n") );
    }
*/


}

