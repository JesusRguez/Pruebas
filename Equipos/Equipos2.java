import java.util.Scanner;
import java.util.ArrayList;

public class Equipos2{
    public static Scanner teclado = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Ingrese el número de jugadores: ");
        int n = teclado.nextInt();

        ArrayList<String> blancos = new ArrayList<String>();
        ArrayList<String> negros = new ArrayList<String>();
        ArrayList<String> jugadores = new ArrayList<String>();

        int numeroaleatorio;
        String nombre;

        teclado.nextLine();
        for(int i=0; i<n; ++i){
            System.out.print(i+1 + ". ");
            nombre = teclado.nextLine();
            jugadores.add(nombre);
            numeroaleatorio = (int) (Math.random() * 2);
            if(numeroaleatorio == 0){
                if(blancos.size() < n/2){
                    blancos.add(jugadores.get(i));
                }else{
                    negros.add(jugadores.get(i));
                }
            }else{
                if(negros.size() < n/2){
                    negros.add(jugadores.get(i));
                }else{
                    blancos.add(jugadores.get(i));
                }
            }
        }

        System.out.print("Equipo blanco: ");
        for(int i=0; i<blancos.size();++i){
            System.out.print(blancos.get(i) + " ");
        }

        System.out.print("\nEquipo negro: ");
        for(int i=0; i<negros.size();++i){
            System.out.print(negros.get(i) + " ");
        }

        System.out.print("\n");

    }
}
