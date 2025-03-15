a simple library containing general purpose functions

## compile locally  
Clone the project  

~~~bash  
  git clone https://github.com/Maxime-juncker/libft
~~~

Go to the project directory  

~~~bash  
  cd libft
~~~

create executable  

~~~bash  
  make
~~~

the libft.a is created under bin/
to use the libft in a project, do not forget to add it when linking
```
  gcc <flags> <files> <path_to_libft>/bin/libft.a -o <name>
```


# input / output functions
function to interact with the input / output of a terminal / file

to use io function you'll need to include ```libft/io.h```

| function        | description                                         |
| --------------- | ----------------------------------------------------|
| malloc_assert   | test if a malloc has failded, if so, print an error |
| alert           | print a msg a msg on stderr on a bright red background |
| info            | print a log msg in gray                             |
| warning         | print a warning msg in stderr |
| error           | print a red msg in stderr |
| success         | print a green msg |
| ft_printf       | remake of the printf function (support %c, %s, %d, %x/X, %p, %%)
| ft_dprintf      | same as printf but a fd in taken in args |
| ft_putchar_fd   | print a char on the given fd |
| ft_putendl_fd   | print a string with a \n on the given fd |
| ft_putnbr_fd    | print a number on the given fd |
| ft_putstr_fd    | print a string on the given fd |
| ft_get_next_line | return the next line to read from the given fd |

# string functions
function to manipulate / create string

to use io function you'll need to include ```libft/string.h```

| function        | description                                         |
| --------------- | ----------------------------------------------------|
| ft_atoi         | convert a string to an int |
| ft_atos         | convert a array of string into a single string |
| ft_itoa         | convert a int to a string |
| ft_sortarr      | sort an array of string |
| ft_split        | split a string into mutiple based on a separator |
| ft_strchr       | seatch the first occurence of a character in a string |
| ft_strrchr      | search for the last occurence of a character in a string |
| ft_strdup       | duplicate a string |
| ft_striteri     | loop over a string and apply the function given in args to each char |
| ft_strmapi      | same as striteri but the result is used to map a new string |
| ft_strjoin      | join two string |
| ft_strjoin_free | join two string which can be free based on the flag in args |
| ft_strlcat      | concatenate src to dest if dest is big enought |
| ft_strlcpy      | copy src to dest if dest is big enought |
| ft_strlen       | return the lenght of a string |
| ft_strncmp      | compare two string up to ```n``` character |
| ft_strcmp       | compare two string |
| ft_strnstr      | search for the fisrt occurent of patern in the string |
| ft_strtrim      | trim a string (ex: ...hello... -> helo)
| ft_strpad       | add a char at the beggining and end of a string |
| ft_substr       | return a sub string from the big string |
| ft_tolower      | set a character to it's lower form |
| ft_toupper      | set a character to it's upper form |

# memory functions
function to manipulate memory

to use io function you'll need to include ```libft/memory.h```

| function        | description                                         |
| --------------- | ----------------------------------------------------|
| ft_bzero        | set ```n``` byte of a pointer to 0 |
| ft_memset       | set ```n``` byte of a pointer to a value |
| ft_calloc       | malloc ```n``` byte then set everthing to 0 |
| ft_memchr       | search for a value in a pointer |
| ft_memcmp       | compare two pointer |
| ft_memcpy       | copy a pointer src to a pointer dest (memory cannot overlap) |
| ft_memmove      | copy a pointer src to a pointer dest (memory can overlap) |


# link list functions
function use link list

to use io function you'll need to include ```libft/link_list.h```

| function        | description                                         |
| --------------- | ----------------------------------------------------|
| ft_lstnew       | create new node |
| ft_lstadd_back  | add node to the end of the list |
| ft_lstaddfront  | add note to the fron of the list |
| ft_lstchr       | search for a value in the list |
| ft_lstclear     | clear the list (the value of each node is passed to the arg function) |
| ft_lstdelone    | delete a node (the value of each node is passed to the arg function) |
| ft_lstiter      | iter over the list to call a function with each element |
| ft_lstmap       | same has lstiter but a new list is created with the result |
| ft_lstlast      | return the last note of the list |
| ft_lstsize      | return the size of the list |
| ft_lstprint     | print the list |

# math functions
function to do math

to use io function you'll need to include ```libft/math.h```

| function        | description                                         |
| --------------- | ----------------------------------------------------|
| overflow_check  | check for an int overflow, it overflow occcure a function pass in args is called |
| ft_abs          | absolute avlue of an int |
| ft_min          | return minimum from two int |
| ft_max          | return maximum from two int |

# is function
a bunch of utility function

to use io function you'll need to include ```libft/is.h```

| function        | description                                         |
| --------------- | ----------------------------------------------------|
| ft_isalnum      | is the char from the alphabet or a number |
| ft_isalpha      | is the char from the alphabet |
| ft_isascii      | is the char from the ascii table |
| ft_isdigit      | is the char a digit |
| ft_isprint      | is the char a printable character |
| ft_iswhitespace | is the char a whitespace |

