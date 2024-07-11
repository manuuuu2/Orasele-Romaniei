#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iomanip.h>
#include <ctype.h>
void initializare();
void motto();
void intro();
void cautare();
void meniu();
void aplicatie();
void meniu_1();
void unu();
int quiz();
int afis_intreb(char nume_fis_intreb[33], char var_corecta[3]);
void parolauitata();
void cunostinte();
void patru();
void bibl();
void structura();
void memo();
void memo_dist();
void afis();
void autor();
int concluzie_quiz();
void introducere();
void citintreb();
int calculateDistance(int x1, int y1, int x2, int y2);
void afisconcl(int corecte, int gresite);
void sortare_descrescator_oras();
void sortare_crescator_oras();
void sortare_crescator_judet();
void sortare_descrescator_judet();
void sortare_crescator_populatie();
void sortare_descrescator_populatie();
void sortare_descrescator_altitudine();
void sortare_crescator_altitudine();
void cautare_dupa_judet();
void cupcaut();
void introdoi();
void introtrei();
void cautare_dupa_populatie();
void inregis();
void verific_user(char user[22]);
int verific_pass(char usernou[22]);
bool username_exists(const char* usernou);
void autentificare();
void verific_user_autentificare(char user[22]);
void colajfoto();
void cautare_dupa_altitudine();

struct orase
{
    char oras[99];
    char jud[20];
    char pop[99];
    char alt[99];
    char harta[99];
    int h;
}
e[320];
int n;
char oraselista[320][30];
int inregistrat = 0;

int main()
{
    initializare();
    memo();
    introducere();
    motto();
    meniu_1();
    cautare();
    return 0;
}

void motto()
{
    int ok = 0, x, y;
    cleardevice();
    readimagefile("Imagini/intro.gif", 0, 0, 1440, 800);
    while (!ok)
    {

        if (ismouseclick(WM_MOUSEMOVE))
        {
            getmouseclick(WM_MOUSEMOVE, x, y);
            if (x > 1161 && x < 1245 && y > 159 && y < 236)
                readimagefile("Imagini/intrhov.gif", 0, 0, 1440, 800);
            else
                readimagefile("Imagini/intro.gif", 0, 0, 1440, 800);
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 1161 && x < 1245 && y > 159 && y < 236)
            {
                ok = 1;
                meniu_1();
            }
        }
    }
    getch();

}

int nd;
int dist[50][50];
char l[50][50];

void memo_dist() {
    readimagefile("Imagini/aplication.gif", 0, 0, 1440, 800);
    char opt[3], tasta;
    int x, y, ok, z;
    do
    {
        readimagefile("Imagini/aplication.gif", 0, 0, 1440, 800);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        ok = 0;
        if (x > 500 && x < 930 && y>570 && y < 675)
        {
            aplicatie();
        }
    } while (!ok);
    getch();
    meniu_1();

}
int conversie_populatie(const char* pop) {
    return atoi(pop);
}



void aplicatie() {
    int i, j, nr;
    setlinestyle(SOLID_LINE, 0, 3);
    ifstream fis("distanta.txt");
    int nd = 0;
    while (fis >> nr) {
        nd++;
    }
    fis.close();
    ifstream f("distanta.txt");
    nd = sqrt(nd);
    int dist[50][50]; // Assuming maximum size for simplicity
    for (i = 0; i < nd; i++)
        for (j = 0; j < nd; j++)
            f >> dist[i][j];
    f.close();

    ifstream fisi("distanta_o.txt");
    int l[50];
    for (i = 0; i < nd; i++) {
        fisi >> l[i];
    }
    fisi.close();

    settextstyle(10, 0, 1);
    readimagefile("Imagini/aplicatie.jpg", 0, 0, 1440, 800);
    int coordonate[50][4] = {
        {510, 381, 529, 393}, {756, 727, 773, 740}, {193, 343, 211, 355}, {975, 292, 994, 306},
        {525, 106, 544, 119}, {638, 172, 656, 185}, {951, 65, 969, 79}, {1123, 504, 1143, 517},
        {787, 447, 805, 461}, {961, 520, 980, 535}, {1051, 691, 1068, 705}, {499, 252, 519, 264},
        {1223, 679, 1242, 691}, {529, 682, 546, 694}, {404, 413, 423, 425}, {374, 614, 399, 632},
        {1009, 427, 1035, 443}, {1136, 474, 1155, 487}, {860, 725, 880, 739}, {380, 433, 393, 440},
        {1080, 183, 1100, 197}, {815, 303, 835, 318}, {274, 212, 297, 229}, {908, 220, 928, 236},
        {694, 570, 714, 584}, {862, 569, 880, 582}, {607, 533, 627, 549}, {279, 514, 296, 528},
        {420, 80, 440, 93}, {834, 411, 856, 424}, {589, 429, 608, 442}, {621, 658, 641, 672},
        {1036, 628, 1055, 643}, {853, 102, 875, 116}, {782, 573, 804, 587}, {475, 550, 495, 564},
        {658, 277, 678, 291}, {175, 433, 195, 447}, {1258, 523, 1278, 537}, {1106, 285, 1125, 300},
        {431, 183, 450, 198}
    };

    ifstream orase_file("distanta_o.txt");
    char orase[50][50];
    for (int i = 0; i < nd; i++) {
        orase_file >> orase[i];
    }
    orase_file.close();

    int x1, y1, x2, y2;
    int click = 0;
    char orasselect[2][50] = { {0} };
    char distanta[100];

    setbkcolor(WHITE);
    setcolor(BLACK);
    cleardevice();
    readimagefile("Imagini/aplicatie.jpg", 0, 0, 1440, 800);
    outtextxy(10, 680, "Prima alegere este: ");
    outtextxy(10, 700, "A doua alegere este: ");
    outtextxy(10, 720, "Dist. ...-... este: ...");
    outtextxy(10, 770, "Apasa pe SPACE pentru a continua cu alte orase.");
    outtextxy(10, 30, "Apasa tasta 'q' pentru a iesi");
    outtextxy(10, 60, "la meniul principal.");

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);

            for (int i = 0; i < nd; i++) {
                if (x >= coordonate[i][0] && x <= coordonate[i][2] && y >= coordonate[i][1] && y <= coordonate[i][3]) {
                    setcolor(YELLOW);
                    setfillstyle(SOLID_FILL, YELLOW);
                    fillellipse((coordonate[i][0] + coordonate[i][2]) / 2, (coordonate[i][1] + coordonate[i][3]) / 2, 8, 8);
                    strcpy(orasselect[click], orase[i]);
                    click++;
                    setcolor(BLACK);
                    if (click == 1) {
                        outtextxy(10, 680, "Prima alegere este: ");
                        setcolor(RED);
                        outtextxy(235, 680, orasselect[0]);
                    }
                    else if (click == 2) {
                        outtextxy(10, 700, "A doua alegere este: ");
                        setcolor(RED);
                        outtextxy(235, 700, orasselect[1]);

                        int poz1 = -1, poz2 = -1;
                        for (int j = 0; j < nd; j++) {
                            if (strcmp(orasselect[0], orase[j]) == 0)
                                poz1 = j;
                            if (strcmp(orasselect[1], orase[j]) == 0)
                                poz2 = j;
                        }
                        if (poz1 != -1 && poz2 != -1) {
                            setcolor(RED);
                            line((coordonate[poz1][0] + coordonate[poz1][2]) / 2, (coordonate[poz1][1] + coordonate[poz1][3]) / 2,
                                (coordonate[poz2][0] + coordonate[poz2][2]) / 2, (coordonate[poz2][1] + coordonate[poz2][3]) / 2);
                            setcolor(BLACK);
                            char dist_text[100];
                            strcpy(dist_text, "Dist. ");
                            setcolor(RED);
                            strcat(dist_text, orasselect[0]);
                            strcat(dist_text, "-");
                            setcolor(RED);
                            strcat(dist_text, orasselect[1]);
                            setcolor(BLACK);
                            strcat(dist_text, " este: ");
                            char dist_str[20];
                            itoa(dist[poz1][poz2], dist_str, 10);
                            strcat(dist_text, dist_str);
                            strcat(dist_text, " km");
                            outtextxy(10, 720, dist_text);
                        }
                        else {
                            setcolor(BLACK);
                            outtextxy(10, 720, "Nu s-a putut gasi distanta.");
                        }
                        click = 0;
                        memset(orasselect, 0, sizeof(orasselect)); // Reset orasselect
                    }
                }
            }
        }

        if (kbhit()) {
            char ch = getch();
            if (ch == ' ') {
                cleardevice();
                readimagefile("Imagini/aplicatie.jpg", 0, 0, 1440, 800);
                setcolor(BLACK);
                outtextxy(10, 680, "Prima alegere este: ");
                outtextxy(10, 700, "A doua alegere este: ");
                outtextxy(10, 720, "Dist. ...-... este: ...");
                outtextxy(10, 770, "Apasa pe SPACE pentru a continua cu alte orase.");
                outtextxy(10, 30, "Apasa tasta 'q' pentru a iesi");
                outtextxy(10, 60, "la meniul principal.");
                click = 0;
                memset(orasselect, 0, sizeof(orasselect)); // Reset orasselect
            }
            else if (ch == 'q') {
                setbkcolor(BLACK);
                setcolor(WHITE);
                cleardevice();
                meniu_1();
                return;
            }
        }
    }
    setbkcolor(BLACK);
    closegraph();
}





void cupcaut()
{
    int x, y, ok = 0;
    readimagefile("Imagini/cuprinscaut.gif", 0, 0, 1440, 800);
    while (!ok)
    {

        if (ismouseclick(WM_MOUSEMOVE))
        {
            getmouseclick(WM_MOUSEMOVE, x, y);
            if (x > 198 && x < 605 && y > 252 && y < 348)
                readimagefile("Imagini/orashov.gif", 0, 0, 1440, 800);
            else if (x > 834 && x < 1239 && y > 251 && y < 348)
                readimagefile("Imagini/judhov.gif", 0, 0, 1440, 800);
            else if (x > 308 && x < 706 && y > 407 && y < 507)
                readimagefile("Imagini/pophov.gif", 0, 0, 1440, 800);
            else if (x > 736 && x < 1136 && y > 408 && y < 500)
                readimagefile("Imagini/althov.gif", 0, 0, 1440, 800);
            else if (x > 932 && x < 1337 && y > 601 && y < 696)
                readimagefile("Imagini/menhov.gif", 0, 0, 1440, 800);
            else
                readimagefile("Imagini/cuprinscaut.gif", 0, 0, 1440, 800);
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 198 && x < 605 && y > 252 && y < 348)
            {
                ok = 1;
                cautare();
            }
            if (x > 834 && x < 1239 && y > 251 && y < 348)
            {
                ok = 1;
                cautare_dupa_judet();
            }
            if (x > 308 && x < 706 && y > 407 && y < 507)
            {
                ok = 1;
                cautare_dupa_populatie();
            }
            if (x > 736 && x < 1136 && y > 408 && y < 500)
            {
                ok = 1;
                cautare_dupa_altitudine();
            }
            if (x > 932 && x < 1337 && y > 601 && y < 696)
            {
                ok = 1;
                meniu_1();
            }
        }
    }
}


void cautare() {
    cleardevice();
    char nume_oras[30];
    int x, y, k = 0;
    readimagefile("Imagini/cautareoras.gif", 0, 0, 1440, 800);
    char caut[50] = ""; // Initializam ?irul de caractere pentru cautare
    char lit, folder[100];
    int gasit = 0, poz = -1, i;

    setbkcolor(WHITE);  // Seteaza fundalul alb
    setcolor(BLACK);    // Seteaza textul negru

    int cautare_x1 = 291;
    int cautare_y1 = 532;
    int cautare_x2 = 504;
    int cautare_y2 = 583;

    bool hover_cautare = false;

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > cautare_x1 && x < cautare_x2 && y > cautare_y1 && y < cautare_y2 && strlen(caut) > 0) {
                settextstyle(10, 0, 5);
                outtextxy(111, 382, caut);
                delay(500);
                gasit = 0; // Resetam indicatorul de gasire
                for (i = 0; i < n; i++) {
                    if (stricmp(caut, e[i].oras) == 0) {
                        gasit = 1;
                        poz = i;
                        break;
                    }
                }

                if (gasit == 0) {
                    settextstyle(10, 0, 3);
                    outtextxy(642, 700, "Nu am gasit.");
                    delay(500);
                    cupcaut();
                }
                else {
                    cleardevice();
                    settextstyle(10, 0, 5);

                    strcpy(folder, "harti/");
                    strcat(folder, e[poz].harta);
                    readimagefile("Imagini/orasgasit.gif", 0, 0, 1440, 800);
                    setbkcolor(BLACK);
                    setcolor(WHITE);
                    int judet_x1 = 281;
                    int judet_y1 = 241;
                    int judet_x2 = 657;
                    int judet_y2 = 336;

                    int pop_x1 = 325;
                    int pop_y1 = 402;
                    int pop_x2 = 660;
                    int pop_y2 = 500;

                    int alt_x1 = 354;
                    int alt_y1 = 563;
                    int alt_x2 = 657;
                    int alt_y2 = 658;

                    int mijloc_judet_x = (judet_x1 + judet_x2) / 2;
                    int mijloc_judet_y = (judet_y1 + judet_y2) / 2;

                    int mijloc_pop_x = (pop_x1 + pop_x2) / 2;
                    int mijloc_pop_y = (pop_y1 + pop_y2) / 2;

                    int mijloc_alt_x = (alt_x1 + alt_x2) / 2;
                    int mijloc_alt_y = (alt_y1 + alt_y2) / 2;

                    int judet_width = textwidth(e[poz].jud);
                    int judet_height = textheight(e[poz].jud);

                    int pop_width = textwidth(e[poz].pop);
                    int pop_height = textheight(e[poz].pop);

                    int alt_width = textwidth(e[poz].alt);
                    int alt_height = textheight(e[poz].alt);

                    int judet_x = mijloc_judet_x - judet_width / 2;
                    int judet_y = mijloc_judet_y - judet_height / 2;

                    int pop_x = mijloc_pop_x - pop_width / 2;
                    int pop_y = mijloc_pop_y - pop_height / 2;

                    int alt_x = mijloc_alt_x - alt_width / 2;
                    int alt_y = mijloc_alt_y - alt_height / 2;

                    outtextxy(judet_x, judet_y, e[poz].jud);
                    outtextxy(pop_x, pop_y, e[poz].pop);
                    outtextxy(alt_x, alt_y, e[poz].alt);

                    int titlu_x = (442 + 995) / 2 - textwidth(e[poz].oras) / 2;
                    int titlu_y = (76 + 170) / 2 - textheight(e[poz].oras) / 2;
                    outtextxy(titlu_x, titlu_y, e[poz].oras);

                    readimagefile(folder, 756, 243, 1346, 659);
                }

                getch();
                cupcaut();
                return;
            }
        }

        if (kbhit()) {
            lit = getch();
            if (isalpha(lit)) {
                caut[k] = lit;
                k++;
                caut[k] = '\0';
                settextstyle(10, 0, 5);
                outtextxy(111, 382, caut);
            }
        }

        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, x, y);
            if (x > cautare_x1 && x < cautare_x2 && y > cautare_y1 && y < cautare_y2) {
                if (!hover_cautare) {
                    readimagefile("Imagini/cauthov1.gif", 0, 0, 1440, 800);
                    outtextxy(111, 382, caut);
                    hover_cautare = true;
                }
            }
            else {
                if (hover_cautare) {
                    readimagefile("Imagini/cautareoras.gif", 0, 0, 1440, 800);
                    outtextxy(111, 382, caut);
                    hover_cautare = false;
                }
            }
        }

        if (kbhit() && lit == char(27)) {
            meniu_1();
            return;
        }
    }
}
void cautare_dupa_judet() {
    cleardevice();
    char nume_judet[30], folder[100], tasta;
    char caut[50] = "";
    char lit;
    int gasit = 0, k = 0, i;
    int y = 200;
    int spatiu = 30;
    int j;
    int x, ok;

    readimagefile("Imagini/judetcaut.gif", 0, 0, 1440, 800);
    setbkcolor(WHITE);
    setcolor(BLACK);

    bool hover_cautare = false;

    // Bucla principala pentru gestionarea interactiunii
    while (true) {
        // Verificare evenimente de la tastatura
        if (kbhit()) {
            lit = getch();
            if (isalpha(lit)) {
                caut[k] = lit;
                k++;
                caut[k] = '\0';
                settextstyle(10, 0, 5);
                outtextxy(111, 382, caut);
            }
        }

        // Verificare evenimente de la mouse
        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, x, y);
            if (x > 291 && x < 504 && y > 532 && y < 583) {
                if (!hover_cautare) {
                    readimagefile("Imagini/judetcauthov.gif", 0, 0, 1440, 800);
                    outtextxy(111, 382, caut);
                    hover_cautare = true;
                }
            }
            else {
                if (hover_cautare) {
                    readimagefile("Imagini/judetcaut.gif", 0, 0, 1440, 800);
                    outtextxy(111, 382, caut);
                    hover_cautare = false;
                }
            }
        }

        // Verificare eveniment de click pe butonul de cautare dupa judet
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 291 && x < 504 && y > 532 && y < 583 && strlen(caut) > 0) {
                settextstyle(10, 0, 3);
                gasit = 0;
                y = 200;

                int rezultate[100];
                int nr_rezultate = 0;

                // Cautare in lista de orase dupa judet
                for (i = 0; i < n; i++) {
                    if (stricmp(caut, e[i].jud) == 0) {
                        rezultate[nr_rezultate++] = i;
                        gasit = 1;
                    }
                }

                if (gasit == 0) {
                    settextstyle(10, 0, 3);
                    outtextxy(642, 700, "Nu am gasit.");
                    delay(500);
                    cupcaut();
                    return;
                }

                int pagina_curenta = 0;
                int rezultate_per_pagina = 5;
                int total_pagini = (nr_rezultate + rezultate_per_pagina - 1) / rezultate_per_pagina;
                char pagina[20];

                // Afi?are rezultate pe pagini
                do {
                    cleardevice();
                    setbkcolor(BLACK);
                    setcolor(WHITE);
                    readimagefile("Imagini/Afisare2.gif", 0, 0, 1440, 800);
                    itoa(pagina_curenta + 1, pagina, 10);
                    strcat(pagina, "/");
                    itoa(total_pagini, pagina + strlen(pagina), 10);
                    outtextxy(1200, 30, pagina);
                    settextstyle(10, 0, 3);

                    // Afi?are rezultate pentru pagina curenta
                    for (j = pagina_curenta * rezultate_per_pagina; j < nr_rezultate && j < (pagina_curenta + 1) * rezultate_per_pagina; j++) {
                        int idx = rezultate[j];
                        int kkk = j % rezultate_per_pagina;

                        int imgX1 = 1190;
                        int imgY1 = 0 + (kkk + 1) * (290 - 157);
                        int imgX2 = 1435;
                        int imgY2 = 130 + (kkk + 1) * (290 - 157);

                        int textWidthOras = textwidth(e[idx].oras);
                        int textWidthJud = textwidth(e[idx].jud);
                        int textWidthPop = textwidth(e[idx].pop);
                        int textWidthAlt = textwidth(e[idx].alt);

                        int xOras = 40 + (260 - textWidthOras) / 2;
                        int xJud = 410 + (212 - textWidthJud) / 2;
                        int xPop = 650 + (340 - textWidthPop) / 2;
                        int xAlt = 920 + (307 - textWidthAlt) / 2;

                        outtextxy(xOras, 55 + (kkk + 1) * 132, e[idx].oras);
                        outtextxy(xJud, 55 + (kkk + 1) * 132, e[idx].jud);
                        outtextxy(xPop, 55 + (kkk + 1) * 132, e[idx].pop);
                        outtextxy(xAlt, 55 + (kkk + 1) * 132, e[idx].alt);

                        strcpy(folder, "harti/");
                        strcat(folder, e[idx].harta);

                        readimagefile(folder, imgX1, imgY1, imgX2, imgY2);
                    }

                    // Gestionarea clicurilor de mouse ?i a tastaturii pentru navigare
                    do {
                        getmouseclick(WM_LBUTTONDOWN, x, y);
                        if (x > 240 && x < 300 && y > 5 && y < 65 && pagina_curenta < total_pagini - 1) {
                            pagina_curenta++;
                            break;
                        }
                        else if (x > 170 && x < 230 && y > 5 && y < 65 && pagina_curenta > 0) {
                            pagina_curenta--;
                            break;
                        }
                        else if (x > 80 && x < 140 && y > 5 && y < 65) {
                            cupcaut();
                            return;
                        }

                        if (kbhit()) {
                            tasta = getch();
                            if (tasta == 27) {
                                cupcaut();
                                return;
                            }
                        }
                    } while (true);

                } while (true);

                return;
            }
        }

        // Verificare apasare tasta Esc pentru revenire la meniu
        if (kbhit() && lit == char(27)) {
            cupcaut();
            return;
        }
    }
}
void cautare_dupa_populatie() {
    cleardevice();
    char folder[100], tasta;
    char caut_min[50] = "", caut_max[50] = "";
    char lit;
    int gasit = 0, k = 0, i;
    int y = 200;
    int spatiu = 30;
    int j;
    int x, y_click, ok;
    int min_populatie, max_populatie;

    readimagefile("Imagini/popul.gif", 0, 0, 1440, 800);
    setbkcolor(WHITE);  // Seteaza fundalul alb
    setcolor(BLACK);    // Seteaza textul negru
    settextstyle(10, 0, 5);

    // Citirea valorilor minime pentru popula?ie
    k = 0;
    do {
        lit = getch();
        if (isdigit(lit)) {
            caut_min[k] = lit;
            k++;
            caut_min[k] = '\0';
            outtextxy(110, 309, caut_min);
        }
    } while (lit != char(13));
    min_populatie = atoi(caut_min);

    // Citirea valorilor maxime pentru popula?ie
    k = 0;
    do {
        lit = getch();
        if (isdigit(lit)) {
            caut_max[k] = lit;
            k++;
            caut_max[k] = '\0';
            outtextxy(110, 503, caut_max);
        }
    } while (lit != char(13));
    max_populatie = atoi(caut_max);

    // Bucla pentru gestionarea hoverului ?i click-ului pe buton
    bool hover_buton = false;
    do {
        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, x, y_click);

            // Verifica hover-ul pe buton
            if (x > 291 && x < 609 && y_click > 530 && y_click < 689) {
                if (!hover_buton) {
                    readimagefile("Imagini/populhov.gif", 0, 0, 1440, 800);
                    outtextxy(110, 309, caut_min);
                    outtextxy(110, 503, caut_max);
                    hover_buton = true;
                }
            }
            else {
                if (hover_buton) {
                    readimagefile("Imagini/popul.gif", 0, 0, 1440, 800);
                    outtextxy(110, 309, caut_min);
                    outtextxy(110, 503, caut_max);
                    hover_buton = false;
                }
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y_click);
            if (x > 291 && x < 609 && y_click > 530 && y_click < 689) {
                // �ncepe cautarea popula?iei
                gasit = 0;
                y = 200;

                // Creaza un array pentru stocarea rezultatelor gasite
                int rezultate[1000];
                int nr_rezultate = 0;

                for (i = 1; i < n; i++) {
                    int populatie = conversie_populatie(e[i].pop);
                    if (populatie >= min_populatie && populatie <= max_populatie) {
                        rezultate[nr_rezultate++] = i;
                        gasit = 1;
                    }
                }

                if (gasit == 0) {
                    settextstyle(10, 0, 3);
                    outtextxy(642, 700, "Nu am gasit.");
                    delay(500);
                    cupcaut();
                    return;
                }

                // Paginarea rezultatelor gasite
                int pagina_curenta = 0;
                int rezultate_per_pagina = 5;
                int total_pagini = (nr_rezultate + rezultate_per_pagina - 1) / rezultate_per_pagina;
                char pagina[20];

                do {
                    cleardevice();
                    setbkcolor(BLACK);
                    setcolor(WHITE);
                    settextstyle(10, 0, 3);
                    readimagefile("Imagini/Afisare2.gif", 0, 0, 1440, 800);
                    itoa(pagina_curenta + 1, pagina, 10);
                    strcat(pagina, "/");
                    itoa(total_pagini, pagina + strlen(pagina), 10);
                    outtextxy(1200, 30, pagina);
                    settextstyle(10, 0, 3);

                    for (j = pagina_curenta * rezultate_per_pagina; j < nr_rezultate && j < (pagina_curenta + 1) * rezultate_per_pagina; j++) {
                        int idx = rezultate[j];
                        int kkk = j % rezultate_per_pagina;

                        int imgX1 = 1190;
                        int imgY1 = 0 + (kkk + 1) * (290 - 157);
                        int imgX2 = 1435;
                        int imgY2 = 130 + (kkk + 1) * (290 - 157);

                        int textWidthOras = textwidth(e[idx].oras);
                        int textWidthJud = textwidth(e[idx].jud);
                        int textWidthPop = textwidth(e[idx].pop);
                        int textWidthAlt = textwidth(e[idx].alt);

                        int xOras = 40 + (260 - textWidthOras) / 2;
                        int xJud = 410 + (212 - textWidthJud) / 2;
                        int xPop = 650 + (340 - textWidthPop) / 2;
                        int xAlt = 920 + (307 - textWidthAlt) / 2;

                        outtextxy(xOras, 55 + (kkk + 1) * 132, e[idx].oras);
                        outtextxy(xJud, 55 + (kkk + 1) * 132, e[idx].jud);
                        outtextxy(xPop, 55 + (kkk + 1) * 132, e[idx].pop);
                        outtextxy(xAlt, 55 + (kkk + 1) * 132, e[idx].alt);

                        strcpy(folder, "harti/");
                        strcat(folder, e[idx].harta);

                        readimagefile(folder, imgX1, imgY1, imgX2, imgY2);
                    }

                    // Gestionarea clicurilor de mouse ?i a tastaturii
                    do {
                        getmouseclick(WM_LBUTTONDOWN, x, y_click);
                        if (x > 240 && x < 300 && y_click > 5 && y_click < 65 && pagina_curenta < total_pagini - 1) {
                            pagina_curenta++;
                            break;
                        }
                        else if (x > 170 && x < 230 && y_click > 5 && y_click < 65 && pagina_curenta > 0) {
                            pagina_curenta--;
                            break;
                        }
                        else if (x > 80 && x < 140 && y_click > 5 && y_click < 65) {
                            cupcaut();
                            return;
                        }

                        if (kbhit()) {
                            tasta = getch();
                            if (tasta == 27) {
                                cupcaut();
                                return;
                            }
                        }
                    } while (true);

                } while (true);
            }
        }
    } while (true);
}





void cautare_dupa_altitudine() {
    cleardevice();
    char folder[100], tasta;
    char caut_min[50] = "", caut_max[50] = "";
    char lit;
    int gasit = 0, k = 0, i;
    int y = 200;
    int spatiu = 30;
    int j;
    int x, y_click, ok;
    int min_altitudine, max_altitudine;

    readimagefile("Imagini/altit.gif", 0, 0, 1440, 800);
    setbkcolor(WHITE);  // Seteaza fundalul alb
    setcolor(BLACK);    // Seteaza textul negru
    settextstyle(10, 0, 5);

    // Citirea valorilor minime pentru altitudine
    k = 0;
    do {
        lit = getch();
        if (isdigit(lit)) {
            caut_min[k] = lit;
            k++;
            caut_min[k] = '\0';
            outtextxy(110, 309, caut_min);
        }
    } while (lit != char(13));
    min_altitudine = atoi(caut_min);

    // Citirea valorilor maxime pentru altitudine
    k = 0;
    do {
        lit = getch();
        if (isdigit(lit)) {
            caut_max[k] = lit;
            k++;
            caut_max[k] = '\0';
            outtextxy(110, 503, caut_max);
        }
    } while (lit != char(13));
    max_altitudine = atoi(caut_max);

    // Bucla pentru gestionarea hoverului ?i a click-ului pe buton
    bool hover_buton = false;
    do {
        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, x, y_click);

            // Verifica hover-ul pe buton
            if (x > 291 && x < 609 && y_click > 530 && y_click < 689) {
                if (!hover_buton) {
                    readimagefile("Imagini/altithov.gif", 0, 0, 1440, 800);
                    outtextxy(110, 309, caut_min);
                    outtextxy(110, 503, caut_max);
                    hover_buton = true;
                }
            }
            else {
                if (hover_buton) {
                    readimagefile("Imagini/altit.gif", 0, 0, 1440, 800);
                    outtextxy(110, 309, caut_min);
                    outtextxy(110, 503, caut_max);
                    hover_buton = false;
                }
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y_click);
            if (x > 291 && x < 609 && y_click > 530 && y_click < 689) {
                // �ncepe cautarea dupa altitudine
                gasit = 0;
                y = 200;

                // Creaza un array pentru stocarea rezultatelor gasite
                int rezultate[1000];
                int nr_rezultate = 0;

                for (i = 1; i < n; i++) {
                    int altitudine = atoi(e[i].alt);
                    if (altitudine >= min_altitudine && altitudine <= max_altitudine) {
                        rezultate[nr_rezultate++] = i;
                        gasit = 1;
                    }
                }

                if (gasit == 0) {
                    settextstyle(10, 0, 3);
                    outtextxy(642, 700, "Nu am gasit.");
                    delay(500);
                    cupcaut();
                    return;
                }

                // Paginarea rezultatelor gasite
                int pagina_curenta = 0;
                int rezultate_per_pagina = 5;
                int total_pagini = (nr_rezultate + rezultate_per_pagina - 1) / rezultate_per_pagina;
                char pagina[20];

                do {
                    cleardevice();
                    setbkcolor(BLACK);
                    setcolor(WHITE);
                    settextstyle(10, 0, 3);
                    readimagefile("Imagini/Afisare2.gif", 0, 0, 1440, 800);
                    itoa(pagina_curenta + 1, pagina, 10);
                    strcat(pagina, "/");
                    itoa(total_pagini, pagina + strlen(pagina), 10);
                    outtextxy(1200, 30, pagina);
                    settextstyle(10, 0, 3);

                    for (j = pagina_curenta * rezultate_per_pagina; j < nr_rezultate && j < (pagina_curenta + 1) * rezultate_per_pagina; j++) {
                        int idx = rezultate[j];
                        int kkk = j % rezultate_per_pagina;

                        int imgX1 = 1190;
                        int imgY1 = 0 + (kkk + 1) * (290 - 157);
                        int imgX2 = 1435;
                        int imgY2 = 130 + (kkk + 1) * (290 - 157);

                        int textWidthOras = textwidth(e[idx].oras);
                        int textWidthJud = textwidth(e[idx].jud);
                        int textWidthPop = textwidth(e[idx].pop);
                        int textWidthAlt = textwidth(e[idx].alt);

                        int xOras = 40 + (260 - textWidthOras) / 2;
                        int xJud = 410 + (212 - textWidthJud) / 2;
                        int xPop = 650 + (340 - textWidthPop) / 2;
                        int xAlt = 920 + (307 - textWidthAlt) / 2;

                        outtextxy(xOras, 55 + (kkk + 1) * 132, e[idx].oras);
                        outtextxy(xJud, 55 + (kkk + 1) * 132, e[idx].jud);
                        outtextxy(xPop, 55 + (kkk + 1) * 132, e[idx].pop);
                        outtextxy(xAlt, 55 + (kkk + 1) * 132, e[idx].alt);

                        strcpy(folder, "harti/");
                        strcat(folder, e[idx].harta);

                        readimagefile(folder, imgX1, imgY1, imgX2, imgY2);
                    }

                    // Gestionarea clicurilor de mouse ?i a tastaturii
                    do {
                        getmouseclick(WM_LBUTTONDOWN, x, y_click);
                        if (x > 240 && x < 300 && y_click > 5 && y_click < 65 && pagina_curenta < total_pagini - 1) {
                            pagina_curenta++;
                            break;
                        }
                        else if (x > 170 && x < 230 && y_click > 5 && y_click < 65 && pagina_curenta > 0) {
                            pagina_curenta--;
                            break;
                        }
                        else if (x > 80 && x < 140 && y_click > 5 && y_click < 65) {
                            cupcaut();
                            return;
                        }

                        if (kbhit()) {
                            tasta = getch();
                            if (tasta == 27) {
                                cupcaut();
                                return;
                            }
                        }
                    } while (true);

                } while (true);
            }
        }
    } while (true);
}
void initializare()
{
    int gdriver = DETECT, gmode, errorcode;
    initwindow(1440, 800, "Orasele Romaniei");
}

void introducere()
{
    int x = 0;
    int y = 0;
    int latime = 480;
    int inaltime = 400;
    int timp_intarziere = 100;
    int pozitie_curenta = 0;

    setcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, 1);


    for (int r = 0; r <= 2; r++) {
        line(x, y + r * inaltime, x + 3 * latime, y + r * inaltime);
    }
    for (int c = 0; c <= 3; c++) {
        line(x + c * latime, y, x + c * latime, y + 2 * inaltime);
    }

    while (true) {

        for (int r = 0; r < 2; r++) {
            for (int c = 0; c < 3; c++) {
                char nume_fisier[20];
                sprintf(nume_fisier, "Colaj/%d.jpg", (pozitie_curenta + r * 3 + c) % 14 + 1);

                readimagefile(nume_fisier, x + c * latime, y + r * inaltime, x + (c + 1) * latime, y + (r + 1) * inaltime);

                delay(timp_intarziere);

                if (kbhit()) {
                    getch();
                    meniu_1();
                }
            }
        }


        for (int r = 0; r <= 2; r++) {
            line(x, y + r * inaltime, x + 3 * latime, y + r * inaltime);
        }
        for (int c = 0; c <= 3; c++) {
            line(x + c * latime, y, x + c * latime, y + 2 * inaltime);
        }

        pozitie_curenta = (pozitie_curenta + 6) % 14;

        delay(350);
        readimagefile("Imagini/Coperta.jpg", 0, 0, 1440, 800);
        getch();
        motto();
    }
    setbkcolor(BLACK);
}


void memo()
{
    int k = 0;
    int i;
    fstream fis("harta.txt", ios::in);
    for (i = 0; i <= 318; i++)
    {
        k++;
        fis >> e[k].oras;
        fis >> e[k].jud;
        fis >> e[k].pop;
        fis >> e[k].alt;
        fis >> e[k].harta;
    }
    n = k;
}


void afisareintro()
{

    int x, y, ok = 0;
    readimagefile("Imagini/afisorase.gif", 0, 0, 1440, 800);
    while (!ok)
    {
        if (ismouseclick(WM_MOUSEMOVE))
        {
            getmouseclick(WM_MOUSEMOVE, x, y);
            if (x > 303 && x < 708 && y>253 && y < 351)
                readimagefile("Imagini/bazhov.gif", 0, 0, 1440, 800);
            else if (x > 734 && x < 1144 && y>253 && y < 350)
                readimagefile("Imagini/cauthov.gif", 0, 0, 1440, 800);
            else if (x > 514 && x < 925 && y>429 && y < 525)
                readimagefile("Imagini/colajhov.gif", 0, 0, 1440, 800);
            else if (x > 928 && x < 1338 && y > 603 && y < 697)
                readimagefile("Imagini/meniuhov.gif", 0, 0, 1440, 800);
            else
                readimagefile("Imagini/afisorase.gif", 0, 0, 1440, 800);
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (303 && x < 708 && y>253 && y < 351)
            {
                ok = 1;
                afis();
            }
            if (x > 734 && x < 1144 && y>253 && y < 350)
            {
                ok = 1;
                cupcaut();
            }
            if (x > 514 && x < 925 && y>429 && y < 525)
            {
                ok = 1;
                colajfoto();
            }
            if (x > 928 && x < 1338 && y > 603 && y < 697)
            {
                ok = 1;
                meniu_1();
            }
        }
    }

}







void colajfoto()
{
    cleardevice();
    readimagefile("Imagini/colaj.gif", 0, 0, 1440, 800);
    getch();
    meniu_1();
}



int meniuapas = 0; // variabila pentru a verifica daca s-a apasat tasta pentru meniu

void afis()
{
    int i = 0, kkk = 0;
    char pagina[10] = "";
    char folder[100];
    char tasta;
    int x, y, ok;

    settextstyle(10, 0, 3);
    setbkcolor(BLACK);
    setcolor(WHITE);
    readimagefile("Imagini/Afisare.gif", 0, 0, 1440, 800);

    do {
        itoa(i / 5 + 1, pagina, 10);
        strcat(pagina, "/64");
        outtextxy(1200, 30, pagina);

        int latimeacadr = 345 - 5;
        int inaltimeacadr = 290 - 157;

        for (int j = i + 1; j <= n && j <= i + 5; j++) {
            kkk++;

            int imgX1 = 1190;
            int imgY1 = 0 + kkk * inaltimeacadr;
            int imgX2 = 1435;
            int imgY2 = 130 + kkk * inaltimeacadr;

            int textWidthOras = textwidth(e[j].oras);
            int textWidthJud = textwidth(e[j].jud);
            int textWidthPop = textwidth(e[j].pop);
            int textWidthAlt = textwidth(e[j].alt);

            int xOras = 40 + (260 - textWidthOras) / 2;
            int xJud = 410 + (212 - textWidthJud) / 2;
            int xPop = 650 + (340 - textWidthPop) / 2;
            int xAlt = 920 + (307 - textWidthAlt) / 2;

            outtextxy(xOras, 55 + kkk * 132, e[j].oras);
            outtextxy(xJud, 55 + kkk * 132, e[j].jud);
            outtextxy(xPop, 55 + kkk * 132, e[j].pop);
            outtextxy(xAlt, 55 + kkk * 132, e[j].alt);

            strcpy(folder, "harti/");
            strcat(folder, e[j].harta);

            readimagefile(folder, imgX1, imgY1, imgX2, imgY2);
        }

        do {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 240 && x < 300 && y > 5 && y < 65) {
                i += 5;
                break;
            }
            else if (x > 170 && x < 230 && y > 5 && y < 65 && i > 0) {
                i -= 5;
                break;
            }
            else if (x > 80 && x < 140 && y > 5 && y < 65) {
                meniu_1();
                return;
            }
            else if (x > 300 && x < 333 && y > 70 && y < 97) {
                sortare_crescator_oras();
                i = 0;
                break;
            }
            else if (x > 300 && x < 330 && y > 102 && y < 127) {
                sortare_descrescator_oras();
                i = 0;
                break;
            }
            else if (x > 635 && x < 666 && y > 72 && y < 98) {
                sortare_crescator_judet();
                i = 0;
                break;
            }
            else if (x > 634 && x < 664 && y > 103 && y < 128) {
                sortare_descrescator_judet();
                i = 0;
                break;
            }
            else if (x > 909 && x < 940 && y > 71 && y < 97) {
                sortare_crescator_populatie();
                i = 0;
                break;
            }
            else if (x > 910 && x < 940 && y > 102 && y < 127) {
                sortare_descrescator_populatie();
                i = 0;
                break;
            }
            else if (x > 1136 && x < 1168 && y > 71 && y < 97) {
                sortare_crescator_altitudine();
                i = 0;
                break;
            }
            else if (x > 1136 && x < 1167 && y > 102 && y < 127) {
                sortare_descrescator_altitudine();
                i = 0;
                break;
            }

            if (kbhit()) {
                tasta = getch();
                if (tasta == 27) {
                    meniu_1();
                    return;
                }
            }
        } while (true);

        kkk = 0;
        cleardevice();
        readimagefile("Imagini/Afisare.gif", 0, 0, 1440, 800);
    } while (!kbhit());
}

void sortare_crescator_oras()
{
    int ok, ii;
    orase inv;
    do {
        ok = 0;
        for (ii = 0; ii < n - 1; ii++) {
            if (strcmp(e[ii].oras, e[ii + 1].oras) > 0) {
                inv = e[ii];
                e[ii] = e[ii + 1];
                e[ii + 1] = inv;
                ok = 1;
            }
        }
    } while (ok);
}

void sortare_descrescator_oras()
{
    int ok, ii;
    orase inv;
    do {
        ok = 0;
        for (ii = 0; ii < n - 1; ii++) {
            if (strcmp(e[ii].oras, e[ii + 1].oras) < 0) {
                inv = e[ii];
                e[ii] = e[ii + 1];
                e[ii + 1] = inv;
                ok = 1;
            }
        }
    } while (ok);
}

void sortare_crescator_judet()
{
    int ok, ii;
    orase inv;
    do {
        ok = 0;
        for (ii = 0; ii < n - 1; ii++) {
            if (strcmp(e[ii].jud, e[ii + 1].jud) > 0) {
                inv = e[ii];
                e[ii] = e[ii + 1];
                e[ii + 1] = inv;
                ok = 1;
            }
        }
    } while (ok);
}

void sortare_descrescator_judet()
{
    int ok, ii;
    orase inv;
    do {
        ok = 0;
        for (ii = 0; ii < n - 1; ii++) {
            if (strcmp(e[ii].jud, e[ii + 1].jud) < 0) {
                inv = e[ii];
                e[ii] = e[ii + 1];
                e[ii + 1] = inv;
                ok = 1;
            }
        }
    } while (ok);
}

void sortare_crescator_populatie()
{
    int ok = 0, ii;
    orase inv;
    do {
        ok = 0;
        for (ii = 0; ii < n - 1; ii++) {
            if (atoi(e[ii].pop) > atoi(e[ii + 1].pop)) {
                inv = e[ii];
                e[ii] = e[ii + 1];
                e[ii + 1] = inv;
                ok = 1;
            }
        }
    } while (ok);
}
void sortare_descrescator_populatie()
{
    int ok = 0, ii;
    orase inv;
    do {
        ok = 0;
        for (ii = 1; ii < n - 1; ii++) {
            if (atoi(e[ii].pop) < atoi(e[ii + 1].pop)) {
                inv = e[ii];
                e[ii] = e[ii + 1];
                e[ii + 1] = inv;
                ok = 1;
            }
        }
    } while (ok);
}


void sortare_crescator_altitudine()
{
    int ok = 0, ii;
    orase inv;
    do {
        ok = 0;
        for (ii = 0; ii < n - 1; ii++) {
            if (atoi(e[ii].alt) > atoi(e[ii + 1].alt)) {
                inv = e[ii];
                e[ii] = e[ii + 1];
                e[ii + 1] = inv;
                ok = 1;
            }
        }
    } while (ok);
}

void sortare_descrescator_altitudine()
{
    int ok = 0, ii;
    orase inv;
    do {
        ok = 0;
        for (ii = 0; ii < n - 1; ii++) {
            if (atoi(e[ii].alt) < atoi(e[ii + 1].alt)) {
                inv = e[ii];
                e[ii] = e[ii + 1];
                e[ii + 1] = inv;
                ok = 1;
            }
        }
    } while (ok);
}

void meniu_1()
{
    int x, y, ok = 0;
    readimagefile("Imagini/Cuprins.gif", 0, 0, 1440, 800);
    while (!ok)
    {

        if (ismouseclick(WM_MOUSEMOVE))
        {
            getmouseclick(WM_MOUSEMOVE, x, y);
            if (x > 146 && x < 547 && y > 247 && y < 341)
                readimagefile("Imagini/intr.gif", 0, 0, 1440, 800);
            else if (x > 146 && x < 545 && y > 400 && y < 495)
                readimagefile("Imagini/baz.gif", 0, 0, 1440, 800);
            else if (x > 146 && x < 545 && y > 562 && y < 656)
                readimagefile("Imagini/cun.gif", 0, 0, 1440, 800);
            else if (x > 897 && x < 1292 && y > 248 && y < 341)
                readimagefile("Imagini/bib.gif", 0, 0, 1440, 800);
            else if (x > 897 && x < 1292 && y > 402 && y < 495)
                readimagefile("Imagini/str.gif", 0, 0, 1440, 800);
            else if (x > 897 && x < 1292 && y > 564 && y < 656)
                readimagefile("Imagini/aut.gif", 0, 0, 1440, 800);
            else if (x > 1033 && x < 1195 && y > 98 && y < 130)
                readimagefile("Imagini/inreg.gif", 0, 0, 1440, 800);
            else if (x > 1211 && x < 1349 && y > 105 && y < 125)
                readimagefile("Imagini/aute.gif", 0, 0, 1440, 800);
            else if (x > 128 && x < 188 && y > 76 && y < 158)
                readimagefile("Imagini/ies.gif", 0, 0, 1440, 800);
            else if (x > 205 && x < 263 && y > 91 && y < 144)
                readimagefile("Imagini/inf.gif", 0, 0, 1440, 800);
            else
                readimagefile("Imagini/Cuprins.gif", 0, 0, 1440, 800);
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 146 && x < 547 && y > 247 && y < 341)
            {
                ok = 1;
                intro();
            }
            if (x > 146 && x < 545 && y > 400 && y < 495)
            {
                ok = 1;
                afisareintro();
            }
            if (x > 146 && x < 545 && y > 562 && y < 656)
            {
                ok = 1;
                cunostinte();
            }
            if (x > 897 && x < 1292 && y > 248 && y < 341)
            {
                ok = 1;
                bibl();
            }
            if (x > 897 && x < 1292 && y > 402 && y < 495)
            {
                ok = 1;
                structura();
            }
            if (x > 897 && x < 1292 && y > 564 && y < 656)
            {
                ok = 1;
                autor();
            }
            if (x > 1033 && x < 1195 && y > 98 && y < 130)
            {
                ok = 1;
                if (inregistrat == 0)
                {
                    inregis();
                }
                else
                {
                    meniu_1();
                }
            }
            if (x > 1211 && x < 1349 && y > 105 && y < 125)
            {
                ok = 1;
                if (inregistrat == 0)
                {
                    autentificare();
                }
                else
                {
                    meniu_1();
                }
            }
            if (x > 128 && x < 188 && y > 76 && y < 158)
            {
                ok = 1;
                exit(0);
            }
            if (x > 205 && x < 263 && y > 91 && y < 144)
            {
                ok = 1;
                system("notepad.exe README.txt");
            }

        }
    }
    readimagefile("Imagini/Cuprins.gif", 0, 0, 1440, 800);
    cleardevice();
    meniu_1();
}



void inregis() {
    char numuser[99][20], usernou[20], pass1[12], pass2[12], lit;
    int x, y, i, ok = 1, k = 0; // ok verifica daca userul nou exista �n fi?ierul ini?ial cu useri
    int nume = 0; // schimbat numele

    usernou[0] = '\0';
    readimagefile("Imagini/inregistrare.gif", 0, 0, 1440, 800);
    setcolor(BLACK);
    setbkcolor(WHITE);
    settextstyle(10, 0, 4);


    do {
        if (kbhit()) {
            lit = getch();
            if (isalpha(lit) || isdigit(lit)) {
                usernou[k] = lit;
                k++;
                usernou[k] = '\0';
            }
            outtextxy(790, 250, usernou);
        }

        // Verificare hover ?i clic pe buton
        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, x, y);
            if (x > 94 && x < 183 && y > 79 && y < 156) {
                readimagefile("Imagini/inregistrarehov.gif", 0, 0, 1440, 800);
                outtextxy(790, 250, usernou); // Reafi?am textul introdus
            }
            else {
                readimagefile("Imagini/inregistrare.gif", 0, 0, 1440, 800);
                outtextxy(790, 250, usernou); // Reafi?am textul introdus
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 94 && x < 183 && y > 79 && y < 156) {
                meniu_1();
            }
        }
    } while (lit != char(13)); // Codul ASCII 13 este pentru tasta Enter

    verific_user(usernou);
}
void intro() {
    int x1 = 749;
    int y1 = 236;
    int x2 = 1320;
    int y2 = 708;

    int latime_mica = (x2 - x1) / 2;
    int inaltime_mica = (y2 - y1) / 2;

    char imagini_mici[12][20] = { "Colaj/7.jpg", "Colaj/8.jpg", "Colaj/9.jpg", "Colaj/10.jpg", "Colaj/11.jpg", "Colaj/12.jpg", "Colaj/13.jpg", "Colaj/14.jpg", "Colaj/15.jpg", "Colaj/16.jpg", "Colaj/17.jpg", "Colaj/18.jpg" };

    readimagefile("Imagini/intro1.gif", 0, 0, 1440, 800);
    rectangle(x1, y1, x2, y2);

    setcolor(WHITE);
    line(x1, (y1 + y2) / 2, x2, (y1 + y2) / 2);
    line((x1 + x2) / 2, y1, (x1 + x2) / 2, y2);

    for (int j = 0; j < 4; j++) {
        readimagefile(imagini_mici[j], x1 + (j % 2) * latime_mica, y1 + (j / 2) * inaltime_mica,
            x1 + (j % 2 + 1) * latime_mica, y1 + (j / 2 + 1) * inaltime_mica);
        delay(500);
    }
    readimagefile("Imagini/intro2.gif", 0, 0, 1440, 800);

    char opt[3], tasta;
    int x, y, ok = 0;
    bool hover_hom = false;
    bool hover_dr = false;

    while (!ok) {
        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, x, y);

            if (x > 1160 && x < 1230 && y > 94 && y < 162) {
                if (!hover_hom) {
                    readimagefile("Imagini/intro1hom.gif", 0, 0, 1440, 800);

                    hover_hom = true;
                    hover_dr = false;
                }
            }
            else if (x > 1235 && x < 1306 && y > 95 && y < 162) {
                if (!hover_dr) {
                    readimagefile("Imagini/intro1dr.gif", 0, 0, 1440, 800);

                    hover_hom = false;
                    hover_dr = true;
                }
            }
            else {
                if (hover_hom || hover_dr) {
                    readimagefile("Imagini/intro2.gif", 0, 0, 1440, 800);
                    hover_hom = false;
                    hover_dr = false;
                }
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 1160 && x < 1230 && y > 94 && y < 162) {
                meniu_1();
                return;
            }
            else if (x > 1235 && x < 1306 && y > 95 && y < 162) {
                introdoi();
                ok = 1;
            }
        }
    }

    getch();
    meniu_1();
}






void introdoi() {
    char opt[3], tasta;
    int x, y, ok = 0;
    bool hover_st = false;
    bool hover_dr = false;

    readimagefile("Imagini/introo2.gif", 0, 0, 1440, 800);

    while (!ok) {
        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, x, y);

            if (x > 1160 && x < 1230 && y > 94 && y < 162) {
                if (!hover_st) {
                    readimagefile("Imagini/introo2st.gif", 0, 0, 1440, 800);

                    hover_st = true;
                    hover_dr = false;
                }
            }
            else if (x > 1235 && x < 1306 && y > 95 && y < 162) {
                if (!hover_dr) {
                    readimagefile("Imagini/introo2dr.gif", 0, 0, 1440, 800);

                    hover_st = false;
                    hover_dr = true;
                }
            }
            else {
                if (hover_st || hover_dr) {
                    readimagefile("Imagini/introo2.gif", 0, 0, 1440, 800);
                    hover_st = false;
                    hover_dr = false;
                }
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 1160 && x < 1230 && y > 94 && y < 162) {
                intro();
                return;
            }
            else if (x > 1235 && x < 1306 && y > 95 && y < 162) {
                introtrei();
                return;
            }
        }

        if (kbhit()) {
            getch();
            meniu_1();
            return;
        }
    }

    getch();
    meniu_1();
}

void introtrei() {
    char opt[3], tasta;
    int x, y, ok = 0;
    bool hover_st = false;
    bool hover_hom = false;

    readimagefile("Imagini/intro3.gif", 0, 0, 1440, 800);

    while (!ok) {
        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, x, y);

            if (x > 1160 && x < 1230 && y > 94 && y < 162) {
                if (!hover_st) {
                    readimagefile("Imagini/intro3st.gif", 0, 0, 1440, 800);

                    hover_st = true;
                    hover_hom = false;
                }
            }
            else if (x > 1235 && x < 1306 && y > 95 && y < 162) {
                if (!hover_hom) {
                    readimagefile("Imagini/intro3hom.gif", 0, 0, 1440, 800);

                    hover_st = false;
                    hover_hom = true;
                }
            }
            else {
                if (hover_st || hover_hom) {
                    readimagefile("Imagini/intro3.gif", 0, 0, 1440, 800);
                    hover_st = false;
                    hover_hom = false;
                }
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (x > 1160 && x < 1230 && y > 94 && y < 162) {
                introdoi();
                return;
            }
            else if (x > 1235 && x < 1306 && y > 95 && y < 162) {
                meniu_1();
                return;
            }
        }

        if (kbhit()) {
            getch();
            meniu_1();
            return;
        }
    }

    getch();
    meniu_1();
}


void cunostinte() {
    char opt[3], tasta;
    int x, y, ok = 0;
    int mouse_x, mouse_y; // Variabile pentru coordonatele mouse-ului

    readimagefile("Imagini/cunostinte.gif", 0, 0, 1440, 800);

    while (!ok) {
        // Verificam daca s-a facut click pe mouse
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);

            // Verificam pozi?ia cursorului ?i ac?ionam �n func?ie de butonul apasat
            if (x > 307 && x < 704 && y > 263 && y < 365) {
                ok = 1;
                memo_dist(); // Apelam func?ia corespunzatoare
            }
            else if (x > 734 && x < 1170 && y > 263 && y < 365) {
                ok = 1;
                quiz(); // Apelam func?ia corespunzatoare
            }
            else if (x > 516 && x < 922 && y > 422 && y < 515) {
                ok = 1;
                meniu_1(); // Apelam func?ia corespunzatoare
            }
        }

        // Verificam mi?carea mouse-ului pentru afi?area imaginilor de hover
        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, mouse_x, mouse_y);

            // Verificam pozi?ia cursorului ?i afi?am imaginea corespunzatoare
            if (mouse_x > 307 && mouse_x < 704 && mouse_y > 263 && mouse_y < 365) {
                readimagefile("Imagini/aplhov.gif", 0, 0, 1440, 800);
            }
            else if (mouse_x > 734 && mouse_x < 1170 && mouse_y > 263 && mouse_y < 365) {
                readimagefile("Imagini/quizzhov.gif", 0, 0, 1440, 800);
            }
            else if (mouse_x > 516 && mouse_x < 922 && mouse_y > 422 && mouse_y < 515) {
                readimagefile("Imagini/menhovv.gif", 0, 0, 1440, 800);
            }
            else {
                // Daca cursorul nu este deasupra niciunui buton, afi?am imaginea principala
                readimagefile("Imagini/cunostinte.gif", 0, 0, 1440, 800);
            }
        }

        // Verificam apasarea tastei Esc pentru a reveni la meniu_1()
        if (kbhit()) {
            tasta = getch();
            if (tasta == 27) {
                cupcaut();
                return;
            }
        }
    }
}




struct Intrebare {
    char numar[4];
    char foto[33];
    char corect[4];
    int poz_nou;
};

void aleatoriu() {
    Intrebare intreb[66];
    int k = 0, n = 9;

    ifstream f("Quiz/quiz.txt");
    if (!f) {
        cerr << "Nu pot deschide fisierul Quiz/quiz.txt" << endl;
        return;
    }

    while (f >> intreb[k].numar >> intreb[k].foto >> intreb[k].corect) {
        k++;
    }
    f.close();

    ofstream fo("Quiz/quiz.txt");
    if (!fo) {
        cerr << "Nu pot deschide fisierul Quiz/quiz.txt pentru scriere" << endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < n; i++) {
        intreb[i].poz_nou = 0;
    }

    int ok = 0;
    do {
        ok = 0;
        int nr = rand() % n;
        if (intreb[nr].poz_nou == 0) {
            fo << intreb[nr].numar << " " << intreb[nr].foto << " " << intreb[nr].corect << endl;
            intreb[nr].poz_nou = 1;
        }
        for (int i = 0; i < k; i++) {
            if (intreb[i].poz_nou == 0) {
                ok = 1;
                break;
            }
        }
    } while (ok);

    fo.close();
}

void citintreb() {
    aleatoriu();
    int x, y, ok = 0;
    readimagefile("Imagini/quizincep.gif", 0, 0, 1440, 800);
    do {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (x > 495 && x < 925 && y > 575 && y < 680) {
            ok = 1;
        }
    } while (!ok);
}

int afis_intreb(char nume_fis_intreb[33], char var_corecta[3]) {
    int x, y;
    char aleg = '0';
    readimagefile(nume_fis_intreb, 0, 0, 1440, 800);
    do {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if (x > 210 && x < 590 && y > 380 && y < 465)
            aleg = '1';
        else if (x > 845 && x < 1230 && y > 380 && y < 465)
            aleg = '2';
        else if (x > 210 && x < 590 && y > 560 && y < 645)
            aleg = '3';
        else if (x > 845 && x < 1225 && y > 560 && y < 645)
            aleg = '4';
    } while (aleg == '0');

    if (aleg == var_corecta[0]) {
        readimagefile("Imagini/corect.gif", 0, 0, 1440, 800);
        delay(1200);
        return 1;
    }
    else {
        readimagefile("Imagini/gresit.gif", 0, 0, 1440, 800);
        delay(1200);
        return 0;
    }
}

int quiz() {
    if (inregistrat == 0)
    {
        readimagefile("neinreg.jpg", 0, 0, 1440, 800);
        delay(1000);
        inregis();
    }
    else {
        Intrebare intreb[66];
        int k = 0;

        ifstream fi("Quiz/quiz.txt");
        if (!fi) {
            cerr << "Nu pot deschide fisierul Quiz/quiz.txt" << endl;
            return 1;
        }

        while (fi >> intreb[k].numar >> intreb[k].foto >> intreb[k].corect) {
            k++;
        }
        fi.close();

        citintreb();

        int corecte = 0, gresite = 0;
        for (int i = 0; i < k; i++) {
            int rezultat = afis_intreb(intreb[i].foto, intreb[i].corect);
            if (rezultat == 1)
                corecte++;
            else
                gresite++;
        }

        afisconcl(corecte, gresite);

        closegraph();
        return 0;
    }
}



void afisconcl(int corecte, int gresite) {
    fstream rezultate("rezultate.txt", ios::out);
    rezultate << "			Ai terminat quizul!	" << endl;
    rezultate << "		Mai jos vezi raspunsurile tale:	" << endl << endl;
    rezultate << "Raspunsuri corecte: " << corecte << endl;
    rezultate << "Raspunsuri gresite: " << gresite << endl;
    rezultate.close();

    char s_corecte[3], s_gresite[3];

    cleardevice();
    setcolor(2);
    settextstyle(10, 0, 4);
    readimagefile("Imagini/quizfoto.gif", 0, 0, 1440, 800);
    itoa(corecte, s_corecte, 10);
    itoa(gresite, s_gresite, 10);
    setcolor(GREEN);
    outtextxy(765, 250, s_corecte);
    setcolor(RED);
    outtextxy(765, 295, s_gresite);
    setcolor(BLACK);
    char opt[3], tasta;
    int x, y, ok, z;
    system("notepad.exe rezultate.txt");
    do
    {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        ok = 0;
        if (x > 360 && x < 708 && y>605 && y < 690)
        {
            meniu_1();
        }
        if (x > 735 && x < 1079 && y>608 && y < 690)
        {
            cleardevice();
            cunostinte();
        }
    } while (!ok);
    getch();
    meniu_1();
}

void bibl()
{
    cleardevice();
    settextstyle(6, 0, 3);
    readimagefile("Imagini/bibliografie.gif", 0, 0, 1440, 800);
    getch();
    meniu_1();
}


void structura() {
    cleardevice();
    settextstyle(8, 0, 5);
    readimagefile("Imagini/Structura.gif", 0, 0, 1440, 800);
    char opt[3], tasta;
    int x, y, ok, z;
    do
    {
        readimagefile("Imagini/Structura.gif", 0, 0, 1440, 800);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        ok = 0;
        if (x > 105 && x < 463 && y>202 && y < 286)
        {
            cleardevice();
            introducere();
        }
        if (x > 100 && x < 462 && y>325 && y < 412)
        {
            motto();
        }
        if (x > 106 && x < 463 && y>455 && y < 535)
        {
            meniu_1();
        }
        if (x > 540 && x < 901 && y>581 && y < 665)
        {
            intro();
        }
        if (x > 538 && x < 904 && y>453 && y < 537)
        {
            afis();
        }
        if (x > 527 && x < 904 && y>324 && y < 414)
        {
            cautare();
        }
        if (x > 537 && x < 899 && y>198 && y < 289)
        {
            memo_dist();
        }
        if (x > 985 && x < 1342 && y>191 && y < 283)
        {
            quiz();
        }
        if (x > 970 && x < 1340 && y>321 && y < 415)
        {
            bibl();
        }
        if (x > 974 && x < 1338 && y>454 && y < 534)
        {
            structura();
        }
        if (x > 975 && x < 1343 && y>574 && y < 661)
        {
            autor();
        }

        if (kbhit()) {
            getch();
            meniu_1();
        }
    } while (!ok);
    getch();
    meniu_1();
}

void autor() {
    char linie[256];
    int rectX1 = 120, rectY1 = 10, rectX2 = 1040, rectY2 = 500;
    int screenWidth = 1440, screenHeight = 800;

    readimagefile("Imagini/Autor.gif", 0, 0, screenWidth, screenHeight);
    readimagefile("Autor/poza1.jpeg", 190, 340, 525, 720);
    readimagefile("Autor/poza2.jpeg", 540, 340, 880, 720);
    readimagefile("Autor/poza3.jpeg", 895, 340, 1230, 720);
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(10, 0, 2);

    fstream fis("autor.txt", ios::in);

    int textWidth = rectX2 - rectX1;
    int textHeight = rectY2 - rectY1;
    int textPosX = (screenWidth - textWidth) / 2;
    int textPosY = (screenHeight - textHeight) / 2;

    int totalHeight = 0;
    while (fis.getline(linie, 256)) {
        int currentHeight = textheight(linie);
        if (totalHeight + currentHeight <= textHeight) {
            outtextxy(textPosX + (textWidth - textwidth(linie)) / 2, textPosY + totalHeight, linie);
            totalHeight += currentHeight + 10;
        }
        else {
            break;
        }
    }

    fis.close();

    getch();
    meniu_1();
}


void verific_user(char usernou[22]) {
    char numuser[99][20], pass[99][12];
    int ku = 0;
    int ok = 1;
    std::ifstream fi("useri.txt", std::ios::in);
    while (fi >> numuser[ku] >> pass[ku]) {
        ku++;
    }
    fi.close();

    // Verificam daca usernou exista deja in fisierul useri.txt
    for (int i = 0; i < ku; i++) {
        if (strcmp(usernou, numuser[i]) == 0) {
            ok = 0;
            break;
        }
    }

    if (ok == 0) {
        readimagefile("Imagini/utilgresit.gif", 0, 0, 1440, 800);
        outtextxy(790, 250, usernou);
        delay(1000);
        inregis();


        ku = 0;
        std::ifstream fi("useri.txt", std::ios::in);
        while (fi >> numuser[ku] >> pass[ku]) {
            ku++;
        }
        fi.close();


        ok = 1;         for (int i = 0; i < ku; i++) {
            if (strcmp(usernou, numuser[i]) == 0) {
                ok = 0;
                break;
            }
        }
    }

    if (ok == 0) {
        readimagefile("Imagini/utilgresit.gif", 0, 0, 1440, 800);
        outtextxy(790, 250, usernou);
        delay(1000);
        inregis();
    }
    else {
        readimagefile("Imagini/utilcorect.gif", 0, 0, 1440, 800);
        outtextxy(790, 250, usernou);
        delay(500);

        do {
            verific_pass(usernou);
        } while (!verific_pass(usernou));
    }
}

int verific_pass(char usernou[22]) {
    char pass1[12], pass2[12], lit, pass1_a[12], pass2_a[12];
    int x, y;
    int num_gresite = 0;
    fstream fo("useri.txt", ios::out | ios::app);
    while (true) {
        int pass_ok = 1;
        int k = 0;

        readimagefile("Imagini/utilcorect.gif", 0, 0, 1440, 800);
        setcolor(BLACK);
        setbkcolor(WHITE);
        settextstyle(10, 0, 4);
        outtextxy(790, 250, usernou);
        k = 0;

        do {
            lit = getch();
            if (isgraph(lit)) {
                pass1[k] = lit;
                pass1_a[k] = '*';
                k++;
                pass1[k] = '\0';
                pass1_a[k] = '\0';
            }
            outtextxy(790, 360, pass1_a);
        } while (lit != char(13));

        if (strlen(pass1) < 8) {
            readimagefile("Imagini/parolaslaba.gif", 0, 0, 1440, 800);
            outtextxy(790, 250, usernou);
            delay(1000);
            pass_ok = 0;
        }
        else {
            int spec_sau_num = 0;
            for (int i = 0; i < strlen(pass1); i++) {
                if (!isalpha(pass1[i])) {
                    spec_sau_num = 1;
                    break;
                }
            }
            if (spec_sau_num) {
                readimagefile("Imagini/parolabuna.gif", 0, 0, 1440, 800);
                outtextxy(790, 250, usernou);
                outtextxy(790, 360, pass1_a);
                delay(1000);
            }
            else {
                readimagefile("Imagini/parolasimb.gif", 0, 0, 1440, 800);
                outtextxy(790, 250, usernou);
                delay(1000);
                pass_ok = 0;
            }
        }

        if (pass_ok == 1) {
            int incerc_gres = 0;
            while (true) {
                k = 0;
                do {
                    lit = getch();
                    if (isgraph(lit)) {
                        pass2[k] = lit;
                        pass2_a[k] = '*';
                        k++;
                        pass2[k] = '\0';
                        pass2_a[k] = '\0';
                    }
                    outtextxy(790, 475, pass2_a);
                } while (lit != char(13));

                if (strcmp(pass1, pass2) == 0) {
                    readimagefile("Imagini/parola2ok.gif", 0, 0, 1440, 800);
                    outtextxy(790, 250, usernou);
                    outtextxy(790, 360, pass1_a);
                    outtextxy(790, 475, pass2_a);
                    delay(1000);

                    char raspuns1[50], raspuns2[50], raspuns3[50];
                    k = 0;

                    readimagefile("Imagini/intreb1.gif", 0, 0, 1440, 800);
                    setcolor(BLACK);
                    setbkcolor(WHITE);
                    settextstyle(10, 0, 4);
                    outtextxy(785, 320, "");

                    while (true) {
                        if (kbhit()) {
                            lit = getch();
                            if (isalpha(lit) || isdigit(lit)) {
                                raspuns1[k] = lit;
                                raspuns1[k + 1] = '\0';
                                outtextxy(782, 366, raspuns1);
                                k++;
                            }
                            else if (lit == 13) {
                                raspuns1[k] = '\0';
                                break;
                            }
                        }
                    }

                    ofstream fout("raspunsuri.txt", ios::app);
                    fout << "Raspuns 1: " << raspuns1 << endl;
                    fout.close();

                    readimagefile("Imagini/intreb2.gif", 0, 0, 1440, 800);
                    setcolor(BLACK);
                    setbkcolor(WHITE);
                    settextstyle(10, 0, 4);
                    outtextxy(782, 366, raspuns1);
                    outtextxy(785, 481, "");

                    k = 0;
                    while (true) {
                        if (kbhit()) {
                            lit = getch();
                            if (isalpha(lit) || isdigit(lit)) {
                                raspuns2[k] = lit;
                                raspuns2[k + 1] = '\0';
                                outtextxy(782, 481, raspuns2);
                                k++;
                            }
                            else if (lit == 13) {
                                raspuns2[k] = '\0';
                                break;
                            }
                        }
                    }

                    fout.open("raspunsuri.txt", ios::app);
                    fout << "Raspuns 2: " << raspuns2 << endl;
                    fout.close();

                    readimagefile("Imagini/intreb3.gif", 0, 0, 1440, 800);
                    setcolor(BLACK);
                    setbkcolor(WHITE);
                    settextstyle(10, 0, 4);
                    outtextxy(782, 366, raspuns1);
                    outtextxy(782, 481, raspuns2);
                    outtextxy(785, 590, "");

                    k = 0;
                    while (true) {
                        if (kbhit()) {
                            lit = getch();
                            if (isalpha(lit) || isdigit(lit)) {
                                raspuns3[k] = lit;
                                raspuns3[k + 1] = '\0';
                                outtextxy(782, 590, raspuns3);
                                k++;
                            }
                            else if (lit == 13) {
                                raspuns3[k] = '\0';
                                break;
                            }
                        }
                    }

                    fout.open("raspunsuri.txt", ios::app);
                    fout << "Raspuns 3: " << raspuns3 << endl;
                    fout.close();

                    readimagefile("Imagini/correct.gif", 0, 0, 1440, 800);
                    outtextxy(782, 366, raspuns1);
                    outtextxy(782, 481, raspuns2);
                    outtextxy(782, 590, raspuns3);
                    delay(1000);

                    while (!inregistrat) {
                        if (ismouseclick(WM_MOUSEMOVE)) {
                            getmouseclick(WM_MOUSEMOVE, x, y);
                            if (x > 851 && x < 1183 && y > 630 && y < 700) {
                                readimagefile("Imagini/parola2okhover.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                            }
                            else {
                                readimagefile("Imagini/parola2ok.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                            }
                        }

                        if (ismouseclick(WM_LBUTTONDOWN)) {
                            getmouseclick(WM_LBUTTONDOWN, x, y);
                            if (x > 851 && x < 1183 && y > 630 && y < 700) {
                                inregistrat = 1;
                                readimagefile("Imagini/1.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/2.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/3.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/4.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/5.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/6.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/7.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/8.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/9.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/10.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                readimagefile("Imagini/corrrect.gif", 0, 0, 1440, 800);
                                outtextxy(790, 250, usernou);
                                outtextxy(790, 360, pass1_a);
                                outtextxy(790, 475, pass2_a);
                                delay(550);

                                fo << endl << usernou << " " << pass1;
                                fo.close();

                                meniu_1();
                            }
                        }
                        delay(100);
                    }

                    return pass_ok;
                }
                else {
                    incerc_gres++;
                    if (incerc_gres >= 3) {
                        num_gresite++;
                        if (num_gresite >= 2) {
                            readimagefile("Imagini/incorecta3.gif", 0, 0, 1440, 800);
                            delay(1000);
                            meniu_1();
                            return 0;
                        }
                        else {
                            readimagefile("Imagini/incorecta3.gif", 0, 0, 1440, 800);
                            delay(1000);
                            break;
                        }
                    }

                    readimagefile("Imagini/par2gres.gif", 0, 0, 1440, 800);
                    outtextxy(790, 250, usernou);
                    outtextxy(790, 360, pass1_a);
                    delay(1000);
                }
            }
        }
        else {
            return 0;
        }
    }
}





void parolauitataof();


void parolauitataof()
{
    cleardevice();
    int k = 0;
    char rsp1[99], rsp2[99], rsp3[99], lit;
    readimagefile("Imagini/parolauitata1.gif", 0, 0, 1440, 800);
    do {
        if (kbhit()) {
            lit = getch();
            if (isalpha(lit) || isdigit(lit)) {
                rsp1[k] = lit;
                k++;
                rsp1[k] = '\0';
            }
            outtextxy(487, 303, rsp1);
        }
    } while (lit != char(13));
    getch();
    meniu_1();


}


void autentificare() {
    char numuser[99][20], pass[99][12], user[20], password[12], password_a[12], lit;
    int x, y, i, ku = 0, user_found = 0;
    int k = 0, inregistrat = 0, incercari = 0;
    int incercari_gresite_admin = 0; // Numaratoare �ncercari gre?ite pentru admin

    user[0] = '\0';
    readimagefile("Imagini/autnum.gif", 0, 0, 1440, 800);
    setcolor(BLACK);
    setbkcolor(WHITE);
    settextstyle(10, 0, 4);

    std::ifstream fi("useri.txt");
    while (fi >> numuser[ku] >> pass[ku]) {
        ku++;
    }
    fi.close();

    do {
        if (kbhit()) {
            lit = getch();
            if (isalpha(lit) || isdigit(lit)) {
                user[k] = lit;
                k++;
                user[k] = '\0';
            }
            outtextxy(824, 340, user);
        }

        if (ismouseclick(WM_MOUSEMOVE)) {
            getmouseclick(WM_MOUSEMOVE, x, y);
            if (strcmp(user, "admin") == 0) {
                // Verificare pentru butonul "Parola uitata pentru admin"
                if (incercari_gresite_admin >= 3 && x > 810 && x < 515 && y > 984 && y < 539) {
                    readimagefile("Imagini/paruitataadmin.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                }
                else {
                    readimagefile("Imagini/autadmin.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                }
            }
            else {
                // Verificare pentru butonul de autentificare pentru utilizator normal
                if (x > 94 && x < 183 && y > 79 && y < 156) {
                    readimagefile("Imagini/autnumhov.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                }
                else {
                    readimagefile("Imagini/autnum.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                }
            }
        }

        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            if (strcmp(user, "admin") == 0) {
                // Verificare pentru butonul "Parola uitata pentru admin"
                if (incercari_gresite_admin >= 3 && x > 810 && x < 515 && y > 984 && y < 539) {
                    parolauitataof();
                    return;
                }
            }
            else {
                // Verificare pentru butonul de autentificare pentru utilizator normal
                if (x > 94 && x < 183 && y > 79 && y < 156) {
                    meniu_1();
                    return;
                }
            }
        }
    } while (lit != char(13));
    for (i = 0; i < ku; i++) {
        if (strcmp(user, numuser[i]) == 0) {
            user_found = 1;
            break;
        }
    }

    if (user_found) {
        if (strcmp(user, "admin") == 0) {
            readimagefile("Imagini/autadmin.gif", 0, 0, 1440, 800);
        }
        else {
            readimagefile("Imagini/autnumcor.gif", 0, 0, 1440, 800);
        }
        outtextxy(824, 340, user);
    }
    else {
        readimagefile("Imagini/usergresit.gif", 0, 0, 1440, 800);
        outtextxy(824, 340, user);
        delay(1000);
        autentificare();
        return;
    }

    while (true) {
        k = 0;
        incercari++;

        do {
            lit = getch();
            if (isgraph(lit)) {
                password[k] = lit;
                password_a[k] = '*'; // Afisam '*' in locul caracterului introdus
                k++;
                password[k] = '\0';
                password_a[k] = '\0';
                outtextxy(824, 460, password_a);
            }
        } while (lit != char(13));

        if (strcmp(password, pass[i]) == 0) {
            if (strcmp(user, "admin") == 0) {
                readimagefile("Imagini/autadmincorect.gif", 0, 0, 1440, 800);
            }
            else {
                readimagefile("Imagini/auteusercorect.gif", 0, 0, 1440, 800);
            }
            outtextxy(824, 340, user);
            outtextxy(824, 460, password_a);

            while (true) {
                if (ismouseclick(WM_MOUSEMOVE)) {
                    getmouseclick(WM_MOUSEMOVE, x, y);
                    if (x > 881 && x < 1214 && y > 563 && y < 634) {
                        if (strcmp(user, "admin") == 0) {
                            readimagefile("Imagini/autadmincorecthov.gif", 0, 0, 1440, 800);
                        }
                        else {
                            readimagefile("Imagini/auteusercorecthover.gif", 0, 0, 1440, 800);
                        }
                        outtextxy(824, 340, user);
                        outtextxy(824, 460, password_a);
                    }
                    else {
                        if (strcmp(user, "admin") == 0) {
                            readimagefile("Imagini/autadmincorect.gif", 0, 0, 1440, 800);
                        }
                        else {
                            readimagefile("Imagini/auteusercorect.gif", 0, 0, 1440, 800);
                        }
                        outtextxy(824, 340, user);
                        outtextxy(824, 460, password_a);
                    }
                }

                if (ismouseclick(WM_LBUTTONDOWN)) {
                    getmouseclick(WM_LBUTTONDOWN, x, y);
                    if (x > 881 && x < 1214 && y > 563 && y < 634) {
                        if (strcmp(user, "admin") == 0) {
                            inregistrat = 1;
                            readimagefile("Imagini/a1.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/a2.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/a3.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/a4.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/a5.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/a6.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/a7.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/a8.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/a9.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/corrrrect.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            delay(550);
                            meniu_1();
                        }
                        else {
                            inregistrat = 1;
                            readimagefile("Imagini/ad1.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/ad2.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/ad3.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/ad4.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/ad5.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/ad6.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/ad7.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/ad8.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            readimagefile("Imagini/cor.gif", 0, 0, 1440, 800);
                            outtextxy(824, 340, user);
                            outtextxy(824, 460, password_a);
                            delay(550);
                        }
                        meniu_1();
                    }
                }
            }
        }
        else {
            if (strcmp(user, "admin") == 0) {
                incercari_gresite_admin++;

                if (incercari_gresite_admin == 1) {
                    readimagefile("Imagini/paradmingres.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                    delay(1000);
                    readimagefile("Imagini/autadmin.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                }
                else if (incercari_gresite_admin == 4) {
                    readimagefile("Imagini/paradmingres.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                    delay(1000);
                    exit(0); // �nchidem programul daca s-au depa?it 4 �ncercari gre?ite pentru admin
                }
                else {
                    readimagefile("Imagini/paradmingres.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                    delay(1000);
                    readimagefile("Imagini/autadmin.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                }
            }
            else {
                // Daca parola este gre?ita pentru utilizator normal
                if (incercari >= 3) {
                    readimagefile("Imagini/parusergres.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                    delay(1000);
                    exit(0); // �nchidem programul daca s-au depa?it 3 �ncercari
                }
                else {
                    readimagefile("Imagini/parusergres.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                    delay(1000);
                    readimagefile("Imagini/autnumcor.gif", 0, 0, 1440, 800);
                    outtextxy(824, 340, user);
                }
            }
        }
    }
}


