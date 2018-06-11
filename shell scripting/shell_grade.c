echo
"Enter name of the student"
read name
echo "Enter Reg. number"
read num
echo "Enter the marks of the student"
read m1 m2 m3 m4 m5
echo "Name of the student is $name"
echo "Reg. number of the student is $num"
echo "Marks obtained"
echo "M1 M2 M3 M4 M5"
echo $m1 $m2 $m3 $m4 $m5
per=`echo \($m1 + $m2 + $m3 + $m4 + $m5\) /5|bc`
echo Percentage is $per
if test $per -ge 60
then
echo "Grade First"
elif test $per -ge 50 -a $per -le 59
then
echo "Grade : Second"
elif test $per -ge 40 -a $per -le 49
then
echo "Grade : Third"
else
echo "Fail"
fi
