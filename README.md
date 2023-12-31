# Simple_Shell

## The Requirements

### List of allowed functions and system calls

chdir (man 2 chdir) <br/>
access (man 2 access) <br/>
chdir (man 2 chdir)<br/>
close (man 2 close)<br/>
closedir (man 3 closedir)<br/>
execve (man 2 execve)<br/>
exit (man 3 exit)<br/>
_exit (man 2 _exit)<br/>
fflush (man 3 fflush)<br/>
fork (man 2 fork)<br/>
free (man 3 free)<br/>
getcwd (man 3 getcwd)<br/>
getline (man 3 getline)<br/>
getpid (man 2 getpid)<br/>
isatty (man 3 isatty)<br/>
kill (man 2 kill)<br/>
malloc (man 3 malloc)<br/>
open (man 2 open)<br/>
opendir (man 3 opendir)<br/>
perror (man 3 perror)<br/>
read (man 2 read)<br/>
readdir (man 3 readdir)<br/>
signal (man 2 signal)<br/>
stat (__xstat) (man 2 stat)<br/>
lstat (__lxstat) (man 2 lstat)<br/>
fstat (__fxstat) (man 2 fstat)<br/>
strtok (man 3 strtok)<br/>
wait (man 2 wait)<br/>
waitpid (man 2 waitpid)<br/>
wait3 (man 2 wait3)<br/>
wait4 (man 2 wait4)<br/>
write (man 2 write)<br/>

## Compilation
Your shell will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
#Testing
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
```
## Checks
The Checker will be released at the end of the project (1-2 days before the deadline). We strongly encoura
ge the entire class to work together to create a suite of checks covering both regular tests and edge cases for each task. See task 8.

## Authors:
[Mathias KINNINKPO](https://github.com/mathias-kinninkpo) <br/>
[Prince Asirifi](https://github.com/TheLoneWolfpk)
