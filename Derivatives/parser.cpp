#include <climits>
#include "parser.h"

Parser::Parser(std::vector<Token> tokens) : tokens(std::move(tokens)) {}

int Parser::precedence(std::string op)
{
  if (op == "+" || op == "-")
  {
    return 1;
  }
  if (op == "*" || op == "/")
  {
    return 2;
  }
  if (op == "^")
  {
    return 3;
  }
  return 0;
}

bool Parser::is_right_associative(std::string op)
{
  return op == "^";
}

int Parser::get_index(int start, int end)
{
  int min_prec = INT_MAX;
  int best_index = -1;

  for (int i = start; i < end; i++)
  {
    Token token = tokens[i];
    Token_Type type = token.get_type();

    bool isOperator = (type == Token_Type::PLUS || type == Token_Type::MINUS ||
                       type == Token_Type::MULTIPLY || type == Token_Type::DIVIDE ||
                       type == Token_Type::POWER);

    if (!isOperator)
    {
      continue;
    }

    int prec = precedence(token.get_value());
    if (prec < min_prec || (prec == min_prec && !is_right_associative(token.get_value())))
    {
      min_prec = prec;
      best_index = i;
    }
  }

  return best_index;
}

Node *Parser::parse_tree(int start, int end)
{
  if (start == end - 1)
  {
    return new Node(tokens[start].get_value());
  }

  int index = get_index(start, end);
  if (index == -1)
  {
    return nullptr;
  }

  Node *node = new Node(tokens[index].get_value());
  node->set_left(parse_tree(start, index));
  node->set_right(parse_tree(index + 1, end));

  return node;
}

Node *Parser::build_tree()
{
  return parse_tree(0, tokens.size());
}
