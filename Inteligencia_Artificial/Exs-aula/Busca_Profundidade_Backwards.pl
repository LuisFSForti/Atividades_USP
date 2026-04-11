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

iniciar_busca_bacwards(Inicio, Fim, Caminho) :-
    busca_b(Inicio, [Fim], Caminho).

busca_b(I, [I | Cam], [I | Cam]).

busca_b(I, [Ult_Est | Resto], Cam) :-
    pode_ir(Novo_Est, Ult_Est),
    not(esta_na_lista(Novo_Est, Resto)),
    busca_b(I, [Novo_Est, Ult_Est | Resto], Cam).

/*
    ===================== Compilação na mão =====================

    ?- iniciar_busca_bacwards("Arad", "Bucharest", Caminho).
        busca_b("Arad", ["Bucharest"], Caminho).
    
    busca_b("Arad", ["Bucharest" | []], Caminho).
    busca_b("Arad", ["Bucharest" | []], Caminho) :-
        pode_ir(Novo_Est, "Bucharest"), -> Novo_Est = "Fagaras"
        not(esta_na_lista("Fagaras", [])), -> true
        busca_b("Arad", ["Fagaras", "Bucharest" | []], Cam).

    busca_b("Arad", ["Fagaras" | ["Bucharest"]], Caminho).
    busca_b("Arad", ["Fagaras" | ["Bucharest"]], Caminho). :-
        pode_ir(Novo_Est, "Fagaras"), -> Novo_Est = "Sibiu"
        not(esta_na_lista("Sibiu", ["Bucharest"])), -> true
        busca_b("Arad", ["Sibiu", "Fagaras" | ["Bucharest"]], Cam).

    busca_b("Arad", ["Sibiu" | ["Fagaras", "Bucharest"]], Caminho).
    busca_b("Arad", ["Sibiu" | ["Fagaras", "Bucharest"]], Caminho). :-
        pode_ir(Novo_Est, "Sibiu"), -> Novo_Est = "Oradea"
        not(esta_na_lista("Oradea", ["Fagaras", "Bucharest"])), -> true
        busca_b("Arad", ["Oradea", "Sibiu" | ["Fagaras", "Bucharest"]], Cam).

    busca_b("Arad", ["Oradea" | ["Sibiu", "Fagaras", "Bucharest"]], Caminho).
    busca_b("Arad", ["Oradea" | ["Sibiu", "Fagaras", "Bucharest"]], Caminho). :-
        pode_ir(Novo_Est, "Oradea"), -> Novo_Est = "Zerind"
        not(esta_na_lista("Zerind", ["Sibiu", "Fagaras", "Bucharest"])), -> true
        busca_b("Arad", ["Zerind", "Oradea" | ["Sibiu", "Fagaras", "Bucharest"]], Cam).

    busca_b("Arad", ["Zerind" | ["Oradea", "Sibiu", "Fagaras", "Bucharest"]], Caminho).
    busca_b("Arad", ["Zerind" | ["Oradea", "Sibiu", "Fagaras", "Bucharest"]], Caminho). :-
        pode_ir(Novo_Est, "Zerind"), -> Novo_Est = "Arad"
        not(esta_na_lista("Arad", ["Oradea", "Sibiu", "Fagaras", "Bucharest"])), -> true
        busca_b("Arad", ["Arad", "Zerind" | ["Oradea", "Sibiu", "Fagaras", "Bucharest"]], Cam).

    busca_b("Arad", ["Arad" | ["Zerind", "Oradea", "Sibiu", "Fagaras", "Bucharest"]], Caminho).
        -> Caminho = ["Arad" | ["Zerind", "Oradea", "Sibiu", "Fagaras", "Bucharest"]]
    iniciar_busca_bacwards("Arad", "Bucharest", Caminho).
        -> Caminho = ["Arad", "Zerind", "Oradea", "Sibiu", "Fagaras", "Bucharest"]

    ===================== Execução real =====================

    ?- iniciar_busca_bacwards("Arad", "Bucharest", Caminho).
    Caminho = ["Arad", "Zerind", "Oradea", "Sibiu", "Fagaras", "Bucharest"] .
*/