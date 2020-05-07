.PHONY: clean
.PHONY: all

all: exe

exe: tgui.o Character.o
	g++ tgui.o Character.o -lsfml-window -lsfml-graphics -lsfml-system -ltgui -o exe

tgui.o: tgui.cpp
	g++ -c tgui.cpp 
Character.o: Character.cpp
	g++ -c Character.cpp

clean:
	rm Saves.txt
	rm tgui.o
	rm exe
