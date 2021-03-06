/*
** test_lexer.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat May 28 08:19:24 2016 antoine
** Last update Sat May 28 08:19:24 2016 antoine
*/

#include "test.h"
#include "../../lexer/lexer.h"

static void             test_empty(void)
{
  t_lexer_result        result;

  result = lex(hs(""));
  ASSERT(result.error == NULL);
  ASSERT(result.tokens == NULL);
  ASSERT(hs_equals(token_list_to_hs(result.tokens), hs("")));
}

static void             test_word(void)
{
  t_lexer_result        result;
  t_token               *token;

  result = lex(hs("  a     "));
  ASSERT(result.error == NULL);
  ASSERT(result.tokens != NULL);
  token = result.tokens->token;
  ASSERT(hs_equals(hs("a"), token->source));
  ASSERT(result.tokens->next == NULL);
  ASSERT(hs_equals(token_list_to_hs(result.tokens), hs("<word a>")));
}

static void             test_words(void)
{
  t_lexer_result        result;
  t_token               *token;

  result = lex(hs("  a   b  "));
  ASSERT(result.error == NULL);
  ASSERT(result.tokens != NULL);
  token = result.tokens->token;
  ASSERT(hs_equals(hs("a"), token->source));
  token = result.tokens->next->token;
  ASSERT(hs_equals(hs("b"), token->source));
  ASSERT(result.tokens->next->next == NULL);
  ASSERT(hs_equals(token_list_to_hs(result.tokens),
                   hs("<word a><word b>")));
}

static void             test_word_2(void)
{
  t_lexer_result        result;

  result = lex(hs("this_is-a/single,Word"));
  ASSERT(result.error == NULL);
  ASSERT(hs_equals(token_list_to_hs(result.tokens),
                   hs("<word this_is-a/single,Word>")));
}

void                    test_suite_lexer(void)
{
  test_empty();
  test_word();
  test_word_2();
  test_words();
}
