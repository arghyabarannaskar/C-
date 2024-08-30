#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int>& data) {
        n = data.size();
        tree.resize(4 * n);
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

    void update(int index, int value, int node, int start, int end) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (index <= mid) {
                update(index, value, 2 * node + 1, start, mid);
            } else {
                update(index, value, 2 * node + 2, mid + 1, end);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void update(int index, int value) {
        update(index, value, 0, 0, n - 1);
    }

    int rangeSum(int left, int right, int node, int start, int end) {
        if (right < start || end < left) {
            return 0; // No overlap
        }
        if (left <= start && end <= right) {
            return tree[node]; // Total overlap
        }
        // Partial overlap
        int mid = (start + end) / 2;
        int sumLeft = rangeSum(left, right, 2 * node + 1, start, mid);
        int sumRight = rangeSum(left, right, 2 * node + 2, mid + 1, end);
        return sumLeft + sumRight;
    }

    int rangeSum(int left, int right) {
        return rangeSum(left, right, 0, 0, n - 1);
    }
};

int main() {
    vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    cout << "Sum of range(1, 3): " << segTree.rangeSum(1, 3) << endl;

    segTree.update(1, 10);
    cout << "Sum of range(1, 3) after update: " << segTree.rangeSum(1, 3) << endl;

    return 0;
}
