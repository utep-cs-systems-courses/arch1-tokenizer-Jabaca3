#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include <string.h>
int main(){
  while(1){
    printf("\n$ ");
    char user_input[100];
    fgets(user_input, 200, stdin);
    printf("%s", user_input);
    printf("%i", count_words(user_input));
    /*
    char* word = "thanks";
    char* test = copy_str(word, 6);
    printf("%c", test);
    for(int i=0; i<6; i++){
      if(test[i] == '\0'){
      printf("%s", "char reached");
      }
      printf("%s", "not detected");
    }
    */
    char **tokens= tokenize(user_input);
    print_tokens(tokens);
  }
}