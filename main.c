#include<stdio.h>
// basic opening and writing of a CSV file in C 
int main(){
    
    // this open the file for writing, if the file doesn't exist
    // then it creates one and opens it in writing mode.

    FILE *file = fopen("market_data.csv", "w");

    //Checking if the file is opened or not
    if (file == NULL){
        perror("error opening file");
        return 1;
    }
    
    //CSV Header

    fprintf(file, "timestamp,symbol,bid_price,ask_price,bid_size,ask_size\n");

    //adding other rows

    fprintf(file, "1630453200000,AAPL,150.25,150.35,100,200\n");
    fprintf(file, "1630453200005,AAPL,150.30,150.40,110,190\n");
    fprintf(file, "1630453200015,AAPL,163.30,165.40,140,170\n");    
    
    printf("Data written to Market_data.csv successfully\n");
    return 0;
}