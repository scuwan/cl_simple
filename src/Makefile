CC= gcc
LFLAGS = -lOpenCL -ggdb3 -fsigned-char
APPNAME = simple
OBJECTS = simple.o
all: $(APPNAME)
$(APPNAME): $(OBJECTS)
	$(CC) -o $(APPNAME) $(OBJECTS) $(LFLAGS)
$(APPNAME).o: $(APPNAME).c
	$(CC)  -c -o $(APPNAME).o $(APPNAME).c $(LFLAGS)
clean:
	rm $(APPNAME) $(OBJECTS)
