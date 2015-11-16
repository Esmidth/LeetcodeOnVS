//Implement Trie(Prefix Tree)	<Medium>
#include "stdafx.h"
#include <string>

using namespace std;

class TrieNode {
public:
	TrieNode() {
		for (auto i = 0; i < 26; i++) {
			next[i] = nullptr;
		}
		isString = false;
	}

	TrieNode *next[26];
	bool isString;
};

class Trie {
private:
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode();
	}

	void insert(string word) const
	{
		auto p = root;
		for (auto i = 0; i < word.size(); ++i) {
			if (p->next[word[i] - 'a'] == nullptr)
				p->next[word[i] - 'a'] = new TrieNode();
			p = p->next[word[i] - 'a'];
		}
		p->isString = true;
	}

	bool search(string word) const
	{
		TrieNode *p = root;
		for (auto i = 0; i < word.size(); ++i) {
			if (p == nullptr)
				return false;
			p = p->next[word[i] - 'a'];
		}
		if (p == nullptr || p->isString == false)
			return false;
		return true;
	}


	bool startsWith(std::string prefix) const
	{
		TrieNode*p = root;
		for (int i = 0; i <= prefix.size(); ++i) {
			if (p == nullptr)
				return false;
			p = p->next[prefix[i] - 'a'];
		}
		return true;
	}
};


// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");