% Luís Filipe Silva Forti - 14592348

% Ordem de inserção: sentido horário por profundidade
pode_ir("Arad", "Zerind").
pode_ir("Zerind", "Oradea").
pode_ir("Oradea", "Sibiu").
pode_ir("Sibiu", "Fagaras").
pode_ir("Fagaras", "Bucharest").
pode_ir("Sibiu", "Rimmicu Viicea").
pode_ir("Rimmicu Viicea", "Pitesti").
pode_ir("Pitesti", "Bucharest").
pode_ir("Arad", "Sibiu").
pode_ir("Arad", "Timisoara").
pode_ir("Timisoara", "Lugoj").
pode_ir("Lugoj", "Mehadia").
pode_ir("Mehadia", "Dobreta").
pode_ir("Dobreta", "Craloava").
pode_ir("Craloava", "Pitesti").
pode_ir("Craloava", "Rimmicu Viicea").

esta_na_lista(X, [X | _]) :- !.
esta_na_lista(X, [_ | Resto]) :-
    esta_na_lista(X, Resto).

iniciar_busca_forwards(Inicio, Fim, Caminho) :-
    busca_f(Fim, [Inicio], Caminho).

busca_f(F, [F | Cam], [F | Cam]).

busca_f(F, [Ult_Est | Resto], Cam) :-
    pode_ir(Ult_Est, Novo_Est),
    not(esta_na_lista(Novo_Est, Resto)),
    busca_f(F, [Novo_Est, Ult_Est | Resto], Cam).

/*
    ===================== Compilação na mão =====================

    ?- iniciar_busca_forwards("Arad", "Bucharest", Caminho).
        busca_f("Bucharest", ["Arad"], Caminho).

    busca_f("Bucharest", ["Arad" | []], Caminho).
    busca_f("Bucharest", ["Arad" | []], Caminho) :-
        pode_ir("Arad", Novo_Est), -> Novo_Est = "Zerind"
        not(esta_na_lista("Zerind", [])), -> true
        busca_f("Bucharest", ["Zerind", "Arad" | []], Cam).

    busca_f("Bucharest", ["Zerind" | ["Arad"]], Caminho).
    busca_f("Bucharest", ["Zerind" | ["Arad"]], Caminho) :-
        pode_ir("Zerind", Novo_Est), -> Novo_Est = "Oradea"
        not(esta_na_lista("Oradea", ["Arad"])), -> true
        busca_f("Bucharest", ["Oradea", "Zerind" | ["Arad"]], Cam).

    busca_f("Bucharest", ["Oradea" | ["Zerind", "Arad"]], Caminho).
    busca_f("Bucharest", ["Oradea" | ["Zerind", "Arad"]], Caminho) :-
        pode_ir("Oradea", Novo_Est), -> Novo_Est = "Sibiu"
        not(esta_na_lista("Sibiu", ["Zerind", "Arad"])), -> true
        busca_f("Bucharest", ["Sibiu", "Oradea" | ["Zerind", "Arad"]], Cam).

    busca_f("Bucharest", ["Sibiu" | ["Oradea", "Zerind", "Arad"]], Caminho).
    busca_f("Bucharest", ["Sibiu" | ["Oradea", "Zerind", "Arad"]], Caminho) :-
        pode_ir("Sibiu", Novo_Est), -> Novo_Est = "Fagaras"
        not(esta_na_lista("Fagaras", ["Oradea", "Zerind", "Arad"])), -> true
        busca_f("Bucharest", ["Fagaras", "Sibiu" | ["Oradea", "Zerind", "Arad"]], Cam).

    busca_f("Bucharest", ["Fagaras" | ["Sibiu", "Oradea", "Zerind", "Arad"]], Caminho).
    busca_f("Bucharest", ["Fagaras" | ["Sibiu", "Oradea", "Zerind", "Arad"]], Caminho) :-
        pode_ir("Fagaras", Novo_Est), -> Novo_Est = "Bucharest"
        not(esta_na_lista("Bucharest", ["Sibiu", "Oradea", "Zerind", "Arad"])), -> true
        busca_f("Bucharest", ["Bucharest", "Fagaras" | ["Sibiu", "Oradea", "Zerind", "Arad"]], Cam).

    busca_f("Bucharest", ["Bucharest" | ["Fagaras", "Sibiu", "Oradea", "Zerind", "Arad"]], Caminho).
        -> Caminho = ["Bucharest" | ["Fagaras", "Sibiu", "Oradea", "Zerind", "Arad"]]
    iniciar_busca_forwards("Arad", "Bucharest", Caminho).
        -> Caminho = ["Bucharest", "Fagaras", "Sibiu", "Oradea", "Zerind", "Arad"]

    ===================== Execução real =====================

    ?- iniciar_busca_forwards("Arad", "Bucharest", Caminho).
    Caminho = ["Bucharest", "Fagaras", "Sibiu", "Oradea", "Zerind", "Arad"] .
*/