# Simple INI file parser

Basic INI-like file parser with no dynamic memory allocations that supports integer, float, boolean, string and wide-string types.

### Example
```
global_key = 0

; this is a line comment
[Main Section]

key1 = 16
key2 = -123
key3 = +1 ; comments in values are also valid
key4 = 0.03
key5 = true
key6 = false

[Strings]
key1 = "some c-string"
key2 = L"some wide string (converted to utf16)"
```

### Notes
- No dynamic memory allocations
- Uses two arenas to store parsed data
- Uses WinAPI for file reads and utf8-to-utf16 conversion
- CR (carrige return) characters are replaces with SPACE (' ')
- Blank lines are ignored
- Empty (global) section is supported
- Section name is considered to be a string enclosed in DOUBLE_QUOTE ('"')
- Key is one word only
- Value can be INT, FLOAT, BOOL, STRING (char *) or WSTRING (wchar_t *)
- WSTRING is assumed to be in UTF-8 encoding
- Hexadecimal\octal\binary format of INT is NOT supported
- Escaped characters (\t, \n, \x, etc.) are NOT supported

### Usage
```
  #define INI_STORAGE_SIZE 1024
  internal char ini_storage[INI_STORAGE_SIZE];
  
  int main(int argc, char *argv[])
  {
    ini_init("..\\data\\test.ini", ini_storage, INI_STORAGE_SIZE);
    bool parse_result = ini_parse();
    if (!parse_result) {
      printf("Can't read file or some lines couldn't be parsed and were skipped!");
    }
    
    int int_value = ini_read_int("section", "key", 0);
    float float_value = ini_read_float("section", "key", 0.0f);
    bool bool_value = ini_read_bool(0, "globalkey", false);
    char *str_value = ini_read_string("section", "key", "default");
    wchar_t *wstr_value = ini_read_wstring("section", "key", L"default");
  }
```

## License
Public domain
