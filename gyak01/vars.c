#include <stdio.h>


int main() {
    // int típusú változó deklarálása, definiálása, inicializációja
    // int típusú literállal inicializáltuk
    int var_1 = 4;

    // print_f_: print _formatted_ -> feldolgozza az első argumentumában
    // átadott stringben szereplő formátum specifikátorokat.
    // %i == %d : előjeles egész számot egész számként (base 10)
    // teljes(ebb) lista a cppref-en és a következő órán
    // %8d : szóközökkel 8 karakter hosszúra egészíti ki a kiírt számot (táblázatokhoz)
    printf("%i\n", var_1 + 7);
    // Kifejezés azonos típusú kifejezést helyettesíthet
    // Matematikai műveletek értelmezéséhez a művelet precedenciájának
    // és zárójelezésének ismerete szükséges: https://en.cppreference.com/c/language/operator_precedence
    printf("%i\n", 6 + 7 * 2);

    // double típusú változó és literál
    double ratio = 5.3;
    // 5.0 <=> 5.
    // 0.3 <=> .3
    // (float) 5.0 == 5.0f

    // double típusú változó, int típusú literál -> implicit cast
    double f = 42;

    // (F - 32) * 5/9 = C
    double c = (f - 32) * ((double) 5 / 9);
    // (double) 5 / 9 <=> ((double) 5) / 9
    // A fenti műveletek sorrendje fontos, mert 5 / 9 == 0 (int / int -> int)
    // Ha egyik vagy másik operandus double vagy float, akkor az egész operandus
    // implicit konvertálódik, matematikai osztás történik. 

    //   egyszer az elején végrehajtja
    //   |          minden ciklus elején megvizsgálja, ha hamis, a ciklus utánra ugrik
    //   |          |       minden ciklus végén végrehajtja
    //   ˇ          ˇ       ˇ
    for (int i = 0; i < 10; i = i + 1) {
        printf("%5.2f\n", c);
        printf("%5.2f\n", f);
    }


    return 0;
}