echo -e "Enter the number"
read n
x=0
y=1
i=2
echo "Fibonacci Series :"
echo "$x"
echo "$y"
for i in $n
do
	i=`expr $i + 1 `
	z=`expr $x + $y `
	echo "$z"
	x=$y
	y=$z
done
