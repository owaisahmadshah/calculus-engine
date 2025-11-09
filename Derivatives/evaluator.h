#pragma once
#include <unordered_map>
#include <sstream>
#include <string>
#include <iomanip>
#include "node.h"

class Evaluator
{
  bool is_number(const std::string &s);
  bool is_variable(const std::string &s);
  std::string double_to_string(double);
  Node *clone_node(Node *);

public:
  double evaluate(Node *root, std::unordered_map<std::string, double> &vars);

  Node *differentiate(Node *, std::string &);
  Node *simplify(Node *);
  Node *power_rules(Node *);
  Node *combine_like_terms(Node *);
  Node *division_simplification(Node *);
  Node *constant_folding(Node *);
  Node *advanced_simplify(Node *);
};
