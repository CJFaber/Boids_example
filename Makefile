CC = g++


SOURCES = $(wildcard source/*.cpp) 
OBJECTS = $(SOURCES:.cpp=.o)
INC_DIR = ./include

CFLAGS = -Wall -pipe -I$(INC_DIR)
OFLAGS = -c -I/usr/include  
LFLAGS = $(CFLAGS) -L/usr/lib/


DEBUG = no
OPTIMIZATION = -O2

ifeq ($(DEBUG), yes)
	CFLAGS += -g
	OPTIMIZATION = -O0
endif

CFLAGS += $(OPTIMIZATION) -lsfml-graphics -lsfml-window -lsfml-system -fopenmp

all: project

project: $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o boids.exe 

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o project

rebuild: clean all

.PHONY : clean
.SILENT : clean
