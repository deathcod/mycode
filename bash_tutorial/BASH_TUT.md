# Writing command on SED  
  
```  
echo Sunday | sed 's/day/night/g'  
  
output----> Sunnight  
```  
  
There are four parts to this substitute command:  
```  
s	  Substitute command  
/../../	  Delimiter  
one	  Regular Expression Pattern Search Pattern  
ONE	  Replacement string  
  
sed 's/\/usr\/local\/bin/\/common\/bin/' <old >new  
  
[alternative]  
sed 's_/usr/local/bin_/common/bin_' <old >new  
```  
  
 You can combine a number with the g (global) flag. For instance, if you want to leave the first word alone, but change the second, third, etc. to be DELETED instead, use /2g:  
  
sed 's/[a-zA-Z]* /DELETED /2g' <old >new    
  
  
# Writing on GREP  
  
grep -i 'regular expression' testfile   [Case-insensitive search]    
  
grep -w 'test' testfile                 [Whole-word search] return the whole sentence    
is test file    
  
grep -v 'practical' testfile  [inverted search] returns the sentences without the word    
  
```  
grep -r -L "Network" /var/log/*  print the files that dont match the list  
/var/log/anaconda.log  
/var/log/anaconda.syslog  
/var/log/audit/audit.log  
/var/log/boot.log  
/var/log/boot.log.1  
...  
  
grep -A1 '123'  testfile [prints a extra trailing line]  
123 456  
Abcd  
  
grep -B2 'Abcd' testfile [prints two extra leading line]  
practical with grep  
123 456  
Abcd  
  
grep -C2 'carry' testfile [prints two extra leading/trailing line]  
this  
is test file  
to carry out few regular expressions  
practical with grep  
123 456  
```  
  
#Writing variables in bash  
  
```  
STR="Hello World!"  
echo $STR  
  
Hello World!  
  
  
#!/bin/sh  
# This is a comment!  
echo "Hello      World"       # This is a comment, too!  
echo "Hello World"  
echo "Hello * World"  
echo Hello * World  
echo Hello      World  
echo "Hello" World  
echo Hello "     " World  
echo "Hello "*" World"  
echo `hello` world  
echo 'hello' world  
  
output  
------  
Hello      World  
Hello World  
Hello * World  
Hello 1 BASH_TUT.md grep-errors.txt ls-l.txt run.sh World  
Hello World  
Hello World  
Hello       World  
Hello * World  
run.sh: 1: run.sh: hello: not found  
world  
hello world  
  
  
expr $x + 1  
```  
  
```  
MY_MESSAGE="Hello World"  
MY_SHORT_MESSAGE=hi  
MY_NUMBER=1  
MY_PI=3.142  
MY_OTHER_PI="3.142"  
MY_MIXED=123abc  
  
#!/bin/sh  
echo What is your name?  
read MY_NAME  
echo "Hello $MY_NAME - hope you're well."  
```  
  
```  
$ ./myvar2.sh  
MYVAR is:  
MYVAR is: hi there  
  
MYVAR hasn't been set to any value, so it's blank. Then we give it a value, and it has the expected result.  
Now run:  
  
$ MYVAR=hello  
$ ./myvar2.sh  
MYVAR is:  
MYVAR is: hi there  
```  
  
It's still not been set! What's going on?!  
When you call myvar2.sh from your interactive shell, a new shell is spawned to run the script. This is partly because of the #!/bin/sh line at the start of the script, which we discussed earlier.  
We need to export the variable for it to be inherited by another program - including a shell script. Type:  
  
```  
$ export MYVAR  
$ ./myvar2.sh  
MYVAR is: hello  
MYVAR is: hi there  
  
  
  
#!/bin/sh  
echo "What is your name?"  
read USER_NAME  
echo "Hello $USER_NAME"  
echo "I will create you a file called ${USER_NAME}_file"  
touch "${USER_NAME}_file"  
```  
  
usae {} to specifically attach the username  
  
  
touch is used to create file.  
  
printf "xyz\n" also works in sh  
  
```  
$ echo "This is \\ a backslash"  
This is \ a backslash  
$ echo "This is \" a quote and this is \\ a backslash"  
This is " a quote and this is \ a backslash  
```  
  
loop  
  
[FOR LOOP]    
```  
#!/bin/sh  
for i in hello 1 * 2 goodbye   
do  
  echo "Looping ... i is set to $i"  
done  
```  
  
[WHILE LOOP]     
```  
#!/bin/sh  
INPUT_STRING=hello  
while [ "$INPUT_STRING" != "bye" ]  
do  
  echo "Please type something in (bye to quit)"  
  read INPUT_STRING  
  echo "You typed: $INPUT_STRING"  
done  
```  
  
[DOWHILE LOOP]  
  
```  
#!/bin/sh"  
while read f  
do  
  case $f in  
	hello)		echo English	;;  
	howdy)		echo American	;;  
	gday)		echo Australian	;;  
	bonjour)	echo French	;;  
	"guten tag")	echo German	;;  
	*)		echo Unknown Language: $f  
		;;  
   esac  
done  
```  
  
"*" is meant for default    
  
reading a file line by line  
```  
#!/bin/sh  
while f=`line`  
do  
  .. process f ..  
done < myfile  
```  
  
  
IF STATEMENT  
  
```  
if  [ something ]; then  
 echo "Something"  
 elif [ something_else ]; then  
   echo "Something else"  
 else  
   echo "None of the above"  
fi  
```  
  
  
```  
#!/bin/sh  
if [ "$X" -lt "0" ]  
then  
  echo "X is less than zero"  
fi  
if [ "$X" -gt "0" ]; then  
  echo "X is more than zero"  
fi  
[ "$X" -le "0" ] && \  
      echo "X is less than or equal to  zero"  
[ "$X" -ge "0" ] && \  
      echo "X is more than or equal to zero"  
[ "$X" = "0" ] && \  
      echo "X is the string or number \"0\""  
[ "$X" = "hello" ] && \  
      echo "X matches the string \"hello\""  
[ "$X" != "hello" ] && \  
      echo "X is not the string \"hello\""  
[ -n "$X" ] && \  
      echo "X is of nonzero length"  
[ -f "$X" ] && \  
      echo "X is the path of a real file" || \  
      echo "No such file: $X"  
[ -x "$X" ] && \  
      echo "X is the path of an executable file"  
[ "$X" -nt "/etc/passwd" ] && \  
      echo "X is a file which is newer than /etc/passwd"  
  
```  
  
enter in the same line:    
echo -en "Please guess the magic number: "  
  
  
```  
echo -en "Please guess the magic number: "  
read X  
echo $X | grep "[^0-9]" > /dev/null 2>&1  
if [ "$?" -eq "0" ]; then  
  # If the grep found something other than 0-9  
  # then it's not an integer.  
  echo "Sorry, wanted a number"  
else  
  # The grep found only 0-9, so it's an integer.   
  # We can safely do a test on it.  
  if [ "$X" -eq "7" ]; then  
    echo "You entered the magic number!"  
  fi  
fi  
```  
  
/dev/null redirects standard output (stdout) to /dev/null, which discards it.  
  
2>&1 redirects standard error (2) to standard output (1), which then discards it as well since standard output has already been redirected.  
  
while [ -n "$X" ] : check if length of n is zero  
  
  
The first set of variables we will look at are ** $0 .. $9 and $#. **  
The variable $0 is the basename of the program as it was called.  
$1 .. $9 are the first 9 additional parameters the script was called with.  
  
The variable ** $@ ** is all parameters $1 .. whatever.   
  
The variable ** $* **, is similar, but does not preserve any whitespace, and quoting, so "File with spaces" becomes "File" "with" "spaces".   
  
This is similar to the echo stuff we looked at in A First Script. As a general rule, use $@ and avoid $*.  
  
  
** $# ** is the number of parameters the script was called with.  
  
  
```  
#!/bin/sh  
/usr/local/bin/my-command  
if [ "$?" -ne "0" ]; then  
  echo "Sorry, we had a problem there!"  
fi  
```  
  
will attempt to run /usr/local/bin/my-command which should exit with a value of zero if all went well, or a nonzero value on failure. We can then handle this by checking the value of $? after calling the command. This helps make scripts robust and more intelligent.  
Well-behaved applications should return zero on success.   
  
  
The other two main variables set for you by the environment are $$ and $!. These are both process numbers.  
  
  
  
The ** $$ ** variable is the PID (Process IDentifier) of the currently running shell. This can be useful for creating temporary files, such as /tmp/my-script.$$ which is useful if many instances of the script could be run at the same time, and they all need their own temporary files.  
  
  
The $! variable is the PID of the last run background process. This is useful to keep track of the process as it gets on with its job.  
  
Another interesting variable is ** IFS **. This is the Internal Field Separator. The default value is SPACE TAB NEWLINE, but if you are changing it, it's easier to take a copy, as shown:  
  
```  
#!/bin/sh  
old_IFS="$IFS"  
IFS=:  
echo "Please input some data separated by colons ..."  
read x y z  
IFS=$old_IFS  
echo "x is $x y is $y z is $z"  
```  
  
  
  
inputs number from command line checks if those are nunber and returns the sum.  
```  
#!/bin/sh  
a=0  
for i in $@; do  
	echo "$i" | grep "[^0-9]" > /dev/null 2>&1  
	if [ ! "$?" -eq "0" ];then  
		a=`expr $a + $i`  
	fi  
done  
echo $a  
  
  
#SIMPLIFIED  
#!/bin/sh  
a=0  
shift;  
for i in $@; do  
	a=`expr $a + $i`  
done  
echo $a  
```  
  
  
```  
echo -en "What is your name [ `whoami` ] "  
read myname  
if [ -z "$myname" ]; then  
  myname=`whoami`  
fi  
echo "Your name is : $myname"  
```  
  
whoami : returns the username  
-z : checks if myname is set  
  
```  
echo -en "What is your name [ `whoami` ] "  
read myname  
echo "Your name is : ${myname:-`whoami`}"  
```  
  
:- checks if the variable is set, if unset use the default value    
  
```  
echo "Your name is : ${myname:=John Doe}"  
```  
  
  
There is another syntax, ":=", which sets the variable to the default if it is undefined:  
  
This technique means that any subsequent access to the $myname variable will always get a value, either entered by the user, or "John Doe" otherwise.   
  
FUNCTIONS  
  
```  
add_a_user()  
{  
  USER=$1  
  PASSWORD=$2  
  shift; shift;  
  # Having shifted twice, the rest is now comments ...  
  COMMENTS=$@  
  echo "Adding user $USER ..."  
  echo useradd -c "$COMMENTS" $USER  
  echo passwd $USER $PASSWORD  
  echo "Added user $USER ($COMMENTS) with pass $PASSWORD"  
}  
```  
  
Changing the global variable so no scope as such  
```  
#!/bin/sh  
  
myfunc()  
{  
  echo "\$1 is $1"  
  echo "\$2 is $2"  
  # cannot change $1 - we'd have to say:  
  # 1="Goodbye Cruel"  
  # which is not a valid syntax. However, we can  
  # change $a:  
  a="Goodbye Cruel"  
}  
  
### Main script starts here   
  
a=Hello  
b=World  
myfunc $a $b  
echo "a is $a"  
echo "b is $b"  
  
```  
  
RECURSION  
  
```  
#!/bin/sh  
  
factorial()  
{  
  if [ "$1" -gt "1" ]; then  
    i=`expr $1 - 1`  
    j=`factorial $i`  
    k=`expr $1 \* $j`  
    echo $k  
  else  
    echo 1  
  fi  
}  
  
  
while :  
do  
  echo "Enter a number:"  
  read x  
  factorial $x  
done           
```  