#pragma once
#include <string>

enum class Token_Type
{
  PLUS = 0,
  MINUS = 1,
  MULTIPLY = 2,
  DIVIDE = 3,
  POWER = 4,

  LPAREN = 10,
  RPAREN = 11,

  NUMBER = 20,
  VARIABLE = 21,

  END_OF_LINE = 101
};

class Token
{
  std::string value;
  Token_Type type;

public:
  Token(std::string, Token_Type);

  std::string get_value() const;
  Token_Type get_type() const;
};