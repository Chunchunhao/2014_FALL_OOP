#ifndef STOCK_H
#define STOCK_H
#include <string>

class Stock
{
public:
	Stock(std::string record);
	const Stock& topval(const Stock& s) const;
	std::string getName() const { return name; }
	double getTotalVal() const { return total_val; }
private:
	std::string name;
	unsigned share_num;
	double share_val;
	double total_val;
};

#endif // STOCK_H
