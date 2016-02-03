#include <fstream>
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <memory>
#include "stock.h"

typedef std::map<std::string, std::unique_ptr<Stock> > Stocks;
 
void add_stock(Stocks& stocks, Stock* s) {
  stocks.(std::unique_ptr<Stock>(s));
}

int main(int argc, char* argv[]) {
  Stocks stocks;
  for (auto& s : stocks) {
    std::cout << "The area of a " 
	      << *s << " is " 
	      << s->area() << std::endl;
  }
  return 0;
}
