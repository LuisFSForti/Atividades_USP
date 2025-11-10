//Ex 1

create table Time (
    nome varchar2(30),
    estado varchar2(2) not null,
    tipo varchar2(12) not null,
    saldo_gols int,
    constraint PK_Time Primary Key (nome),
    constraint CK_Estado_Time CHECK (length(estado) = 2),
    constraint CK_Tipo_Time CHECK (Upper(tipo) IN ('AMADOR', 'PROFISSIONAL'))
);

create table Joga (
    time1 varchar2(30),
    time2 varchar2(30),
    classico number(1) default 0 not null,
    constraint PK_Joga Primary Key (time1, time2),
    constraint FK_Joga_Time1 foreign key (time1)
        references Time(nome)
        on delete cascade,
    constraint FK_Joga_Time2 foreign key (time2)
        references Time(nome)
        on delete cascade,
    constraint BOOL_Classico_Joga check (classico in (0, 1))    
);

create table Partida(
    time1 varchar2(30),
    time2 varchar2(30),
    data date,
    placar varchar2(5) default '0x0' not null,
    local varchar2(50) not null,
    constraint PK_Partida Primary Key (time1, time2, data),
    constraint FK_Partida Foreign Key (time1, time2)
        references Joga(time1, time2)
        on delete cascade,
    constraint CK_Placar_Partida check (REGEXP_LIKE(placar, '^(?:[0-9]|[1-9][0-9])x(?:[0-9]|[1-9][0-9])$'))    
);

create table Jogador(
    cpf varchar2(11),
    rg varchar2(9),
    nome varchar2(30),
    data_nasc date not null,
    naturalidade varchar2(20),
    time varchar2(30) not null,
    constraint PK_Jogador Primary Key (cpf),
    constraint SK_Jogador unique(rg, nome),
    constraint FK_Jogador_Time Foreign Key(time)
        references Time(nome)
        on delete cascade,
    constraint CK_CPF_Jogador check (cast(cpf as number(11, 0)) > 9999999999),
    constraint CK_RG_Jogador check (cast(rg as number(9, 0)) > 99999999)
);

create table Posicao_Jogador(
    jogador varchar2(11),
    nome varchar2(30),
    constraint PK_Posicao_Jogador Primary Key (jogador, nome),
    constraint FK_Posicao_Jogador_Jogador Foreign Key (jogador)
        references Jogador(cpf)
        on delete cascade
);

create table Diretor(
    time varchar2(30),
    nome varchar2(30),
    constraint PK_Diretor Primary Key (time, nome),
    constraint FK_Diretor_Time Foreign Key (time)
        references Time(nome)
        on delete cascade
);

create table Uniforme(
    time varchar2(30),
    tipo varchar2(7),
    cor_principal varchar(30) not null,
    constraint PK_Uniforme Primary Key (time, tipo),
    constraint FK_Uniforme_Time Foreign Key (time)
        references Time(nome)
        on delete cascade,
    constraint CK_Tipo_Uniforme check (upper(tipo) in ('TITULAR', 'RESERVA'))    
);

//Ex 2

insert into Time values('XV de Piracicaba', 'SP', 'profissional', 100);
insert into Time values('Grêmio', 'RS', 'profissional', -100);
insert into Time values('Corinthinas', 'SP', 'profissional', 0);
insert into Time values('Flamengo', 'RJ', 'profissional', 2);

insert into Jogador values('52581866870', '547029809', 'Luís', sysdate, 'Piracicabano', 'XV de Piracicaba');
insert into Jogador values('52581866880', '547029810', 'Josue', sysdate, 'Carioca', 'Flamengo');
insert into Jogador values('52583866880', '547020810', 'Luiza', sysdate, 'Paraense', 'Corinthinas');
insert into Jogador values('54583866880', '567020810', 'Joana', sysdate, 'Amapense', 'Grêmio');

select * from Time;
select * from Jogador;