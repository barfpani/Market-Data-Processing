#include"support.h"
#include<stdio.h>
#define MAX_LINE_LENGTH 100

int main(){
    
    // This file pointer opens your pre-existing CSV file in reading mode

    FILE *file = fopen("your_file.csv", "r");

    // Checking if the file is opened or not

    if (file == NULL){
        perror("error opening file\n");
        return 1;
    }
    
    // Reading from the CSV file and storing required content into our struct

    char line[MAX_LINE_LENGTH];
    Market_data data;
    while(fgets(line, sizeof(line), file)){
        if(parse_line(line, &data) == 6){
            printf("Timestamp: %ld, Symbol: %s, Bid: %2f, Ask: %2f\n", 
            data.timestamp, data.symbol, data.bid_price, data.ask_price);
        }
    }

    // obvious closing statement
    
    fclose(file);

    /*fprintf(file, "timestamp,symbol,bid_price,ask_price,bid_size,ask_size\n");

    //adding other rows

    fprintf(file, "1630453200000,AAPL,150.25,150.35,100,200\n");
    fprintf(file, "1630453200005,AAPL,150.30,150.40,110,190\n");
    fprintf(file, "1630453200015,AAPL,163.30,165.40,140,170\n");    
    
    printf("Data written to Market_data.csv successfully\n");*/

    return 0;
}