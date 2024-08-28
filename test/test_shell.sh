#!/bin/bash

echo "Running Betty style check..."
betty *.c *.h
if [ $? -ne 0 ]; then
  echo "Betty style check failed."
  exit 1
fi

echo "Compiling the shell..."
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
if [ $? -ne 0 ]; then
  echo "Compilation failed."
  exit 1
fi

echo "Running functionality tests..."

commands=("ls" "ls -l" "/bin/ls" "/bin/ls -l" "env" "exit")

for cmd in "${commands[@]}"; do
  expected_output=$(eval "$cmd" | sort)
  actual_output=$(echo "$cmd" | ./hsh | sort)
  
  if [[ "$expected_output" != "$actual_output" ]]; then
    echo "Test failed for command: $cmd"
    echo "Expected:"
    echo "$expected_output"
    echo "Got:"
    echo "$actual_output"
    exit 1
  fi
done

echo "Running Valgrind memory check..."
valgrind --leak-check=full --error-exitcode=1 ./hsh < /dev/null
if [ $? -ne 0 ]; then
  echo "Memory leak detected."
  exit 1
fi

echo "All tests passed!"

