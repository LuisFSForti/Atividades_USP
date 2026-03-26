% Luís Filipe Silva Forti - 14592348

% Para incluir o cálculo de reprovação
:- consult('Ex4-1.pl').

aluno("Carlos Silva", "Rua das Orquideas, 32", "016966666666", "05/05/1955", 10,10,10,10,4,8,100).
aluno("Mari Pereira", "Rua das Orquideas, 32", "016966666666", "05/05/1955", 10,2,10,3,4,8,30).
aluno("Joao Barrosa", "Rua das Orquideas, 32", "016966666666", "05/05/1955", 6,10,7,10,4,8,60).
aluno("Matias Luzes", "Rua das Orquideas, 32", "016966666666", "05/05/1955", 0,0,0,0,0,0,0).

/*
% a)

?- aluno(Nome, _, _, _, _, 10, _, 10, _, _, _).
Nome = "Carlos Silva" ;
Nome = "Joao Barrosa".

% b)

?- aluno(Nome, _, _, _, 10, _, 10, _, _, _, _).
Nome = "Carlos Silva" ;
Nome = "Mari Pereira" .

% c)

?- aluno(Nome, _, _, _, _, P1, _, P2, _, _, _), P1 < 5, P2 < 5.
Nome = "Mari Pereira",
P1 = 2,
P2 = 3 ;
Nome = "Matias Luzes",
P1 = P2, 
P2 = 0.

% d)

?- aluno(Nome, _, _, _, _, _, _, _, _, _, Freq), Freq < 70.
Nome = "Mari Pereira",
Freq = 30 ;
Nome = "Joao Barrosa",
Freq = 60 ;
Nome = "Matias Luzes",
Freq = 0.

% e)

?- situacao_sem_rec(Nome, Situacao), Situacao = reprovado.
Nome = "Matias Luzes",
Situacao = reprovado.

% f)

?- situacao_sem_rec(Nome, Situacao), Situacao = aprovado.
Nome = "Carlos Silva",
Situacao = aprovado ;
Nome = "Mari Pereira",
Situacao = aprovado ;
Nome = "Joao Barrosa",
Situacao = aprovado .

*/