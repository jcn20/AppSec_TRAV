#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#define DICTIONARY "wordlist.txt"

int main(int argc, char *argv[]){
	// needs 3 arguments - otherwise this doesn't work.
	
        if (argc!=3){
		printf("You need 3 arguments: the C Program and two files.");
		exit(EXIT_FAILURE);
	}

	hashmap_t hashtable[HASH_SIZE];
	char *misspelled[MAX_MISSPELLED] = {0}; // Initial array to populate.

	FILE *fp = fopen(argv[1], "r");
	char * dictionary = argv[2]; // "Dictionary"
	load_dictionary(dictionary, hashtable);
	
	// Loop through the array, check for misspelled words 
	int num_misspelled = check_words(fp, hashtable, misspelled);
	
	for(int i=0; i < num_misspelled; i++){
		printf("%s\n", misspelled[i]);
	}	
	exit(0);
}
