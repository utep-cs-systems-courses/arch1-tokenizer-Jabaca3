#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include <string.h>
#include "history.h"

int main(){
  List *history = init_history();
  while(1){
    printf("\n$ ");
    char user_input[100];
    fgets(user_input, 200, stdin);
    if(user_input[0] == 33 && user_input[1] == 51){
      printf("%s\n", "recalling history!");
      int num_selected = atoi(user_input+1);
      char* token = get_history(history, num_selected);
      char** tokenized = tokenize(token);
      print_tokens(tokenized);
      free_tokens(tokenized);
    }
    else{
    printf("%s\n", user_input);
    char **tokens= tokenize(user_input);
    print_tokens(tokens);
    printf("%s\n", "adding history!");
    char *copy =copy_str(user_input, strlen(user_input));
    add_history(history, copy);
    free_tokens(tokens);
    }
  }
}
