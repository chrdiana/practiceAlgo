/*
 * Trie.c
 *
 *  Created on: Aug 23, 2018
 *      Author: dichris
 */

#include "app.h"
#include <stdbool.h>

#define SIZE 26

typedef struct node {

	struct node *children[SIZE];
	bool endWord;

} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {

	int i = 0;
	Trie *node = malloc(sizeof(Trie));
	if (!node) {
		return NULL;
	}
	node->endWord = false;
	for (i = 0; i<SIZE; i++) {
		node->children[i] = NULL;
	}
	return node;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char* word) {
	if (!obj || !word) {
		return;
	}
	Trie *tmp = obj;
	int i = 0;
	while (word[i] != '\0') {
		int idx = word[i] - 'a';
		if (!tmp->children[idx]) {
			//create new node
			tmp->children[idx] = trieCreate();
		}
		tmp = tmp->children[idx];
		i++;
	}
	tmp->endWord = true;
}

Trie* trieSearchPrefix(Trie *obj, char *prefix) {
	if (!obj || !prefix) {
		return NULL;
	}
	int i = 0;
	Trie *tmp = obj;
	while (prefix[i] != '\0') {
		int idx = prefix[i] - 'a';
		if (!tmp->children[idx]) {
			return NULL;
		}
		tmp = tmp->children[idx];
		i++;
	}
	return tmp;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char* word) {

	Trie *tmp = trieSearchPrefix(obj, word);
	if (tmp && tmp->endWord) {
		return true;
	}
	return false;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char* prefix) {
	Trie *tmp = trieSearchPrefix(obj, prefix);
	if (tmp) {
		return true;
	}
	return false;
}

void trieFree(Trie* obj) {
	if (!obj) {
		return;
	}
	for (int i=0; i<SIZE; i++) {
		free(obj->children[i]);
		obj->children[i] = NULL;
	}
	free(obj);
}


int testTrie() {

	 bool warning = false;
	 Trie* obj = trieCreate();
	 char word[] = "apple";
	 char word2[] = "app";
	 char prefix[] = "app";
	 trieInsert(obj, word);
	 //trieInsert(obj, word2);
	 bool param_2 = trieSearch(obj, word2);
	 printf("word %s %s in trie\n", word2, param_2? "exists" : "does not exists");
	 bool param_3 = trieStartsWith(obj, prefix);
	 printf("prefix %s %s in trie\n", prefix, param_3? "exists" : "does not exists");
	 trieFree(obj);

	return 0;
}
