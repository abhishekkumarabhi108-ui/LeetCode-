int maxProfit(int* prices, int pricesSize) {

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {

        // Update minimum buying price
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        }

        // Calculate today's profit
        int profit = prices[i] - minPrice;

        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit;
}