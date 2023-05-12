CC = gcc
SOURCES=main.c LAB_specific.c Default_func.c Hash_func.c Menu_func.c 
TARGET = main


compile:
	$(CC) $(SOURCES) -o $(TARGET)
clean:
	rm $(TARGET)
