
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
make src/w05
echo
echo ===========
echo SETUP COMPLETE
echo ===========
echo

echo === TEST 1:
#echo EXPECTED RESULT:
#echo ACTUAL RESULT:
./src/w05

echo ===========
echo TESTS COMPLETE
echo ===========
echo