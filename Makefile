compiler = gcc


default: build



bin_dir:
	mkdir -p ./bin

bin/hash.o: bin_dir src/hash.c
	${compiler} -c ./src/hash.c -o ./bin/hash.o

bin/main.o: bin_dir src/main.c
	${compiler} -c ./src/main.c -o ./bin/main.o



bin/c_hash: bin/main.o bin/hash.o bin_dir
	${compiler} ./bin/main.o ./bin/hash.o -o bin/c_hash



build: bin/c_hash

run:
	@./bin/c_hash



rb: build run
