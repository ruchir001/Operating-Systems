echo "Enter the value of n : "
read n
# store single digit
i=0
# store number of digit
sum=0
# use for loop to caclulate the sum of all digits
for ((i=0;i<=$n;i++))
do
sum=$(( $sum + $i )) # calculate sum of digit
done
echo "Sum of all $n natural numbers is $sum"

