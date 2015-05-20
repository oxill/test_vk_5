#include <stdio.h>
#define MAX_SIZE 9
int bsearch(char *arr, int n)
{
  int i, left = 0, right = MAX_SIZE, mid;
  while(left <= right)   
  {
    mid = left + (right - left) / 2;
    printf("mid %d\n",mid);
    if(n < arr[mid]) {
      right = mid - 1;
      printf("right %d\n",right);     
      if(right == -1) return -1;
    }
    else if(n > arr[mid]) {
      left = mid + 1;          
      printf("left %d\n",left);
      if(left == MAX_SIZE+1) return -1;
    }        
    else {
      for(i = mid;i <= MAX_SIZE;i++)
      { 
	if(i == MAX_SIZE) return 0;
	else if(arr[i] == arr[i+1]) continue;
	else return i+1;
      }
    }
  }
  return -1;
}

int main(int argc, char **argv)
{
  char arr[] = {10,20,30,30,40,50,60,60,60,70};
  int i, n, s;
  for(i=0;i<=MAX_SIZE;i++) 
    printf("%d ",arr[i]);
  
  printf("\nenter number:");
  scanf("%d",&n);
  
  s = bsearch(arr, n);
  if(s == -1) printf("array doesn't have this number\n");
  else if(s == 0) printf("it's last number\n");
  else printf("first index is %d\n", s);
  return 0;
}
