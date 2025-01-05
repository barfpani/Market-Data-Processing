#include"support.h"
#include<stdio.h>
#define MAX_LINE_LENGTH 200

int main(){
    
    // This file pointer opens our pre-existing CSV file in reading mode

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
        if(parse_line(line, &data) == 8){
            printf("Symbol: %s, Open: %lf, Close: %lf, LTP: %lf, Volume: %lf, Value: %lf\n", 
            data.symbol, data.OPEN, data.CLOSE, data.LTP, data.VOLUME, data.VALUE);
        }
        //printf("Parse_line returned: %d\n", parse_line(line, &data));
    }

    // obvious closing statement
    
    fclose(file);

    return 0;
}