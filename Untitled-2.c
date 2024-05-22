
void countCharactersAndWords(const char *filename, int *charCount, int *wordCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int c;
    int inWord = 0;
    *charCount = 0;
    *wordCount = 0;
	while ((c = fgetc(file)) != EOF) {
        (*charCount)++;
        
        if (c == ' ' || c == ',' || c == '\n' || c == '\t') {
            if (inWord) {
                (*wordCount)++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
    }

    if (inWord) {
        (*wordCount)++;
    }

    fclose(file);
}
int main() {
    const char *filename = "test.txt";
    int charCount, wordCount;

    countCharactersAndWords(filename, &charCount, &wordCount);

    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);

    return 0;
}