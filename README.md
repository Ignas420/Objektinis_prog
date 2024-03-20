Šioje programos (v0.4) versijoje visas darbas buvo fokusuojamas į duomenų rūšiavimą, į dvi kategorijas, pagal jų galutinį balą (mediana arba vidurkis). Studentai, kurių galutinis balas yra mažesnis nei 5.0, vadinami "Nuskriaustieji", o tie, kurių balas yra 5.0 ar aukštesnis, vadinami "Mokslinčiais".

Programa leidžia vartotojui įvesti studentų duomenis ranka arba sugeneruoti atsitiktinius studentų sąrašus. Tada ji rūšiuoja studentus pagal jų galutinį balą ir išveda juos į du naujus failus.

Kaip naudoti šią programą?
1. Paleiskite programą.
2. Pasirinkite ar norite įvesti studentų duomenis ranka ar skaityti failą.
3. Pasirinkite ar norite generuoti naujus failus.
5. Jei pasirinkote skaityti duomenis iš failo, pasirinktas failas bus nuskaitomas ir išvedami duomenys.
6. Jei pasirinkote generuoti naujus failus, bus sugeneruoti nauji failai (pagal vector IrasuSk elementu skaičių ir elementus vektoriuje).
7. Sugeneruoti failai bus išskirti į papildomus du failus, Nuskriaustieji(index) ir Mokslinčiai(index) pagal vidurkį arba medianą.
8. Abiejais atvejais bus klausiama naudotojo kaip norima rikiuoti failu duomenis.
9. Galiausiai bus išvesti failai su surikiuotais duomenimis.

Štai, kaip atrodytų programos veikimas, su pirmuoju generuojamu failu:
![image](https://github.com/Ignas420/Objektinis_prog/assets/145566919/e6641817-7a9f-4054-a1f2-b7ea10e94787)

Vidurkio skaičiavimai su turimais failais:

| Veiksmas                                         | Vidutinis laikas (sekundės)     |
|--------------------------------------------------|---------------------------------|
| Nuskaitymas                                      | 0.58707928                     |
| Studentų rūšiavimas                              | 0.11429616                     |
| Mokslinčių studentų išvedimas į failus          | 1.114220953             |
| Nuskriaustųjų studentų išvedimas į failus       | 2.679223533             |
| Visų programų vykdymo laikas                    | 6.363009653              |

Vidurkio skaičiavimai su sukurtais failais:

| Veiksmas                                    | Vidutinis laikas (sekundės) |
|-----------------------------------------|------------------|
| Nuskaitymas                                 | 6.00445633       |
| Studentų rūšiavimas                                 | 1.19214156       |
| Mokslinčių studentų išvedimas į failus    | 7.111998         |
| Nuskriaustųjų studentų išvedimas į failus   | 10.19265756      |
| Visų programų vykdymo laikas                      | 39.58228033      |

