package main

import "fmt"
import "os"

func main() {
    const N = 1000000
    var sieve [N+1] bool
    t0s, t0n, _ := os.Time()
    for i := 2; i <= N; i++ {
	if !sieve[i] {
	    // fmt.Printf("%d\n", i)
	    for j := 2 * i; j <= N; j += i {
		sieve[j] = true
	    }
	}
    }
    t1s, t1n, _ := os.Time()
    fmt.Println(float64(t1s - t0s) + float64(t1n - t0n) / 1.0E9)
}
