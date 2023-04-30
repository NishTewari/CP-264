#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"

void set_stopword(char *filename, char *stopwords[]) {
// your implementation, refer to class code example 22 -- csv file read with string value
	FILE *fp;
	int i = 0;
	char delimiters[] = " .,\n\t\r";
	char word_array[MAX_LINE_LEN];
	char *token;
	i = 0;
	if ((fp = fopen(filename, "r")) != NULL) {
		while (fgets(word_array, sizeof(word_array), fp) != NULL) {
			token = (char*) strtok(word_array, delimiters);
			i++;
			while (token != NULL) {
				i = (int) (*token - 'a');

				if (*stopwords[i] == '\0') {
					strcat(stopwords[i], ","); //set the first char
				}
				strcat(stopwords[i], token);
				strcat(stopwords[i], ",");
				token = (char*) strtok(NULL, delimiters);
			}
		}
	}
}

// this function check if word is a word in string str,
// returns 1 if yes, 0 otherwise
int contain_word(char *str, char *word) {
	if (str == NULL || word == NULL)
		return 0;
	// your code
	char temp[MAX_WORD] = { 0 };
	strcat(temp, ",");
	strcat(temp, word);
	strcat(temp, ",");
	if (strstr(str, temp)) {
		return 1;

	}

	return 0;
}
// this function check if the word is contained in directory stopwords[]
// returns 1 if yes, 0 otherwise. It use function contain_word()
int is_stopword(char *stopwords[], char *word) {
// your code
}

int process_word(char *filename, WORDSUMMARY *ws, char *stopwords[]) {
	const char delimiters[] = " .,;:!()&?-\n\t\r\"\'";
	// your implementation

}

int save_to_file(char *filename, WORDSUMMARY *ws) {
// your implementation
	FILE *fp;
	int i = 0;
	if ((fp = fopen(filename, "w")) != NULL) {
		fprintf(fp, "%-20s  %8d\n", "Line count", ws->line_count);
		fprintf(fp, "%-20s  %8d\n", "Word count", ws->word_count);
		fprintf(fp, "%-20s  %8d\n", "Keyword count", ws->keyword_count);

		fprintf(fp, "%-18s  %10s\n", "Keyword", "frequency");
		while (i < ws->keyword_count) {
			fprintf(fp, "%-20s  %8d\n", ws->word_array[i].word,
					ws->word_array[i].frequency);

			i++;
		}
	}
	return 0;
}
