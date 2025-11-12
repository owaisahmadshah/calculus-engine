#pragma once
#include <string>
#include "token.h"

class Lexer
{
  std::string source;
  char cur_char;
  int cur_pos;

public:
  Lexer(std::string);

  // Get current character
  char get_cur_char();

  // Process the next character
  void next_char();

  // Return the lookahead character
  char peek();

  // Invalid token found, print error and exit
  void abort(std::string);

  // Skip white spaces
  void skip_white_spaces();

  // Return next token
  Token get_token();
};
