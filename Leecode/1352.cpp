//
// Created by GreenArrow on 2020/9/12.
//

#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers {
public:

    vector<int> numbers;

    ProductOfNumbers() {

    }

    void add(int num) {
        numbers.push_back(num);
    }

    int getProduct(int k) {
        int results = 1;
        for (int i = numbers.size() - 1; i >= numbers.size() - k; i--) {
            results *= numbers[i];
        }
        return results;
    }
};

/**-
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main(){
    
}