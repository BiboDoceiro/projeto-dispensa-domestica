# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Target executable
TARGET = dispensa

# Source files
SRC = main.c \
      orcamento/orcamento.c \
      orcamento/ler_orcamento.c \
      pessoa/pessoa.c \
      pessoa/ler_pessoa.c \
      pessoa/pessoa_arquivo.c \
      produtos/produtos.c \
      produtos/ler_produtos.c \
      produtos/produto_arquivo.c \
      relatorios/relatorio.c \
      sobre/sobre.c \
      util/util.c

# Header files
HEADERS = orcamento/orcamento.h \
          orcamento/ler_orcamento.h \
          pessoa/pessoa.h \
          pessoa/ler_pessoa.h \
          pessoa/pessoa_arquivo.h \
          produtos/produtos.h \
          produtos/ler_produtos.h \
          produtos/produto_arquivo.h \
          relatorios/relatorio.h \
          sobre/sobre.h \
          util/util.h

# Object files
OBJ = $(SRC:.c=.o)

# Build directory for object files
BUILD_DIR = build

# Object files stored in the build directory
BUILD_OBJ = $(patsubst %.o, $(BUILD_DIR)/%.o, $(OBJ))

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(BUILD_OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(BUILD_OBJ)

# Compile source files to object files in build directory
$(BUILD_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Rebuild the project from scratch
rebuild: clean all

# Phony targets
.PHONY: all clean rebuild run
