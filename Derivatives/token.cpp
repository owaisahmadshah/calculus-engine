#include "token.h"

Token::Token(std::string value, Token_Type type) : value(value), type(type) {}

std::string Token::get_value() const
{
  return value;
}

Token_Type Token::get_type() const
{
  return type;
}