DIR = build

compile: src/main.c src/omega.c | $(DIR)
	gcc -o $(DIR)/omega src/main.c src/omega.c -lcrypto
run: compile
	./build/omega passwordTest Github
$(DIR):
	@mkdir -p $(DIR)
