!#/bin/bash
read -p "Enter Limit: " limit
for((i=0; i<=limit; i++))
do
for((j=0; j<=i; j++))
do
echo -n " *  " 
done
echo $'\n'
done

