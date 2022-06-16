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
 * Program powinien umieć wczytać komendy z pliku oraz zapisać je w postaci tablicy danych przechowującej zdjęcie oraz czas jaki dana klatka będzie trawć. Dozwolone są różne rozmiary animacji.
 Po wczytaniu danych program pozwala na odtworzenie/zatrzymanie animacji, odtworzenie od początku animacji, przewijanie do przodu i do tyłu klatek oraz zmianę szybkości odtwarzania. Istnieje również 
 możliwość zapisu poszczególnych klatek w postaci plików .png, które są numerowane w kolejności występowania w tablicy danych. Dodatkowo program ma możliwość:
 * - wyboru różnych opcji wczytywania danych z plików:
 *		- odczyt 3D pozwala na czytanie z pliku .txt 3-wymiarowych wspołrzędnych i rzutowanie tych danych na obraz
 *		- .png umożliwia użytkownikowi wybór dowolnej ilości zdjęć oraz wczytanie ich do tablicy danych (odczyt w kolejności alfanumerycznej względem ścieźki dostępu do każdego z obrazów)
 * - program wypisuje informacje o aktualnym stanie animacji
 * - użytkownik może zmieniać kolor tła aplikacji
 * - aby wczytać/zapisać animację można użyć skrótów Ctrl+O/Ctrl+S
 * - użytkownik może wybrać tło animacji oraz zaznaczyć czy ma ono zostać wyświetlone w danym momencie
 *		- jeśli obie powyższe czynności są wykonane to podczas zapisu każda klatka zostanie zapisana razem z tłem
 * - użytkownik może zmienić nazwę oraz sposób numeracji zapisywanych obrazów
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
 *Program można podzielić na 3 grupy algorytmów:
 * - pierwsza grupa zajmuje się wczytaniem klatek do wektora. Danymi wejściowymi jest ścieżka do pliku
 (bądź plików w przypadku czytania ze zdjęć), który użytkownik wybierze do odczytu. Na początku algorytm czyści wektor z poprzedniej animacji i zmienia stan programu
 na @LoadingToBuffer. Po otwarciu pliku program zczytuje rozmiar i ilość wszystkich klatek. Jest to potrzebne, aby zmienić rozmiar całego okna oraz zarezerowoać 
 pamięć w wektorze. Następnie program czyta kolejne komendy i rysuje odpowiadające im figury na zmiennej tymczasowej typu sf::RenderTexture do momentu napotkania komendy stop (ST).
 Wtedy wyświetla i zapisuje buffer jako sf::Texture. Danymi wyjściowymi jest wektor przechowujący wszystkie klatki.
 * - druga zapisuje klatki z wektora do folderu. Danymi wejściowymi jest folder wybrany przez użytkownika, do którego mają zostać zapisane klatki. Na początku algorytm pobiera z
 * komputera informację o ilości wątków jaką dysponuje. Zapis dokonuje się w dwóch pętlach. Środkowa ustalana nazwe, numeracje pliku oraz czy klatka ma zostać zapisana razem z tłem,
 a następnie wywołuje zapis na osobnym wątku. W ten sposób wewnętrzna pętla rozsyła zapis na różne wątki, z kolei w zewnętrznej czekamy aż wszystkie zapisy się skończą
 i powtarzamy mechanizm. Algorytm zabezpiecza również sytuację, gdy parę klatek nie zostanie zapisanych. Sytuazja ta może wystąpić, kiedy ilość klatek nie jest podzielna przez ilość wątków.
 Danymi wyjściowymi w tym przypadku są zapisane obrazy.
 * - trzecia zajmuje się wyświetleniem animacji. Algorytm ten jest złożonyc z wielu funkcji, które wzajemnie ze sobą współgrają. Całe wyświetlanie jest oparte o metode @Notify
 (dziedziczona po wxTimer), która jest wywoływana co czas trwania danej klatki, natomiast w jej ciele znajduje się przejście do kolejnej klatki. Wypisywanie na ekran
 zależy od @AnimationState. W momencie odtwarzania animacji, na ekran wyświetlana jest aktualna klatka wraz z tłem, jeśli jest ustawione. W skład algorytmu wchodzą również metody
 wywoływane po akcji użytkownika, które zmieniają stan animacji - zmienia się z @DuringDisplay na @DisplayStopped, aktualna klatka jest inkrementowana/deinkrementowana,
 aktualna klatka zostaje zmieniona na zerowoą, czas pomiędzy klatkami wydłuża się/skraca.
 *
 *<hr>
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