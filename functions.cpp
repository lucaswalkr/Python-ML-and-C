#include <iostream>
#include <string>
#include <vector>

// ANSWERS (FUNCTIONS)

// 1. sum_first_last_divide_middle function
float sum_first_last_divide_middle(std::vector<float> list) {
    // calculates size of input vector
    int n = list.size();
    // determines the position (index) of the middle element
    int middle;

    // ERROR HANDLING: Check if the list has at least two elements
    if (n < 2) {
        throw std::invalid_argument("The input vector must have at least two elements.");
    }

    // if divisible by 2 then list is even (remainder of division is 0), the element
    // just before halfway is assigned as middle else select the middle element
    // e.g 9/2 = 4.5 (int so rounds down to index 4), 3 elements exist either side of 4 so this is the middle
    if (n % 2 == 0) {
        middle = list[n / 2 - 1];
    } else {
        middle = list[n / 2];
    }

    // returns sum of first element + last element divided by the middle element
    return (list[0] + list[n - 1]) / middle;
}

// 2. as_negative function
float as_negative(float num) {
   // ERROR HANDLING: check if input is already negative
   if (num < 0) {
        std::cout << "Some or all inputs are already negative." << std::endl;
        return num;
   }

    // std::abs finds the absolute value of input which is multiplied by -1 to make it negative
    return -1 * std::abs(num);
}

// 3. n_multiples_of function
std::vector<int>  n_multiples_of(int n, int x) {
    // ERROR HANDLING: Check if x is zero
    if (x == 0) {
        throw std::invalid_argument("x (the 2nd integer) must be non-zero.");
    }

    std::vector<int> multiples; // creates empty vector called "multiples"

    for (int i = 1; i <= n; i++) { // for loop, iterates "n" times starting from 1
        multiples.push_back(x * i); // calculates the nth multiple of x, appends this to the end of the "multiples" vector
    }

    return multiples; // returns the "multiples" vector, containing n multiples of x
}

// 4. is_multiple function
bool is_multiple(std::vector<int> nums, int n) {
   // ERROR HANDLING: Checks whether input vector is empty
   if (nums.empty()) {
        throw std::invalid_argument("Input vector must have at least one element.");
   }

// calculate the sum of the input integers
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }

    // test to see if sum of passed vector is divisible by n
    if (sum % n == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // The code in this function is provided as an example of how the
    // functions you write may be called. It is non-exhaustive and
    // does not check correctness.

    // First, last, middle calculation
    std::vector<float> test_values = {1, 4, 20, 11};
    float result = sum_first_last_divide_middle(test_values);
    std::cout << "The sum of the first and last, divided by the middle element is " << result << std::endl;

    // As negative
    std::cout << std::endl;  // Just a blank line
    for(auto i : {-5.4, 4.0, 3.67}) {
        float neg = as_negative(i);
        std::cout << i << " as negative is " << neg << std::endl;
    }

    // N multiples of
    std::cout << std::endl;  // Just a blank line
    int n = 5;
    int x = 4;
    std::vector<int> multiples = n_multiples_of(n, x);
    std::cout << "The " << n << " multiples of " << x << " are:" << std::endl;
    for (auto i : multiples) {
        std::cout << "  " << i << std::endl;
    }

    // Is multiple
    std::cout << std::endl;  // Just a blank line
    std::vector<int> number_set = {5, 9, 51, 4, 8, 95, 54, 96, 5};
    auto multiple = 3;
    bool it_is_a_multiple = is_multiple(number_set, multiple);
    if(it_is_a_multiple) {
        std::cout << "Sum of list is a multiple of " << multiple << std::endl;
    } else {
        std::cout << "Sum of list is not a multiple of " << multiple << std::endl;
    }
}
