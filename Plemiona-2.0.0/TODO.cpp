/*
LISTA TO_DO :

na mapie :

 stolica
 miasta inne
 osadnicy (wybor proporcji ludnosci)
 jednostki l¹dowe
 jednostki morskie
 robotnicy
 kap³an (zwieksza religjnosc gminy)
 admira³ (zwieksza militarnosc gminy)
 urzêdnik (zwieksza gospodarczosc gminy)
 dyplomata (wysy³any do panstw-miast)

 tytu³y graczy
 handlarz
 budowa tartakow
budowa farm
 budowa kopaln
 granice
 budowa wiosek(zwieksza ludnosc miasta)
 budowa fortów (leczenie jednostek)
ruch jednostkami
 operacje jednostek
 barbarzyncy
-+ mgla wojny 
mapa zasiegu miast (zalezy od wiary)

stolica:

	 budowanie budynkow 
	'kapitol 5
	'ratusz 5 (+szybkosc rekrutacji robotnikow)
	'rynek 3 (+zloto na ture, kupowanie produkcji)
	'dzielnice:
	; mieszkalna 3 (+ludnosc, +niezadowolenie, +produkcja) 
	; handlowa 3 (+zloto, +% zlota, handel) 
	; naukowa 3 (+nauka, +% nauki)
	; wojskowa 3 (+max zolnierzy, +obrona) 
	; religijna 3 (+wiara, +% wiary)
	; rekreacjna 3 (+zadowolenie, +% zadowolenia) 


	'akademia 2 (+szybkosci rekrutacji elit)
	'szkola 2 (+nauka)
	'mury 3 (+obrona)
	'koszary 4 (+szybkosc rekrutacji piechoty)
	'huta 2 (+%kamienia na ture, +niezadolowanie, +produkcja)
	'oboz najemnikow  3 ( tansze jednostki, +niezadowolenie)
	'bank 2 (+%zlota, +zloto)
	'gildia 3 (+szybkosc rekrutacji osadnikow)
	'biblioteka 2 (+nauka)
	'park 3 (+zadowolenie)
	'pomnik 3 (+zadowolenie)
	'ambasada 3 ( +wiara, +obrona przeciwko barbarzyncom)
	'port 3 (+zywnosc, +kultura)
	'teatr 2 (+zadowolenie)
	'ulepszenie drog 1 (+szybkosc rekrutacji kazdego)
	'tawerna 3 (+zadowolenie)
	'magazyn 4 (+zywnosc, kamienie, drewno, +produkcja)
	'm³yn 4 (+%zywnosci, +produkcja)
	'plac bojowy 1 (formowanie jednostek bojowtch)
	'tartak 4 (+%drewna, +produkcja)
	'kamieniarz 4 (+%kamienia +produkcja)
	'cud: Kolos 1 (wygrana)
	'kosciol 3 (+wiara)
	'katedra 3 (+wiara)
	'skarbiec 3 (+zloto, +%zlota)
	'fort 4 (+obrona, +niezadowolenie, +max zolnierzy)
	'weglarnia 2 (+kamien +niezadowolenie, +produkcja)
	'warsztat 2 (+szybkosc rekrutacji kusznikow, +produkcja)
	'stajnia 4 (+szybkosc rekrutacji jazdy)
	((((TO DO PRZEBUDOWY))))

	 rekrurtacja jednostek
	 kupowanie jednostek
	 zmiana nazwy 
	budowa 2D
	 produkcja 
	przychod miasta
	 ludnosc(+obrona miasta, x za kazda budowle poza miastem, +produkcja)
	obrona 
	max zolnierzy
	poziom miast
	wybieranie punktow produkcji (jak w cywilizacji)
	
	podzia³ ludnosci (ch³opi, mieszczanie, arystokraci - wp³ywa to na produkcje surocwów, jednostek itp)
	podzia³ ludnosci (ekonomiœci, duchowni, miliratyœci - wp³ywa na traity w regionie [musi byc równowaga jesli nie ma sie bonusów])
	(do rozwiniêcia)


	zamieszki
	choroby
	armie spozywaja jedzenie (trezba im dac na poczatku x jedzenia i potem dostarczac z miast lub moga miec w armii robotnikow zeby nie martwic sie o to)
	bezrobocie (niezadowolenie jesli za duzo)
	lojalnoœæ (zalezne od podzia³u ludnosci i praw dla nich ustawnowionych)
	prawa dla danych grup spo³ecznych
	niewolnictwo
	wielcy ludzie

	regiony (tereny wokó³ miast beda regionami, dla kazdego mozna ustanawiac jakies tam prawa, do regoinu mozna uzyc kilku miast [max 2 miasta, z technologiami wiecej itp])
	gminy (tereny tylko wokol jednego miasta)
	budowa dróg (niewidoczne na mapie, ale widoczne na info terenu)(widoczne na widoku mapy dróg)
	system podatkow




	osady:
	(((DO PRZEBUDOWY)))
	 budowanie budynków :  
	'rada osady 4
	'koszary 3 [1] 
	'warsztat 2 [2]
	'stajnia 3 [3]
	'magazyn 3 
	'm³yn 3
	'kamieniarz 3
	'weglarz 2
	'pomnik 2
	'park 2
	'plac bojowy 1
	'port 2
	'kosciol 2
	'biblioteka 2
	'dzielnica mieszkalna 2
	'dzielnica handlowa 2
	'dzielnica robotnicza 2
	'dzielnica wojskowa 2
	'tawerna 2
	 zmiana nazwy 
	rekrutacja jednostek(bez osadnikow) 
	przychod osady 
	zbierz podatek
	 ludnosc
	 wystawianie armii

	ogolne:

handel
panstwa-miasta z prostym AI
 barbarzyncy z prostym AI
 wioski barbarzyncow
 przychod ogolny

 technologie : 
'hodowla (+x%przyrostu zywnosci z farm i rozbudowa magazynu do 3lvl)
'pieniadz (+x%przyrostu z³ota i rozbudowa rynku do 3 lvl i budowa ambasady)
'gildie (mozliwosc budowy gildii)
'mechanika (mozliwosc budowy taranow oraz 2 poziom warsztatu)
'hutnictwo (mozliwosc budowy huty i wiekszy atak piechoty)
'³owiectwo (mozliwosc produkcji lucznikow)
'infrastruktura (mozliwosc rozbudowy drog)
'administracja (mozliwosc handlu i rozbudowy kapitolu na 5 lvl)
'obrobka zelaza (mozliwosc rekrutacji kusznikow i ciezkozbrojnych)
'obrobka stali (mozliwosc rekturacji ciezkiej jazdy i elity)
'nawigacja (wiekszy zasieg jednostek i mozliwosc rozbudowy portu do 3 lvl)
'sztuka (mozliwosc budowy teatru i budowy cudu)
'ewangelizacja (mozliwosc budowy katedr i +x%religii)
'browarnictwo (mozliwosc budowy tawerny do 3lvl i +x% wiecej zadowolenia z tawern)

(((TO DO PRZEBUDOWY)))


 nastepna tura 
przelaczanie miedzy miastami 
walka 
oblezenie
 rozbudowa budowli 
cele: kulturowy(cud), religijny(x wiary), wojskowy(podbic), polityczny (suwerennosc kilku wiosek)
 -+ mapa teretorialna
 -+ 4 graczy 
jednostki :
	'pikinier(wymaga: koszary 1)(1,5x wiecej taranom)
	'³ucznik (koszary 2)(atak nie powoduje kontry
	'kusznik (koszary 3)(omijaja punkty obrony oraz atak nie powoduje kontry)
	'ciezkozbrojny (koszary 4)(zadaje x1,5 obrone)
	'lekka jazda (wymaga stajni 1)(zadaja 1,25 razy wiecej pikinierom i ciezkozbrojnym)
	'ciezka jazda (wymaga stajni 3)(zadaje x1,5 razy wiecej pikinierom i ciezkozbrojnym)
	'taran (wymaga warsztat 2)(niszczy tylko obrone)
	'elita (wymaga akademii)
	(((DO PRZEBUDOWY)))
morskie:
	'katamaran
	'galera
	'kawalera
	'liniowiec
	'handlowiec
	'kuter

	 zamiana wiary na zloto
	 maksymalna odleglosc budowy zabudowan
	 budynki wplywaja na najblizsza miejscowosc
	 zapis
	 wczytanie
	 inne mapy
	 menu z logo

	 zywnosc (produkcja jednostek oraz zywienie ludnosci i rozwoj miasta)
	 kamien (budowa buydnków oraz jednostek)
	 drewno (budowa buydnków oraz jednostek)
	 metal (budowa buydnków oraz jednostek)
	 produkcja (czas budowy budynków)
	 dobra luksusowe (zadowolenie miasta)
	 /\ te surowce osobno dla kazdego regoinu


	 zloto (utrzymanie jednostek i budynkow, kupowanie jednostek, kupowanie terenu, handel)
	 wiara (wymiana na z³oto, powiekszanie teretorium automatyczne)
	 nauka (technologie)

	 punkty dowodzenia (ilosc ruchow jakie mozna wykonac danej tury)
	 punkty dyplomacji (rozmowa z panstwami-miastami, handel z innymi graczami)
	 punkty wp³ywów (¿¹dania od panstw-miast, budowle specjalne, tworzenie armii, budowa osadników)
	 punkty w³adzy (zmiana ustrojów w panstwie)

	 ustroje


	 -+ narrator ktory opowiada wydarzenia na mapie podczas tury
	 civilization builder 
	 edytor map
	 pory roku

	 SILNIKOWE:

	 ++Dzwieki manager
	 AI
	 Multiplayer online
	 -+ wyswietlanie innych map
	 kody (debug)
	 zapisywanie w plikach dat
	 event systems
	 dialog box
	 ++time in game
	 ++progress bar
	 ++procent string


	*/