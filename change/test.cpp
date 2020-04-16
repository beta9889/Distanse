#include <TGUI/TGUI.hpp>
#include <iostream>


using namespace std;

int main(){
	sf::RenderWindow window(sf::VideoMode(800,600), "Test child");
	window.setFramerateLimit(30);

	tgui::Gui gui(window);

 	auto child = tgui::ChildWindow::create();
	//child->setRenderer(theme.getrendere("ChildWindow"));
	child->setSize("50%","50%");
	child->setPosition("40%","40%");
	child->setVisible(false);
	gui.add(child);
	
	tgui::Label::Ptr label = tgui::Label::create();
        //label->setRenderer(theme.getRenderer("Label"));
        label->setText("Hi! I'm a child window.");
        label->setPosition(30, 30);
        label->setTextSize(15);
        child->add(label);	

	auto close = tgui::Button::create();
        //close->setRenderer(theme.getRenderer("Button"));
        close->setPosition(75, 70);
        close->setText("OK");
        close->setSize(100, 30);
        close->connect("pressed", [=](){ child->setVisible(false); });
        child->add(close);


	tgui::Button::Ptr mchild = tgui::Button::create();
	mchild->setText("test child");
	mchild->setSize("60%","60%");
	gui.add(mchild);
	mchild->connect("pressed", [=](){child->setVisible(true);});


	while (window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				window.close();
			}
			gui.handleEvent(event);
		}
		window.clear();
		gui.draw();
		window.display();

	}
return 0;

}
