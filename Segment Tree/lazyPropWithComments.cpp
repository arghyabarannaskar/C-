#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree, lazy;
    int n;

public:
    // Constructor: Initializes the segment tree and lazy arrays
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n); // Segment tree array (size is 4 times the number of elements)
        lazy.resize(4 * n, 0); // Lazy array for deferred updates (initialized to 0)
        buildTree(data, 0, 0, n - 1); // Build the segment tree
    }

    // Build the segment tree: Recursively builds the tree from the input data
    void buildTree(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            // Leaf node, store the value in the tree
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            // Recursively build the left and right children
            buildTree(data, 2 * node + 1, start, mid);
            buildTree(data, 2 * node + 2, mid + 1, end);
            // Store the sum of the left and right children in the current node
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Update range [left, right] by adding 'value' to each element
    void updateRange(int left, int right, int value, int node, int start, int end) {
        // If there's a pending update for this node, apply it before proceeding
        if (lazy[node] != 0) {
            // Apply the pending update to the current node
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                // Propagate the pending update to the left and right children
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            // Clear the pending update for the current node
            lazy[node] = 0;
        }

        // No overlap condition: The current range is completely outside the update range
        if (start > end || start > right || end < left) {
            return;
        }

        // Total overlap condition: The current range is completely within the update range
        if (start >= left && end <= right) {
            // Apply the update to the current node
            tree[node] += (end - start + 1) * value;
            if (start != end) {
                // Propagate the update to the left and right children
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        // Partial overlap condition: The current range partially overlaps with the update range
        int mid = (start + end) / 2;
        // Recursively update the left and right children
        updateRange(left, right, value, 2 * node + 1, start, mid);
        updateRange(left, right, value, 2 * node + 2, mid + 1, end);
        // Update the current node with the new values of its children
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Query the sum of elements in the range [left, right]
    int rangeSum(int left, int right, int node, int start, int end) {
        // If there's a pending update for this node, apply it before proceeding
        if (lazy[node] != 0) {
            // Apply the pending update to the current node
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                // Propagate the pending update to the left and right children
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            // Clear the pending update for the current node
            lazy[node] = 0;
        }

        // No overlap condition: The current range is completely outside the query range
        if (start > end || start > right || end < left) {
            return 0;
        }

        // Total overlap condition: The current range is completely within the query range
        if (start >= left && end <= right) {
            return tree[node];
        }

        // Partial overlap condition: The current range partially overlaps with the query range
        int mid = (start + end) / 2;
        // Recursively query the left and right children
        int sumLeft = rangeSum(left, right, 2 * node + 1, start, mid);
        int sumRight = rangeSum(left, right, 2 * node + 2, mid + 1, end);
        // Return the sum of the left and right children
        return sumLeft + sumRight;
    }

    // Public function to update a range
    void updateRange(int left, int right, int value) {
        updateRange(left, right, value, 0, 0, n - 1);
    }

    // Public function to query a range sum
    int rangeSum(int left, int right) {
        return rangeSum(left, right, 0, 0, n - 1);
    }
};

int main() {
    // Sample input data
    vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    // Query the sum of range [1, 3]
    cout << "Sum of range(1, 3): " << segTree.rangeSum(1, 3) << endl;

    // Update the range [1, 3] by adding 3 to each element
    segTree.updateRange(1, 3, 3);

    // Query the sum of range [1, 3] after the update
    cout << "Sum of range(1, 3) after range update: " << segTree.rangeSum(1, 3) << endl;

    return 0;
}
