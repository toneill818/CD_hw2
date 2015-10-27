#/bin/sh

rm tests.txt
touch tests.txt

file="tests.txt"

echo "Testing good input with no white space" >> $file
echo "1+2-3*4/5%6" | ./calc >> $file
echo "1+2-3*4/5%6" | ./calc2sexpr >> $file
echo "1+2-3*4/5%6" | ./calc2postfix >> $file

echo "Testing input from HW sheet" >> $file
echo "9-5+2" | ./calc >> $file
echo "9-5+2" | ./calc2sexpr >> $file
echo "9-5+2" | ./calc2postfix >> $file
echo "1_2*3" | ./calc >> $file
echo "1_2*3" | ./calc2sexpr >> $file
echo "1_2*3" | ./calc2postfix >> $file

echo "Testing input with whitespace" >> $file
echo "9 - 5	+ 2	" | ./calc >> $file
echo "9 - 5	+ 2	" | ./calc2sexpr >> $file
echo "9 - 5	+ 2	" | ./calc2postfix >> $file

echo "Testing order of operations with ()" >> $file
echo "(1+2) *5 / (6-3)" | ./calc >> $file
echo "(1+2) *5 / (6-3)" | ./calc2sexpr >> $file
echo "(1+2) *5 / (6-3)" | ./calc2postfix >> $file

echo "Tesing invalid input" >> $file
echo "a+b+7" | ./calc >> $file
echo "a+b+7" | ./calc2sexpr >> $file
echo "a+b+7" | ./calc2postfix >> $file

echo "8%3 +2 )" | ./calc >> $file
echo "8%3 +2 )" | ./calc2sexpr >> $file
echo "8%3 +2 )" | ./calc2postfix >> $file

diff tests.txt correct.txt
