#include <iostream>
#include <cctype>
#include "lexer.h"

Lexer::Lexer(std::string source = "")
{
  this->source = source;
  this->cur_char = ' ';
  this->cur_pos = -1;
  this->next_char();
}

char Lexer::get_cur_char()
{
  return cur_char;
}

void Lexer::next_char()
{
  cur_pos++;

  if (cur_pos >= source.length())
  {
    cur_char = '\0';
  }
  else
  {
    cur_char = source[cur_pos];
  }
}

char Lexer::peek()
{
  if (cur_pos + 1 >= source.length())
  {
    return '\0';
  }

  return source[cur_pos + 1];
}

void Lexer::skip_white_spaces()
{
  while (cur_char == ' ' || cur_char == '\t')
  {
    next_char();
  }
}

void Lexer::abort(std::string message)
{
  std::cout << "Lexing error. " << message << '\n';
  exit(EXIT_FAILURE);
}

Token Lexer::get_token()
{
  skip_white_spaces();
  if (cur_char == '\0')
  {
    return Token(std::string(1, '\0'), Token_Type::END_OF_LINE);
  }

  if (cur_char == '-')
  {
    Token token(std::string(1, cur_char), Token_Type::MINUS);
    next_char();
    return token;
  }
  else if (cur_char == '+')
  {
    Token token(std::string(1, cur_char), Token_Type::PLUS);
    next_char();
    return token;
  }
  else if (cur_char == '*')
  {
    Token token(std::string(1, cur_char), Token_Type::MULTIPLY);
    next_char();
    return token;
  }
  else if (cur_char == '/')
  {
    Token token(std::string(1, cur_char), Token_Type::DIVIDE);
    next_char();
    return token;
  }
  else if (cur_char == '^')
  {
    Token token(std::string(1, cur_char), Token_Type::POWER);
    next_char();
    return token;
  }
  else if (cur_char == '(')
  {
    Token token(std::string(1, cur_char), Token_Type::LPAREN);
    next_char();
    return token;
  }
  else if (cur_char == ')')
  {
    Token token(std::string(1, cur_char), Token_Type::RPAREN);
    next_char();
    return token;
  }
  else if (isdigit(cur_char))
  {
    std::string numStr;
    bool has_point = false;
    while (isdigit(cur_char) || (cur_char == '.' && !has_point))
    {
      if (cur_char == '.')
      {
        has_point = true;
      }
      numStr += cur_char;
      next_char();
    }
    return Token(numStr, Token_Type::NUMBER);
  }
  else if (isalpha(cur_char))
  {
    Token token = Token(std::string(1, cur_char), Token_Type::VARIABLE);
    next_char();
    return token;
  }
  else
  {
    abort(std::string("Unknown token: ") + cur_char);
  }

  return Token('\0', Token_Type::END_OF_LINE);
}