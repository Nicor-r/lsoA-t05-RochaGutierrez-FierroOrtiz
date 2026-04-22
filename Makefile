CC= gcc
CFLAGS= -Wall -Wextra -Werror -pthread
TARGET= lectores_escritores

##Directiva principal
all: $(TARGET)

##Acciones
$(TARGET): principal.o hilos.o
	$(CC) $(CFLAGS) -o $(TARGET) principal.o hilos.o

principal.o: src/principal.c src/hilos.h
	$(CC) $(CFLAGS) -c src/principal.c

hilos.o: src/hilos.c src/hilos.h
	$(CC) $(CFLAGS) -c src/hilos.c

##Directiva phony
clean:
	rm -f *.o $(TARGET)



