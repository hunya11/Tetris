#include "Root.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){


	Frame* frame = new Frame();
	try{
		frame->Init();
		frame->Main();
	}catch(int ex){
		return ex;
	}
	delete frame;

	return 0 ;				// ソフトの終了 

}