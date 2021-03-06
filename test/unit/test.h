/*
** test.h for unit in /home/antoine/42sh/test/unit
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Feb 24 20:01:52 2016 antoine
** Last update Wed Jun 01 01:19:53 2016 Antoine Baudrand
*/

#ifndef TEST_H_
# define TEST_H_

# include "../../sh.h"

# define STATS          (STATICS->test_stats)

# include "../../string/string.h"

# define STRINGIFY_(s)          #s
# define STRINGIFY(s)           STRINGIFY_(s)

# define TEST_GET_POSITION()    (__FILE__ ":" STRINGIFY(__LINE__))

void                    fail_impl(const char *position);
void                    assert_impl(int a, const char *position);

# define FAIL()         fail_impl(TEST_GET_POSITION())
# define ASSERT(a)      assert_impl(a, TEST_GET_POSITION())

void    run_test_suites(void);

void    test_suite_token_list(void);

void    test_suite_parse_int(void);
void    test_suite_string_concat(void);
void    test_suite_string_find_char(void);
void    test_suite_string_find(void);
void    test_suite_string_type(void);
void    test_suite_string_type_convert(void);
void    test_suite_colorize(void);
void    test_suite_exec(void);
void    test_suite_lexer(void);
void    test_suite_lexer_symbols(void);
void	test_suite_expand_variables(void);

#endif /* !TEST_H_ */
