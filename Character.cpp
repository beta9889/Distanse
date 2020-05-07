#include <iostream>
#include "Character.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

void Character::gameover(tgui::Gui& gui){

    auto over = tgui::ChildWindow::create("Game Over");
    over->setSize("50%","50%");
    over->setPosition("40%","40%");
    gui.add(over);

    tgui::Label::Ptr label = tgui::Label::create();
    label->setText("You have died please try again");
    label->setPosition(30, 30);
    label->setTextSize(15);
    over->add(label);

    auto close = tgui::Button::create();
    close->setPosition(75, 70);
    close->setText("OK");
    close->setSize(100, 30);
    close->connect("pressed", [=](){ over->setVisible(false); });
    over->add(close);
}

void Character::setstats(string chara, int str, int dex){
	name = chara;
	strenght =str;
	dexterity = dex;
	srand((unsigned)time(0));
	Character::health = strenght +(rand()%8);
}
void Character::showstats(){
	cout << name << endl << dexterity << endl 
		<< strenght << endl << health << endl <<"---------\n";
}
void Character::changehealth (int dmg, tgui::Gui& gui){
	health = health - dmg;
	if (health <= 0) 
		gameover(std::ref(gui));
}
