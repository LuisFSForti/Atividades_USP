% Luís Filipe Silva Forti - 14592348

aluno("Carlos Silva", "Rua das Orquideas, 32", "016966666666", "05/05/1955", 6,5,7,3,4,8,100).

% a)

calcular_media_prova(NomeAluno, Nota) :-
    aluno(NomeAluno, _, _, _, _, P1, _, P2, Sub, _, _),

    % Verifica quais notas utilizar na conta
    (Sub > P1, P1 =< P2 -> NovoP1 is Sub, NovoP2 is P2 ;
     Sub > P2, P2 < P1 -> NovoP1 is P1, NovoP2 is Sub ;
     NovoP1 is P1, NovoP2 is P2),

    Nota is ((2*NovoP1) + (3*NovoP2))/5.

% b)

calcular_media_trabalho(NomeAluno, Nota) :-
    aluno(NomeAluno, _, _, _, T1, _, T2, _, _, _, _),
    Nota is ((1*T1) + (3*T2))/4.

% c)

calcular_media_final_sem_rec(NomeAluno, Nota) :-
    calcular_media_prova(NomeAluno, NotaProva),
    calcular_media_trabalho(NomeAluno, NotaTrabalho),
    Nota is (NotaProva + NotaTrabalho)/2.

% d)

situacao_sem_rec(NomeAluno, Situacao):-
    calcular_media_final_sem_rec(NomeAluno, Nota),
    (Nota >= 5 -> Situacao = aprovado ;
    Situacao = reprovado).