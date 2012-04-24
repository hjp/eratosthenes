C sieve of eratosthenes in FORTRAN IV
      dimension notprm(1000000)
      integer t0, t1, t_rate
      call system_clock(t0, t_rate)
      n = 1000000
      do 12, i=2,n
      if (notprm(i) .eq. 1) go to 11
C     write(0,20) i
      do 10, j=2*i,n,i
      notprm(j) = 1
   10 continue
   11 continue
   12 continue
      call system_clock(t1, t_rate)
      dt = (t1 - t0) / (1.0 * t_rate)
      write(*,30) dt

   20 format(' ', I10)
   30 format(' ', F10.3)
      end
