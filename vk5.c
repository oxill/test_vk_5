#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stddef.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

//#define PRINT
#ifdef PRINT
#define P(X) X;
#else 
#define P(X) ;
#endif

int end_of_enter(char *buffer)
{
  if(strcmp("exit",buffer)==0)
    return 1;
  else
    return 0;
}

int main(int argc, char *argv[])
{ 
   
  FILE* temp_file;  
  FILE* dictionary;  
  
  char ch, check, feof_flag;
  int prev, cur, buffer_size;
    
  if(argc == 2) {    
    if((dictionary = fopen(argv[1],"r")) == NULL) {
      printf("can't open file %s\n",argv[1]);
      return 0;
    }    
  }
  else {
    printf("enter:%s file name\n", argv[0]);
    return 0;
  }
  
  if (ferror(dictionary)) {
    P(printf("error"));
    return 0;
  }
 
  for(;;) 
  {         
    if(!(temp_file=fopen("temp_file.txt", "w"))) {
      P(printf("Open temp_file failed.\n"));
      return 0;
    }
      
    buffer_size = 0;
    P(printf("enter string:\n"));
    
    do {
      ch = getchar();
      putc(ch, temp_file);
      buffer_size++;
    } while(ch!='\n');

    fclose(temp_file);

    if(!(temp_file=fopen("temp_file.txt", "r"))) {
      P(printf("Open log_file failed.\n"));
      return 0;
    }
    
    char input_buffer[buffer_size];        
    fgets(input_buffer, sizeof(input_buffer), temp_file);                
    P(printf("input_buffer is %s\n", input_buffer));
    
    if(end_of_enter(input_buffer)) {            
      fclose(dictionary);
      fclose(temp_file);
      remove("temp_file.txt");
      break;      
    }  
            
    prev = 0, cur = 0, feof_flag = 0;
    rewind(dictionary);
    
    while(!(feof(dictionary)))
    { 
      buffer_size = 0;
      
      if(fseek(dictionary, cur, SEEK_SET)!=0) {
	P(printf("ERROR FSEEK FIRST");exit(1));
      } 

      do {
	ch = getc(dictionary);
	cur++;
	buffer_size++;
	if(feof(dictionary)==1) {
	  feof_flag=1;
	  break;
	}
      } while(ch!='\n');
            
      if(fseek(dictionary, prev, SEEK_SET)!=0) {
	P(printf("ERROR FSEEK SECOND");exit(1));	
      }
      
      prev=cur;
         
      char output_buffer[buffer_size];      
      fgets(output_buffer, sizeof(output_buffer), dictionary);      
      P(printf("output_buffer is %s\n", output_buffer));
	    
      if (strcmp(output_buffer,input_buffer) == 0) {
	check = 1;
	break;
      }
      else check = 0;
      
      if(feof_flag==1) break;
    }
    
    fclose(temp_file);
    if(check) printf("YES\n");
    else printf("NO\n");            
  }
return 0;
}
