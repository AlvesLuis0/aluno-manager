#ifndef IO_H
#define IO_H

#include "lista.h"

void IO_ExportarLista(Lista*, char *caminho);
Lista* IO_ImportarLista(char *caminho);

#endif