CC = gcc

CFLAGS =  

SOURCES = vk5.c

OBJECTS = $(SOURCES:.c = .o)

EXECUTABLE = vk5

#all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
	
clean:
	rm -rf *.o $(EXECUTABLE)
