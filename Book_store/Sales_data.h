#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
#include<string>
class Sales_data
{
  friend Sales_data operator+(const Sales_data &,const Sales_data&);
  friend Sales_data operator-(const Sales_data &,const Sales_data&);
  friend std::istream &operator>>(std::istream&, Sales_data &);
  friend std::ostream &operator<<(std::ostream&, const Sales_data &);
  friend bool operator==(const Sales_data&, const Sales_data&);
public:
  //constructor added
  Sales_data(std::string s, unsigned n, double p) : BookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data() : Sales_data(" ", 0, 0) {}
  Sales_data(std::string&) : Sales_data() {}
  Sales_data(std::istream &);
  Sales_data &combine(const Sales_data &);
  Sales_data &operator+=(const Sales_data &);
  Sales_data &operator-=(const Sales_data &);
  std::string isbn() const { return BookNo; }
private:
  //other members as before
  std::string BookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  double avg_price() const;
};

Sales_data operator+(const Sales_data &,const Sales_data&);
Sales_data operator-(const Sales_data &,const Sales_data&);
std::istream &operator>>(std::istream&, Sales_data &);
std::ostream &operator<<(std::ostream&, const Sales_data &);
bool operator==(const Sales_data&, const Sales_data&);
bool operator!=(const Sales_data&, const Sales_data&);
#endif
