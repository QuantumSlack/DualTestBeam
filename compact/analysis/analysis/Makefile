## Compiler settings
CXX = g++ -std=c++20
CXXFLAGS = -O2 -Wall -Wunused-variable -fPIC $(shell root-config --cflags)
#-I/cvmfs/sft.cern.ch/lcg/releases/Geant4/11.3.0-3cd7f/x86_64-el9-gcc14-opt/include/Geant4
LDFLAGS = $(shell root-config --libs)

### necessary directories
INCDIR = include
SRCDIR = src 
OBJDIR = obj 
LIBDIR = lib

G4_INCLUDE = $(shell geant4-config --cflags)
#/cvmfs/sft.cern.ch/lcg/releases/Geant4/11.3.0-3cd7f/x86_64-el9-gcc14-opt/include/Geant4
G4_LIBS = $(shell geant4-config --libs)

### DD4hep paths - ADD THESE LINES
DD4HEP_INCLUDE = $(shell dd4hep-config --include)
DD4HEP_LIBS = $(shell dd4hep-config --libs)

### Add DD4hep to compiler flags - MODIFY THIS LINE
CXXFLAGS += -I$(INCDIR) $(DD4HEP_INCLUDE) $(G4_INCLUDE)

### Add DD4hep to linker flags - MODIFY THIS LINE
LDFLAGS += $(DD4HEP_LIBS) $(G4_LIBS)

### Find source files - FIXED: proper wildcard syntax
SOURCE_FILES = $(shell find $(SRCDIR) -name "*.cc")
SOURCES = $(SOURCE_FILES)
OBJECTS = $(patsubst $(SRCDIR)/%.cc,$(OBJDIR)/%.o,$(SOURCES))

LIBNAME = libMyAnalysis.so
LIBPATH = $(LIBDIR)/$(LIBNAME)
## build the shared libraries
all: $(LIBPATH)

## rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cc
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

## rule to build libraries
$(LIBPATH): $(OBJECTS)
	@echo $(LIBPATH)
	@mkdir -p $(LIBDIR)
	@echo "-------------------------------------"
	@echo "Building shared library: $@"
	@echo "Using objects: $(OBJECTS)"
	@echo "-------------------------------------"
	$(CXX) -shared -o $@ $(OBJECTS) $(LDFLAGS) -I$(G4_INCLUDE)

## rule for make clean
debug:
	@echo "SRCDIR = $(SRCDIR)"
	@echo "SOURCE_FILES = $(SOURCE_FILES)"
	@echo "SOURCES = $(SOURCES)"
	@echo "OBJECTS = $(OBJECTS)"
	@echo "LIBPATH = $(LIBPATH)"

clean:
	rm -rf $(OBJDIR) $(LIBDIR)

.PHONY: all clean debug
