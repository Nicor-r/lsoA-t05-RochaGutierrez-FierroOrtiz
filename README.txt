=====================================================
  Lectores-Escritores con pthreads
  Laboratorio de Sistemas Operativos — Grupo A
  Universidad del Cauca
=====================================================

INTEGRANTES
-----------
Nombre  : Nicolas Rocha Gutierrez
Correo  : nicolasrcocha@unicauca.edu.co
Nombre  : Luis Eduardo Fierro Ortiz
Correo  : luisfierro@unicauca.edu.co

DESCRIPCIÓN
-----------
Implementación en C del problema clásico de Lectores-Escritores
presentado por Tanenbaum, usando la biblioteca POSIX pthreads.

  - N = 60 hilos lectores  (cumple N > 50)
  - M = 25 hilos escritores (cumple M > 20)

ESTRUCTURA
----------
lsoA-t05-RochaGutierrez-FierroOrtiz/
├── Makefile
├── README.txt
├── src/
│   ├── hilos.h    (declaraciones y parámetros)
│   ├── hilos.c    (implementación completa)
│   ├── principal.c    (ejecucion del programa)
│
└── docs/
    └── lsoA-t05-lsoA-t05-RochaGutierrez-FierroOrtiz.docx  (informe)

COMPILACIÓN Y EJECUCIÓN
-----------------------
  make          # Compila el ejecutable
  make clean    # Elimina archivos objeto y ejecutable

REQUISITOS
----------
  - GCC 
  - Biblioteca pthreads 
  - Sistema operativo GNU/Linux
