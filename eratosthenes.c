#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define N 1000000

int main(void) {
    char sieve[N+1];
    struct timeval t0, t1;

    gettimeofday(&t0, NULL);

    for (int i = 2; i <= N; i++) {
        if (sieve[i]) continue;

        // printf("%d\n", i);
        for (int j = 2 * i; j <= N; j += i) {
            sieve[j] = 1;
        }
    }

    gettimeofday(&t1, NULL);

    printf("%g\n",
           ((t1.tv_sec - t0.tv_sec) * 1E6 + (t1.tv_usec - t0.tv_usec)) / 1E6);
    return 0;
}
