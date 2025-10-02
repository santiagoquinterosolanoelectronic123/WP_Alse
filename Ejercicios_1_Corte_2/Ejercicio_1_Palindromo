#include <iostream>
using namespace std;

class Palindrome_number{ //Definimos la clase Palindrome_number
private:
    int x;
public:
    Palindrome_number(){} //Método Constructor para la clase
    void set_num(int num){ // Método set para setear los valores de un objeto
      x = num;
    }

    bool isPalindrome(int x) { // Método para verificar si el número entero ingresado por el usuario es Palindromo
      bool Answer;
        if (x < 0) {
            Answer = false;
        }
        if (x < 10) {
            Answer = true;
        }

        int orig = x;
        long rever = 0;

        while (x > 0) {
            int dig = x % 10;
            rever = rever * 10 + dig;
            x = x / 10;
        }
        if (rever == orig) {
            Answer = true;
        } else {
            Answer = false;
        }
        return Answer;
    }
};

int main(){
  Palindrome_number num_1; //Creamos un objeto de la clase Palindrome_number llamado num_1

  int n1 = 0; // Inicializamos el valor default n1
  bool answer_1; // Definimos answer_1 como un booleano

  cout <<"Ingrese el 1° para evaluar si es palindromo: ";
  cin >> n1;
  num_1.set_num(n1);

  answer_1 = num_1.isPalindrome(n1);

  if (answer_1 == true){
    cout <<"\nEl número " << n1 << " es palindromo";
  }
  else{
    cout <<"\nEl número " << n1 << " no es palindromo";
  }

  return 0;

}

