DIR  = build
NAME = omega

compile: src/main.c src/$(NAME).c | $(DIR)
	gcc -o $(DIR)/$(NAME) src/main.c src/$(NAME).c $(shell pkg-config --cflags --libs openssl)
run: compile
	./$(DIR)/$(NAME) Teste 3
$(DIR):
	@mkdir -p $(DIR)
