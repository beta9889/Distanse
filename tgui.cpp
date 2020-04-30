#include <iostream>
#include <TGUI/TGUI.hpp>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

void Startpage(tgui::Gui& gui);
void NewStats(tgui::Gui& gui);
void LoadStats(tgui::Gui& gui);

class Character{
public:
    string name;
    void setstats(string chara, int str, int dex){

        name = chara; 
        strenght = str;
        dexterity = dex;
        srand((unsigned)time(0));
        health = strenght +(rand()%8); 	

    }
    void showstats(){
        cout << name << endl
		<< dexterity << endl 
		<< strenght <<endl
		<< health << endl<<"-----------\n";
    }
    void changehealth(int dmg, tgui::Gui& gui){
        health = health - dmg;
	if (health==0){gameover(std::ref(gui));}
    }
private:
    int health;
    int strenght;
    int dexterity;

    void gameover(tgui::Gui& gui){
    
    auto over = tgui::ChildWindow::create("Game Over");
    over->setSize("50%","50%");
    over->setPosition("40%","40%");
    gui.add(over);
	
    tgui::Label::P3tr label = tgui::Label::create();
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
};


void Gamestart(tgui::Gui& gui){
    auto gamew = tgui::ChildWindow::create(person.name);
    gamew->setSize("80%","80%");
    gui.add(gamew);

    




}

void LoadChar(tgui::Gui& gui, tgui::EditBox::Ptr load){
    
    fstream savefile;
    savefile.open("Saves.txt", fstream::in | fstream::out); 
    
    Character person;
    string name;
    string peep;
    peep = load->getText().toAnsiString();	

    do{
        savefile >> name;
    }while (peep!=name);

    int str;
    savefile >> str;
    int dex;
    savefile >> dex;
    person.setstats(name,str,dex);

    person.showstats();

 
    auto child = tgui::ChildWindow::create();
    child->setSize("50%","50%");
    child->setPosition("40%","40%");
    gui.add(child);
	
    tgui::Label::Ptr label = tgui::Label::create();
    label->setText(person.name);
    label->setPosition(30, 30);
    label->setTextSize(15);
    child->add(label);	 

    auto close = tgui::Button::create();
    close->setPosition(75, 70);
    close->setText("OK");
    close->setSize(100, 30);
    close->connect("pressed", [=](){ child->setVisible(false); });
    child->add(close); 
/*
    auto  newButton = tgui::Button::create("Back to start");
    newButton-> setSize("40%", "25%");
    newButton-> setPosition("25%", "75%");
    gui.add(newButton);
   
    newButton->connect("pressed", Startpage,std::ref( gui));
*/
}



void SaveChar(tgui::EditBox::Ptr name, tgui::EditBox::Ptr str, 
		tgui::EditBox::Ptr dex, tgui::Gui& gui){

    string checkint = str->getText().toAnsiString();
    if(bool has_only_didgets = (checkint.find_first_not_of("0123456789") != string::npos)){
  //      checkint = dex->getText().toAnsiString();
    //    if(bool has_only_didgets = (checkint.find_first_not_of("0123456789") != string::npos)){
                
        
            auto child = tgui::ChildWindow::create();
	    child->setSize("50%","50%");
	    child->setPosition("40%","40%");
	    gui.add(child);
	
	    tgui::Label::Ptr label = tgui::Label::create();
            label->setText("Strenght and Dexterity can only \n contain numbers.");
            label->setPosition(30, 30);
            label->setTextSize(15);
            child->add(label);	

	    auto close = tgui::Button::create();
            close->setPosition(75, 70);
            close->setText("OK");
            close->setSize(100, 30);
            close->connect("pressed", [=](){ child->setVisible(false); });
            child->add(close); 
			
//	}
    }
    else{
        ofstream savefile;
        savefile.open("Saves.txt", std::ofstream::app);
        savefile <<name->getText().toAnsiString() << " ";
        savefile <<str->getText().toAnsiString()<<" ";
        savefile <<dex->/*getValue()*/getText().toAnsiString() << endl;
   
        cout << "Character Saved \n";
        savefile.close();

        gui.removeAllWidgets();
        
	auto label = tgui::Label::create();
        label->setText("Character Saved");
        label->setPosition("30%","45%");
        label->setTextSize(15);
        gui.add(label);

        auto  newButton = tgui::Button::create("Back to start");
        newButton-> setSize("40%", "25%");
        newButton-> setPosition("25%", "75%");
        gui.add(newButton);
   
        newButton->connect("pressed", Startpage,std::ref( gui));

    }
}


void LoadStats(tgui::Gui& gui){
    gui.removeAllWidgets();

    tgui::EditBox::Ptr savefile = tgui::EditBox::create();
    savefile-> setDefaultText("Name of your character");
    savefile-> setSize("35%","10%");
    savefile-> setPosition("35%","45%");
    gui.add(savefile, "savefile");


    tgui::Button::Ptr Load = tgui::Button::create("Load Character");
    Load->setPosition("55%", "65%");
    Load->setSize("15%","10%");
    gui.add(Load,"Load");
    
    Load->connect("pressed", LoadChar, std::ref(gui), savefile);


    auto  newButton = tgui::Button::create("New Character");
    newButton-> setSize("15%", "5%");
    newButton-> setPosition("25%", "75%");
    gui.add(newButton);
   
    newButton->connect("pressed", NewStats,std::ref( gui));

}
//blablabla testing makefile

void NewStats(tgui::Gui& gui){
    gui.removeAllWidgets();
    
    
    tgui::Button::Ptr Load = tgui::Button::create("Load Character");
    Load-> setSize("15%", "10%");
    Load-> setPosition("25%", "75%");
    gui.add(Load);

    Load->connect("pressed",LoadStats, std::ref(gui));


    tgui::EditBox::Ptr name = tgui::EditBox::create();
    name -> setDefaultText("Character name");
    name->setSize("20%" , "5%");
    name->setPosition("40%","35%"); 
    gui.add(name, "name");
  

    tgui::EditBox::Ptr strenght = tgui::EditBox::create();
    strenght -> setDefaultText("Strenght");
    strenght ->setSize("10%", "5%");
    strenght->setPosition("45%", "40%");
    gui.add(strenght, "strenght");


    tgui::EditBox::Ptr dexterity = tgui::EditBox::create();
    dexterity-> setDefaultText("Dexterity");
    dexterity-> setSize("10%", "5%");
    dexterity->setPosition("45%","45%");
    gui.add(dexterity, "dexterity");
/*
    tgui::Slider::Ptr dexterity = tgui::Slider::create();
    dexterity->setPosition("45", "50%");
    //dexterity->setColor("Green");
    dexterity->setSize("30%", "15%");
    dexterity->setMinimum(0);
    dexterity->setMaximum(20);	     
    dexterity->setStep(1);
    dexterity->setVerticalScroll(true);
    dexterity->setChangeValueOnScroll(true);
    gui.add(dexterity);
*/

    tgui::Button::Ptr Submit = tgui::Button::create("Submit");
    Submit->setPosition("43%","60%");
    Submit->setSize("10%", "5%");
    gui.add(Submit); 

    Submit->connect("pressed", SaveChar, name, strenght, dexterity, std::ref(gui)); 
}


void Startpage(tgui::Gui& gui){
    gui.removeAllWidgets();


    auto newButton = tgui::Button::create("New Character");
    newButton-> setSize("25%", "25%");
    newButton-> setPosition("25%", "50%");
    gui.add(newButton);
   
    newButton->connect("pressed", NewStats,std::ref( gui));
		   
    auto Load = tgui::Button::create("Load Character");
    Load-> setSize("25%", "25%");
    Load-> setPosition("65%", "50%");
    gui.add(Load);

    Load->connect("pressed",LoadStats, std::ref(gui));
}


int main(){
    
    sf::RenderWindow window(sf::VideoMode(700,500), "Baby game creator");
    tgui::Gui gui(window);

    try{
    Startpage(gui); 
    }
    catch (const tgui::Exception& e){
	    std::cerr << "something went wrong :" << e.what() << std::endl;
    }


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::Resized){

		window.setView(sf::View(sf::FloatRect(0.f, 0.f, static_cast<float>(event.size.width),
						                static_cast<float>(event.size.height))));
		gui.setView(window.getView());
            	
	    }
            gui.handleEvent(event); // Pass the event to the widg
           // Load->connect("pressed", Loadstats, std::ref(gui))    
            
	}


        window.clear();
        gui.draw(); // Draw all widgets
        window.display();
    }
    return EXIT_SUCCESS;
}
