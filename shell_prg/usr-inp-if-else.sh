#!/bin/bash
read -p "Enter Number 1: " numone
read -p "Enter Number 2: " numtwo
if [ $numone -gt $numtwo ]
then
echo $numone is Largest!!
else
echo $numtwo is Largest!!
fi
