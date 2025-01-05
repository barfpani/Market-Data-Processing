// This file contains all the functions and decalrations

#ifndef SUPPORT_H  //checks if the main.h is defined or not
#define SUPPORT_H  //defines main.h if it's not defined
#include "string.h"
#include <stdio.h>
// A typed defined struct which holds all the important info
// which you need, this can be edited as per you requirement

typedef struct {        
    //long timestamp;
    char symbol[15];
    //char owner[20];
    double OPEN;
    double CLOSE;
    double LTP;
    double VOLUME;
    double VALUE;


}Market_data;

// This function parse lines from a CSV file to the Market_data struct

int parse_line(const char *line, Market_data *data){
    return sscanf(line, "%[^,],%lf ,%lf ,%lf ,%lf ,%lf",
                  //&data->timestamp,
                  data->symbol,
                  &data->OPEN,
                  &data->CLOSE,
                  &data->LTP,
                  &data->VOLUME,
                  &data->VALUE
                );
}
#endif