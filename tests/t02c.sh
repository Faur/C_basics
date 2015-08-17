# This file is using unix file endings

set -e
printf "\33c"


echo ===========
echo SETTING UP ...
echo ===========
echo
echo === CLEANING ...
echo
make clean
echo
echo === COMPILING ...
echo
make src/w02c
echo
echo ===========
echo SETUP COMPLETE
echo ===========
echo

echo === TEST 1:
echo EXPECTED RESULT:
echo 3 10 17
echo ACTUAL RESULT:
echo 3 17 3 10 | ./src/w02c
echo

echo === TEST 2: Empty list
echo EXPECTED RESULT:
echo 
echo ACTUAL RESULT:
echo 0 | ./src/w02c
echo

echo ===========
echo TESTS COMPLETE
echo ===========
echo
