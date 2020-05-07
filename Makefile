.PHONY: clean
.PHONY: all

all: exe

exe: tgui.o
	g++ tgui.o -lsfml-window -lsfml-graphics -lsfml-system -ltgui -o exe

tgui.o: tgui.cpp
	g++ -c tgui.cpp

clean:
	rm Saves.txt
	rm tgui.o
	rm exe
