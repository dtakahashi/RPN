OBJS = main.o stac.o stac_func.o another_func.o save.o load.o line.o file_rect.o rectangle_func.o tri.o
TARGET ?= binary_stac
CC ?= gcc
CFLAGS += -O
CFLAGS += -Wall

.SUFFIXES: .c .o

all: $(TARGET)

$(TARGET): $(OBJS)
	   $(CC) $(OBJS) -o $(TARGET) $(CFLAGS)

.c .o:     $<
	   $(CC) -c $< $(CFLAGS)
clean:
	rm -f $(OBJS) $(TARGET)