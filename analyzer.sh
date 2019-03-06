#!/bin/sh

##
##Need to have ./checker and ./push_swap
##
##first request is the range of number with the smallest and biggest
##
##second request is total loops that the program will perfom
##
##third request is for know how many loops are above and below


echo "\x1B[36m";
echo "\n--- [ ANALYSING PUSH_SWAP] ---";
echo "\x1B[0m";

read -p "How many range of number [from ... to] (2 number needed) : " NBRBOT NBRTOP
read -p "How many loop : " TRY
read -p "Mediane for test : " MED
NBR=$(($NBRTOP - $NBRBOT))
((NBR++))
MOY=0;
MAX=-1;
MIN=-1;
ACTMAX="";
ACTMIN="";
MORE=0;
LESS=0;
IND=$TRY;
WELL=0;
TEST="";

# printf "[ NBR == $NBR && TRY == $TRY && MED == $MED ]\n"

echo "Analyse in progress ...\n";
while [[ $IND -gt 0 ]];
do
	ARG=`ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')"`
	NBRCOUP=$(./push_swap $ARG | wc -l);
	# echo $TEST;
	TEST=`./push_swap $ARG | ./checker $ARG | grep OK`;
	# if [[ $TEST == "\033[0;92mOK\n" ]]; then
	if [[ "$TEST" ]]; then
		printf "\033[0;32m▓\033[0;0m"
		let WELL++;
	else
		printf "\033[0;31m▓\033[0;0m"
	fi
	if [ $MAX -lt $NBRCOUP ]; then 
		MAX=$NBRCOUP; 
		ACTMAX=$ARG; 
	fi
	if [ $MIN -eq "-1" ]; then 
		MIN=$NBRCOUP; 
		ACTMIN=$ARG; 
	fi
	if [ $NBRCOUP -lt $MIN ]; then
		MIN=$NBRCOUP;
		ACTMIN=$ARG; 
	fi
	let "MOY+=$NBRCOUP";
	let IND--;
	if [ $NBRCOUP -gt $MED ]; then 
		let MORE++
	else
		let LESS++
	fi
done;
let "MOY/=$TRY";

echo "\nThere is \x1b[33m$WELL/$TRY\x1b[0m correct answer"
echo "There is \x1B[31m$MORE\x1b[0m more than $MED"
echo "There is \x1B[32m$LESS\x1b[0m less than $MED"
echo "The biggest is :    \x1B[31m$MAX\x1b[0m"
echo "The average is :    \x1b[33m$MOY\x1b[0m"
echo "The smallest is :   \x1B[32m$MIN\x1b[0m"
echo "\x1B[31mThe worst list :\x1b[0m $ACTMAX"
echo "\x1B[32mThe best list :\x1b[0m $ACTMIN"
