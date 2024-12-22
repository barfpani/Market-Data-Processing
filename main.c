#include"support.h"
#include<stdio.h>
#define MAX_LINE_LENGTH 200

int main(){
    
    // This file pointer opens our pre-existing CSV file in reading mode

    FILE *file = fopen("stocks.csv", "r");

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
            printf("Inside the 'if' statement");
            printf("Symbol: %s, Open: %2f, Close: %2f, LTP: %2f, Volume: %2f, Value: %2f\n", 
            data.symbol, data.open, data.close, data.LTP, data.volume, data.value);
        }
    }

    // obvious closing statement
    
    fclose(file);

    return 0;
}