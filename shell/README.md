# Mastering Linux Shell Scripting

## Chapter 1: intro
#### Usage of `basename`
```
#!/bin/bash
echo "You are using $(basename $0)"
```
is equivalent to 
```
#!/bin/bash
echo "You are using `basename $0`"
```
#### Define arrays
```
#!/bin/bash
myarr=(one two three four five)
echo ${myarr[1]}    # Prints two which is the second element
echo ${myarr[*]}    # Prints all elements

unset myarr[1]      # Removes the second element
unset myarr         # Removes all the elements
```
#### Environment variables
```
$ printenv HOME     # Prints environment variables 
```
All environment variables are written in **capital** letters.
#### Variable scope
```
# script1.sh
#!/bin/bash
name="Mokhtar"
export name # The variable will be accessible to other processes
./script2.sh
```
```
# script2.sh
#!/bin/bash
echo $name
```
`script2.sh` only makes a copy of the variable and never touches the original one.
#### Command substitution
```
#!/bin/bash
cur_dir=`pwd`
echo $cur_dir
```
or 
```
#!/bin/bash
cur_dir=${pwd}
echo $cur_dir
```
#### Debugging the scripts
Bash provides two options, `-v` and `-x`.
```
$ bash -v $HOME/bin/hello2.sh fred      # Enables verbosity
```
or
```
$ bash -x $HOME/bin/hello2.sh fred      # Enables decision branch
```

## Chapter 2: creating interacting scripts
#### Using `echo` with options
```
# Both of the following commands will print the text without
# adding a new line.
$ echo -n "Which directory do you want to use? "
$ echo -e "Which directory do you want to use? \c"
```
- `-n` suppress the line feed
- `-e` allows escape sequences
#### Reading inputs using `read`
```
#!/bin/bash
echo -n "Hello $(basename $0)! May I ask your name: "
read
echo "Hello $REPLY"
exit 0
```
or follow the syntax of `read -p <prompt> <variable name>`
```
#!/bin/bash
read -p "May I have your name: " name
```
#### Limiting the number of entered characters
If we use `-n` option followed by an integer, we can specify
the number of characters to accept before continuing. Further,
the silent option, `-s` disable the visibility of the entered
text.
```
#!/bin/bash
read -p "May I ask your name: " name
echo "Hello $name"
read -sn1 -p "Press any key to exit"
echo
exit 0
```
#### Passing parameters with options
Options are characters with a single dash before them, e.g.
```
$ ./script1.sh -a -b -c -- p1 p2 p3
```
A possible script can be
```
#!/bin/bash
while [ -n "$1"]
do
case "$1" in
-a) echo "-a option found" ;;
-b) echo "-b option found" ;;
-c) echo "-c option found" ;;
--) shift
break ;;
*) echo "Option $1 is not an option" ;;
esac
shift
done
# iteration over options is finished here
# iteration over parameters started
num=1
for param in $@
do
echo "#$num: $param"
num=$(( $num + 1 ))
done
```
or a **better** one
```
#!/bin/bash
while [ -n "$1" ]
do
case "$1" in
-a) echo "-a option passed" ;;
-b) param="$2"
echo "-b option passed, with value $param"
shift ;;
-c) echo "-c option passed" ;;
--) shift
break ;;
*) echo "Option $1 not an option";;
esac
shift
done
num=1
for param in "$@"
do
echo "#$num: $param"
num=$(( $num + 1 ))
done
```
## Chapter 3: conditions
#### Using the test shell built-in
When the `test` command is run without any expressions to evalutate,
then the test will return false. So, if we run the `test` as shown
in the following command, the exit status will be 1, even though
no error output is shown:
```
$ test
```
The `test` command will always return either `True` or `False`, `0`
or `1`, respectively. The basic syntax of `test` is as follows:
```
test EXPRESSION
```
If we need to include multiple expressions, this can be done
using `AND` or `OR` together, using the `-a` and `-o` options,
respectively:
```
test EXPRESSION -a EXPRESSION
test EXPRESSION -o EXPRESSION
```
We can also write this as a shorthand version, replacing the
`test` with square brackets to surround the expression, as
shown in the following example:
```
[ EXPRESSION ]
```

##### Testing strings
We can test for the equality or inequality of two strings.
```
test $USER = root
```
or
```
[ $USER = root ]
```
To test if a string has a value, we can use the `-n` option.
```
test -n $SSH_TTY
[ -n $SSH_TTY ]
```
To test a zero string value, we can use the `-z` option.
```
test -z $1
[ -z $1 ]
```
##### Testing integers
`-eq` (equal), `-ge` (greater || equal), `gt` (greater), `le` (less || equal), `lt` (less), `ne` (not equal)
```
test $# -gt 0
```

#### Using `if`
```
# syntax
if condition; then
statement
elif condition; then
statement
else
statement
fi
exit 0
``` 
#### Using `case` statements
```
# syntax
case expression in
    case1)
        statement1
        statement2
    ;;
    case2)
        statement1
        statement2
    ;;
    *)
        statement1
    ;;
esac
```
An example is shown below. In bash, we can use the `case` statement
to test for simple values, such as strings or integers. Case
statements can cater for a wide range of letters, such as `[a-f]`,
but they cannot easily deal with integer ranges such as `[1-20]`.
```
#!/bin/bash
if [ ! $# -eq 2 ] ; then
    echo "You must provide <student> <grade>"
    exit 2
fi
case $(2^^) in  # Paramter expansion is used to capitalize input
    [A-C]) echo "$1 is a star pupil"
    ;;
    [D]) echo "$1 needs to try a little harder!"
    ;;
    [E-F]) echo "$1 could do a lot better next year"
    ;;
    *) echo "Grade could not be evaluated for $1 $2"
    ;;
esac
```

## Chapter 4: alternative syntax
#### Avanced tests using `[[`: regex
#### Arithmetic operations using `((`
#### Counting directories and files
```
#!/bin/bash
for path in /home/likegeeks/* do
    if [ -d "$path" ] then
        echo "$path is a directory"
    elif [ -f "$path" ] then
        echo "$path is a file"
    fi
done
```
or a C-style for loop
```
#!/bin/bash
for (( v=1; v <= 10; v++ )) do
    echo "value is $v"
done
```

## Chapte 7: functions
```
function-name() {
<code to execute>
}
```
or 
```
function <function-name> {
<code to execute>
}
```