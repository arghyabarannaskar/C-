#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree, lazy;
    int n;

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        buildTree(data, 0, 0, n - 1);
    }

    void buildTree(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(data, 2 * node + 1, start, mid);
            buildTree(data, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void updateRange(int left, int right, int value, int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > right || end < left) {
            return; // No overlap
        }

        if (start >= left && end <= right) { // Total overlap
            tree[node] += (end - start + 1) * value;
            if (start != end) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        // Partial overlap
        int mid = (start + end) / 2;
        updateRange(left, right, value, 2 * node + 1, start, mid);
        updateRange(left, right, value, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int rangeSum(int left, int right, int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > right || end < left) {
            return 0; // No overlap
        }

        if (start >= left && end <= right) { // Total overlap
            return tree[node];
        }

        // Partial overlap
        int mid = (start + end) / 2;
        int sumLeft = rangeSum(left, right, 2 * node + 1, start, mid);
        int sumRight = rangeSum(left, right, 2 * node + 2, mid + 1, end);
        return sumLeft + sumRight;
    }

    void updateRange(int left, int right, int value) {
        updateRange(left, right, value, 0, 0, n - 1);
    }

    int rangeSum(int left, int right) {
        return rangeSum(left, right, 0, 0, n - 1);
    }
};

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    cout << "Sum of range(1, 3): " << segTree.rangeSum(1, 3) << endl;

    segTree.updateRange(1, 3, 3); // Add 3 to elements in range [1, 3]
    cout << "Sum of range(1, 3) after range update: " << segTree.rangeSum(1, 3) << endl;

    return 0;
}
