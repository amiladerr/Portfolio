#include <iostream>
#include "Stock.h"
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    Stock stock("MSFT", "Microsoft Corporation");
    stock.setPreviousClosingPrice(27.5);
    stock.setCurrentPrice(27.6);
    cout << fixed << setprecision(2) << stock.getChangePercentage() << "%" << endl;
    return 0;
}
