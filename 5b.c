#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHARS 256 

typedef struct trienode{
  struct trienode * letters[MAX_CHARS];
  bool terminal;
}NODE;

NODE* createNode(){
  NODE* newNode = malloc(sizeof(NODE));

  for(int i = 0 ; i<MAX_CHARS ; i++ ){
    newNode->letters[i] = NULL;
  }
  newNode->terminal = false;
  return newNode;

}

bool insertTrie(NODE** root , char* signedText){
  
  if(*root==NULL){
    *root = createNode();
  }
  
  unsigned char* text = (unsigned char *) signedText; // prevents local bounds issues cuz ascii +  negative numbers ,  ascii being used as index is not good ,  hence unsigned for making ti usable across devices

  NODE* temp = *root;
  int length = strlen(signedText);

  for(int i = 0 ;  i<length ; i++){
    if(temp->letters[text[i]] == NULL){   // checking if the letter exists or not , if it doesnt then it creates a newNode for that letter
      temp->letters[text[i]] = createNode();
    }
    temp = temp->letters[text[i]];  // if it already exists then why make new node just go to node 
  }

  if(temp->terminal){
    return false;
  }
  else{
    temp->terminal = true ;
    return true;
  }
}

void printTrieRec(NODE* node,unsigned char* prefix ,int length){// prefix tells the letters that has been parsed through
  
  unsigned char newPrefix[length+2];  // why +2 ?   because we need to add the current symbol to the word and also add a null charector ;
  memcpy(newPrefix , prefix , length);  // mempy copies the current prefix to the newPrefix and length specifies the sizze it needs to copy;
  newPrefix[length+1]=0;

  if(node->terminal){   // in cases of word like CAT and CATTLE there maybe letters after CAT's T so we print CAT and then continue to parse through
    printf("WORD : %s\n",prefix);
  }
  
  for(int i =0 ; i<MAX_CHARS ; i++){
    if(node->letters[i] != NULL){
      newPrefix[length] = i ;
      printTrieRec(node->letters[i],newPrefix , length+1);
  } // this part goes through if theres anymore words to be formed ;
}
}

void printTrie(NODE* root){
  if(root == NULL){
    printf("TRIE IS EMPTY");
    return;
  }
  printTrieRec(root , NULL , 0);

}

int main(){
  NODE* root = NULL;

  insertTrie(&root,"KAT");
  insertTrie(&root,"KITKAT");
  insertTrie(&root,"CAT");
  insertTrie(&root,"CATTLE");
  insertTrie(&root,"FINALLY");
  insertTrie(&root,"TRIES");
  insertTrie(&root,"OVER");
  printTrie(root);
  
  return 0;
}
