#include <windows.h>

int WINAPI WinMain(HINSTANCE hi, HINSTANCE, PSTR cmd, int show)
{

HANDLE uchwyt_zdarzenia_b = OpenEvent(EVENT_ALL_ACCESS, FALSE, TEXT("zdarzenie"));
                                          

BOOL test = SetEvent(uchwyt_zdarzenia_b);

if(test==TRUE)
MessageBox(NULL, TEXT("Uda³o siê!"), TEXT("Sukces"),  
                 MB_OK | MB_ICONINFORMATION);
else 
MessageBox(NULL, TEXT("Nie uda³o siê!"), TEXT("Pora¿ka"), 
                  MB_OK | MB_ICONERROR);

return 0;
}
