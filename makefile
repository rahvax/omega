DIR  = build
NAME = omega

compile: src/main.c src/$(NAME).c | $(DIR)
	gcc -o $(DIR)/$(NAME) src/main.c src/$(NAME).c -lcrypto
run: compile
	./$(DIR)/$(NAME) passwordTest Github
$(DIR):
	@mkdir -p $(DIR)
