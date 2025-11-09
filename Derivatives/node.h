#pragma once
#include <string>

class Node
{
  std::string value;
  Node *left;
  Node *right;

public:
  Node(std::string, Node * = nullptr, Node * = nullptr);

  void set_left(Node *);
  void set_right(Node *);

  std::string get_value() const;
  Node *get_left() const;
  Node *get_right() const;

  void print(std::string indent = "") const;
  std::string to_expression(std::string indent = " ", bool add_paren = true) const;
  std::string pretty_print() const;
};
