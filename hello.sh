Hello()
{
	echo "$1 $2 $3"
	p=$1
	n=$2
	r=$3
	echo "$p $n $r"
	si=`expr $p \* $n \* $r`
	echo "$si"
}
Hello 1000 5 2.5
ret=$?
echo "Return value is $ret"
