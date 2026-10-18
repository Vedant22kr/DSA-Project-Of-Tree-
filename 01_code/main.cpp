
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <iomanip>
using namespace std;

// Structure of a BST node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Insert a value into the BST
Node* insertNode(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Calculate height of the BST
// Height is measured in number of nodes
int treeHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// Construct a BST from a sequence
Node* buildTree(const vector<int>& sequence) {
    Node* root = nullptr;

    for (int value : sequence) {
        root = insertNode(root, value);
    }

    return root;
}

// Display a sequence
void printSequence(const vector<int>& sequence) {
    for (int value : sequence) {
        cout << value << " ";
    }
    cout << endl;
}

// Free dynamically allocated memory
void deleteTree(Node* root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int n;

    cout << "=================================\n";
    cout << "       BST HEIGHT ANALYSIS\n";
    cout << "=================================\n";

    cout << "Enter number of elements (1-10000): ";

    if (!(cin >> n) || n < 1 || n > 10000) {
        cout << "Invalid input! Enter a value from 1 to 10000.\n";
        return 1;
    }

    vector<int> ascending;
    vector<int> descending;
    vector<int> randomOrder;

    // Generate ascending sequence: 1 to n
    for (int i = 1; i <= n; i++) {
        ascending.push_back(i);
    }

    // Generate descending sequence
    descending = ascending;
    reverse(descending.begin(), descending.end());

    // Generate randomized sequence using the same elements
    randomOrder = ascending;

    mt19937 generator(
        static_cast<unsigned int>(time(nullptr))
    );

    shuffle(
        randomOrder.begin(),
        randomOrder.end(),
        generator
    );

    // Construct three BSTs
    Node* rootAscending = buildTree(ascending);
    Node* rootDescending = buildTree(descending);
    Node* rootRandom = buildTree(randomOrder);

    // Calculate tree heights
    int heightAscending = treeHeight(rootAscending);
    int heightDescending = treeHeight(rootDescending);
    int heightRandom = treeHeight(rootRandom);

    // Display insertion sequences
    cout << "\n--- Insertion Sequences ---\n";

    cout << "Ascending : ";
    printSequence(ascending);

    cout << "Descending: ";
    printSequence(descending);

    cout << "Random    : ";
    printSequence(randomOrder);

    // Display height comparison
    cout << "\n--- BST Height Comparison ---\n";

    cout << left << setw(20) << "Sequence"
         << "Height" << endl;

    cout << "------------------------------\n";

    cout << left << setw(20) << "Ascending"
         << heightAscending << endl;

    cout << left << setw(20) << "Descending"
         << heightDescending << endl;

    cout << left << setw(20) << "Random"
         << heightRandom << endl;

    // Analyze the results
    cout << "\n--- Analysis ---\n";

    if (n == 1) {
        cout << "All three BSTs have height 1.\n";
    }
    else {
        cout << "Ascending insertion creates a right-skewed BST.\n";
        cout << "Descending insertion creates a left-skewed BST.\n";
        cout << "Both heights are equal to n = " << n << ".\n";

        cout << "Random insertion may produce a shorter tree.\n";
        cout << "Its height depends on the insertion order.\n";
    }

    // Release memory
    deleteTree(rootAscending);
    deleteTree(rootDescending);
    deleteTree(rootRandom);

    cout << "\nProgram completed successfully.\n";

    return 0;
}
