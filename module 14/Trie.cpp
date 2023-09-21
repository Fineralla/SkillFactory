#include "Trie.h"
#include <iostream>

Trie::Trie()
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        children[i] = nullptr;
    }
}

Trie::~Trie()
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (this->children[i])
        {
            delete this->children[i];
        }
    }
}


void Trie::insert(const std::string &key)
{
    Trie *node = this;

    for (int i = 0; i < key.length(); i++)
    {
       
        int index = key[i] - 'a';
        if (!node->children[index])
            node->children[index] = getNewNode();
        else
            node->children[index]->freq++;
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

bool Trie::search(struct Trie *root, const std::string &key)
{
    struct Trie *node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

Trie *Trie::remove(Trie *root, std::string &key, int depth)
{
    if (!root)
        return nullptr;

    if (depth == key.size())
    {

        if (root->isEndOfWord)
            root->isEndOfWord = false;

        if (isEmpty(root))
        {
            delete (root);
            root = nullptr;
        }

        return root;
    }
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false)
    {
        delete (root);
        root = nullptr;
    }


    return root;
}

std::string Trie::getMinPrefixes()
{
    std::string ret;
    char buf[ALPHABET_SIZE];
    getAllMinPrefixes(this, buf, 0, ret);
    return ret;
}

void Trie::getAllWordsByPrefix(Trie *root, const std::string &prefix, std::string &ret)
{
    if (root == nullptr)
        return;

    char buf[ALPHABET_SIZE];
    int ind = 0;
    Trie *node = root;

    for (int i = 0; i < prefix.size(); i++)
    {
        buf[i] = prefix[ind];

        for (int j = 0; j < ALPHABET_SIZE; j++)
        {
            if (node->children[j] != nullptr && (j + 'a') == prefix[i])
            {

                if (node->children[j]->isEndOfWord)
                {
                    buf[ind + 1] = '\0';
                    ret.append(buf);
                    ret.push_back(' ');
                }
                node = node->children[j];
                break;
            }
        }
        ind++;
    }
    getAllWordFromNodePosition(node, buf, ind, ret);
}

void Trie::generateDictionary()
{
    std::string dictArray[30] = {"hello", "friend", "people", "enter",
                                 "name", "address", "girl", "children",
                                 "age", "old", "young", "you", "he", "she",
                                 "parents", "father", "wife", "sister", "brother",
                                 "uncle", "arm", "bone", "eye", "face", "hair", "hand",
                                 "head", "she", "singl", "sinoptics"};

    for (int i = 0; i < 30; i++)
    {
        this->insert(dictArray[i]);
    }
}

bool Trie::isEmpty(Trie *root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

Trie *Trie::getNewNode()
{

    Trie *pNode = new Trie;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void Trie::getAllWordFromNodePosition(Trie *node, char buf[], int ind, std::string &res)
{
    if (node == nullptr)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {

        if (node->children[i] != nullptr)
        {
            buf[ind] = i + 'a';
            if (node->children[i]->isEndOfWord)
            {
                buf[ind + 1] = '\0';
                res.append(buf);
                res.push_back(' ');
            }

            getAllWordFromNodePosition(node->children[i], buf, ind + 1, res);
        }
    }
}

void Trie::getAllMinPrefixes(Trie *root, char buf[], int ind, std::string &res)
{
    if (root == nullptr)
        return;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {

        if (root->children[i] != nullptr)
        {
            buf[ind] = i + 'a';
            if (root->children[i]->freq == 1)
            {
                buf[ind + 1] = '\0';
                res.append(buf);
                res.push_back(' ');
                buf[ind] = '\0';
                continue;
            }

            getAllMinPrefixes(root->children[i], buf, ind + 1, res);
        }
    }
}