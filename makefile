# Makefile for Project 1 of CS485, Fall 2016
# This project is to manipulate binary data in C.

PROJECT = prog1
GOAL = prog1
CFLAGS = -Wall
DATAFILE = testData
INPUT = inputFile
OUTPUT = outputFile

# interactive
run-i: $(GOAL) $(DATAFILE)
	./$(GOAL) $(DATAFILE)

# batch
run-b: $(GOAL) $(DATAFILE) $(INPUT) $(OUTPUT)
	./$(GOAL) $(DATAFILE) < $(INPUT) > $(OUTPUT)

clean:
	rm -f $(GOAL) $(OUTPUT)

submit: $(GOAL).c Makefile README
	tar -czf $(PROJECT).tgz $(GOAL).c Makefile README
