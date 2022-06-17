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
 * <hr>
 * @section head_of_terms Założenia wstępne przyjęte w realizacji projektu
 * Program powinien umieć wczytać komendy z pliku oraz zapisać je w postaci tablicy danych przechowującej zdjęcie oraz czas jaki dana klatka będzie trwać. Dozwolone są różne rozmiary animacji.
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
 * - dane wejściowe są to pliki .txt zawierające komendy, na podstawie których są rysowane klatki lub zbiór zdjęć, które są wczytywane do wektora.
Wczytane klatki są zapisywane do kontenera std::vector.
 *
 * - dane wyjściowe są to animacje, które można wyświetlić na ekranie poklatkowo lub zapisać do pliku z rozszerzeniem .png.
 *
 * - struktury danych - cała animacja jest przechowywana w std::vector, który z kolei przechowuje @Frame. @Frame jest to struktura stworzona na potrzeby programu,
 * przechowuje ona pojedyńczą klatkę złożoną z czasu odtwarzania tej klatki oraz zdjęcia jakie ma wyświetlić.
 *
 *
 * - interfejs użytkownika pozwala na:
 *		- wybór pliku do wczytania (File -> Open -> wybór pliku)
 *		- wybór miejsca, gdzie animacja ma zostać zapisana (File -> Save -> wybór katalogu)
 *		- wybór koloru tła aplikacji (Settings -> Background color -> wybór koloru)
 *		- wybór opcji wczytywania animacji 2D / 3D / ze zdjęć (Settings -> Read animation from -> wybór opcji)
 *		- wybór tła animacji (Settings -> Other settings -> Chose animation background -> wybór pliku .png)
 *		- zaznaczenie czy tło animacji ma zostać wyświetlone (Settings -> Other settings -> Show animation background)
 *		- wybranie numeracji zapisanych plików (Settings -> Other settings -> 0001/1)
 *		- zmiane nazwy zapisywanych plików (Settings -> Other settings -> Name of files)
 *		- odtworzenie animacji "play" / zatrzymanie animacji "pause"
 *		- przeskoczenie paru klatek do przodu ">>" / tyłu "<<"
 *		- odtworzenie animacji od początku "replay"
 *		- zmiane prędkośći odtwarzania animacji poprzez suwak
 *
 *
 * - wyodrębnienie i zdefiniowanie zadań - cały projekt można podzielić na 3 odrębne moduły: tworzenie animacji, odczyt/zapis animacji oraz wyświetlenie animacji.
 * Z punktu widzenia pozostałych modułów każdy moduł można określić jako dane wejściowe i wyjściowe, gdyż dla pozostałych nie jest istotne w jaki sposób dany moduł wykonuje swoje zadanie.
 * Dokładny opis modułów jako algorytmy jest przeprowadzony w sekcji "Opracowanie i opis niezbędnych algorytmów".
 *
 *
 * - narzędzia programistyczne - zdecydowaliśmy się na połączenie 2 bibliotek SFML i wxWigets. wxWigets odpowiada za ładny interfejs użytkownika oraz interakcje z nim.
 Z kolei SFML zapewnia nam szybkie rysowanie animacji na wxPanelu oraz szybsze wczytanie danych do programu.
 *

 *
 * <hr>
 *
 * @section work_division Podział pracy i analiza czasowa
 *
 * Prace przy projekcie zostały podzielone pomiędzy poszczególnych autorów projektu w taki sposób, że każdy z nich był odpowiedzialny za wdrożenie innego obszaru funkcjonalności projektu.
 * Adam był odpowiedzialny za:
 * - stworzenie szkieletu projektu
 * - zaimplementowanie wczytywania animacji z pliku oraz zapisywania ich w postaci serii obrazów w wybranym formacie
 * - zaimplementowanie funkcjonalności interfejsu użytkownika pozwalającego na m.in: zmianę kolorów tła oraz modyfikację zapisu plików
 * - całość można zawrzeć w module odczyt/zapis animacji
 *
 * Tomek był odpowiedzialny za:
 * - stworzenie przykładowych animacji do projektu, odczytywanych przez program z plików .txt
 * - stworzenie algorytmów w języku C++, które zapisywały klatki w.w. animacji jako kolejne linie w pliku .txt
 * - ustalenie najbardziej optymalnego czasu wyświetlania pojedynczej klatki animacji
 * - całość można zawrzeć w module tworzenie animacji
 *
 *
 * Szymon był odpowiedzialny za:
 * - zaimplementowanie wyświetlania obrazów przechowywanych w wektorze @Animation
 * - zaimplementowanie funkcjonalności dla róznych przycisków sterujących
 *		- przyciski play/pause
 *		- przyciski przewijania klatek przód/tył
 *		- przycisk replay
 * - zaimplementowanie sterowania prędkością odtwarzania za pomocą slidera
 * - zaimplementowanie wyświetlania odpowiednich komunikatów dla różnych stanów programu
 * - całość można zawrzeć w module wyświetlanie animacji
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
 * Poprawność działania aplikacji testowano za pomocą własnoręcznie napisanych animacji. W tym celu stworzono sześć odrębnych animacji testujących wizualizację obrazów 2D oraz dwie sprawdzające odczyt 3D. Dzięki temu sprawdzono poprawność działania każdego z aspektów aplikacji. Programy zwracające plik txt z szeregiem instrukcji pisano w języku C++, zadbano o różnorodność animacji, w tym celu skorzytano z wielu algorytmów, między innymi funkcji symulującej działanie siły grawitacji na spadającą piłkę wykonaną z gumy, a także funkcji wizualizującą trajektorię lotu pocisku wystrzelonego z armaty (wykorzystano te dane w animacji "day_night_sky"). Dużym wyzwaniem podczas testowania było stworzenie poklatkowej animacji, które nie zajmowałyby zbyt dużej ilości klatek ale tym samym były płynne, po głębszej analizie dobrano parametry w ten sposób iż każda animacja odtwarza się w zadowalający sposób. Poniżej ukazano, w formacie gif, animacje o których mowa wyżej. W celu poprawy prezentacji wizualnej, do każdej z aniamcji wstawiono tło.
 *
 * \image html raindrops_on_water_surface.gif "Raindrops on water surface" width=500cm
 *
 * \image html bouncing_ball.gif "Bouncing ball" width=500cm
 *
 * \image html bubble_sort.gif "Bubble sort" width=500cm
 *
 * \image html day_night_sky.gif "Day/night sky" width=500cm
 *
 * \image html rain_3D.gif "Rain 3D" width=500cm
 *
 * \image html rolling_circle.gif "Rolling circle" width=500cm
 *
 * \image html 3DPlane.gif "Plane 3D" width=500cm
 *
 * Dodatkowo w celu sprawdzenia działania poprawności napisanych animacji wielokrotnie dokonywano prób odczytu każdego z trybów (animacja 2D oraz 3D z pliku txt, a także zbiór zdjęć) oraz zapisu do pliku w formie plików png. Na tej podstawie można było wywnioskować bezbłędne działanie zarówno odczytu jak i zapisu.
 *
 * <hr>
 *
 * @section conclusion Wdrożenie, raport i wnioski
 *
 *
 * Udało się zaimplementować wszystkie postawione założenia podstawowe, a także roszerzono możliwości programu o szereg opcji dodatkowych takich jak np. zmiana tła, obsługa animacji 3D, wczytywanie animacji z obrazów. Dodatkowo w przyszłości można by rozszerzyć funkcjonalność programu o obsługę efektów dźwiękowych do animacji czy dodanie progress bar'u, wyświetlanego w trakcie odtwarzania animacji, umożliwiającego przeskoczenie do wybranej klatki poprzez kliknięcie na nią.
 * Z nie do końca rozwiązanych problemów, przy uruchamianiu niektórych animacji, czasami program nie skaluje jej idealnie do ramek okna, lecz pozostawia szerokie paski. Dodatkowo przy zbyt małych rozmiarach animacji, ucinane są przyciski i nie da się sterować animacją.
 *
 *
 */