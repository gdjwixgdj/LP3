
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    double value, weight;
};

// Compare items by value/weight ratio
bool compare(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

int main() {
    // Items = {value, weight}
    Item items[] = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int n = 3;
    double capacity = 50;
    double maxValue = 0;

    // Sort items by highest ratio first
    sort(items, items + n, compare);

    // Select items using greedy approach
    for (int i = 0; i < n; i++) {

        if (capacity == 0)
            break;

        if (capacity >= items[i].weight) {
            // Take complete item
            maxValue += items[i].value;
            capacity -= items[i].weight;
        }
        else {
            // Take fractional part
            maxValue += items[i].value *
                        (capacity / items[i].weight);
            capacity = 0;
        }
    }

    cout << "Maximum Value = " << maxValue;

    return 0;
}
