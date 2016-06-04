#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#define true 1
#define false 0

typedef unsigned char boolean;

void escreve_boolean(FILE* arq, boolean* var);
void escreve_int(FILE* arq, unsigned int* var);
void escreve_float(FILE* arq, float* var);
void escreve_str(FILE* arq, char* str);
void le_boolean(FILE* arq, boolean* var);
void le_int(FILE* arq, unsigned int* var);
void le_float(FILE* arq, float* var);
void le_str(FILE* arq, char** str);

#endif