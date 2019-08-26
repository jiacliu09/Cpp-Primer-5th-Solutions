#include <iostream>
using std::cout; using std::cin; using std::cerr; using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <functional>
using std::mem_fn;
#include <algorithm>
using std::find_if;
#include "Sales_data.h"
#include <functional>
using std::bind;

using namespace std::placeholders;

bool isBigger(const double &avg, const vector<Sales_data>::iterator &it_vS){
    return it_vS->avg_price() > avg;
}

vector<Sales_data>::iterator &firstBiggeravg(vector<Sales_data> &vS, const double &avg){
    auto it = find_if(vS.begin(), vS.end(), bind(isBigger, avg, _1));
    return it;
}

int main(){}