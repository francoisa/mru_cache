#include "stock.h"

Stock::Stock(const std::string& sym, 
	     const std::map<std::string, std::string>& s_vals, 
	     const std::map<std::string, int>& i_vals, 
	     const std::map<std::string, double>& d_vals) : _symbol(sym), str_vals(s_vals), int_vals(i_vals), dbl_vals(d_vals) {
}

double Stock::pe_ratio() const {
  double pe = -1.0;
  return pe;
}
 
double Stock::mkt_value() const {
  double mv = -1.0;
  return mv;
}

std::string  Stock::symbol() const {
  return _symbol;
}

std::ostream& operator <<(std::ostream& o, Stock& s) {
  o << "{ symbol:" << s._symbol << " }";
  return o;
}
