#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "hilos.h"


pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t db    = PTHREAD_MUTEX_INITIALIZER;
int rc       = 0;
int database = 0;


void* reader(void* arg) {
    int id = *(int*)arg;
    srand(time(NULL) ^ (id * 67891)); // Semilla diferente para cada hilo lector
    for (int op = 0; op < NUM_OPS; op++) {
        sleep((rand() % 3) + 1); // Simula tiempo de lectura
        pthread_mutex_lock(&mutex);
        rc++;
        if (rc == 1){
            pthread_mutex_lock(&db);   
        }
        pthread_mutex_unlock(&mutex);
        printf("[Lector  %d | op %d] LEYENDO   -> database = %d\n",id, op + 1, database);
        pthread_mutex_lock(&mutex);
        rc--;
        if (rc == 0){
            pthread_mutex_unlock(&db); 
        }
        pthread_mutex_unlock(&mutex);
    }
    printf("[Lector  %d] Finalizado.\n", id); 
    pthread_exit(NULL);                        
}


void* writer(void* arg) {
    int id = *(int*)arg; 
    srand(time(NULL) ^ (id * 67891)); // Semilla diferente para cada hilo escritor
    for (int op = 0; op < NUM_OPS; op++) {
        sleep((rand() % 3) + 1); // Simula tiempo de escritura
        int nuevo = rand() % 1000; // Nuevo valor para la base de datos
        pthread_mutex_lock(&db);
        database = nuevo;
        printf("[Escritor %d | op %d] ESCRIBIO  -> database = %d\n",id, op + 1, database);
        pthread_mutex_unlock(&db);
    }
    printf("[Escritor %d] Finalizado.\n", id);
    pthread_exit(NULL);
}

void ejecutar_hilos() {
    pthread_t lectores[NUM_LECTORES];
    pthread_t escritores[NUM_ESCRITORES];
    int idEscritores[NUM_ESCRITORES];
    int idLectores[NUM_LECTORES];

    for (int i = 0; i < NUM_ESCRITORES; i++) {
        idEscritores[i] = i + 1;
        if (pthread_create(&escritores[i], NULL, writer, (void *)&idEscritores[i]) != 0) {
            perror("Error al crear el hilo");  
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_LECTORES; i++) {
        idLectores[i] = i + 1;
        if (pthread_create(&lectores[i], NULL, reader, (void *)&idLectores[i]) != 0) {
            perror("Error al crear el hilo");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_ESCRITORES; i++) {
        pthread_join(escritores[i], NULL);
    }
    
    for (int i = 0; i < NUM_LECTORES;   i++) {
        pthread_join(lectores[i],   NULL);
    }
    

    printf("Todos los hilos han terminado.\n"); 

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&db);
}
