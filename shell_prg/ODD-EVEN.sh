#!/bin/bash
read -p "Enter Number To Check Odd Or Even: "$'\n' number
if [ `expr $number % 2` == 0 ]
then 
echo "Entered Number : $number Is EVEN!!"
else
echo "Entered Number : $number Is ODD!!"
fi
