
#include <iostream>   // For cout
#include <queue>      // For priority_queue
#include <vector>     // For vector
using namespace std;

// Step 1: Create a node for the Huffman tree
struct Node {
    char ch;           // Stores character (a, b, c...)
    int freq;          // Stores frequency of character
    Node *left, *right; // Pointers to left and right child

    // Constructor: creates a new node
    Node(char c, int f) {
        ch = c;                // Store character
        freq = f;              // Store frequency
        left = right = NULL;   // Initially no children
    }
};

// Step 2: Compare frequencies (smallest first)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; // Smaller frequency gets priority
    }
};

// Step 3: Print Huffman codes
void printCode(Node* root, string code) {

    if (root == NULL) return; // Stop if node is empty

    // Check if current node is a leaf (no children)
    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " 
             << (code == "" ? "0" : code) << endl;
        return; // Stop recursion for this character
    }

    // Go left and add 0
    printCode(root->left, code + "0");

    // Go right and add 1
    printCode(root->right, code + "1");
}

int main() {

    // Step 4: Input characters and frequencies
    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = 6; // Total characters

    // Step 5: Create min-priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert every character into queue
    for (int i = 0; i < n; i++) {
        pq.push(new Node(ch[i], freq[i]));
    }

    // Step 6: Build Huffman tree
    while (pq.size() > 1) {

        Node* left = pq.top();  // Get smallest frequency
        pq.pop();               // Remove it

        Node* right = pq.top(); // Get second smallest
        pq.pop();               // Remove it

        // Create parent node with combined frequency
        Node* parent = new Node('-', left->freq + right->freq);

        parent->left = left;   // Attach left child
        parent->right = right; // Attach right child

        pq.push(parent);       // Insert parent into queue
    }

    // Step 7: Print final Huffman codes
    cout << "Huffman Codes:" << endl;

    printCode(pq.top(), ""); // Start from root with empty code

    return 0; // End program
}
