# Guidelines

These are some extra things aside of [codam's](https://www.codam.nl/en/) norminette that im noting down as a reminder for myself for consistency's sake

### Include Ordering

```txt
<System includes>

<Third party system includes>

<Local includes>

<Private includes>
```

### Functions

#### Function Name Syntax

`<action>_<target>_<addition>`

Prefix the function name with `ft_` if its a public function
Keep it one public function per file and give the file the same name as the public function inside

**Examples:**

`ft_join_ttasks`
`ft_join_ttasks_all`
`ft_new_serialize`
`correct_serialize_endian`

#### Function Prototype Syntax

```txt
<documentation>
<return type>    <function name>
(
    <param>
    <...>
)
```

Only include `<documentation>` in the source file, not header

**Examples:**

```c
/*
** * Convert rgba byte data to hex string data
** * Returns NULL if the allocation of the hex string failed
*/
char    *ft_convert_rgba_to_hex
(
    t_uint32 rgba,
    bool include_alpha
)
```

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
