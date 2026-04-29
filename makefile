DIR  = build
NAME = omega
FLAGS = -std=c17 -Wall -Wextra -Wpedantic -Iinclude

debug: src/main.c | $(DIR)
	gcc $(FLAGS) -g -O0 src/*.c -o $(DIR)/debug/$(NAME)
release: src/main.c | $(DIR)
	gcc $(FLAGS) -O2 src/*.c -o $(DIR)/release/$(NAME)
test: debug
	./$(DIR)/debug/$(NAME) senhaTeste Chaveteste
$(DIR):
	@mkdir -p $(DIR)/debug
	@mkdir -p $(DIR)/release
	@mkdir -p $(DIR)/libs