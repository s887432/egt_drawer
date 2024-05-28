#include <egt/ui>
#include <memory>
#include <string>

int main(int argc, char** argv)
{
    egt::Application app(argc, argv);

    egt::TopWindow win;
    win.background(egt::Image("file:./background.png"));
    
    egt::Label label0("Touch scren to start");
    label0.font(egt::Font(28));
    win.add(label0);
    
    egt::PeriodicTimer timer1(std::chrono::milliseconds(500));
    timer1.on_timeout([&]()
    {
    	if( label0.visible() )
    	{
    		label0.hide();
    	}
    	else
    	{
    		label0.show();
    	}
    });
    timer1.start();
    
    win.show();

    return app.run();
}
