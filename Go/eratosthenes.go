package main

import "fmt"
import "time"

func main() {
    const N = 1000000
    var sieve [N+1] bool
    t0 := time.Now()
    for i := 2; i <= N; i++ {
	if !sieve[i] {
	    // fmt.Printf("%d\n", i)
	    for j := 2 * i; j <= N; j += i {
		sieve[j] = true
	    }
	}
    }
    d := time.Since(t0)
    fmt.Println(d.Seconds())
}
