#include <fstream>
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <memory>
#include "stock.h"

typedef std::unordered_map<std::string, std::unique_ptr<Stock> > Stocks;
 
void add_stock(Stocks& stocks, const Stock& s) {
  stocks[s.symbol()] = std::unique_ptr<Stock>(new Stock(s));
}

void add_stocks(Stocks& stocks) {
  std::map<std::string, std::string> str_vals;
  std::map<std::string, int> int_vals;
  std::map<std::string, double> dbl_vals;
  str_vals["name"] = "Google";
  str_vals["industry"] = "Inforation Technology";
  int_vals["shares"] = 100;
  dbl_vals["price"] = 821;
  dbl_vals["earnings"] = 78;
  dbl_vals["debt"] = 120;
  Stock goog("GOOG", str_vals, int_vals, dbl_vals);
  add_stock(stocks, goog);
}

int main(int argc, char* argv[]) {
  Stocks stocks;
  add_stocks(stocks);
  for (auto& s : stocks) {
    std::cout << "Stock " 
	      << *(s.second) 
	      << std::endl;
  }
  return 0;
}
