package at.hjp.eratosthenes;

import java.util.Date;

class Main {

    static final int N = 1000000;
    public static void main(String[] argv) {
	boolean[] sieve = new boolean[N+1];

	Date t0 = new Date();
	for (int i = 2; i <= N; i++) {
	    if (sieve[i]) continue;

	    //System.out.println(i);
	    for (int j = 2 * i; j <= N; j += i) {
		sieve[j] = true;
	    }
	}
	Date t1 = new Date();
	System.out.println((t1.getTime() - t0.getTime()) / 1000.0);
    }
}
