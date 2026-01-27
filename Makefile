OUT    = pomokey
SRC    = $(wildcard src/*.c)

CFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = -Llib
LIBS   = -lraylib -lGL -lm -lpthread -ldl

all: $(OUT)

$(OUT): $(SRC)
	cc $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS) $(LIBS)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)


