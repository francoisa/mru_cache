#ifndef CACHE_H
#define CACHE_H
#include <unordered_map>
#include <map>
#include <list>
#include "stock.h"

typedef std::list<Stock> Stocks_List;
typedef Stocks_List::iterator Stocks_Iter;
typedef std::unordered_map<std::string, Stocks_Iter> Stocks;

class Cache {
public:
  const Stock& get(const std::string& sym);
  void add(const Stock& s);

private:
  Stocks_List stocks_list;
  Stocks stocks;
  std::map<std::string, Stock> stocks_map;
};
#endif
