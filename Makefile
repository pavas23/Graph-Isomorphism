COMPILER = gcc
RM = rm -f
EXE = run
FLAGS = -c
OBJECTFILES = PartB.o

all:build touch

build:$(OBJECTFILES)
	$(COMPILER) $(OBJECTFILES) -o $(EXE)

PartA.o: PartA.c 
	$(COMPILER) $(FLAGS) PartA.c 

PartB.o: PartB.c 
	$(COMPILER) $(FLAGS) PartB.c 

clean:
	$(RM) $(OBJECTFILES) $(EXE)

touch:
	@echo "\n"
	@echo "Compilation Done !"
	@echo "\n"
