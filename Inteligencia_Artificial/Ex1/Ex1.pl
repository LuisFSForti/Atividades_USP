temVarinha(hermione).
temVarinha(harry).
temVassoura(harry).

jogadorQuadribol(X) :- 
    temVassoura(X).
bruxo(X) :-
    temVassoura(X), temVarinha(X). 