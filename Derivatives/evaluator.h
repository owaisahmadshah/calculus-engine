#pragma once
#include <unordered_map>
#include <string>
#include "node.h"

class Evaluator
{
public:
  double evaluate(Node *root, std::unordered_map<std::string, double> &vars);
};
