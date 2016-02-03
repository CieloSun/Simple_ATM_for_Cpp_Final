#ifndef TOOLNEED_H
#define TOOLNEED_H

#include<string>
#include<sstream>

using std::string;
using std::ostringstream;
using std::istringstream;

class ToolNeed
{
public:
  template <typename T>
  inline string Othertostring(T a)
  {
    ostringstream oss;
    oss << a;
    return oss.str();
  }
  inline double StringToDouble(string str)
  {
    istringstream iss(str);
    double a;
    iss >> a;
    return a;
  }
};

#endif // TOOLNEED_H

