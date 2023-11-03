# Define the compiler
CC := gcc

# Define the flags for the compiler
CFLAGS := -I.

# Define the source files
SRC := main.c comparison.c sortingAlgorithms/sorting.c utils/utils.c 

# Define the program name
PROG := prog

# Default target
all: $(PROG)

# Link the program
$(PROG): $(SRC)
	$(CC) $(CFLAGS) -o $(PROG) $(SRC)

# Phony target to run the program
.PHONY: run
run: $(PROG)
	./$(PROG) > data.txt

# Phony target to clean the build
.PHONY: clean
clean:
	rm -f $(PROG)

