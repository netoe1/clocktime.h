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


#ifndef CLOCKTIME_H
#define CLOCKTIME_H

#pragma region namespaces

typedef char *pDATE;
#define CDATE_free(pdate) free(pdate)

#pragma endregion namespaces

#pragma region structs

typedef struct
{
	int day;
	int month;
	int year;
	int hour;
	int min;
	int sec;
} CDATE_Date;

#pragma endregion structs

#pragma region functions

CDATE_Date getDateNow();
pDATE getDateAsString(); // Dinamic ptr allocation, free memory with CDATE_free() or free() function availble in stdlib.h namespace.
pDATE getFullDateAsString();	 // Dinamic ptr allocation, free memory with CDATE_free() or free() function availble in stdlib.h namespace.

#pragma endregion functions

#endif
