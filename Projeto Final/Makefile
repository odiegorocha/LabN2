# Nome do executável
TARGET = programao

# Compilador e flags
CC = gcc
CFLAGS = -Wall

# Arquivos fonte
SRCS = main.c consultas.c mensalidades.c util.c

# Regra principal
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Limpeza
clean:
	rm -f *.o programao
