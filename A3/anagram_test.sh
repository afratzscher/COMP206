#!/bin/bash

clear #clears screen

gcc -o anagram anagram.c #compiles anagram.c into exectuable called anagram
./anagram listen silent #execute with inputs of silent and listen (are anagrams)

ret=$? #set exit code to ret
if [ $ret -eq  0 ]; then #if exit code is 0, then IS anagram, so test succeeded
	echo "Test Succeeded"
else
	echo "Test Failed"
fi

./anagram listen silence #execute with inputs of silence and listen (NOT anagrams)
return=$? #set exit code to return
if [ $return -eq 1 ]; then #if exit code is 1, then IS NOT anagram, so test succeeded
	echo "Test Succeeded"
else
	echo "Test Failed"
fi

echo "Execution of anagram program has ended successfully!"
