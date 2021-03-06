/*
** readline_read.c for readline in /home/antoine/360SH-NoScop3/readline
**
** Made by Jamy Bailly
** Login   <bailly_j@epitech.net>
**
** Started on  Wed May 25 15:34:49 2016 Jamy Bailly
** Last update Sun Jun  5 21:18:03 2016 Valentin Pichard
*/

#include <unistd.h>
#include "../sh.h"
#include "private.h"

static char     *read_char(int input)
{
  char          *c;
  int		length;
  int		read_length;

  c = egc_malloc_atomic(7);
  if ((length = read(input, c, 1)) < 1)
    return (NULL);
  c[length] = 0;
  if (c[0] == 27)
    {
      length = 1;
      if ((read_length = read(input, c + 1, 5)) < 1)
        return (NULL);
      length += read_length;
      c[length] = 0;
    }
  if (!c[0] || c[0] == '\n')
    return (NULL);
  return (c);
}

/*
** Reads a character from the standard input
**
** If the EOF is reach or an error occured, '\0' is returned.
*/
static char     read_char_raw(int input)
{
  char          c;

  if (read(input, &c, 1) != 1)
    return ('\0');
  return (c);
}

/*
** Reads a line from the standard input
**
** The line is terminated by a Ctrl+D or a '\n'.
*/
static int      readline_raw(t_readline *readline, t_hs *line)
{
  char          c;

  *line = hs_new_empty();
  while (1)
    {
      c = read_char_raw(readline->input);
      if (!c && !hs_length(*line))
        return (-1);
      if (!c || c == '\n')
        break ;
      *line = hs_concat_hs_char(*line, c);
    }
  return (0);
}

static int      init(t_readline *readline)
{
  if (readline_setupterm(readline->output))
    return (-1);
  readline_init_capacity(&readline->capacity);
  readline->line = hs_new_empty();
  readline->cursor_index = 0;
  readline_setup_term(readline->output, &readline->termios);
  readline_print_prompt(readline);
  readline_get_winsize(readline);
  readline_get_cursor_pos(readline, &readline->cursor_x, &readline->cursor_y);
  readline_get_history(readline);
  return (0);
}

int	readline_read(t_readline *readline, t_hs *line)
{
  char	*c;
  int	r;

  if (!isatty(readline->input) || readline_get_term(&readline->termios))
    return (readline_raw(readline, line));
  r = init(readline);
  while (42)
    {
      if (!(c = read_char(readline->input)))
        break ;
      if (c[0] >= 32)
	readline_update(readline, c);
      else if (readline_event(readline, c))
        {
          r = -1;
          break ;
        }
    }
  readline_restore_term(&readline->termios);
  if (hs_length(readline->line) > 0)
    insert_line_file(path_history(), readline->line);
  egc_printf(r == -1 ? "" : "\n");
  *line = readline->line;
  return (r);
}
