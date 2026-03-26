% a) Eu usaria a estrutura de sequências seq(cidade1, cidade2)
%    Desta forma eu garanto a unilateralidade dos caminhos

% b)

caminho(araraquara, sao_carlos).
caminho(barretos, franca).
caminho(bauru, botucatu).
caminho(botucatu, sorocaba).
caminho(franca, ribeirao_preto).
caminho(marilia, bauru).
caminho(ribeirao_preto, araraquara).
caminho(sao_carlos, bauru).

% c)

/*encontrar_caminho(Cidade1, Cidade2) :-
    caminho(Cidade1, Cidade2).
encontrar_caminho(Cidade1, Cidade2) :-
    caminho(Cidade1, CidadeIterm),
    encontrar_caminho(CidadeIterm, Cidade2).*/

% d)

% Para criar a bilateralidade
ligado(Cidade1, Cidade2) :-
    caminho(Cidade1, Cidade2) | caminho(Cidade2, Cidade1).

% Inicia a busca, passando a cidade atual como uma visitada
encontrar_caminho(Cidade1, Cidade2) :-
    encontrar_caminho(Cidade1, Cidade2, [Cidade1]).

% Se as duas forem diretamente conectadas
encontrar_caminho(Cidade1, Cidade2, _) :-
    ligado(Cidade1, Cidade2).

% Se precisar uma busca mais profunda
% Encontra alguma conexão com a Cidade1, valendo a bilateralidade
% \+ = não pode se provar como verdadeiro
% \+ member(Alguem, Visitados) verifica se a cidade encontrada já foi visitada,
% avançando apenas se não foi
% Então começa outra busca por recursividade, adicionando a cidade visitada à lista
encontrar_caminho(Cidade1, Cidade2, Visitados) :-
    ligado(Cidade1, Alguem),
    \+ member(Alguem, Visitados), encontrar_caminho(Alguem, Cidade2, [Alguem|Visitados]).

% Este exercício não usa cortes (!), 
% uma vez que todas as buscas por backtracking são essenciais para o bom funcionamento