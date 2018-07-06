#include <stdio.h>
#include <stdlib.h>


int lengthOfLongestSubstring(char* s) {
    int * answer;
    int * leng;
    leng = malloc(sizeof(int));
    answer = malloc(sizeof(int));
    char *current;
    char * last;
    int * streak;
    streak = malloc(sizeof(int));
    current = malloc(sizeof(char));
    last = malloc(sizeof(char));
    *leng = strlen(s);
    char * cheat[*leng];
    cheat[0] = malloc(sizeof(char));
    strcpy(s, cheat);
      *last = '-';
      int * hiScore;
      hiScore = malloc(sizeof(int));
    *hiScore = 0;
    
    for(int i = 0 ; i< *leng; i++){
        
     current =   cheat[i];
        
         
         if(*current==*last){
             
             *streak = 1;
             
             
         }
        else{
            *streak = *streak + 1;
            
        }
        
        last = current;
        
        
        if(*streak>*hiScore){
hiScore = streak;

        }


    }
    
    
    
    return hiScore;
    
    
    
    
    
    
}

int main(){
char * f[50];
f[0] = malloc(sizeof(char)*50);
 *f= "bcabcbb";
int x = lengthOfLongestSubstring(f);

printf("%d", x);

}