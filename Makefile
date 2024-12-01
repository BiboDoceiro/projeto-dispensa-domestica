CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Target executable
TARGET = dispensa

# Source files
SRC = main.c \
      orcamento/orcamento.c \
      pessoa/pessoa.c \
      pessoa/ler_pessoa.c \
      produtos/produtos.c \
      produtos/ler_produtos.c \
      relatorios/relatorio.c \
      sobre/sobre.c \
      util/util.c

# Header files
HEADERS = orcamento/orcamento.h \
          pessoa/pessoa.h \
          pessoa/ler_pessoa.h \
          produtos/produtos.h \
          relatorios/relatorio.h \
          sobre/sobre.h \
          util/util.h

# Object files
OBJ = $(SRC:.c=.o)

# Build target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile source files to object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets
.PHONY: clean