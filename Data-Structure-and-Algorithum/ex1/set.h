#ifndef SET_H
#define SET_H
#include <list>
#include <vector>
#include <algorithm>
#include <iostream>
template <typename T>
class Set
{
public:
  Set() {}
  Set(const Set &);
  explicit Set(std::vector<T> &);
  Set operator+(const Set &) const;
  Set operator-(const Set &) const;
  Set operator&(const Set &)const;
  Set &Sort();
  void print();

private:
  std::vector<T> set;
  bool sorted;
};

template <typename T>
inline Set<T>::Set(const Set &orig)
{
  set = orig.set;
  sorted = orig.sorted;
}

template <typename T>
Set<T> &Set<T>::Sort()
{
  std::sort(set.begin(), set.end());
  sorted = true;
  return *this;
}
template <typename T>
Set<T> Set<T>::operator+(const Set &orig) const
{
  Set<T> res(*this);
  if (!(*this).set.empty())
  {
    for (auto i : orig.set)
      res.set.push_back(i);
    res.Sort();
    auto end_unique = std::unique(res.set.begin(), res.set.end());
    res.set.erase(end_unique, res.set.end());
    res.sorted = true;
  }
  return res;
}
template <typename T>
Set<T> Set<T>::operator&(const Set &orig) const
{
  Set<T> res, temp(*this);
  if (!(*this).set.empty())
  {
    for (auto i : orig.set)
      temp.set.push_back(i);
    temp.Sort();
    auto i = temp.set.begin();
    for (auto j = i + 1; j != temp.set.end(); ++j)
      if (*i == *j)
      {
        res.set.push_back(*j);
        ++i;
      }
      else
        ++i;
  }
  return res;
}

template <typename T>
Set<T>::Set(std::vector<T> &in)
{
  set = in;
  sorted = false;
}

template <typename T>
void Set<T>::print()
{
  for (auto i : set)
    std::cout << i << " ";
  std::cout << std::endl;
}
template <typename T>
Set<T> Set<T>::operator-(const Set<T> &lv) const
{
  Set<T> res, temp = ((*this) & lv);
  for (auto i : (*this).set)
    temp.set.push_back(i);
  temp.Sort();
  for (auto i = temp.set.begin(); i != temp.set.end(); ++i)
  {
    auto j = i + 1;
    if (j == temp.set.end() || *i != *j)
    {
      res.set.push_back(*i);
    }
    else
    {
      ++i;
    }
  }
  return res;
}
#endif