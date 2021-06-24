# Guidelines

These are some extra things aside of [codam's](https://www.codam.nl/en/) Norminette that im noting down as a reminder for myself for consistency's sake

### Include Ordering

```txt
<System includes>

<Third party system includes>

<Local includes>

<Private includes>
```

### Functions

Keep struct arguments pointers to avoid copy overhead

#### Function Name Syntax

Function names should be a verb/action

`<action>_<target>_<addition>`

Prefix the function name with `ft_` if its a public function
Keep it one public function per file and give the file the same name as the public function inside

**Examples:**

`ft_join_pool_tasks`
`ft_new_serializer`

#### Function Definition/Prototype Syntax

```txt
<documentation>
<return type>    <function name>(
    <param>
    <...>
)
```

If there's no param and thus `void`, there is no need the newlines
Only include documentation in the source file, not header

**Examples:**

```c
/*
** * Convert rgba byte data to hex string data
** * Returns NULL if the allocation of the hex string failed
*/
char    *ft_convert_rgba_to_hex(
    t_uint32 rgba,
    bool include_alpha
)
```

For scalar types stick to their t_ type:
`char` would be `t_int8`
`int` would be `t_int32`
`float` would be `t_float32`
etc.

#### Function Error Handling

**Always handle function related errors, yes that includes `write`**

Most functions should not account for `NULL` input, exceptions are:

- Delete functions
- Print functions

### Tests

#### Test File Name Syntax

`<function name>_test`

Keep it one test file per public function

### Extras

#### Numbers

Avoid random numbers values as much as possible, make them defines/enums instead

##### Number Notation

- Memory/byte values = hexadecimal
- Bit shift values = octal
