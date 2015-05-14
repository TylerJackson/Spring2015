#!/usr/bin/env bash
use strict;
use warnings;

my ($arg1, arg2)= @ARGV;
 
if ( $arg2 eq "1" ) 
{
	perl -e 'print pack("H*", $arg1)';
} 
if ( $arg2 eq "2" )
{
	perl -e 'print unpack("H*", $arg1)';
}
