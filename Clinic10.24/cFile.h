#ifndef CFILE_H
#define CFILE_H

#include"cData.h"
#include"cTool.h"
#include "cList.h"

FILE * file_open(char * filepath);

void writeAccFile(LIST * head,FILE * fp);

void writeDocFile(LIST * head,FILE * fp);

void writeClaFile(LIST * head,FILE * fp);

LIST * readAccFile(FILE * fp);

LIST * readDocFile(FILE * fp);

LIST * readClaFile(FILE * fp);

#endif