import java.util.Scanner;
import java.util.ArrayList;

public class Equipos{
    public static Scanner teclado = new Scanner(System.in);

    public static void main(String[] args) {

        System.out.println("¿Cuántos jugadores son?");
        int n = teclado.nextInt();

        String[] jugadores = new String[n];
        String[] negros = new String[n/2];
        String[] blancos = new String[n/2];
        boolean[] usados = new boolean[n];

        for (int i=0; i<n; ++i) {
            usados[i]=false;
        }

        System.out.println("Introduzca el nombre de los jugadores:");
        teclado.nextLine();
        for (int i=0; i<n; ++i) {
            System.out.print(i+1 + ". ");
            jugadores[i] = teclado.nextLine();
        }

        int cont = 0;
        int pos;
        while(cont < n/2){
            pos = (int) (Math.random() * n);
            if(usados[pos]==false){
                negros[cont]=jugadores[pos];
                usados[pos]=true;
                cont++;
            }
        }

        while(cont < n){
            for (int i=0; i<n; ++i) {
                if(usados[i]==false){
                    blancos[n-cont-1]=jugadores[i];
                    cont++;
                }
            }
        }

        System.out.print("El equipo negro/rojo es:");
        for (int i=0; i<n/2; ++i) {
            System.out.print(negros[i] + " ");
        }

        System.out.print("\nEl equipo blanco/azul es:");
        for (int i=0; i<n/2; ++i) {
            System.out.print(blancos[i] + " ");
        }
        System.out.print("\n");
    }
}
