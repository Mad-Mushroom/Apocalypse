COMPILER = g++
NAME = Apocalypse
OUTPUT = $(BIN-DIR)/$(NAME)
SRC-DIR = ./src
BIN-DIR = ./bin
FILES = $(wildcard $(SRC-DIR)/*.cpp) $(wildcard $(SRC-DIR)/*/*.cpp) $(wildcard $(SRC-DIR)/engine/objects/*.cpp) $(wildcard $(SRC-DIR)/engine/console/*.cpp)
COMPILER-FLAGS = -Wall -std=c++11
LINKER-FLAGS = -lraylib

compile:
	$(COMPILER) $(COMPILER-FLAGS) -o $(OUTPUT) $(FILES) $(LINKER-FLAGS)

run:
	$(OUTPUT)

compile.run:
	$(COMPILER) $(COMPILER-FLAGS) -o $(OUTPUT) $(FILES) $(LINKER-FLAGS)
	$(OUTPUT)

clean:
	rm $(OUTPUT)

compile.run.clean:
	$(COMPILER) $(COMPILER-FLAGS) -o $(OUTPUT) $(FILES) $(LINKER-FLAGS)
	$(OUTPUT)
	rm $(OUTPUT)
