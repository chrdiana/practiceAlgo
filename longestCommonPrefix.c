/*
 * longestCommonPrefix.c
 *
 *  Created on: Aug 23, 2018
 *      Author: dichris
 */

#include "app.h"
#include <stdbool.h>

#define SIZE 26

typedef struct node {

	struct node *children[SIZE];
	int numChild;
	bool endWord;

} Trie;

/** Initialize your data structure here. */
Trie* trieCreateLCP() {

	int i = 0;
	Trie *node = malloc(sizeof(Trie));
	if (!node) {
		return NULL;
	}
	node->numChild = 0;
	node->endWord = false;
	for (i = 0; i<SIZE; i++) {
		node->children[i] = NULL;
	}
	return node;
}

/** Inserts a word into the trie. */
void trieInsertLCP(Trie* obj, char* word) {
	if (!obj || !word) {
		return;
	}
	Trie *tmp = obj;
	int i = 0;
	while (word[i] != '\0') {
		int idx = word[i] - 'a';
		if (!tmp->children[idx]) {
			//create new node
			tmp->children[idx] = trieCreateLCP();
			tmp->numChild++;
		}
		tmp = tmp->children[idx];
		i++;
	}
	tmp->endWord = true;
}

int getChildIdx(Trie *trie) {
	if (!trie) {
		return -1;
	}
	for (int i = 0; i<SIZE; i++) {
		if (trie->children[i]) {
			return i;
		}
	}
	return -1;
}

char* longestCommonPrefix(char** strs, int strsSize) {

	if (!strs || strsSize == 0) {
		return NULL;
	}

	int buffsiz = 1024;
	char *prefix = calloc(buffsiz, sizeof(char));
	int i = 0, j = 0;
	Trie *trie = trieCreateLCP();

	for (i = 0; i < strsSize; i++) {
		if (!strs[i] || (strcmp(strs[i], "") == 0)) {
			return "";
		}
		trieInsertLCP(trie, strs[i]);
	}

	Trie *tmp = trie;
	int childIdx = -1;
	while (tmp->numChild == 1 && !tmp->endWord) {
		childIdx = getChildIdx(tmp);
		if (childIdx == -1){
			return NULL;
		}
		prefix[j] = (uint32_t)childIdx + 'a';
		j++;
		if (j > (buffsiz - 1)) {
			buffsiz += buffsiz;
			prefix = realloc(prefix, buffsiz);
		}
		tmp = tmp->children[childIdx];
	}
	char *s = strdup(prefix);
	return s;
}

int testLCP() {

	//["flower","flow","flight"]
	char **strs = calloc(3, sizeof(char *));

	strs[0] = strdup("b");
	strs[1] = strdup("bb");
	strs[2] = strdup("bb");

	char *prefix = longestCommonPrefix(strs, 3);

	printf("Prefix: %s\n", prefix);
	return 0;
}




