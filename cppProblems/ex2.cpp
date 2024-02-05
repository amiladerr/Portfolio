#include <iostream>
#include <vector>

bool PretraziNiz(int *&p1, int *&p2, int broj){
    for (int *i = p1; i < p2; i++)
        if (*i == broj) return true;

    return false;
}

template <typename Blok1, typename Blok2, typename Blok3>
std::vector<Blok3> *SimetricnaRazlikaBlokova(Blok1 *p1, Blok1 *p2, Blok2 *p3, Blok2 *p4, std::vector<Blok3> *p5){
    int brojac = 0;
    for (int *i = p1, *k = p3; i < p2, k < p4; i++, k++){
        bool duplikat = false;
        if (!PretraziNiz(p3, p4, *i)){
            for (int j = 0; j < brojac; j++)
                if ((*p5)[j] == *i){
                    duplikat = true;
                    break;
                }
                if (!duplikat){ (*p5).push_back(*i); brojac++;}
        }
    }
        for (int *i = p3; i < p4; i++){
        if (!PretraziNiz(p1, p2, *i)){
            bool found = false;
            for (int j = 0; j < brojac; j++)
                if ((*p5)[j] == *i){
                    found = true;
                    break;
                }

            if (!found){ (*p5).push_back(*i); brojac++; }
        }
        }
        return p5;
}

int main(){
    int niz1[] = {5, 2, 7, 4, 6, 1, 3, 2, 7, 4};
    int niz2[] = {2, 9, 0, 6, 0, 4, 8, 3, 2, 5};
    std::vector<int> destination;
    std::vector<int> *p5 = SimetricnaRazlikaBlokova(niz1, niz1+10, niz2, niz2+10, &destination);
    for (int i = 0; i < destination.size(); i++) std::cout << destination[i];
    return 0;
}
