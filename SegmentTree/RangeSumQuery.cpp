#include <vector>
#include <memory>
#include <algorithm>

class NumArray {
private:
    struct Node {
        int left_index{};
        int right_index{};
        int total{};
        std::unique_ptr<Node> left{};
        std::unique_ptr<Node> right{};

        Node(int l, int r, int value = 0)
            : left_index(l), right_index(r), total(value) {}
    };

    std::unique_ptr<Node> root_;

public:
    explicit NumArray(const std::vector<int>& nums) {
        if (!nums.empty()) {
            root_ = build(nums, 0, nums.size() - 1);
        }
    }

    void update(int index, int val) {
        if (root_) updateNode(root_.get(), index, val);
    }

    int sumRange(int left, int right) const {
        if (!root_) return 0;
        return query(root_.get(), left, right);
    }

private:
    // Build segment tree
    std::unique_ptr<Node> build(const std::vector<int>& nums, int l, int r) {
        if (l == r) {
            return std::make_unique<Node>(l, r, nums[l]);
        }

        int mid = l + (r - l) / 2;

        auto node = std::make_unique<Node>(l, r);
        node->left = build(nums, l, mid);
        node->right = build(nums, mid + 1, r);

        node->total = node->left->total + node->right->total;
        return node;
    }

    // Update a single index
    int updateNode(Node* node, int index, int val) {
        if (node->left_index == node->right_index) {
            int diff = val - node->total;
            node->total = val;
            return diff;
        }

        int mid = node->left_index + (node->right_index - node->left_index) / 2;
        int diff = 0;

        if (index <= mid)
            diff = updateNode(node->left.get(), index, val);
        else
            diff = updateNode(node->right.get(), index, val);

        node->total += diff;
        return diff;
    }

    // Query range sum
    int query(const Node* node, int left, int right) const {
        // No overlap
        if (right < node->left_index || left > node->right_index)
            return 0;

        // Full overlap
        if (left <= node->left_index && right >= node->right_index)
            return node->total;

        int mid = node->left_index + (node->right_index - node->left_index) / 2;

        return query(node->left.get(), left, std::min(right, mid)) +
               query(node->right.get(), std::max(left, mid + 1), right);
    }
};

