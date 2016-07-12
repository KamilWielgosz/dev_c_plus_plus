#include <windows.h>

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {

switch (Message)
   {
    case WM_CREATE:{//Stuff to initialize windows info}break;

    case WM_COMMAND:{//Stuff that responds to menubar selections}break;


    case WM_KEYDOWN:
   {
       switch(wParam)
       {
       case VK_UP:{moveUp=true;}break;

               case VK_DOWN:{moveDown=true;}break;

       case VK_LEFT:{moveLeft=true;}break;

       case VK_RIGHT:{moveRight=true;}break;

       //More cases for handling W,Q,A,S,D and SPACE inputs

       default: //Stop moving character

       }
   }

   //Make changes to player input over here
   case WM_KEYUP:
   {
       switch(wParam)
       {
                //Cases for handling ESCAPE, P, R, W and SPACE inputs

            case VK_UP:{moveUp=false;}break;

                case VK_DOWN:{moveDown=false;}break;

                case VK_LEFT: {moveLeft=false;}break;

            case VK_RIGHT:{moveRight=false;}break;
       }//end switch

   }//end WM_KEYUP

   break;


   case WM_PAINT:{}break;

   case WM_SIZE:{}break;

   case WM_DESTROY:{}break;

   }//end switch


   return DefWindowProc (hwnd, msg, wParam, lParam);
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG Msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		640, /* width */
		480, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produre unreasonably CPU usage
	*/
	while(GetMessage(&Msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&Msg); /* Translate keycodes to chars if present */
		DispatchMessage(&Msg); /* Send it to WndProc */
	}
	return Msg.wParam;
}











