DIR  = build
NAME = omega

compile: src/main.c src/omega.c | $(DIR)
	gcc -o $(DIR)/$(NAME) src/main.c src/omega.c -lcrypto
run: compile
	./$(DIR)/$(NAME) passwordTest Github
$(DIR):
	@mkdir -p $(DIR)
