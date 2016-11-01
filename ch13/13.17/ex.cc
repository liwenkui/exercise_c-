#include <iostream>
using namespace std;

class numbered
{
  public:
    numbered()
    {
        mysn = ++unique;
    }
    //13.15
    numbered(const numbered &)
    {
        mysn = ++unique;
    }
    int mysn;
    static int unique;
};
int numbered::unique = 10;

//13.15
void f(const numbered &s)
//void f(numbered s)
{
    cout << s.mysn << endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}