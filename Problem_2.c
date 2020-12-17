#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define row1 10//stores how long row1 will be 
#define row2 5//stores how long row2 will be 
#define row3 2//stores how long row3 will be 
#define row4 7//stores how long row4 will be 
#define row5 6//stores how long row5 will be 
float* create50floats();//function prototype for randomly generating 50 floats from 0 to 100
float* allocate(int num); //function prototype for allocating space
float* put_in(float* k,int start,int end); //function prototype for getting a chunk of of an array 
void printg(float* k,int len);//function prototype for printing an array
float** sort_sel(float** k,int rownum);//function prototype for sorting an array via selection sort
float** sort_ins(float** k,int rownum);//function prototype for sorting an array via insertion sort
int main(void) {
  float* numbers=create50floats(); //creating an one dimisonal array and using the create50floats() function to put 50 random generated numbers in it.
  float** ragged_arry=(float**)calloc(5, sizeof(float*)); //creating an two dimisonal array to store the ragged array
  ragged_arry[0]=put_in(numbers,1,10);  
  ragged_arry[1]=put_in(numbers,11,5);
  ragged_arry[2]=put_in(numbers,16,2);
  ragged_arry[3]=put_in(numbers,18,7);
  ragged_arry[4]=put_in(numbers,25,6);
  printf("Original:\n");
  printg(ragged_arry[0], row1);
  printg(ragged_arry[1], row2);
  printg(ragged_arry[2], row3);
  printg(ragged_arry[3], row4);
  printg(ragged_arry[4], row5);
  printf("\n");
  printf("Sorted:\n");
  ragged_arry=sort_sel(ragged_arry,0);
  ragged_arry=sort_ins(ragged_arry,1);
  ragged_arry=sort_sel(ragged_arry,2);
  ragged_arry=sort_ins(ragged_arry,3);
  ragged_arry=sort_sel(ragged_arry,4);
  ragged_arry=sort_ins(ragged_arry,5);
  ragged_arry=sort_sel(ragged_arry,6);
  ragged_arry=sort_ins(ragged_arry,7);
  ragged_arry=sort_sel(ragged_arry,8);
  ragged_arry=sort_ins(ragged_arry,9);
  printg(ragged_arry[0], row1);
  printg(ragged_arry[1], row1);
  printg(ragged_arry[2], row1);
  printg(ragged_arry[3], row1);
  printg(ragged_arry[4], row1);
  free(ragged_arry);
  free(numbers);
  return 0;
}

float* allocate(int num){
return (float*)calloc(num, sizeof(float));
}

float* put_in(float* k,int start,int end){
  start-=1;
  float* numbers=allocate(row1);
  for(int i=start;i<start+end;i++){
  numbers[i-start]=k[i];
  }
  return numbers;
}

float* create50floats(){
  srand(time(NULL));
  float* numbers=(float*)calloc(50, sizeof(float)); //creating an array of 50 floats
  for(int i=0;i<50;i++){
  numbers[i]=((float)(rand()%(1000-1)+1)*.1);
  }
return numbers;
}
void printg(float* k,int len){
  for(int i=0;i<len;i++){
    if(k[i]!=0){
    printf("%.1f ",k[i]);
    }
  }
  printf("\n");  
}
float** sort_sel(float** k,int rownum){
int min=0; //storing the position of the current least number
float temp=0.0; //storing the current least number 
for(int i = 0; i <5; i++){
min=i;
for(int j = i+1; j <5; j++){
if(k[j][rownum] < k[min][rownum]){
min=j;
}
}
if(min!=i){
  temp=k[min][rownum];
  k[min][rownum]=k[i][rownum];
  k[i][rownum]=temp;
}
}

return k;  
}
float** sort_ins(float** k,int rownum){
   float ins; //storing the current insert number
   int hp; //storing the current position of the hole
   
  
   for(int i = 1; i < 5; i++) { 
	 
      ins = k[i][rownum];
		
     hp = i;
		
      while (hp > 0 && k[hp-1][rownum] > ins) {
         k[hp][rownum] = k[hp-1][rownum];
         hp--;
         
      }

      if(hp != i) {
         k[hp][rownum] = ins;
      }

   }  

  return k;
}   
  
