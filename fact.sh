fact=1
a=1
echo -e "Enter a number"
read n
while [ $a -le $n ]
do 
	fact=`expr $a \* $fact`
	a=`expr $a + 1`
done
echo -e "Factorial  $fact " 
