#include "App.h"
#include "ChartFrame.h"
#include <wx/wx.h>

bool App::OnInit() {
	ChartFrame* frame = new ChartFrame("Hello World");
	frame->SetSize(600, 400);
	frame->Center();
	frame->Show(true);
	return true;
}

wxIMPLEMENT_APP(App);