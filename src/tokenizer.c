#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include <string.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  if(c =='\t' || c ==' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c =='\t' || c ==' ' || c=='\0'){
    return 0;
  }
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char* word_start(char *str){
  
  while(non_space_char(*str) && *str != '\0'){
      str++;
  }
  while(space_char(*str) && *str != '\0'){
      str++;
  }
  return str;
}

char *word_terminator(char *word){
  int i=0;
  while(word[i] != ' '){
    i++;
  }
  return word+i;
}

int word_count;
int count_words(char *str){
  int i =0;
  word_count=0;
  while(str[i] != '\0'){
    while(space_char(*(str+i))){
      i++;
    }
    if(non_space_char(*(str+i))){
      word_count++;
    }
    while(non_space_char(*(str+i))){
      i++; 
    }
  }
  return word_count;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *strCopy= (char*)malloc(sizeof(char)*len+1);
  for(int i=0; i<len; i++){
    strCopy[i]= inStr[i];
  }
  strCopy[len] = '\0';
  return strCopy;
}


char **tokenize(char* str){
  
  int total_words = count_words(str)+1;
  char** tokens = (char **)malloc(sizeof(char*) * (total_words));
  char* word_holder = str;
  char* end_of_word;
 
  int i=0;
  while(i < total_words){
    end_of_word = word_terminator(word_holder);
    word_holder = copy_str(word_holder, end_of_word - word_holder);
    tokens[i] = word_holder;
    word_holder = word_start(end_of_word);
    i++;
  }
  tokens[i] = NULL;
  return tokens;
}

void print_tokens(char **tokens){
  int i=0;
  while (i < word_count){
    printf("%s\n", tokens[i]);
    i++;
  }
}

void free_tokens(char ** tokens){
  int i =0;
  while(i<=word_count+1){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}





