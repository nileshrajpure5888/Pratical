#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Node structure
struct Node
{
    char ch;
    int freq;

    Node *left, *right;

    Node(char character, int frequency)
    {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Compare nodes by frequency
struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

// Print Huffman codes
void printCodes(Node* root, string code)
{
    if (root == nullptr)
        return;

    // Leaf node
    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

// Build Huffman Tree
void huffmanEncoding(char characters[], int frequencies[], int n)
{
    // Min-heap
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters into priority queue
    for (int i = 0; i < n; i++)
    {
        pq.push(new Node(characters[i], frequencies[i]));
    }

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        // Create internal node
        Node* newNode = new Node('$',
                                 left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    cout << "\nHuffman Codes:\n";

    // Root of Huffman tree
    printCodes(pq.top(), "");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive number.\n";
        return 0;
    }

    vector<char> characters(n);
    vector<int> frequencies(n);

    // Input characters
    cout << "Enter characters:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> characters[i];
    }

    // Input frequencies
    cout << "Enter frequencies:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> frequencies[i];

        if (frequencies[i] < 0)
        {
            cout << "Frequency cannot be negative.\n";
            return 0;
        }
    }

    huffmanEncoding(characters.data(),
                    frequencies.data(),
                    n);

    return 0;
}
