#include <vector> #include <queue> using namespace std; class Solution { 
public:
    double maxProbability(int n, vector<vector<int>>& edges, 
vector<double>& succProb, int start_node, int end_node) {
        // Priority queue to store nodes and probabilities, max heap by 
default
        priority_queue<pair<double, int>> bfsq; vector<double> maxProb(n, 
        0.0);  // Store the maximum probability to reach each node 
        vector<vector<pair<int, double>>> mapping(n); // Build the graph 
        for (int i = 0; i < edges.size(); i++) {
            mapping[edges[i][0]].push_back({edges[i][1], succProb[i]}); 
            mapping[edges[i][1]].push_back({edges[i][0], succProb[i]});
        } // Start BFS with the start node and initial probability of 1.0 
        bfsq.push({1.0, start_node}); maxProb[start_node] = 1.0; // BFS 
        using a priority queue while (!bfsq.empty()) {
            auto curr = bfsq.top(); bfsq.pop(); int node = curr.second;
            double prob = curr.first;

            // If we reached the end node, return the probability
            if (node == end_node) {
                return prob;
            }

            // Traverse neighbors
            for (const auto& neighbor : mapping[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;

                // If going through this node offers a better probability, update and push to the queue
                if (maxProb[nextNode] < prob * edgeProb) {
                    maxProb[nextNode] = prob * edgeProb;
                    bfsq.push({maxProb[nextNode], nextNode});
                }
            }
        }

        // If there's no path from start to end, return 0
        return 0.0;
    }
};

