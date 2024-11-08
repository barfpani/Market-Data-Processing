#include"support.h"
#include<stdio.h>
#define MAX_LINE_LENGTH 100

int main(){
    
    // This file pointer opens your pre-existing CSV file in reading mode

    FILE *file = fopen("testing.csv", "r");

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
            printf("Timestamp: %ld, Symbol: %s, Bid: %2f, Ask: %2f, Bid_Size: %d, Ask_Size: %d, Market Cap: %2f, Owner: %s\n", 
            data.timestamp, data.symbol, data.bid_price, data.ask_price, data.bid_size, data.ask_size, data.cap, data.owner);
        }
    }

    // obvious closing statement
    
    fclose(file);

    return 0;
}