#pragma once
#include <vector>
#include <string>
#include "token.h"
#include "node.h"

class Parser
{
  std::vector<Token> tokens;

  int precedence(std::string op);
  bool is_right_associative(std::string op);
  int get_index(int start, int end);
  Node *parse_tree(int start, int end);

public:
  Parser(std::vector<Token> t);
  Node *build_tree();
};
