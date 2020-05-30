#include <stdio.h>

int check_anagram(char[], char[]);
void lowercase(char[]);
int main(int argc, char *argv[]){
	char* firstWord = argv[1]; // get input from bash script for word One
	char* secondWord = argv[2]; // get input for word Two
	lowercase(firstWord); // convert all uppercase letters to lowercase (if exist) for word one
	lowercase(secondWord); // convert all uppercase letters to lowercase for word two
	int ret = check_anagram(firstWord, secondWord); // returns value from check_anagram
	return ret;
}

void lowercase(char s[]){
	int c=0; // counter initialized
	while (s[c]){ // while char not null
		if (s[c] >= 'A' && s[c] <= 'Z'){ // if uppercase
			s[c] = s[c]+32; // add 32 to make uppercase lowercase
		}
	c++; // increment location in array
	}
}

int check_anagram(char firstWord[], char secondWord[]){
	int first[26]={0}, second[26]={0}, i=0; // make array for 26 letters for both words and initialize counter
	while (firstWord[i]){ // while char not null
		first[firstWord[i]-'a']++;
		i++;
	}

	i = 0; // reinitialize counter
	while(secondWord[i] != '\0'){
		second[secondWord[i]-'a']++;
		i++;
	}

	for (i=0; i<26;i++){ // compare counts for each letter
		if (first[i] != second[i]){ // if counts NOT equal for some letter between firstWord and secondWord, is NOT an anagram
			return 1; // return 1 if NOT anagram
		}
	}
	return 0; // if all letter counts equal, is anagram, so return 0
} 

