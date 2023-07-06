#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const int (&a)[2], const int (&b)[2]) {
    return (a[0] < b[0]) || ((a[0] == b[0]) && (a[1] < b[1]));
}

int main() {
    std::vector<int[2]> vec;
    
    int arr1[2] = {1, 2};
    int arr2[2] = {3, 4};
    int arr3[2] = {5, 6};
    int arr4[2] = {7, 8};

    vec.push_back(arr1);
    vec.push_back(arr2);
    vec.push_back(arr3);

    // Sort the vector using the custom comparison function
    std::sort(vec.begin(), vec.end(), compare);

    // Find the lower bound of a target value
    int target[2] = {3, 5};
    std::vector<int[2]>::iterator it = std::lower_bound(vec.begin(), vec.end(), target, compare);

    if (it != vec.end()) {
        std::cout << "Lower bound: " << (*it)[0] << ", " << (*it)[1] << std::endl;
    } else {
        std::cout << "No lower bound found" << std::endl;
    }

    return 0;
}

