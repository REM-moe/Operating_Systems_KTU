!#/bin/bash
read -p "Enter Limit: " limit
t1=0
t2=1
echo -n $t1 $'\t' $t2
for((i=3; i<=limit; i++))
do
sum=$((t1+$t2))
echo -n $'\t' $sum 
t1=$t2
t2=$sum
done
echo $'\n'
