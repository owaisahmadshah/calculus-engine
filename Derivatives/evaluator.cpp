#include <iostream>
#include <math.h>
#include "evaluator.h"
#include "utils.h"

double Evaluator::evaluate(Node *root, std::unordered_map<std::string, double> &vars)
{
  if (!root)
  {
    return 0;
  }

  if (Utils::is_number(root->get_value()))
  {
    return stod(root->get_value());
  }

  if (Utils::is_variable(root->get_value()))
  {
    return vars[root->get_value()];
  }

  double left = evaluate(root->get_left(), vars);
  double right = evaluate(root->get_right(), vars);

  if (root->get_value() == "+")
  {
    return left + right;
  }

  if (root->get_value() == "-")
  {
    return left - right;
  }
  if (root->get_value() == "*")
  {
    return left * right;
  }

  if (root->get_value() == "/")
  {
    return left / right;
  }

  if (root->get_value() == "^")
  {
    return pow(left, right);
  }

  return 0; // fallback
}
