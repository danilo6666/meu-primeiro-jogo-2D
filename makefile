# Nome do executável
EXEC = jogo.exe

# Compilador
CC = gcc

# Flags (ajuste o caminho da raylib se necessário)
CFLAGS = -IC:\raylib\include
LDFLAGS = -LC:\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm -lm

# Arquivo fonte
SRC = main.c

# Regra principal
all: run

# Compila
$(EXEC): $(SRC)
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS) $(LDFLAGS)

# Executa o jogo
run: $(EXEC)
	./$(EXEC)

# Limpa arquivos gerados
clean:
	del $(EXEC)