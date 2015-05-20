CC = gcc

CFLAGS =  

SOURCES = vk5.c

OBJECTS = $(SOURCES:.cpp = .o)

EXECUTABLE = vk5

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJS) -o $@	 
	
clean:
	$(RM) -f *.o
	$(RM) -f main
	
