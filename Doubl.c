#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct ProfilePointer {
 
char fName[50];
char lName[50];
int age;
struct ProfilePointer *next;
struct ProfilePointer *previous;
};
 
struct ProfilePointer *create_profile_pointer(char * fName, char * lName, int age){
 
    struct ProfilePointer *temp;
    temp = (struct ProfilePointer *) malloc(sizeof(struct ProfilePointer));
    
    strcpy((*temp).fName, fName);
    strcpy((*temp).lName, lName);
    (*temp).age = age;
    (*temp).next = NULL;
    (*temp).previous = NULL;
    return temp;
 
}  if (option == 1) {
         blank = current->fName;
     } else if (option == 0) {
         blank = current->lName;
     }
 
     if (strcmp(name, blank) == 0) {
 
         return current;
 
     }

struct ProfilePointer *search_by_age(int age, struct ProfilePointer *beg) {
  
    struct ProfilePointer *cur;
    cur = beg;

 if((!(age < cur->age) && !(age > cur->age))){

     return cur;



 }


 search_by_age(age, beg->next);
   
    return NULL;
 
}


struct ProfilePointer *search_by_name(char *name,
     struct ProfilePointer *beginning, int option) {
 
 struct ProfilePointer *current;
      char* blank;

        if (option == 1) {
         blank = current->fName;
     } else if (option == 0) {
         blank = current->lName;
     }
 
     if (strcmp(name, blank) == 0) {
 
         return current;
 
     }


   
 
 
 blank = search_by_name(name, beginning->next, option);
 
 return blank
 ;
 
}
 
void insert_by_name(struct ProfilePointer *begin,
        struct ProfilePointer *inserting, char *name, int option) {
 
    struct ProfilePointer *found;
 
    found = search_by_name(name, begin, option);
    struct ProfilePointer *after;
    if (found != NULL) {
 
        after = found->next;
        inserting->next = after;
    after->previous = inserting;
        found->next = inserting;
    inserting->previous = found;
 
    }
}
 
 
 
struct ProfilePointer *create_pointer_list(int list_size) {
 
    struct ProfilePointer *begin = NULL;
    struct ProfilePointer *end = NULL;
    struct ProfilePointer *current = NULL;
 
    char fName[20];
    char lName[20];
 
    for (int x = 0; x < list_size; x++) {
 
        sprintf(fName, "first%d", x);
        sprintf(lName, "last%d", x);
        current = create_profile_pointer(fName, lName, x);
 
 
        if (begin == NULL) {
 
            begin = current;
 
        }
        if (end == NULL) {
 
            end = current;
 
        } else {
 
            end->next = current;
            current->previous = end;
            end = current;
 
        }
 
    }
 
    return begin;
 
}
 
 
 
 
void print_each(struct ProfilePointer *begin) {
 
    struct ProfilePointer *current = NULL;
    if (begin == NULL) {
        printf("The Starting node is nonexistent");
        return;
 
    }
    for (current = begin; current != NULL; current = current->next) {
 
        if(current->fName[0]==0 && current->lName[0]==0){
            return;
        }
        printf("\n name : %s %s", current->fName, current->lName);
        printf("\n age  : %d \n \n", current->age);
 
    }
 
}
 
 
void addToSize(struct ProfilePointer *head, int additions){
 
struct ProfilePointer *end;
struct ProfilePointer *cur;
 
 
for(cur = head; cur != NULL; cur = cur->next){
 
if(cur->next==NULL){
 
    end = cur;
 
}
 
 
}
char fn[30];
char ln[30];
 
 
 
struct ProfilePointer *past = NULL;
struct ProfilePointer *tempo = NULL;
 
int i;
struct ProfilePointer *begin = NULL;
 
struct ProfilePointer *current = NULL;
 
for(i = 0;i<additions;i++){                    
    if(current!=NULL){
past= current;}
 
 
sprintf(fn, "additionfname%d", i);
sprintf(ln, "additionlname%d", i);
 
tempo = create_profile_pointer(fn,ln, i);
 
current = tempo;
if(i==0){
    end->next = current;
    current->previous = end;
 
}
 
if(past!=NULL||i>0){
 
    past->next = current;
    current->previous = past;
 
}
 
}
 
 
 
 
}
 
 
//IN REGARDS TO PREVIOUS, NOT CURRENT *****
void delete_general(struct ProfilePointer *rightbefore) {
 
    struct ProfilePointer *demo = rightbefore;
    if (rightbefore->next != NULL) {
        struct ProfilePointer *a = rightbefore->previous;
        struct ProfilePointer *b = rightbefore->next;
 
        a->next = b;
        b->previous = a;
 
    }
    if (rightbefore->next == NULL) {
    }
    if (rightbefore == NULL) {
        printf("finland");
    }
    free(demo);
 
}
 



void delete_bulk(int request, struct ProfilePointer *head){
 
for(int i = 0; i< request; i++){
 
delete_general(head->next);
 
 
}
}
 
void delete_by_age(struct ProfilePointer *begin, int age) {
    struct ProfilePointer *look_up;
    look_up = search_by_age(age, begin);
 
    if (look_up != NULL) {
 
        delete_general(look_up);
 
    }
    delete_general(look_up);
 
}
void delete_by_name(struct ProfilePointer *begin, char *name, int option) {
 
    struct ProfilePointer *look_up;
    look_up = search_by_name(name, begin, option);
    if (look_up != NULL) {
 
        delete_general(look_up);
 
    } else {
        printf("yarg");
 
    }
 
}
 
 
void tester(){
 
 
struct ProfilePointer *it;
it = create_pointer_list(5);
addToSize(it,  5);
struct ProfilePointer *insert;
insert = create_profile_pointer("John", "Blart", 19);
 
insert_by_name(it, insert, "additionfname1", 1);
delete_by_name(it, "first3", 1);
print_each(it);
delete_bulk(3, it);
 
 
 
}
 
 
 
 
 int main(int argc, char const *argv[]) {
 
 
 
tester();
 
}