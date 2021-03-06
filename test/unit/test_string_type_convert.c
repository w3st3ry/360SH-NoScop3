/*
** test_string_type_convert.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar  9 12:37:21 2016 antoine
** Last update Sat Apr 16 13:42:16 2016 Valentin Pichard
*/

#include <stdlib.h>
#include "test.h"

static void     test_string_to_uppercase(void)
{
  char          *s;

  s = string_to_uppercase("");
  ASSERT(string_equals("", s));
  s = string_to_uppercase(".#$'");
  ASSERT(string_equals(".#$'", s));
  s = string_to_uppercase("The Quick Brown foX jumps over the Lazy dog");
  ASSERT(string_equals("THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG", s));
}

static void     test_string_to_lowercase(void)
{
  char          *s;

  s = string_to_lowercase("");
  ASSERT(string_equals("", s));
  s = string_to_lowercase(".#$'");
  ASSERT(string_equals(".#$'", s));
  s = string_to_lowercase("The Quick Brown foX jumps over the Lazy dog");
  ASSERT(string_equals("the quick brown fox jumps over the lazy dog", s));
}

void            test_suite_string_type_convert(void)
{
  test_string_to_uppercase();
  test_string_to_lowercase();
}
