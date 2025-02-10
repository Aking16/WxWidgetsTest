#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>

bool App::OnInit() {
	MainFrame* frame = new MainFrame("Hello World");
	frame->SetSize(600, 400);
	frame->Center();
	frame->Show(true);
	return true;
}

wxIMPLEMENT_APP(App);