#!/bin/bash
COLOR_NC='\e[0m' # No Color
COLOR_BLACK='\e[0;30m'
COLOR_GRAY='\e[1;30m'
COLOR_RED='\e[0;31m'
COLOR_LIGHT_RED='\e[1;31m'
COLOR_GREEN='\e[0;32m'
COLOR_LIGHT_GREEN='\e[1;32m'
COLOR_BROWN='\e[0;33m'
COLOR_YELLOW='\e[1;33m'
COLOR_BLUE='\e[0;34m'
COLOR_LIGHT_BLUE='\e[1;34m'
COLOR_PURPLE='\e[0;35m'
COLOR_LIGHT_PURPLE='\e[1;35m'
COLOR_CYAN='\e[0;36m'
COLOR_LIGHT_CYAN='\e[1;36m'
COLOR_LIGHT_GRAY='\e[0;37m'
COLOR_WHITE='\e[1;37m'

function change_color() { 
    awk -v "red=$(tput setaf 1)" -v "green=$(tput setaf 2)" \
        -v "reset=$(tput sgr0)" '
    { for (i = 1; i <= NF; i++) {
           if ($i == "KO") printf "%s", red "KO" reset;
           else if ($i == "OK") printf "%s", green "OK" reset;
           else printf "%s", $i

           if (i == NF) printf "%s", ORS
           else printf "%s", OFS 
      }}'
}

function check_error() {
	printf "${COLOR_BLUE}Test of Error numbers:\n$COLOR_NC"
	valgrind --leak-check=full ./push_swap $array &> output.log && grep -A5 "LEAK SUMMARY:" output.log && rm output.log
	for i in "${array[@]}"
	do
		OUT=$(./push_swap $i)
		echo $OUT | tr ' ' '\n' | ./checker_linux $i | change_color | tr '\n' ' '
	done
	echo ""
}

function testarray() {
	len=$(echo $array[1] | tr ' ' '\n' | wc -l);
	printf "${COLOR_BLUE}Test of %d numbers:\n$COLOR_NC" $len
	valgrind --leak-check=full ./push_swap $array &> output.log && grep -A5 "LEAK SUMMARY:" output.log && rm output.log
	OUT=$(./push_swap)
	echo $OUT | tr ' ' '\n' | ./checker_linux | change_color | tr '\n' ' '
	echo $OUT | wc -w | tr '\n' ' '
	for i in "${array[@]}"
	do
		OUT=$(./push_swap $i)
		echo $OUT | tr ' ' '\n' | ./checker_linux $i | change_color | tr '\n' ' '
		echo $OUT | wc -w | tr '\n' ' '
	done
	echo ""
}

function testbig() {
	len=$(echo $(ruby -e "puts (1..$1).to_a.shuffle.join(' ')") | wc -w);
	printf "${COLOR_BLUE}Test of %d numbers:\n$COLOR_NC" $len
	valgrind --leak-check=full ./push_swap $(ruby -e "puts (1..$1).to_a.shuffle.join(' ')") &> output.log && grep -A5 "LEAK SUMMARY:" output.log
	for (( c=0; c<=$2; c++ ))
	do
		ARGS=$(ruby -e "puts (1..$1).to_a.shuffle.join(' ')")
		OUT=$(./push_swap $ARGS)
		echo $OUT | tr ' ' '\n' | ./checker_linux $ARGS | change_color | tr '\n' ' '
		echo $OUT | wc -w | tr '\n' ' '
	done
	echo ""
}

function advancedtest() {
	len=$(echo $(ruby -e "puts ($1..$2).to_a.shuffle.join(' ')") | wc -w);
	printf "${COLOR_BLUE}Test of %d numbers:\n$COLOR_NC" $len
	valgrind --leak-check=full ./push_swap $(ruby -e "puts ($1..$2).to_a.shuffle.join(' ')") &> output.log && grep -A5 "LEAK SUMMARY:" output.log
	for (( c=0; c<=$3; c++ ))
	do
		ARGS=$(ruby -e "puts ($1..$2).to_a.shuffle.join(' ')")
		OUT=$(./push_swap $ARGS)
		echo $OUT | tr ' ' '\n' | ./checker_linux $ARGS | change_color | tr '\n' ' '
		echo $OUT | wc -w | tr '\n' ' '
	done
	echo ""
}

make

array=("1 2 3" " 1 2 2 3" "1 2 one 3" "2147483648 2147483647" "-2147483649 -2147483648")
check_error
array=( "2 1 3" "3 2 1" "1 3 2" "2 3 1" "3 1 2")
testarray 
array=("1 2 4 3" "1 3 2 4" "1 3 4 2" "1 4 2 3" "1 4 3 2" "2 1 3 4" "2 1 4 3" "2 3 1 4" "2 3 4 1" "2 4 1 3" "2 4 3 1" "3 1 2 4" "3 1 4 2" "3 2 1 4" "3 2 4 1" "3 4 1 2" "3 4 2 1" "4 1 2 3" "4 1 3 2" "4 2 1 3" "4 2 3 1" "4 3 1 2" "4 3 2 1")
testarray 
array=("1 2 3 5 4" "1 2 4 3 5" "1 2 4 5 3" "1 2 5 3 4" "1 2 5 4 3" "1 3 2 4 5" "1 3 2 5 4" "1 3 4 2 5" "1 3 4 5 2" "1 3 5 2 4" "1 3 5 4 2" "1 4 2 3 5" "1 4 2 5 3" "1 4 3 2 5" "1 4 3 5 2" "1 4 5 2 3" "1 4 5 3 2" "1 5 2 3 4" "1 5 2 4 3" "1 5 3 2 4" "1 5 3 4 2" "1 5 4 2 3" "1 5 4 3 2" "2 1 3 4 5" "2 1 3 5 4" "2 1 4 3 5" "2 1 4 5 3" "2 1 5 3 4" "2 1 5 4 3" "2 3 1 4 5" "2 3 1 5 4" "2 3 4 1 5" "2 3 4 5 1" "2 3 5 1 4" "2 3 5 4 1" "2 4 1 3 5" "2 4 1 5 3" "2 4 3 1 5" "2 4 3 5 1" "2 4 5 1 3" "2 4 5 3 1" "2 5 1 3 4" "2 5 1 4 3" "2 5 3 1 4" "2 5 3 4 1" "2 5 4 1 3" "2 5 4 3 1" "3 1 2 4 5" "3 1 2 5 4" "3 1 4 2 5" "3 1 4 5 2" "3 1 5 2 4" "3 1 5 4 2" "3 2 1 4 5" "3 2 1 5 4" "3 2 4 1 5" "3 2 4 5 1" "3 2 5 1 4" "3 2 5 4 1" "3 4 1 2 5" "3 4 1 5 2" "3 4 2 1 5" "3 4 2 5 1" "3 4 5 1 2" "3 4 5 2 1" "3 5 1 2 4" "3 5 1 4 2" "3 5 2 1 4" "3 5 2 4 1" "3 5 4 1 2" "3 5 4 2 1" "4 1 2 3 5" "4 1 2 5 3" "4 1 3 2 5" "4 1 3 5 2" "4 1 5 2 3" "4 1 5 3 2" "4 2 1 3 5" "4 2 1 5 3" "4 2 3 1 5" "4 2 3 5 1" "4 2 5 1 3" "4 2 5 3 1" "4 3 1 2 5" "4 3 1 5 2" "4 3 2 1 5" "4 3 2 5 1" "4 3 5 1 2" "4 3 5 2 1" "4 5 1 2 3" "4 5 1 3 2" "4 5 2 1 3" "4 5 2 3 1" "4 5 3 1 2" "4 5 3 2 1" "5 1 2 3 4" "5 1 2 4 3" "5 1 3 2 4" "5 1 3 4 2" "5 1 4 2 3" "5 1 4 3 2" "5 2 1 3 4" "5 2 1 4 3" "5 2 3 1 4" "5 2 3 4 1" "5 2 4 1 3" "5 2 4 3 1" "5 3 1 2 4" "5 3 1 4 2" "5 3 2 1 4" "5 3 2 4 1" "5 3 4 1 2" "5 3 4 2 1" "5 4 1 2 3" "5 4 1 3 2" "5 4 2 1 3" "5 4 2 3 1" "5 4 3 1 2" "5 4 3 2 1")
testarray
# testbig "21" "50"
# testbig "42" "50"
advancedtest "-49" "50" "50"
testbig "100" "75"
testbig "500" "25"


rm output.log
