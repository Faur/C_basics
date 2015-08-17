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
make src/w04
echo
echo ===========
echo SETUP COMPLETE
echo ===========
echo

echo === TEST 1:
echo EXPECTED RESULT:
echo 1
echo 2
echo 4
echo ACTUAL RESULT:
echo "8 PU 3 PU 5 PU 1 PO PU 4 PU 2 PO PO" | ./src/w04

echo ===========
echo TESTS COMPLETE
echo ===========
echo


