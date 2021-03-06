/*
** colorize.h for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Thu Apr 14 11:47:15 2016 antoine
** Last update Wed Jun  1 14:59:52 2016 Valentin Pichard
*/

#ifndef COLORIZE_H_
# define COLORIZE_H_

# include "../egc.h"

t_hs	uncolorize(t_hs source);

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

t_hs	colorize(const char *style, t_hs source);
int	read_keyword(t_glist_hs *words, int *i, const char *keyword);
int	read_color(t_glist_hs *words, int *i);

#endif /* !COLORIZE_H_ */
