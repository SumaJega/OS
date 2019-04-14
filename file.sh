echo -e "Listing files having read,write and execute"
for file in *
do
	if [ -r $file -a -w $file -a -x $file ]
	then
		echo "$file"
	fi
done
