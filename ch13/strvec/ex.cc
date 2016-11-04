#include <iostream>
#include <string>
#include <vector>
class StrVec
{
  public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);

  private:
    std::cap;
    std::string *elements;
    std::string *first_free;
}