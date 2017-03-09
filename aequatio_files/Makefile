CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(notdir $(CPP_FILES:.cpp=.o))

all: $(OBJ_FILES) subsystem

%.o: %.cpp %.hpp
	$(COMPILER) $(FLAGS) -o $(notdir $*).o $*.cpp

.PHONY : subsystem
subsystem:
	@setterm -fore blue
	@printf "EQUATION/\n";
	@setterm -fore white
	@cd equation && $(MAKE)
	@setterm -fore green
	@printf "FUNCTIONS/\n";
	@setterm -fore white
	@cd functions && $(MAKE)
