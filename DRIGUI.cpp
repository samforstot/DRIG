#include "DRIGUI.h"
#include <unordered_map>
#include <vector>
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(int argc, const char** argv) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DRIG::DRIGUI form; 
	Application::Run(% form);
}

