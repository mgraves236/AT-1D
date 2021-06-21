# Model-AT-w-1D-public-private

<i>model_private-public</i> daje tylko pliki wyjściowe z mapami.

<i>model_private-public-time</i> daje tylko plik wyjściowy z czasami ewolucji oraz końcowymi wartościami funkcji korelacyjnych dla S oraz sigma.

<i>model_private-public-all</i> daje wszytskie statystyki opróćz pliku z czasami ewolucji: średnią magnetyzację, dysonans od czasu, funkcje korelacyjne od czasu.

_________________________________________________________________

Opis plików:

<b>MAPY</b>

<i>model2...</i> - konfiguracja zapisana za pomocą 4 stanów:

             (S_i, sigma_i)
              1 - (1,1)
              2 - (1, -1)
              3 - (-1, 1)
              4 - (-1, -1)
              
<i>Smodel2...</i> - konfiguracja tylko dla spinu S

<i>simgamodel2...</i> - konfiguracja tylko dla spinu sigma

<b>MAGNETYZACJA</b>

<i>model2-magnetization...</i> - średnia magnetyzacja w czasie. Kolejne kolumny to:

               <S_i>
               <sigma_i>
               <S_i, S_(i+1)>
               <S_i, S_(i+2)> 
               <sigma_i, sigma_(i+1)>
               <sigma_i, sigma_(i+2)>
               <S_i, sigma_i>


<b>DYSONANS</b> 

<i>model2-dis...</i> - dysonans między spinem S a sigma w jednym węźle w czasie

<b>FUNCKJE KORELACYJNE</b>

<i>model2-cor...</i> - wartość w czasie. Kolejne kolumny to:

                g(S)
                g(sigma)

<b>ŚREDNI CZAS</b>

<i>TIMEmodel2...</i> - zbiera czasy ewolucji układu do policzenia średniej. Kolejne kolmuny to:

                liczba kroków MC
                wartość g(S)
                wartość g(sigma)
                 
//warunek stopu, gdy g(S) * g(S) == 1 && g(sigma) * g(sigma) == 1
