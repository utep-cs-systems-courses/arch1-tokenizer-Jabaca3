#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include <string.h>
#include "history.h"

int main(){
  List *history = init_history();
  while(1){

    //Getting user Input
    printf("\n$ ");
    char user_input[100];
    fgets(user_input, 200, stdin);

    
    //Checking user input for a history recall
    if(user_input[0] == 33 && (user_input[1] > 48 && user_input[1] < 58)){

      //Recalling history
      printf("%s\n", "--------recalling history!------------");
      int num = atoi(user_input+1);
      char* token = get_history(history, num);
      printf("%s%s\n","$ ", token);

      //Handeling user out of bounds errors
      if(strcmp(token,"Error") == 0){
	printf("%s\n", "Sorry you must have asked for an ID that is out of bounds");
	break;
      }
      
      //tokenizing history and printing
      char** tokenized = tokenize(token);
      print_tokens(tokenized);
    }

    //Creating history for user input
    else{
    char **tokens= tokenize(user_input);
    print_tokens(tokens);
    printf("%s\n", "---------adding history!---------------");
    char* copy = copy_str(user_input, strlen(user_input));
    add_history(history, copy); //works
    }
  }
}
