//
//Cat readable
//
#include <iostream>
#include <TGUI/TGUI.hpp>
#include <fstream>
#include <string>

using namespace std;

void NewStats(tgui::Gui& gui);

/*
void LoadChar(ifstream savefile, tgui::Gui& gui, ){
    gui.removeAllWidgets();
    
    savefile.open; 
    string name;
    savefile >> name;

    int strenght;
    savefile >> strenght;

    int dexterity;
    savefile >> dexterity;

}
*/


void SaveChar(tgui::EditBox::Ptr name, tgui::EditBox::Ptr str, tgui::EditBox::Ptr dex, tgui::Gui& gui){

    ofstream savefile;
    savefile.open("Saves.txt");
    
    string endchar ="---------------------------------------------------------------------------";

    savefile << endchar << endl;
    savefile << name->getText().toAnsiString() << endl;
    savefile << str->getText().toAnsiString()<< endl;
    savefile << dex->getText().toAnsiString()<< endl;
    savefile << endchar << endl;
   
    cout << "Character Saved";

    savefile.close();

    gui.removeAllWidgets();

    auto label = tgui::Label::create();
    label->setText("character saved");
    label->setPosition("30%","45%");
    label->setTextSize(15);
    gui.add(label);

}


void LoadStats(tgui::Gui& gui){
    gui.removeAllWidgets();

    tgui::EditBox::Ptr savefile = tgui::EditBox::create();
    savefile-> setDefaultText("Location of savefile");
    savefile-> setSize("35%","10%");
    savefile-> setPosition("35%","45%");
    gui.add(savefile, "savefile");


    tgui::Button::Ptr Load = tgui::Button::create("Load Character");
    Load->setPosition("55%", "65%");
    Load->setSize("15%","10%");
    gui.add(Load);
    
//    Load->connect("pressed", Loadchar, savefile, std::ref( gui));


    auto  newButton = tgui::Button::create("New Character");
    newButton-> setSize("15%", "5%");
    newButton-> setPosition("25%", "75%");
    gui.add(newButton);
   
    newButton->connect("pressed", NewStats,std::ref( gui));

//    Load->connect("pressed", makechar, std::ref(gui));

}


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


    tgui::Button::Ptr Submit = tgui::Button::create("Submit");
    Submit->setPosition("43%","60%");
    Submit->setSize("10%", "5%");
    gui.add(Submit); 

    Submit->connect("pressed", SaveChar, name, strenght, dexterity, std::ref(gui)); 


}


void Startpage(tgui::Gui& gui){


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
    
    sf::RenderWindow window(sf::VideoMode(700,500), "WindowName");
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
