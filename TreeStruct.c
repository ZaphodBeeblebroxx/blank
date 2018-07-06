#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct profile_tree_node{

char fName[50];
char lName[50];
int age;
struct profile_tree_node *parent;
struct profile_tree_node *children[10];
int childCount;


      };
struct profile_tree_node *get_adam(struct profile_tree_node * any){

  struct profile_tree_node *result;
  result = any;
  if(result->parent!=NULL){

    return result;


  }


}

struct profile_tree_node *search_name(char * name, int option, struct profile_tree_node * base){

  struct profile_tree_node *result;







}
struct profile_tree_node *createTreePointer(char * fName, char * lName, int age){

  struct profile_tree_node *node;
  node = malloc(sizeof(struct profile_tree_node));
  strcpy((*node).fName, fName);
	strcpy((*node).lName, lName);
	(*node).age = age;
  (*node).age = 0;
  (*node).parent = NULL;
  for(int i = 0; i < 10; i++){
  (*node).children[i] = NULL;

}







  return node;

      }

      void childTo(struct profile_tree_node *parent, struct profile_tree_node *child){
int *i;
i = malloc(sizeof(int));
*i = parent->childCount-1;
        parent->children[*i] = child;
        child->parent = parent;
        int *y;
        y = malloc(sizeof(int));
        *y = parent->childCount+1;
        parent->childCount = *y;



      }

      void childMultiple(struct profile_tree_node *parent, struct profile_tree_node *children[]){

for(int i = 0; i <10; i++){
if(children[i]==NULL){
break;

}
childTo(parent, children[i]);


}




      }

void test_one(){

  struct profile_tree_node *root = createTreePointer("John", "Smith", 76);
  struct profile_tree_node *john[10];
  struct profile_tree_node *jerry[10];
  john[0] = malloc(sizeof(struct profile_tree_node)*10);
    jerry[0] = malloc(sizeof(struct profile_tree_node)*10);
  struct profile_tree_node *one_one = createTreePointer("Thurman", "Smith", 34);
  struct profile_tree_node *one_two = createTreePointer("Jerry", "Smith", 46);
  struct profile_tree_node *one_three = createTreePointer("Rachel", "Smith", 46);
  john[0] = one_one;
  john[1] = one_two;
  john[2] = one_three;
 childMultiple(root, john);
  struct profile_tree_node *two_one = createTreePointer("Jean", "Westwood", 16);
  jerry[0] = two_one;

  struct profile_tree_node *two_two = createTreePointer("John", "Smith", 26);
  jerry[1] = two_two;
  childMultiple(one_two, jerry);
  for(int i =0; i < root->childCount; i++){
printf("\n%s\n", root->children[i]->fName);

  }



}


int main(){

test_one();


}