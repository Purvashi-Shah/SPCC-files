#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LINE_LENGTH 1024
typedef enum {
 KEYWORD,
 HEADER_FILE,
 SYMBOL,
 COMMENT,
 IDENTIFIER,
 PREPROCESSOR_DIRECTIVE,
 VARIABLE
} TokenType;
void identifyToken(const char *token) {
 // Add more sophisticated logic based on the
context
 // This is a simplified example
 // Check for keywords
 const char *keywords[] = {"int", "float", "char",
"if", "else", "while", "for", "return"};
int i; // Move the declaration outside
for (i = 0; i < sizeof(keywords) /
sizeof(keywords[0]); i++) {
 if (strcmp(token, keywords[i]) == 0) {
 printf("Keyword: %s \n", token);
 return;
 }
}
// Check for string literals
 if (token[0] == '"' && token[strlen(token) - 1] ==
'"') {
 printf("String Literal: %s\n", token);
 return;
 }
 // Check for header files
 if (strncmp(token, "<", 1) == 0 && strstr(token,
".h>")) {
 printf("Header File: %s \n", token);
 return;
 }
 // Check for symbols
 const char *symbols = "+-*%=<>&;|(){}";
 if (strchr(symbols, token[0]) != NULL) {
 printf("Symbol: %s \n", token);
 return;
 }
 // Check for comments
 if (strncmp(token, "//", 2) == 0 ||
strncmp(token, "/*", 2) == 0) {
 printf("Comment: %s \n", token);
 return;
 }
 // Check for preprocessor directives
 if (token[0] == '#') {
 printf("Preprocessor Directive: %s \n",
token);
return;
 }
 // Check for variables/identifiers
 if (isalpha(token[0]) || token[0] == '_') {
 printf("Identifier: %s \n", token);
 return;
 }
}
int main() {
 char filename[100];
 FILE *sourceFile;
 char line[MAX_LINE_LENGTH];
 printf("Enter the filename: ");
 scanf("%s", filename);
 sourceFile = fopen(filename, "r");
 if (sourceFile == NULL) {
 fprintf(stderr, "Error opening file '%s'\n",
filename);
 return 1;
 }
 // Read the file line by line and identify tokens
in each line
 while (fgets(line, MAX_LINE_LENGTH,
sourceFile) != NULL) {
 // Remove newline character from the end
of the line
 line[strcspn(line, "\n")] = '\0';
 char *token = strtok(line, " \t\n");
 while (token != NULL) {
 identifyToken(token);
 token = strtok(NULL, " \t\n");
 }
 }
 fclose(sourceFile);
 return 0;
}

-------------------------
sample:
#include <stdio.h>
int main() {
 printf ( "Purvashi_Shah" ) ;
 return 0;
}
