NODE* delete(NODE* root, int data){
  if (data < root-> data ) return delete(root->left , data);
  else if (data > root-> data ) return delete(root->right , data);
  else {
   if(root->left == NULL && root->right == NULL){
      free(root);
      root=NULL;
   }
   else if(root->left == NULL){
    NODE* temp = root;
    root = root->right;
    free(temp);
   }
   else if(root->right == NULL){
    NODE* temp = root;
    root = root->left;
    free(temp);
   }
   else{
    NODE* temp =  findMax(root->left);
    root->data = temp->data;
    root->left = delete(root->left , temp->data);
   }
  }
return root;
}
