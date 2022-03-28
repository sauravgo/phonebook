#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 



void listAll() {
char line[30] ;
FILE *f ;
    f = fopen("phonebook.txt" , "r+") ;
     while(1) {
         fscanf(f , "%s" , &line) ;
         printf("\n %s" , line ) ; 

      if(feof(f)) {
          break ; 
      }

     }//while


}

int save(char name[20] , char number[12]) {
    printf("\n saving.... ") ;
    printf( "\n %s=%s" , name , number ) ;
    FILE *f ;
    f = fopen("phonebook.txt" , "a") ;
    fprintf(f , "\n %s=%s" , name , number ) ;
    fclose(f) ; 


return 1 ; 
}

void searchIt(char keyword[20]) {

   char line[30] ; 
   char nme[20] ;
   char reset[20] ; 
   FILE *f ;
    f = fopen("phonebook.txt" , "r+") ;
     while(1) {
         fscanf(f , "%s" , &line) ;
         //spliting 
         for(int f=0 ; f < strlen(line) ; f++) {
             if (line[f] == '=') {
                 break ;
             }else {
               nme[f] = line[f] ; 
               
             }
             
         }
         //printf("\n %s " , nme ) ;
         int l = strlen(nme) ;
         nme[l]='\0' ; 
         //printf("\n %s = %s " , nme , keyword ) ; 
        if(strcmp(nme , keyword) == 0 ) {
            printf("\n %s " , line ) ;
        } 
        // printf("\n %s" , line ) ;
         if(feof(f)) {
             break ;
         }
       
   for(int j=0 ; j< strlen(line) ; j++) {
       nme[j]='\0' ; 
   }
printf("\n %s " , nme) ;
     }//end of while 

  fclose(f) ;

}



int main() {

    char number[12] ;
    char name[20] ;
    char keyword[20] ;

int option ;
printf("\n ******************************************");
printf("\n            DIVA'S PHONEBOOK               ");
printf("\n ******************************************\n");
printf("\n This program is free to share modify and distribute \n created by Diva(R) Chandannagar , Hooghly \n Licensed under GNU GPL v2\n") ; 

 printf("\n 1 to add New Contact \n 2 to Display all \n 3 to Serach by Name \n 4  to exit ") ;
 scanf("%d" , &option ) ;

 switch(option){
     case 1:printf("\n Input name ") ; scanf("%s" , &name ) ;
            printf("\n Input Number ") ; scanf("%s" , &number) ;
            int r = save(name , number) ;
            if(r==1) {
            printf("\n Saved ");
            }else {
            printf("\n Not saved ") ; 
            } ;
            break ;
     case 2: listAll() ;
     break ;
     case 3: printf("\n Type a name to search ") ;
            scanf("%s" , &keyword) ;
            searchIt(keyword) ;     
     break ;
     case 4: exit(0) ;
     break ;
     default: printf("\n Wrong Input ") ;          
 }
    
   
    
    
    
    

    
    



    return 0 ; 
}