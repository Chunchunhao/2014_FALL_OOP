/* Trie is a tree structure that save each character in a node
 * and find the words thorugh traversal
 * I modify the origin trie, to let them store the times of access and all alphabetic to lowercase
 * and i left only searchword method, actually it is combined searchWord and addWord,
 * do this for more efficincy 
 */
#include <iostream>
#include <vector>
#include <cctype>

class Node {
public:
    Node() { mContent = ' '; mMarker = false; mTimes = 0;}
    ~Node() {}
    
    char content() { return mContent; }
    void setContent(char c) { mContent = c; }
    
    bool wordMarker() { return mMarker; }
    void setWordMarker() { mMarker = true; }
    
    int showTimes() { return mTimes; }
    void addTimes() { mTimes += 1; }
    
    Node* findChild(char c);
    void appendChild(Node* child) { mChildren.push_back(child); }
    std::vector<Node*> children() { return mChildren; }

private:
    char mContent;
    bool mMarker;
    int mTimes;
    std::vector<Node*> mChildren;
};

class Trie {
public:
    Trie();
    ~Trie();
    int searchWord(std::string s); 
    // Compbine search and insert
    // if something wrong it'll return error
    // else it should return number of times in our list
private:
    Node* root;
};


Node* Node::findChild(char c) {
    for ( int i = 0; i < mChildren.size(); i++ ) {
        Node* tmp = mChildren.at(i);
        if ( tmp->content() == c ) {
            return tmp;
        }
    }
    return NULL;
}

Trie::Trie()
{
    root = new Node();
}

Trie::~Trie()
{
    // Free memory
}

int Trie::searchWord(std::string s)
{
    Node* current = root;
    bool isFound = true;
    if ( s.length() == 0 ) {
        std::cerr << "Read an empty string in input !!" << std::endl;
        current->setWordMarker(); // an empty word
        current->addTimes();
        return current->showTimes();
    }

    for ( int i = 0; i < s.length(); i++ ) {        
        Node* child = current->findChild(tolower(s[i]));
        if ( child != NULL ) {
            current = child;
        }
        else {
            isFound = false;
            Node* tmp = new Node();
            tmp->setContent(tolower(s[i]));
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1)
          current->setWordMarker();
    }
    current->addTimes();
    return current->showTimes();
}
