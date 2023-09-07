#include <stack>
#include <vector>
using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> stockPrices; 

public:
    StockSpanner() {}

    int next(int price) {
        int span = 1;
        while (!stockPrices.empty() && price >= stockPrices.top().first) {
            span += stockPrices.top().second;
            stockPrices.pop();
        }
        stockPrices.push({price, span});

        return span;
    }
};
