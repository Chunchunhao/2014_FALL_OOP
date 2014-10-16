#include "Stock.h"
#include <string>
#include <sstream>
using namespace std;

Stock::Stock(string record)
{
	istringstream input_istring(record);
	input_istring >> name >> share_num >> share_val;
	total_val = share_num * share_val;
}

const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val) return s;
	else return *this;
}
