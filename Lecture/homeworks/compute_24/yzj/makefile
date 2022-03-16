CC = g++
PATH_SRC = ./src
PATH_HEAD = ./include
PATH_BUILD = ./build

all: $(PATH_SRC)/*.cpp 
	g++ -c $(PATH_SRC)/*.cpp -I $(PATH_HEAD)
	mv *.o ${PATH_BUILD}

.PHONY: install
install:
	$(CC) ${PATH_BUILD}/*.o -o ${PATH_BUILD}/main -I $(PATH_HEAD) 
	
.PHONY: clean
clean:
	rm -rf ${PATH_BUILD}/*.o
