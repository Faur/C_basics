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
make src/w04b
echo
echo ===========
echo SETUP COMPLETE
echo ===========
echo

echo === TEST 1:
echo EXPECTED RESULT:
echo 3
echo 5
echo 1
echo ACTUAL RESULT:
echo "8 E 3 E 5 E 1 D E 4 E 2 D D" | ./src/w04b

echo ===========
echo TESTS COMPLETE
echo ===========
echo


