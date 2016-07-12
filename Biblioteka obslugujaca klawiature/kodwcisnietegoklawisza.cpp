#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    unsigned char znak;
    cout << "klawisz [ESC] wychodzi z programu." << endl;
    do
    {
        znak = getch();
        cout << "znak: '" << znak << "' kod: " << static_cast < int >( znak ) << endl;
        while( kbhit() )
        {
            znak = getch();
            cout << "*znak: '" << znak << "' kod: " << static_cast < int >( znak ) << endl;
        }
        cout << endl;
    } while( znak != 27 ); //ESC
    
    return( 0 );
}
// funkcja getch() przechowuje znak wcisniety na klawiaturze
// funkcja static_cast<int>(znak) przerabia nasza literke na liczbe
//funkcja kbhit() sprawdza czy zosta³ wcisniety jakis inny znak np. liczby pod numlockiem 


