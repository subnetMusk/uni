#!/bin/bash
array=(1 13 2 14 3 15 10)
index=0
while [ $index -lt ${#array[@]} ]
do
	echo ${array[$index]}
	if [ ${array[$index]} -lt 10 ]; then
		array[$index]=0
	else
		if [ ${array[$index]} -gt 10 ]; then
			array[$index]=1
		fi
	fi
	((index++))
done
echo "Array modificato:"
index=0
while [ $index -lt ${#array[@]} ]
do
	echo ${array[$index]}
	((index++))
done
