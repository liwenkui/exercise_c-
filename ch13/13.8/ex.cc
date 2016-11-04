#include <string>

class HasPtr
{
  public:
    //HasPtr(const HasPtr &orig) : i(orig.i), ps(new std::string(*orig.ps)) {}
    HasPtr(const HasPtr &orig) : i(orig.i), ps(orig.ps), use(orig.use) { ++*use; }
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0), use(new size_t(1)) {}
    HasPtr &operator=(HasPtr &);
    ~HasPtr()
    {
        if (--*use == 0)
        {
            delete ps;
            delete use;
        }
    }

  private:
    std::string *ps;
    int i;
    size_t *use;
};

// HasPtr &HasPtr::operator=(HasPtr &rhs_hp)
// {
//     if (this != &rhs_hp)
//     {
//         std::string *temp_ps = new std::string(*(rhs_hp.ps));
//         delete ps;
//         ps = temp_ps;
//         i = rhs_hp.i;
//     }
//     return *this;
// }
// HasPtr &HasPtr::operator=(HasPtr &rhs_hp)
// {
//     if (this != &rhs_hp)
//     {
//         delete ps;
//         ps = rhs_hp.ps;
//         i = rhs_hp.i;
//     }
//     return *this;
// }
HasPtr &HasPtr::operator=(HasPtr &rhs_hp)
{
    ++*rhs_hp.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs_hp.ps;
    use = rhs_hp.use;
    i = rhs_hp.i;
    return *this;
}
int main(int argc, char *argv[])
{
    HasPtr p;
    return 0;
}