#!/usr/bin/perl
use warnings;
use strict;
use Time::HiRes qw(time);

my $t0 = time;

my $n = 1_000_000;

my $sieve = "";

for my $i (2 .. $n) {
    next if vec($sieve, $i, 1);
    # print "$i\n";
    for (my $j = 2 * $i; $j <= $n; $j += $i) {
	vec($sieve, $j, 1) = 1;
    }
}

my $t1 = time;
print $t1 - $t0, "\n";
