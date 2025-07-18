compile: src/main.c src/omega.c
	gcc -o ./build/omega src/main.c src/omega.c -lcrypto
test: compile
	./build/omega testPassword TestKey
clean: build/omega
	rm build/omega
