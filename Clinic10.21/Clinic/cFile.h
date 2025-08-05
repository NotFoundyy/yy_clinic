#ifndef CFILE_H
#define CFILE_H

#include"cData.h"
#include"cTool.h"
#include "cList.h"

FILE * file_open(char * filepath);

void writeFile(LIST * head,FILE * fp);

LIST * readAccFile(FILE * fp);

LIST * readDocFile(FILE * fp);

LIST * readClaFile(FILE * fp);

#endif