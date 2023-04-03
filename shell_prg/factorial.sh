#!/bin/bash
read -p "Enter Number: "$'\n' number
fact=1
for (( i=1; i<=number; i++ ))
do
fact=$(($fact*$i))
done
echo "Factorial of $number is: $fact"
