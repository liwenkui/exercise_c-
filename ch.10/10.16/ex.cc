#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;
using namespace std::placeholders;
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
string make_plural(vector<string>::difference_type ctr, const string &a, const string &b)
{
    return (ctr > 1) ? a + b : a;
}
bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    //auto wc = find_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
    auto wc = find_if(words.begin(), words.end(), bind(check_size, _1, sz));
    auto count = words.end() - wc;
    auto count_2 = count_if(words.begin(), words.end(), [sz](const string &a) { return a.size() >= sz; });
    cout << count_2 << " " << make_plural(count, "word", "s")
         << " of length " << sz << " or longer" << endl;
    for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
}
int main()
{
    vector<string> svec{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(svec, 4);
    return 0;
}