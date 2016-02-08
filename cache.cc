#include "cache.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

bool Cache::get(const std::string& sym, Stock& s) {
  if (stocks.count(sym)) {
    s = *(stocks[sym]);
    stocks_list.erase(stocks[sym]);
    stocks_list.push_back(s);
    stocks[sym] = --(stocks_list.end());
    return true;
  }
  else {
    if (get_stock(sym, s)) {
      stocks_list.push_back(s);
      stocks[sym] = --(stocks_list.end());
      if (stocks_list.size() >= max_size) {
	const std::string& front_sym = stocks_list.front().symbol();
	std::cout << "Removing: " << front_sym << std::endl;
	stocks.erase(front_sym);
	stocks_list.erase(stocks_list.begin());
      }
      return true;
    }
    else {
      return false;
    }
  }
}

void Cache::add(const Stock& s) {
  stocks_map[s.symbol()] = s;
}

void Cache::parse_stock(const std::string& line, Stock& stock) {
  std::istringstream iss(line);
  std::string field;
  std::vector<std::string> fields;
  while (iss >> field) {
    fields.push_back(field);
  }
  const std::string str_vol = fields.back();
  fields.pop_back();
  const std::string str_price = fields.back();
  fields.pop_back();
  std::ostringstream os;
  std::copy(fields.begin()+1, fields.end(),
	    std::ostream_iterator<std::string>{os," "});
  std::cout << "symbol: " << fields[0] << " name: '" << os.str()
	    << "' price: " << str_price << " vol: " << str_vol << std::endl;
  std::map<std::string, std::string> str_vals;
  std::map<std::string, int> int_vals;
  std::map<std::string, double> dbl_vals;
  str_vals["name"] = os.str();
  std::istringstream int_iss(str_vol);
  int_iss >> int_vals["shares"];
  std::istringstream dbl_iss(str_price);
  dbl_iss >> dbl_vals["price"];
  Stock s(fields[0], str_vals, int_vals, dbl_vals);
  stock = s;
}

bool Cache::get_stock(const std::string& sym, Stock& stock) {
  std::ifstream ifs("stocks.dat");
  std::string line;
  while (getline(ifs, line)) {
    std::istringstream iss(line);
    std::string symbol_field;
    iss >> symbol_field;
    std::cout << symbol_field << " ";
    if (symbol_field == sym) {
      std::cout << std::endl;
      parse_stock(line, stock);
      return true;
    }
  }
  return false;
}
