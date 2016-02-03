#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <map>

class Stock {
 public:
  Stock(const Stock& s) = default;
  Stock& operator=(const Stock& s) = default;
  Stock(Stock&& s) = default;
  Stock& operator=(Stock&& s) = default;
  Stock(const std::string& symbol, 
	const std::map<std::string, std::string>& str_vals, 
	const std::map<std::string, int>& int_vals, 
	const std::map<std::string, double>& dbl_vals);
  std::string symbol() const;
  double pe_ratio() const;
  double mkt_value() const;
  ~Stock() {}
  friend std::ostream& operator <<(std::ostream& o, Stock& s);
 private:
  std::string _symbol;
  std::map<std::string, std::string> str_vals;
  std::map<std::string, int> int_vals;
  std::map<std::string, double> dbl_vals;
};
#endif
