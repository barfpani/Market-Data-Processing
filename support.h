// This file contains all the functions and decalrations

#ifndef SUPPORT_H  //checks if the main.h is defined or not
#define SUPPORT_H  //defines main.h if it's not defined
#include "string.h"
#include <stdio.h>
// A typed defined struct which holds all the important info
// which you need, this cna be edited as per you requirement

typedef struct {        
    long timestamp;
    char symbol[10];
    float bid_price;
    float ask_price;
    int bid_size;
    int ask_size;

}Market_data;

// This function parse lines from a CSV file to the Market_data struct

int parse_line(const char *line, Market_data *data){
    return sscanf(line, "%ld,%[^,],%f,%f,%d,%d",
                  &data->timestamp,
                  data->symbol,
                  &data->bid_price,
                  &data->ask_price,
                  &data->bid_size,
                  &data->ask_size);
}
#endif