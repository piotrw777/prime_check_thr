#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <unistd.h>
#include "prime_check.h"

long long suma_elem(int tab[], int rozmiar) {
    long long suma = 0;
    for(int k = 0; k < rozmiar; k++) {
        suma += tab[k];
    }
    return suma;
}

void wyswietl(int tablica[], int rozmiar) {
    for(int k = 0; k < rozmiar; k++) {
        printf("%d ", tablica[k]);
    }
    printf("\n");
}

void *threadFunction(void * arg) {
    args * wsk = (args *) arg;

    ull n = wsk->liczba;
    ull max_d = wsk->max_d;
    int thread_nr = wsk->thread_nr;
    int start = wsk->start;
    int step = wsk->step;
    int *w = wsk->w;
    bool result = -1;

    for(int k = start; k < max_d; k += step) {
        sleep(1);
        printf("Jestem wątkiem nr %d i sprawdzam dzielnik %lld\n", thread_nr, k);
        //mamy dzielnik - liczba jest złożona
        if(n % k == 0) {
            result = 0;
            //zamykamy wątki
            pthread_cancel(w[1 - thread_nr]);
            pthread_exit( (void *) result);
        }
    }   //end for
    //liczba przeszła testy - jest pierwsza
    result = 1;
    //zamykamy wątki
    pthread_cancel(w[1 - thread_nr]);
    pthread_exit( (void *) result);

}   //end threadFunction

bool is_prime_thr(ull n) {

    if(n <= 1) return false;
    if(n == 2 || n == 3 || n == 5) return true;
    if( n % 2 == 0) return false;
    if( n % 3 == 0) return false;
    if( n % 5 == 0) return false;

    const int M = 2; //liczba wątków
    const int STEP = 6;

    pthread_t Threads[M]; //wątki
    int Results[M];       //wyniki zwracane przez wątki
    memset(Results, 0, M * sizeof(* Results) );
    args Args_thr[M];  //argumenty dla wątków
    int ret;
    int Start[M] = {5, 7};
    //wypełnienie tablicy argumentów dla wątków
    for(int k = 0; k < M; k++) {
        Args_thr[k] = { n, (ull) sqrt(n) + 1, k, Start[k], STEP, Threads };
    }
    //tworzenie wątków
    for(int k = 0; k < M; k++) {
        ret = pthread_create(&Threads[k], NULL, &threadFunction, &Args_thr[k]);
        if(ret != 0) {
            printf("Błąd wątku %d", k);
            exit(-1);
        }
    }
    //czekamy na wątki
    for(int k = 0; k < M; k++) {
        pthread_join(w[k], (void *) &Results[k]);
    }

    printf("Rezultaty zwrócone przez wątki: ");
    wyswietl(Results, M);
    int suma_results = suma_elem(Results, M);
    if(suma_results >  0) {
        return true;
    }
    else if(suma_results == 0) {
        return false;
    }
    else {
        perror("Błąd funkckcji is_prime");
    }
}

