/*
** node_to_hs.c for  in /home/antoine
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Sat Jun  4 22:11:39 2016 antoine
** Last update Sat Jun  4 22:11:39 2016 antoine
*/

#include <assert.h>
#include <unistd.h>
#include "private.h"

static t_hs     generic_list_to_hs(const t_node *node, t_hs separator)
{
  int           i;
  t_hs          s;
  t_node        *child;

  s = hs("");
  i = -1;
  while (++i < glist_voidp_length(&node->children))
    {
      if (i)
        s = hs_concat(s, separator);
      child = glist_voidp_get(&node->children, i);
      s = hs_concat(s, node_to_hs(child));
    }
  return (s);
}

static t_hs     op_to_hs(t_list_op op)
{
  if (op == LIST_OP_AND_AND)
    return (hs(" && "));
  if (op == LIST_OP_PIPE_PIPE)
    return (hs(" || "));
  if (op == LIST_OP_SEMICOLON)
    return (hs("; "));
  return (hs(" "));
}

static t_hs     list_to_hs(const t_node *node)
{
  int           i;
  t_hs          s;
  t_node        *child;

  s = hs("");
  i = -1;
  while (++i < glist_voidp_length(&node->children))
    {
      child = glist_voidp_get(&node->children, i);
      if (i)
        s = hs_concat(s, op_to_hs(child->prev_op));
      s = hs_concat(s, node_to_hs(child));
    }
  return (s);
}

static t_hs     node_to_hs_impl(const t_node *node)
{
  if (node->type == NODE_COMMAND)
    return (hs_join(hs(" "), &node->args));
  else if (node->type == NODE_PIPE)
    return (generic_list_to_hs(node, hs(" | ")));
  else if (node->type == NODE_LIST)
    return (list_to_hs(node));
  assert(0);
  return (hs(""));
}

t_hs    node_to_hs(const t_node *node)
{
  t_hs  s;

  s = node_to_hs_impl(node);
  return (hs_format("[%hs (%d %d %d)]",
                    s,
                    node->redir.input,
                    node->redir.output,
                    node->redir.error_output));
}
