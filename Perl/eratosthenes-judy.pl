#!/usr/bin/perl
use warnings;
use strict;
use Time::HiRes qw(time);
use Bit::Vector::Judy ':all';

my $t0 = time;

my $n = 1_000_000;

my $sieve = 0;
my $nprimes = 0;

for my $i (2 .. $n) {
    next if judy1_test($sieve, $i);
    # print "$i\n";
    $nprimes++;
    for (my $j = 2 * $i; $j <= $n; $j += $i) {
	judy1_set($sieve, $j);
    }
}

my $t1 = time;
printf "found %d primes <= %d in %.3f seconds\n", $nprimes, $n, $t1 - $t0;
