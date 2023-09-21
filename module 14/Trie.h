#pragma once
#include <string>
const int ALPHABET_SIZE = 26;

struct Trie
{
    Trie();
    ~Trie();

    void insert(const std::string &);

    bool search(Trie *, const std::string &);

    Trie *remove(Trie *, std::string &, int depth = 0);

    std::string getMinPrefixes();

    void getAllWordsByPrefix(Trie *, const std::string &prefix, std::string &ret);

    void generateDictionary();

    Trie *children[ALPHABET_SIZE];

private:
    bool isEmpty(Trie *);

    Trie *getNewNode();

    void getAllWordFromNodePosition(Trie *node, char buf[], int ind, std::string &res);
    void getAllMinPrefixes(Trie *, char[], int, std::string &);

    bool isEndOfWord{false};
    int freq = 1;
};
