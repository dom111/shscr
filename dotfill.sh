#!/bin/bash

clear

setterm -cursor off

size=$(tput cols)

while true
do
	tput cup $((1 + RANDOM % $size)) $((1 + RANDOM % $size))
	tput setaf $((1 + RANDOM % $size))
	echo -en "."
done
