# This file is using unix file endings

printf "\33c"
set -e

echo =====================
echo Setting up...
echo =====================
make clean
echo
echo Clean complete
echo 
make src/w01

echo =====================
echo Compilation complete
echo =====================
echo

echo Test 1: Increasing numbers - Expcted result 4
echo "5 0 1 2 3 4" | ./src/w01 

echo Test 2: Decreasing numbers - Expcted result 0
echo "5 4 3 2 1 0" | ./src/w01 

echo Test 3: Toppoint in the middle - Expcted result 2
echo "5 0 1 2 1 0" | ./src/w01 

echo Test 4: Flat middle - Expcted result 1
echo "5 0 1 1 1 0" | ./src/w01 

echo Test 5:  Expcted result 14
echo "15 1 3 7 15 17 11 2 3 6 8 7 5 9 5 23" | ./src/w01 

