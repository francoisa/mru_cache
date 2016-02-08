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
  bool get(const std::string& sym, Stock& s);
  void add(const Stock& s);
  Cache(unsigned int size) : max_size(size) { }
  Cache() : max_size(4) { }

private:
  void parse_stock(const std::string& line, Stock& stock);
  bool get_stock(const std::string& sym, Stock& stock);
  Stocks_List stocks_list;
  Stocks stocks;
  std::map<std::string, Stock> stocks_map;
  unsigned int max_size;
};
#endif
