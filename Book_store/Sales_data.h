#ifndef SALES_DATA_H
#define SALES_DATA_H
using namespace std;
class Sales_data
{
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend istream &read(istream &, Sales_data &);
  friend ostream &print(ostream &, const Sales_data &);

public:
  //constructor added
  Sales_data(string s, unsigned n, double p) : BookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data() : Sales_data(" ", 0, 0) {}
  Sales_data(string&) : Sales_data() {}
  Sales_data(istream &);
  Sales_data &combine(const Sales_data &);
  string isbn() const { return BookNo; }
private:
  //other members as before
  string BookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  double avg_price() const;
};
Sales_data add(const Sales_data &, const Sales_data &);
istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);
#endif