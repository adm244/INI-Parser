/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include <windows.h>
#include <stdio.h>
#include <assert.h>

#include "ini_parser.h"

#define INI_STORAGE_SIZE 1024
internal char ini_storage[INI_STORAGE_SIZE];

int main(int argc, char *argv[])
{
  ini_init("..\\data\\test.ini", ini_storage, INI_STORAGE_SIZE);
  bool parse_result = ini_parse();
  if (parse_result)
    printf("SUCCESS!\n");
  else
    printf("FAILURE!\n");
  
  int int_value = ini_read_int("TestSection", "key1", -1);
  printf("%d\n", int_value);
  
  bool bool_value = ini_read_bool(0, "globalkey", false);
  printf("%s\n", bool_value ? "true" : "false");
  
  char *str_value = ini_read_string("TestSection", "key4", "default");
  printf("%s\n", str_value);
  
  wchar_t *wstr_value = ini_read_wstring("TestSection2", "key1", L"default");
  wprintf(L"%ls\n", wstr_value);
  
  return 0;
}
