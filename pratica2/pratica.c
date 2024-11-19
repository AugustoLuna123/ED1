#include <stdio.h>
#include "duende.h"

int main() {
    int qtdDuendes, qtdTimes;
    Duende *duendes;
    Time *times;

    lerQuantidade(&qtdDuendes);
    qtdTimes = qtdDuendes / 4;
    duendes = alocaDuendes(qtdDuendes);
    times = alocaTimes(qtdTimes);
    lerDuendes(duendes, qtdDuendes);
    escalarTimes(duendes, times, qtdDuendes); // escalarTimes O(n^2) e proximoMaisvelho é O(n)
    printTimes(times, qtdTimes);
    desalocaDuendes(&duendes);
    desalocaTimes(&times);

    return 0; //nao remova
}
