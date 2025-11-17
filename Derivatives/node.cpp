#include <iostream>
#include "node.h"

Node::Node(std::string val, Node *l, Node *r)
    : value(std::move(val)), left(l), right(r) {}

void Node::set_left(Node *left)
{
    this->left = left;
}

void Node::set_right(Node *right)
{
    this->right = right;
}

std::string Node::get_value() const
{
    return value;
}

Node *Node::get_left() const
{
    return left;
}

Node *Node::get_right() const
{
    return right;
}

void Node::print(std::string indent) const
{
    std::cout << indent << value << "\n";
    if (left || right)
    {
        if (left)
            left->print(indent + "  L: ");

        if (right)
            right->print(indent + "  R: ");
    }
}

std::string Node::to_expression(std::string indent, bool add_paren) const
{
    // Leaf node
    if (!left && !right)
        return value;

    // Binary operators
    std::string left_expr = left ? left->to_expression(indent, add_paren) : "";
    std::string right_expr = right ? right->to_expression(indent, add_paren) : "";

    // Add parentheses for clarity
    if (add_paren)
    {

        return "(" + left_expr + indent + value + indent + right_expr + ")";
    }

    return left_expr + indent + value + indent + right_expr;
}

std::string Node::pretty_print() const
{
    // Leaf node
    if (!left && !right)
        return value;

    std::string op = value;
    std::string L = left ? left->pretty_print() : "";
    std::string R = right ? right->pretty_print() : "";

    auto is_number = [](const std::string &s)
    {
        if (s.empty())
            return false;
        char *endptr = nullptr;
        strtod(s.c_str(), &endptr);
        return *endptr == '\0';
    };

    auto is_variable = [](const std::string &s)
    {
        if (s.empty())
            return false;
        // any non-digit, alphabetic string (like x, y, var1)
        return std::isalpha(s[0]) != 0;
    };

    // Multiplication cases
    if (op == "*")
    {
        // remove * when it’s between constant and variable
        if (is_number(L) && is_variable(R))
            return L + R; // 2x
        if (is_variable(L) && is_number(R))
            return L + R; // x2 (optional)
        return L + "*" + R;
    }

    // Addition / Subtraction
    if (op == "+" || op == "-")
        return L + " " + op + " " + R;

    // Division
    if (op == "/")
        return L + "/" + R;

    // Power
    if (op == "^")
        return L + "^" + R;

    // Fallback
    return "(" + L + " " + op + " " + R + ")";
}
