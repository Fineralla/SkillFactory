CPP = g++ # компилятор
BIN_DIR = bin
FLAGS = -std=c++2a -stdlib=libc++ -fdiagnostics-color=always  # флаги компиляции
TARGETSRC = main.cpp # главный main файл
TARGET = concept # цель -> исполняемый файл

all: 	$(TARGETSRC)
		mkdir -p ./$(BIN_DIR)
		$(CPP) $(FLAGS) -o $(PWD)/$(BIN_DIR)/$(TARGET) $(TARGETSRC)

