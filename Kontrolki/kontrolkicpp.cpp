#include <windows.h>
#include <commctrl.h>

HWND hButton,hWnd;
CHAR szClassName[]="OknoRodzica";
HINSTANCE* hInst;

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance,HINSTANCE,LPSTR lStart,INT nShow)
{
  hInst=&hInstance;
  WNDCLASSEX wc;
  wc.hInstance=*hInst;
  wc.lpszClassName=szClassName;
  wc.lpfnWndProc=WndProc;
  wc.style=0;
  wc.cbSize=sizeof(WNDCLASSEX);
  wc.hIcon=LoadIcon(0,IDI_APPLICATION);
  wc.hIconSm=LoadIcon(0,IDI_APPLICATION);
  wc.hCursor=LoadCursor(0,IDC_ARROW);
  wc.lpszMenuName=0;
  wc.cbClsExtra=0;
  wc.cbWndExtra=0;
  wc.hbrBackground=(HBRUSH)COLOR_BACKGROUND;
  if(!RegisterClassEx(&wc)) return 0;
  hWnd=CreateWindowEx(0,szClassName,"Tworzenie buttona",WS_OVERLAPPEDWINDOW,20,20,600,300,0,0,*hInst,0);
  ShowWindow(hWnd,nShow);
  MSG msgs;
  while(GetMessage(&msgs,0,0,0))
  {
    TranslateMessage(&msgs);
    DispatchMessage(&msgs);
  }
  return msgs.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wPar,LPARAM lPar)
{
  switch(msg)
  {
    case WM_CREATE:
      //funkcja tworz¹ca kontrolkê
      hButton=CreateWindowEx(0,WC_BUTTON,"Przycisk",WS_CHILD|WS_VISIBLE,20,20,200,70,hwnd,(HMENU)1,*hInst,0);
      break;
    case WM_COMMAND:
      if(wPar==1) MessageBox(hwnd,"Przycisk naciœniêty",":>",MB_OK);
      //je¿eli zosta³ naciœniêty przycisk o identyfikatorze numer 1 wyœwietli siê komunikat
      break;
    case WM_DESTROY:
      DestroyWindow(hButton);
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd,msg,wPar,lPar);
  }
  return 0;
}
