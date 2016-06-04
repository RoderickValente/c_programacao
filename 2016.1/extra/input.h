#ifndef _INPUT_H_
#define _INPUT_H_

void flush();
void ler_caractere(const char* prompt, char* var);
void ler_inteiro(const char* prompt, unsigned int* var);
void ler_string_dinamica(const char* prompt, char** var);
void ler_real(const char* prompt, float* var);

#endif