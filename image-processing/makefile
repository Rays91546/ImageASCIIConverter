# Find all the names of the source files and object files we need to create
SOURCES = $(wildcard *.cc)
OBJECTS = $(notdir $(SOURCES:.cc=.o))
EXE = image-processor

# make will build the executable
all: $(EXE)

# Target for building object files from source files
%.o: %.cc
	g++ -g -c $< -o $@

# Build executable based on objects that are available
$(EXE):  $(OBJECTS)
	g++ -g  $(OBJECTS) -o $@

# Remove objects and executables
clean:
	rm -rf *.o
	rm -rf $(EXE)