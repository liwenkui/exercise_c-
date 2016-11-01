#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
class HasPtr
{
    friend bool operator<(const HasPtr &, const HasPtr &);

  public:
    HasPtr(const HasPtr &orig) : i(orig.i), ps(new std::string(*orig.ps)) {}
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr &operator=(HasPtr);
    const std::string &print() const { return *ps; };
    ~HasPtr()
    {
        delete ps;
    }
    void swap(HasPtr &);

  private:
    std::string *ps;
    int i;
};
bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}
void HasPtr::swap(HasPtr &lhs)
{
    using std::swap;
    swap(ps, lhs.ps);
    swap(i, lhs.i);
    std::cout << "call swap" << std::endl;
}

HasPtr &HasPtr::operator=(HasPtr temp)
{
    this->swap(temp);
    return *this;
}

int main(int argc, char *argv[])
{
    std::vector<HasPtr> ptr{std::string("a"), std::string("c"), std::string("b")};
    std::sort(ptr.begin(), ptr.end());
    for (auto i : ptr)
        std::cout << i.print() << " ";
    std::cout << std::endl;
    return 0;
}