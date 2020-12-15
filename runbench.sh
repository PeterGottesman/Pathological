#!/bin/bash

TEST_NAME=${1:-"unnamed test"}
echo "Running benchmarks with name '$TEST_NAME'..."

{
	./pathological bench |
		awk -e '{OFS=","} match($0, /[0-9]+\.[0-9]+/){printf $1",";}'
	echo "$TEST_NAME"
} >> benchmarks.csv

