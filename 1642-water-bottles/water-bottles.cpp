class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = numBottles;
        int drink = numBottles;
        while(emptyBottles >= numExchange){
            int exchange = emptyBottles/numExchange;
            drink += exchange;
            emptyBottles = exchange + emptyBottles%numExchange;

        }

        return drink;
    }
};