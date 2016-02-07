#include <fstream>
#include <iostream>
#include "stock.h"
#include "cache.h"

void add_stocks(Cache& c) {
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
  c.add(goog);
  str_vals["name"] = "Microsoft";
  str_vals["industry"] = "Inforation Technology";
  int_vals["shares"] = 160;
  dbl_vals["price"] = 82;
  dbl_vals["earnings"] = 7;
  dbl_vals["debt"] = 90;
  Stock msft("MSFT", str_vals, int_vals, dbl_vals);
  c.add(msft);
  str_vals["name"] = "Moodys";
  str_vals["industry"] = "Financial Analysis";
  int_vals["shares"] = 90;
  dbl_vals["price"] = 77;
  dbl_vals["earnings"] = 5;
  dbl_vals["debt"] = 10;
  Stock mco("MCO", str_vals, int_vals, dbl_vals);
  c.add(mco);
}

int main(int argc, char* argv[]) {
  Cache c;
  add_stocks(c);
  std::cout << "Stock " 
	    << c.get("GOOG") 
	    << std::endl;

  return 0;
}
