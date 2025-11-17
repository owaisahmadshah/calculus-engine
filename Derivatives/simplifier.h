#pragma once
#include "node.h"

class Simplifier
{
public:
  Node *simplify(Node *);
  Node *power_rules(Node *);
  Node *combine_like_terms(Node *);
  Node *division_simplification(Node *);
  Node *constant_folding(Node *);
  Node *advanced_simplify(Node *);
};