#!/usr/bin/perl
use warnings;
use strict;
use Time::HiRes qw(time);

my $t0 = time;

my $n = 1_000_000;

my $sieve = "0" x $n;

for my $i (2 .. $n) {
    next if substr($sieve, $i-1, 1);
    #print "$i\n";
    my $k = $n / $i;
    my $mask = ("0" x ($i - 1) . "1") x $k;
    $sieve |= $mask;
}

my $t1 = time;
print $t1 - $t0, "\n";

