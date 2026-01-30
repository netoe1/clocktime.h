// Copyright 2026 ELy Torres Neto
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
//
// CUSTOM DETAILS:
// Patenting this program is prohibited. Patent rights belong exclusively to the creator, in this case, Ely Torres Neto (netoe1) or Vertex Project.
// You may use it freely, both for proprietary and open-source projects.
//
// Sincerely,
// Ely Torres Neto - Vertex Project

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/clocktime.h"

#pragma region conts
#define UNDEFINED -1
#define TO_SUM_YEAR 1900
#define TO_SUM_MON 1
#pragma endregion conts
/*--------------------*/
#pragma region structs

#pragma endregion structs
/*--------------------*/
#pragma region implementation

CDATE_Date getDateNow()
{
    CDATE_Date convert;
    time_t currentTime = time(&currentTime);
    struct tm *localTime = localtime(&currentTime);
    convert.day = localTime->tm_mday;
    convert.month = localTime->tm_mon + TO_SUM_MON;
    convert.year = localTime->tm_year + TO_SUM_YEAR;
    convert.hour = localTime->tm_hour;
    convert.min = localTime->tm_min;
    convert.sec = localTime->tm_sec;
    return convert;
}
pDATE getDateAsString()
{
    time_t currentTime;
    time(&currentTime);

    // Convert time to the tm structure
    struct tm *localTime = localtime(&currentTime);

    // Allocate space for the formatted date string
    char *formattedDate = (char *)malloc(11 * sizeof(char)); // 10 characters for the date + 1 for the null terminator

    // Check if the allocation was successful
    if (formattedDate == NULL)
    {
        fprintf(stderr, "[clocktime-runtime-err]: Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }

    // Adjust month and year as needed
    localTime->tm_mon += TO_SUM_MON;
    localTime->tm_year += TO_SUM_YEAR;

    // Format the date string
    snprintf(formattedDate, 11, "%02d/%02d/%d", localTime->tm_mday, localTime->tm_mon, localTime->tm_year);

    return formattedDate;
}
pDATE getFullDateAsString()
{
    CDATE_Date dateNow = getDateNow();

    char *ret = (char *)malloc(22 * sizeof(char *));

    sprintf(ret, "%02d/%02d/%d %02d:%02d:%02d", dateNow.day, dateNow.month, dateNow.year, dateNow.hour, dateNow.min, dateNow.sec);
    return ret;
}
#pragma endregion implementation
