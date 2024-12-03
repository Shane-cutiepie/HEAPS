#include <iostream>
#include <vector>
#include <queue>
#include <functional> // For std::greater

using namespace std;

// Utility function to display a heap
void display_heap(const vector<int>& heap) {
    for (int value : heap) {
        cout << value << " ";
    }
    cout << endl;
}

// Task 1: Insert treasure chests into a Max-Heap
void task1_max_heap_insertion(const vector<int>& chest_values) {
    cout << "Task 1: Inserting treasure chests into Max-Heap\n";

    priority_queue<int> max_heap;
    for (int value : chest_values) {
        max_heap.push(value);
        cout << "Heap after inserting " << value << ": ";

        // Display heap content
        vector<int> temp;
        while (!max_heap.empty()) {
            temp.push_back(max_heap.top());
            max_heap.pop();
        }

        for (int val : temp) {
            cout << val << " ";
            max_heap.push(val);
        }
        cout << endl;
    }
}

// Task 2: Remove the most valuable chest from the Max-Heap
void task2_remove_root(vector<int> chest_values) {
    cout << "\nTask 2: Removing the most valuable chest (root) from Max-Heap\n";

    priority_queue<int> max_heap(chest_values.begin(), chest_values.end());
    if (!max_heap.empty()) {
        cout << "Removed root: " << max_heap.top() << endl;
        max_heap.pop(); // Remove the root

        cout << "Heap after removal: ";
        vector<int> temp;
        while (!max_heap.empty()) {
            temp.push_back(max_heap.top());
            max_heap.pop();
        }

        for (int val : temp) {
            cout << val << " ";
            max_heap.push(val);
        }
        cout << endl;
    } else {
        cout << "The heap is empty. Nothing to remove.\n";
    }
}

// Task 3: Heapify chest values into a Min-Heap
void task3_heapify_min_heap(const vector<int>& chest_values) {
    cout << "\nTask 3: Heapifying chest values into Min-Heap\n";

    priority_queue<int, vector<int>, greater<int>> min_heap(chest_values.begin(), chest_values.end());

    cout << "Min-Heap: ";
    while (!min_heap.empty()) {
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    cout << endl;
}

int main() {
    vector<int> chest_values = {250, 150, 500, 100};

    // Task 1: Insert treasure chests into Max-Heap
    task1_max_heap_insertion(chest_values);

    // Task 2: Remove the root from Max-Heap
    task2_remove_root(chest_values);

    // Task 3: Heapify chest values into a Min-Heap
    task3_heapify_min_heap(chest_values);

    return 0;
}
