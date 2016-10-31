#include <string>

class HasPtr
{
  public:
    HasPtr(const HasPtr &orig) : i(orig.i), ps(new std::string(*(orig.ps))) {}
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr &operator=(HasPtr &);
    ~HasPtr(){delete ps;}
  private:
    std::string *ps;
    int i;
};

HasPtr &HasPtr::operator=(HasPtr &rhs_hp)
{
    if (this != &rhs_hp)
    {
        std::string *temp_ps = new std::string(*(rhs_hp.ps));
        delete ps;
        ps = temp_ps;
        i = rhs_hp.i;
    }
    return *this;
}
int main(int argc, char *argv[])
{
    HasPtr p;
    return 0;
}