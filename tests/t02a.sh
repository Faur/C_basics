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
echo 1
echo -1
echo ACTUAL RESULT:
echo 3 1 5 7 2 5 6 | ./src/w02
echo

echo === TEST 2:
echo EXPECTED RESULT:
echo -1
echo ACTUAL RESULT:
echo 0 1 5 | ./src/w02
echo

echo === TEST 3:
echo EXPECTED RESULT:
echo -1
echo -1
echo 0
echo -1
echo -1
echo -1
echo -1
echo 1
echo -1
echo 2
echo -1
echo 3
echo -1
echo 4
echo -1
echo -1
echo -1
echo 5
echo -1
echo -1
echo -1
echo ACTUAL RESULT:
echo 6 2 7 9 11 13 17 21 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 | ./src/w02
echo

echo ===========
echo TESTS COMPLETE
echo ===========
echo

