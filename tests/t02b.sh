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
make src/w02
echo
echo ===========
echo SETUP COMPLETE
echo ===========
echo

echo === TEST 1:
echo EXPECTED RESULT:
echo 1 2 3 4 5 6
echo ACTUAL RESULT:
echo 3 2 4 6  3 1 3 5 | ./src/w02
echo

echo === TEST 2:
echo EXPECTED RESULT:
echo 
echo ACTUAL RESULT:
echo 0 0 | ./src/w02
echo

echo ===========
echo TESTS COMPLETE
echo ===========
echo

