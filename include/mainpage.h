/** @file mainpage.h
 * @brief Definition of class Template
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/workbook/pages/advanced_doxygen/usingDoxygen.htm,v 1.1.1.1 2007/06/29 15:03:16 chuckp Exp $
 */
/** @mainpage Animacje
 *
 * @authors Adam Jędrychowski, Szymon Moździerz, Tomasz Kozieł
 *
 * <hr>
 *
 * @section description Opis Projektu
 *
 * Celem projektu było napisanie programu tworzącego oraz wyświetlającego animację poklatkową złożoną z ciągu bitmap wyświetlanych w zadanych
 * odstępach czasu. Dane wejściowe pobierane są z pliku tekstowego zawierającego:
 *
 * - w pierwszej linii rozmiar generowanych klatek (bitmap)
 * - w drugiej linii ilość wszystkich klatek (w celu przyspieszenia procesu zapisywania danych w std::vector)
 * - numer klatki oraz czas jej trwania w milisekundach
 * - opis zawartości każdej z klatek, zapisany jako szereg instrukcji rysujących (każda w oddzielnej linii), użyte instrukcje (w poniższych instrukcjach znacznik flaga informuje o tym czy figura ma być wypełniona kolorem pędzla (flaga=1) czy też program ma narysować jedynie obrys (flaga=0)):
 *   - punkt (PT) x, y – rysuje punkt o współrzędnych x i y
 *   - elipsa (EL) x1, y1, x2, y2, flaga – rysuje elipsę
 *   - prostokat (PR) x1, y1, x2, y2, flaga – rysuje prostokąt
 *   - linia (LN) x1, y1, x2, y2 – rysuje linie
 *   - rozmiar_piora (RP) d – ustala grubość pióra
 *   - kolor_piora (KP) r g b – ustawia kolor pióra
 *   - kolor_wypelnienia (KW) r g b - ustawia kolor wypełnienia (pędzla)
 * - końca klatki sygnalizowanego instrukcją stop (ST)
 *
 *
//  * There are 3 examples:
//  *
//  * - User-Defined generic C++ class
//  * -# templates/ClassTemplate.h
//  * -# src/ClassTemplate.cxx
//  * - User-Defined Gaudi Algorithm
//  * -# src/ExampleAlg.cxx
//  * -# src/Dll/templates_dll.cxx
//  * -# src/Dll/templates_load.cxx
//  * - User-Defined Gaudi Service
//  * -# templates/IExampleSvc.h
//  * -# templates/ExampleSvc.h
//  * -# src/ExampleSvc.cxx
//  * -# src/Dll/templates_dll.cxx
//  * -# src/Dll/templates_load.cxx
//  *
//  *
//  * Also note the existence of the following directories:
//  * - cmt
//  * -# Contains the requirements file
//  * - doc
//  * -# Contains the release.notes file
//  *
//  * As you prepare to develop code for GLAST SAS, please be sure you are aware
//  * of our current
//  * <A HREF="http://www-glast.slac.stanford.edu/software/CodeHowTo/codeStandards.html"> Coding Standards </A>
//  *
//  *
//  * If using the code in this package as an example - please modify the comments
//  * as appropriate for your own specific code.
 *
 * <hr>
 * @section head_of_terms Założenia wstępne przyjęte w realizacji projektu
 * release.notes
 *
 * <hr>
 *
 * @section analysis Analiza projektu
 *
 *
 *
 *
 *
 * <hr>
 *
 * @section work_division Podział pracy i znaliza czasowa
 *
 *
 *
 *
 *
 *
 *  <hr>
 *
 * @section algorithms Opracowanie i opis niezbędnych algorytmów
 *
 *
 *
 *
 *
 *
 *
 *
 *  <hr>
 *
 * @section tests Testowanie
 *
 * Poprawność działania aplikacji testowano za pomocą własnoręcznie napisanych animacji. W tym celu stworzono sześć odrębnych animacji testujących wizualizację obrazów 2D oraz dwie sprawdzające odczyt 3D. Wszystkie animacje zgodnie z poleceniami zapisywano w pliku z rozszerzeniem txt jako szereg instrukcji. Dzięki temu sprawdzono poprawność działania każdego z aspektów aplikacji.
 *
 *
 *
 * \image html raindrops_on_water_surface.gif "test" width=500cm
 * \image html malpka.gif "test" width=500cm
 *
 *
 *
 *
 * <hr>
 *
 * @section conclusion Wdrożenie, raport i wnioski
 *
 *
 *
 *
 *
 *
 *
//  * @section requirements requirements
//  * @verbinclude requirements
//  * <hr>
//  * @todo [optionally include text about more work to be done]
//  * @todo Give each todo item its own line
 *
 */