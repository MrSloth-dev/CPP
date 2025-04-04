#!/usr/bin/env bash

set -e

ARGC=$#
NUMTEST=100

if [[ $ARGC -lt 3 ]]; then
	echo -e "Usage ./tester.sh <min-max> <count> <number_of_tests>(optional)"
	exit 1
fi
if [[ $ARGC -gt 4 ]]; then
	echo -e "Usage ./tester.sh <min-max> <count> <number_of_tests>(optional)"
	exit 2
fi
if [[ $ARGC -eq 4 ]]; then
	NUMTEST=$3
fi
if [ ! -f "./PmergeMe" ]; then
	echo -e "No binary 'PmergeMe' file found"
	exit 3
fi
if [ ! -f "./checker" ]; then
	echo -e "No binary 'checker' file found, please run 'make checker'"
	exit 4
fi

echo "Running.. $NUMTEST tests"
for i in `seq 1 $NUMTEST`; do
	./PmergeMe `shuf -i $1 -r -n $2` | ./checker 2>err.log 1>/dev/null
done
if [ $(cat err.log | wc -l) -eq 0 ]; then
	echo -e "No errors found ( please check if errors are sent to std::cerr)"
fi
rm -fr err.log
