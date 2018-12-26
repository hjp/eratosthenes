/* Sieve of eratosthenes in C
 *
 * This differs from the example in directory ../C by doing all the
 * arithmetic in double instead of int - just to check how much slower
 * it is (on a Core2 Duo using gcc 4.9.1 for i586-linux-gnu about 5
 * times slower, but on a Xeon X7460 (gcc 4.7.2, x86_64-linux-gnu) only
 * about 30%)
 */
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define N 1000000

int main(void) {
    char sieve[N+1];
    struct timeval t0, t1;

    gettimeofday(&t0, NULL);

    double nprimes = 0;
    for (double i = 2; i <= N; i++) {
        if (sieve[(int)i]) continue;

        nprimes++;
        // printf("%d\n", i);
        for (double j = 2 * i; j <= N; j += i) {
            sieve[(int)j] = 1;
        }
    }

    gettimeofday(&t1, NULL);

    printf("%g primes <= %g found in %g seconds\n",
           nprimes,
           (double)N,
           ((t1.tv_sec - t0.tv_sec) * 1E6 + (t1.tv_usec - t0.tv_usec)) / 1E6);  // sic!
    return 0;
}
