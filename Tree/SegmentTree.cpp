#include <iostream>
#include <vector>

using namespace std;


class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;

            buildTree(arr, 2 * node + 1, start, mid);
            buildTree(arr, 2 * node + 2, mid + 1, end);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    int query(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return 0; // range outside

        if(l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        int leftSum = query(2 * node + 1, start, mid, l, r);    
        int rightSum = query(2 * node + 2, mid + 1, end, l, r);
        return leftSum + rightSum;
    }
    void update(int node, int start, int end, int idx, int val) {
        if(start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if(idx <= mid) {
                update(2 * node + 1, start, mid, idx, val);
            } else {
                update(2 * node + 2, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
public: 
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    void update(int idx, int val) {
        update(0, 0, n - 1, idx, val);
    }
};


int main() {

    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    // Query range sum
    cout << "Sum of range [1, 3]: " << segTree.query(1, 3) << endl;

        // Update element at index 1
    segTree.update(1, 10);
    cout << "After update, sum of range [1, 3]: " << segTree.query(1, 3) << endl;

    return 0;
}