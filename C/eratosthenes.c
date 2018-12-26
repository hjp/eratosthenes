#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N 1000000

typedef unsigned prime_t;

int main(void) {
    struct timeval t0, t1;

    assert((prime_t)N + 1 > N);
    assert((prime_t)N * 2 > N);
    assert((size_t)N == N);

    gettimeofday(&t0, NULL);

    char *sieve = calloc(N, 1);
    assert(sieve);

    int found = 0;

    for (prime_t i = 2; i <= N; i++) {
        if (sieve[i]) continue;
        found++;

        // printf("%d\n", i);
        for (prime_t j = 2 * i; j <= N; j += i) {
            sieve[j] = 1;
        }
    }

    gettimeofday(&t1, NULL);

    printf("%d primes <= %ju found in %g seconds\n",
           found,
           (uintmax_t)N,
           ((t1.tv_sec - t0.tv_sec) * 1E6 + (t1.tv_usec - t0.tv_usec)) / 1E6); // sic!
    return 0;
}
