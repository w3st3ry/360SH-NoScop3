/*
** colorize.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 14 11:47:15 2016 antoine
** Last update Thu Apr 14 11:47:15 2016 antoine
*/

#ifndef COLORIZE_H
# define COLORIZE_H

# include "egc/include/egc.h"

void    colorize_enable(void);
void    colorize_disable(void);
int     colorize_is_enabled(void);

/*
** A bit like the colorize gem (https://github.com/fazibear/colorize)
**
** Examples:
**
**     hs_puts(colorize_str("green", "This text is green"));
**     hs_puts("This text is normal");
**     hs_puts(colorize_str("red on blue", "This text is red on blue"));
**     hs_puts(colorize_str("pink underlined",
**                          "This text is pink and underlined"));
*/
t_hs    colorize_hs(const char *color_name, t_hs source);
t_hs    colorize_str(const char *color_name, const char *source);
t_hs    colorize_char(const char *color_name, char source);

#endif /* COLORIZE_H */
