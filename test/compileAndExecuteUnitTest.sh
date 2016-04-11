#!/bin/bash

make

TEST_SUITES=$(ls | xargs file | grep "ELF 64-bit" | awk -F: '{print $1}')
for TEST_SUITE in $TEST_SUITES
do
   echo "Running $TEST_SUITE"
   ./$TEST_SUITE
   echo
   echo
done

