echo -e "1.Concating Two String"
echo -e "2.Length of the String"
echo -e "3.Comparing Two String"
echo -e "Enter your choice:"
read ch
case $ch in
   1)
	echo "Enter first String"
     read s1
     echo "Enter second string "
     read s2
	s3=$s1$s2
	echo "Concatenated String"
	echo $s3
      ;;
   2)
	echo "Enter  String"
   	read s1
	a=`echo -e $s1 | wc -m`
	echo "Length of string is $a"
      ;;
    3)
	echo "Enter first String"
	     read s1
	     echo "Enter second string "
	     read s2
	     if [ $s1 = $s2 ]
	     then    
			echo "Two strings are equal "
		else
		echo "Two strings are not equal"
	     fi;;
esac
