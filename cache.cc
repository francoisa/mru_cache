#include "cache.h"

const Stock& Cache::get(const std::string& sym) {
  if (stocks.count(sym)) {
    Stock& s = *(stocks[sym]);
    stocks_list.erase(stocks[sym]);
    stocks_list.push_back(s);
    stocks[sym] = --(stocks_list.end());
    return s;
  }
  else {
    Stock& s = stocks_map[sym];
    stocks_list.push_back(s);
    stocks[sym] = --(stocks_list.end());
    if (stocks_list.size() > 10) {
      const std::string& front_sym = stocks_list.front().symbol();
      stocks.erase(front_sym);
      stocks_list.erase(stocks_list.begin());
    }
    return s;
  }  
}

void Cache::add(const Stock& s) {
  stocks_map[s.symbol()] = s;
}
