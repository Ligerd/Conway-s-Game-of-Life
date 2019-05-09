# Conway-s-Game-of-Life

Program powinien umożliwiać:

- wczytywanie do programu początkowej konfiguracji generacji z pliku o wybranym formacie,

- przeprowadzenie zadanej liczby generacji,

- wygenerowanie N obrazów przedstawiających stan wybranych generacji (np. w postaci plików PNG),

- zapisywanie bieżącej generacji do pliku (który może zostać potem wczytany).

Należy zwrócić uwagę na prawidłowe rozdzielenie "wymiennych" elementów programu, tj. sąsiedztwo, zestaw zasad, siatka, rysowanie itp.



#Zasady 
Komórka może znajdować się w jednym z dwóch stanów: matwa (biały kolor), żywa (czarny kolor).

Zestaw zasad przy tworzeniu nowej generacji  jest następujący:

   Martwa komórka, która ma dokładnie 3 żywych sąsiadów, staje się żywa w następnej jednostce czasu (rodzi się)
   Żywa komórka z 2 albo 3 żywymi sąsiadami pozostaje nadal żywa; przy innej liczbie sąsiadów umiera (z "samotności" albo "zatłoczenia").

W Grze w życie stosuje się sąsiedztwo Moore'a.
