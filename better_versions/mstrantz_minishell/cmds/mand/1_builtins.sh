# **************************************************************************** #
#   BUILTINS                                                                   #
# **************************************************************************** #

### ECHO ###
echo

echo ''

echo ""

echo '' ""

echo echo

echo test1

echo 'test1'

echo "echo hallo"

echo echo"1"

echo "test1 test2"

echo "test1  test2" test3

echo " test1 test2 " 'test3 '

echo test1		test2

echo -n test1

echo -n "test1 test2"

echo -n "test1 test2" test3

echo -n " test1 test2 " 'test3 '

echo -n test1		test2

echo test1 -n

echo "test1 -n"

echo -n -n test1

echo -n -n -n -n -n test1

echo "-n test1 -n test2"

echo "test1 -n test2"

echo ~42

eCho

eChO

eCHO

ECHO

### CD ###
pwd
cd
pwd

pwd
cd ..
pwd

pwd
cd .
pwd

pwd
cd "."
pwd

pwd
cd /Users
pwd

pwd
cd //////
pwd

pwd
cd ./././
pwd

pwd
cd /
pwd

pwd
cd '/////' 2>/dev/null
pwd

pwd
cd "$PWD/file_tests"
pwd

pwd
cd "doesntexist"
pwd

pwd
cd "doesntexist" 2>/dev/null
pwd

pwd
cd ../../..
pwd

pwd
cd "wtf" 2>/dev/null
pwd

pwd
cd ..
cd ..
pwd

pwd
cd ?
pwd

pwd
cd +
pwd

pwd
cd _
pwd

pwd
cd echo
pwd

pwd
cd echo echo
pwd

pwd
cd '/'
pwd

pwd
cd $PWD/file_tests
pwd

pwd
cd $OLDPWD/something
pwd

pwd
cd "1$HOME"
pwd

### ENV ###
env | grep DOESNT_EXIST

env | grep HOME

env | grep USER

env | wc -l

### PWD ###
pwd

"pwd"

pw"d"

pwd test42

pwd 42 42 42

pwd pwd

pwd pwd pwd

### EXPORT ###
/bin/echo $HALLO
env | grep HALLO
export HALLO=42
/bin/echo $HALLO
env | grep HALLO

/bin/echo $HOME
env | grep HOME
export HOME=42
/bin/echo $HOME
env | grep HOME

export =============123

export =

export =42

export ''=''

export ""=""

export export

export echo

export cd

export test

export TEST

export TES_T=123
/bin/echo $TES_T
env | grep TES_T

export HELLO42=T=""
/bin/echo $HELLO42
env | grep HELLO42
env | grep HELLO42=T=

echo $?
export ?=hallo
echo $?

/bin/echo $test
export test=42 | echo 99
/bin/echo $test

/bin/echo $mini_test
env | grep mini_test
export mini_test=
/bin/echo $mini_test
env | grep mini_test

### UNSET ###
unset ""

unset =

unset "="

unset ""=

unset =""

unset ==

unset ?

unset "?"

unset $

unset "$"

unset $""

/bin/echo $HOME
unset $HOME
/bin/echo $HOME

/bin/echo $HOME
unset HOME
/bin/echo $HOME

/bin/echo $HOME
unset HOME
unset HOME
unset HOME
/bin/echo $HOME

/bin/echo $HOME
unset HOME
unset HOME
unset HOME
unset HOME
/bin/echo $HOME

###  EXIT ###
exit

exit 0

exit 10

exit 42

exit 1

exit +++++

exit ++++++

exit +1

exit ++1

exit ++12560

exit -----

exit ------

exit -1

exit --1

exit -12560

exit --12560

exit 255

exit 1 2

exit 1 2 3

exit A

exit A 2 3

exit "A"

exit "+++"

exit ++++3193912939

exit 01

exit 001

exit 0001

exit +++000

exit ++++000

exit ---000

exit ----000

exit "something"

exit x

exit echo

exit cd ..

exit exit
