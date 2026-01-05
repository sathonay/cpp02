SRC=main.cpp Fixed.cpp Point.cpp
F_EXT = .cpp

OBJ = $(SRC:$(F_EXT)=.o)
TARGET = a.out

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


%.o: %$(F_EXT)
	$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(TARGET) 

all: $(TARGET)

re: fclean all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

exec: all
	./$(TARGET)

.PHONY: all re clean fclean exec

