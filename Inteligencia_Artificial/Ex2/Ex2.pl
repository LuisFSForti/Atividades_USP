%Original

/*classe(Numero, positivo) :-
    Numero > 0.
classe(0, zero).
classe(Numero, negativo) :- Numero < 0.*/

%Otimizado

classe(Numero, Classe) :-
    Numero > 0 -> Classe = positivo
    | Numero =:= 0 -> Classe = zero
    | Classe = negativo.