#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) 
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};
struct cmp 
{
    bool operator()(Node* a, Node* b) 
    {
        return a->freq > b->freq;
    }
};
void getCodes(Node* root, string code, map<char, string>& huff) 
{
    if (!root) 
        return;

    if (root->ch != '$')
        huff[root->ch] = code;

    getCodes(root->left, code + "0", huff);
    getCodes(root->right, code + "1", huff);
}
string decode(Node* root, string encoded) 
{
    string ans = "";
    Node* curr = root;

    for (char bit : encoded) 
    {
        if (bit == '0') 
            curr = curr->left;
        else 
            curr = curr->right;

        if (!curr->left && !curr->right) 
        {
            ans = ans + curr->ch;
            curr = root;
        }
    }
    return ans;
}
int main() 
{
    string str = "akshveer";
    map<char, int> freq;
    for (char c : str) 
        freq[c]++;

    priority_queue<Node*, vector<Node*>, cmp> pq;
    
    for (auto x : freq)
        pq.push(new Node(x.first, x.second));

    while (pq.size() > 1) 
    {
        Node* a = pq.top(); pq.pop();
        Node* b = pq.top(); pq.pop();
        Node* newNode = new Node('$', a->freq + b->freq);
        newNode->left = a;
        newNode->right = b;
        pq.push(newNode);
    }
    Node* root = pq.top();
    map<char, string> huff;
    getCodes(root, "", huff);
    string encoded = "";
    for (char c : str)
        encoded = encoded + huff[c];

    string decoded = decode(root, encoded);
    cout << "Original: " << str << endl;
    cout << "Encoded : " << encoded << endl;
    cout << "Decoded : " << decoded << endl;
    return 0;
}
