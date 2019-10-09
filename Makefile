CC = g++



CFLAGS = -g -Wall

OBJ = customer.o q1.o

TARGET = customer
%.o: %.c $(DEPS)
		$(cc) -C -O $@ $< $(CFLAGS)
		
$(TARGET): $(OBJ)
		$(CC) -o $@ $^ $(CFLAGS)
		
clean:
		$(RM) $(OBJ) $(TARGET)