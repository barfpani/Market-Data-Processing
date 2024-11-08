// This program is for creating a personalised CSV file
 
#include<stdio.h>
int main(){

FILE *file = fopen("testing.csv", "w");

if(file == NULL){
    perror("file not opened");
    return 1;
}

fprintf(file, "timestamp,symbol,bid_price,ask_price,bid_size,ask_size,marketcap(in crore),owner\n");

    //adding other rows

    fprintf(file, "1630453200000,AAPL,150.25,150.35,100,200,7.25,Sanchit\n");
    fprintf(file, "1630453200005,AAPL,150.30,150.40,110,190,26.58,Rachit\n");
    fprintf(file, "1630453200015,AAPL,163.30,165.40,140,170,11.25,Saad\n");    
    
    printf("Data written to testing.csv successfully\n");


return 0;

}
