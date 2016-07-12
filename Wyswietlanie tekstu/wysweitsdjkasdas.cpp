#include <windows.h>
#include <string>

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

INT WINAPI WinMain(HINSTANCE hInst,HINSTANCE,LPSTR lStart,INT nShow)
{
  WNDCLASSEX wc;
  wc.hInstance=hInst;
  wc.lpszClassName="Klasa okna";
  wc.lpfnWndProc=WndProc;
  wc.style=CS_DBLCLKS;
  wc.cbSize=sizeof(WNDCLASSEX);
  wc.hIcon=LoadIcon(0,IDI_APPLICATION);
  wc.hIconSm=LoadIcon(0,IDI_APPLICATION);
  wc.hCursor=LoadCursor(0,IDC_ARROW);
  wc.lpszMenuName=0;
  wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
  wc.cbWndExtra=0;
  wc.cbClsExtra=0;
  if(RegisterClassEx(&wc)==0) return 0;
  HWND Okno=CreateWindowEx(0,"Klasa okna","Tytu³ okna",WS_OVERLAPPEDWINDOW,50,50,300,300,0,0,hInst,0);
  MSG msgs;
  ShowWindow(Okno,nShow);
  UpdateWindow(Okno);
  while(GetMessage(&msgs,0,0,0))
  {
    TranslateMessage(&msgs);
    DispatchMessage(&msgs);
  }
  return msgs.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wPar,LPARAM lPar)
{
  HDC hdc;
  PAINTSTRUCT ps;
  
  std::string tekst; 
      tekst = "Wyswietlany tekst"; 
      
  switch(msg)
  {
    case WM_PAINT:
      hdc=BeginPaint(hwnd,&ps);
      //funkcje rysuj¹ce
      
      RECT rect; 
      SetRect(&rect, 15, 30, 150, 100); 
      
      DrawText( hdc, tekst.c_str(), -1, &rect, DT_EDITCONTROL);
      
      MoveToEx(hdc,50,50,0); //przeniesienie pozycji pióra na punkt (50,50)
      LineTo(hdc,100,100); //narysowanie linni do wspó³rzêdnej (100,100)
//w efekcie wywo³añ tych funkcji, narysujemy liniê od punktu (50,50) do punktu (100,100)
      EndPaint(hwnd,&ps);
      break;
      
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hwnd,msg,wPar,lPar);
  }
  return 0;
}
