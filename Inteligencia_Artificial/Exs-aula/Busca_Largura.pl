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

final("Bucharest").

concatenar([], L, L).
concatenar([X|Y], L, [X|Lista]) :-
    concatenar(Y, L, Lista).

esta_na_lista(X, [X | _]) :- !.
esta_na_lista(X, [_ | Resto]) :-
    esta_na_lista(X, Resto).

estender([No|Caminho], NovosCaminhos) :-
    findall([NovoNo, No|Caminho],
            (pode_ir(No, NovoNo),
            not(esta_na_lista(NovoNo, [No | Caminho]))),
            NovosCaminhos).

resolva(No, Solucao) :-
    busca_largura([[No]], Solucao).

busca_largura([[No | Caminho] | _], [No | Caminho]) :-
    final(No).

busca_largura([Caminho | OutrosCaminhos], Sol) :-
    estender(Caminho, NovosCaminhos),
    concatenar(OutrosCaminhos, NovosCaminhos, Caminhos1),
    busca_largura(Caminhos1, Sol).

/*
    ===================== Compilação na mão =====================

    ?- resolva("Arad", Solucao).
        busca_largura([["Arad"]], Solucao).

    busca_largura([["Arad" | []] | _], ["Arad" | []]) :-
        final("Arad"). -> false
    busca_largura([["Arad"] | []], Sol) :-
        estender(["Arad"], NovosCaminhos),
            -> NovosCaminhos = [["Zerind", "Arad"], ["Sibiu", "Arad"], ["Timisoara", "Arad"]]
        concatenar([], NovosCaminhos, Caminhos1),
            -> Caminhos1 = [["Zerind", "Arad"], ["Sibiu", "Arad"], ["Timisoara", "Arad"]]
        busca_largura(Caminhos1, Sol).

    busca_largura([["Zerind", "Arad"] | _], ["Zerind", "Arad"]) :-
        final("Zerind"). -> false
    busca_largura([["Zerind", "Arad"] | [["Sibiu", "Arad"], ["Timisoara", "Arad"]]], Sol) :-
        estender(["Zerind", "Arad"], NovosCaminhos),
            -> NovosCaminhos = [["Oradea", "Zerind", "Arad"]]
        concatenar([["Sibiu", "Arad"], ["Timisoara", "Arad"]], NovosCaminhos, Caminhos1),
            -> Caminhos1 = [["Sibiu", "Arad"], ["Timisoara", "Arad"], ["Oradea", "Zerind", "Arad"]]
        busca_largura(Caminhos1, Sol).

    busca_largura([["Sibiu", "Arad"] | _], ["Sibiu", "Arad"]) :-
        final("Sibiu"). -> false
    busca_largura([["Sibiu", "Arad"] | [["Timisoara", "Arad"], ["Oradea", "Zerind", "Arad"]]], Sol) :-
        estender(["Sibiu", "Arad"], NovosCaminhos),
            -> NovosCaminhos = [["Fagaras", "Sibiu", "Arad"], ["Rimmicu Viicea", "Sibiu", "Arad"]]
        concatenar([["Timisoara", "Arad"], ["Oradea", "Zerind", "Arad"]], NovosCaminhos, Caminhos1),
            -> Caminhos1 = [["Timisoara", "Arad"],["Oradea", "Zerind", "Arad"],["Fagaras", "Sibiu", "Arad"],["Rimmicu Viicea", "Sibiu", "Arad"]]
        busca_largura(Caminhos1, Sol).

    busca_largura([["Timisoara", "Arad"] | _], ["Timisoara", "Arad"]) :-
        final("Timisoara"). -> false
    busca_largura([["Timisoara", "Arad"] | [["Oradea", "Zerind", "Arad"], ["Fagaras", "Sibiu", "Arad"], ["Rimmicu Viicea", "Sibiu", "Arad"]]], Sol) :-
        estender(["Timisoara", "Arad"], NovosCaminhos),
            -> NovosCaminhos = [["Lugoj", "Timisoara", "Arad"]]
        concatenar([["Oradea", "Zerind", "Arad"], ["Fagaras", "Sibiu", "Arad"], ["Rimmicu Viicea", "Sibiu", "Arad"]], NovosCaminhos, Caminhos1),
            -> Caminhos1 = [
                ["Oradea", "Zerind", "Arad"],
                ["Fagaras", "Sibiu", "Arad"],
                ["Rimmicu Viicea", "Sibiu", "Arad"],
                ["Lugoj", "Timisoara", "Arad"]
                ]
        busca_largura(Caminhos1, Sol).

    busca_largura([["Oradea", "Zerind", "Arad"] | _], ["Oradea", "Zerind", "Arad"]) :-
        final("Oradea"). -> false
    busca_largura([["Oradea", "Zerind", "Arad"] | [["Fagaras", "Sibiu", "Arad"], ["Rimmicu Viicea", "Sibiu", "Arad"], ["Lugoj", "Timisoara", "Arad"]]], Sol) :-
        estender(["Oradea", "Zerind", "Arad"], NovosCaminhos),
            -> NovosCaminhos = [["Sibiu", "Oradea", "Zerind", "Arad"]]
        concatenar([["Fagaras", "Sibiu", "Arad"], ["Rimmicu Viicea", "Sibiu", "Arad"], ["Lugoj", "Timisoara", "Arad"]], NovosCaminhos, Caminhos1),
            -> Caminhos1 = [
                ["Fagaras", "Sibiu", "Arad"],
                ["Rimmicu Viicea", "Sibiu", "Arad"],
                ["Lugoj", "Timisoara", "Arad"],
                ["Sibiu", "Oradea", "Zerind", "Arad"]
                ]
        busca_largura(Caminhos1, Sol).

    busca_largura([["Fagaras", "Sibiu", "Arad"] | _], ["Fagaras", "Sibiu", "Arad"]) :-
        final("Fagaras"). -> false
    busca_largura([["Fagaras", "Sibiu", "Arad"] | [["Rimmicu Viicea", "Sibiu", "Arad"], ["Lugoj", "Timisoara", "Arad"], ["Sibiu", "Oradea", "Zerind", "Arad"]]], Sol) :-
        estender(["Fagaras", "Sibiu", "Arad"], NovosCaminhos),
            -> NovosCaminhos = [["Bucharest", "Fagaras", "Sibiu", "Arad"]]
        concatenar([["Rimmicu Viicea", "Sibiu", "Arad"], ["Lugoj", "Timisoara", "Arad"], ["Sibiu", "Oradea", "Zerind", "Arad"]], NovosCaminhos, Caminhos1),
            -> Caminhos1 = [
                ["Rimmicu Viicea", "Sibiu", "Arad"],
                ["Lugoj", "Timisoara", "Arad"],
                ["Sibiu", "Oradea", "Zerind", "Arad"],
                ["Bucharest", "Fagaras", "Sibiu", "Arad"]
                ]
        busca_largura(Caminhos1, Sol).

    busca_largura([["Rimmicu Viicea", "Sibiu", "Arad"] | _], ["Rimmicu Viicea", "Sibiu", "Arad"]) :-
        final("Rimmicu Viicea"). -> false
    busca_largura([["Rimmicu Viicea", "Sibiu", "Arad"] | [["Lugoj", "Timisoara", "Arad"], ["Sibiu", "Oradea", "Zerind", "Arad"], ["Bucharest", "Fagaras", "Sibiu", "Arad"]]], Sol) :-
        estender(["Rimmicu Viicea", "Sibiu", "Arad"], NovosCaminhos),
            -> NovosCaminhos = [["Pitesti", "Rimmicu Viicea", "Sibiu", "Arad"]]
        concatenar([["Lugoj", "Timisoara", "Arad"], ["Sibiu", "Oradea", "Zerind", "Arad"], ["Bucharest", "Fagaras", "Sibiu", "Arad"]], NovosCaminhos, Caminhos1),
            -> Caminhos1 = [
                ["Lugoj", "Timisoara", "Arad"],
                ["Sibiu", "Oradea", "Zerind", "Arad"],
                ["Bucharest", "Fagaras", "Sibiu", "Arad"],
                ["Pitesti", "Rimmicu Viicea", "Sibiu", "Arad"]
                ]
        busca_largura(Caminhos1, Sol).

    busca_largura([["Lugoj", "Timisoara", "Arad"] | _], ["Lugoj", "Timisoara", "Arad"]) :-
        final("Lugoj"). -> false
    busca_largura([["Lugoj", "Timisoara", "Arad"] | [["Sibiu", "Oradea", "Zerind", "Arad"], ["Bucharest", "Fagaras", "Sibiu", "Arad"], ["Pitesti", "Rimmicu Viicea", "Sibiu", "Arad"]]], Sol) :-
        estender(["Lugoj", "Timisoara", "Arad"], NovosCaminhos),
            -> NovosCaminhos = [["Mehadia", "Lugoj", "Timisoara", "Arad"]]
        concatenar([["Sibiu", "Oradea", "Zerind", "Arad"], ["Bucharest", "Fagaras", "Sibiu", "Arad"], ["Pitesti", "Rimmicu Viicea", "Sibiu", "Arad"]], NovosCaminhos, Caminhos1),
            -> Caminhos1 = [
                ["Sibiu", "Oradea", "Zerind", "Arad"],
                ["Bucharest", "Fagaras", "Sibiu", "Arad"],
                ["Pitesti", "Rimmicu Viicea", "Sibiu", "Arad"],
                ["Mehadia", "Lugoj", "Timisoara", "Arad"]
                ]
        busca_largura(Caminhos1, Sol).

    busca_largura([["Sibiu", "Oradea", "Zerind", "Arad"] | _], ["Sibiu", "Oradea", "Zerind", "Arad"]) :-
        final("Sibiu"). -> false
    busca_largura([["Sibiu", "Oradea", "Zerind", "Arad"] | [["Bucharest", "Fagaras", "Sibiu", "Arad"], ["Pitesti", "Rimmicu Viicea", "Sibiu", "Arad"], ["Mehadia", "Lugoj", "Timisoara", "Arad"]]], Sol) :-
        estender(["Sibiu", "Oradea", "Zerind", "Arad"], NovosCaminhos),
            -> NovosCaminhos = [["Fagaras", "Sibiu", "Oradea", "Zerind", "Arad"],["Rimmicu Viicea", "Sibiu", "Oradea", "Zerind", "Arad"]]
        concatenar([["Bucharest", "Fagaras", "Sibiu", "Arad"], ["Pitesti", "Rimmicu Viicea", "Sibiu", "Arad"], ["Mehadia", "Lugoj", "Timisoara", "Arad"]], NovosCaminhos, Caminhos1),
            -> Caminhos1 = [
                ["Bucharest", "Fagaras", "Sibiu", "Arad"],
                ["Pitesti", "Rimmicu Viicea", "Sibiu", "Arad"],
                ["Mehadia", "Lugoj", "Timisoara", "Arad"],
                ["Fagaras", "Sibiu", "Oradea", "Zerind", "Arad"],
                ["Rimmicu Viicea", "Sibiu", "Oradea", "Zerind", "Arad"]
                ]
        busca_largura(Caminhos1, Sol).

    busca_largura([["Bucharest", "Fagaras", "Sibiu", "Arad"] | _], ["Bucharest", "Fagaras", "Sibiu", "Arad"]) :-
        final("Bucharest"). -> true

    resolva("Arad", Solucao).
        -> Solucao = ["Bucharest", "Fagaras", "Sibiu", "Arad"].
            

    ===================== Execução real =====================

    ?- resolva("Arad", Solucao).
    Solucao = ["Bucharest", "Fagaras", "Sibiu", "Arad"] .
*/