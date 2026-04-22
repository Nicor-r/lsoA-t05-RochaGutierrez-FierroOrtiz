#ifndef HILOS_H
#define HILOS_H
#include <pthread.h>

#define NUM_LECTORES  60   // N > 50 
#define NUM_ESCRITORES 25  // M > 20 
#define NUM_OPS 2   // operaciones por hilo

extern pthread_mutex_t mutex; // protege rc
extern pthread_mutex_t db;    // protege la BD
extern int rc;                // lectores activos
extern int database;          // recurso compartido

void* reader(void* arg);    
void* writer(void* arg);      
void ejecutar_hilos();       

#endif