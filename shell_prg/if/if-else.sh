#!/bin/bash
read -p "Enter Your Name: "$'\n' n
if [ $n == "Angel" ]
then
echo "Yes, You Are Angel"
else
echo You Are Not Angel, You Are :$n
fi
