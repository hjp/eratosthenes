C sieve of eratosthenes in FORTRAN IV
      dimension notprm(1000000)
      n = 1000000
      do 12, i=2,n
      if (notprm(i) .eq. 1) go to 11
      write(0,20) i
      do 10, j=2*i,n,i
      notprm(j) = 1
   10 continue
   11 continue
   12 continue

   20 format(' ', I10)
      end
