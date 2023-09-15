#ifndef _SHELL_H_
#define _SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	"._history"
#define HIST_MAX	4096


extern char **environ;

/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} lst_t;


/**
 * struct passinfo - contains pseudo-arguements to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	lst_t *env;
	lst_t *history;
	lst_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; 
	int cmd_buf_type; 
	int readfd;
	int histcount;
} information_t;



#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(information_t *);
} builtin_table;



int hsh(information_t *, char **);
int find_builtin(information_t *);
void find_cmd(information_t *);
void fork_cmd(information_t *);
int is_cmd(information_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(information_t *, char *, char *);
int loophsh(char **);
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
int bfree(void **);
int interactive(information_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);
int _erratoi(char *);
void print_error(information_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);
int _myexit(information_t *);
int _mycd(information_t *);
int _myhelp(information_t *);
int _myhistory(information_t *);
int _myalias(information_t *);
ssize_t get_input(information_t *);
int _getline(information_t *, char **, size_t *);
void sigintHandler(int);
void clear_info(information_t *);
void set_info(information_t *, char **);
void free_info(information_t *, int);
char *_getenv(information_t *, const char *);
int _myenv(information_t *);
int _mysetenv(information_t *);
int _myunsetenv(information_t *);
int _env_lst(information_t *);
char **get_environ(information_t *);
int _unsetenv(information_t *, char *);
int _setenv(information_t *, char *, char *);
char *get_history_file(information_t *info);
int write_history(information_t *info);
int read_history(information_t *info);
int build_history_lst(information_t *info, char *buf, int linecount);
int renumber_history(information_t *info);
lst_t *add_node(lst_t **, const char *, int);
lst_t *add_node_end(lst_t **, const char *, int);
size_t print_lst_str(const lst_t *);
int delete_node_at_index(lst_t **, unsigned int);
void free_lst(lst_t **);
size_t lst_len(const lst_t *);
char **lst_to_strings(lst_t *);
size_t print_lst(const lst_t *);
lst_t *node_starts_with(lst_t *, char *, char);
ssize_t get_node_index(lst_t *, lst_t *);
int is_chain(information_t *, char *, size_t *);
void check_chain(information_t *, char *, size_t *, size_t, size_t);
int rplc_alias(information_t *);
int rplc_vars(information_t *);
int rplc_string(char **, char *);

#endif


