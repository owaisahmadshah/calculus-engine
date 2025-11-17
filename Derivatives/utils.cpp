#include "utils.h"

bool Utils::is_number(const std::string &s)
{
  if (s.empty())
    return false;

  char *endptr = nullptr;
  const char *str = s.c_str();

  // Try to parse as double
  std::strtod(str, &endptr);

  // If endptr points to the end of the string, parsing was successful
  return *endptr == '\0';
}

bool Utils::is_variable(const std::string &s)
{
  return s.size() == 1 && std::isalpha(static_cast<unsigned char>(s[0])) && s != "+" && s != "-" && s != "/" && s != "*" && s != "^";
}

std::string Utils::double_to_string(double num)
{
  std::ostringstream oss;
  oss << std::setprecision(15) << std::noshowpoint << num;
  std::string s = oss.str();

  // Remove trailing zeros and decimal point if unnecessary
  if (s.find('.') != std::string::npos)
  {
    // Remove trailing zeros
    s.erase(s.find_last_not_of('0') + 1, std::string::npos);
    // If the last character is '.', remove it too
    if (s.back() == '.')
      s.pop_back();
  }
  return s;
}
