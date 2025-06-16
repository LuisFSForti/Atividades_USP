using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;


public class ThreadController : MonoBehaviour, IDropHandler
{
    //Sprites de cada recurso
    [SerializeField] private List<Sprite> _spritesRecursos;
    //Controladores de imagens dos recursos da thread
    [SerializeField] private List<Image> _slotsRecursos;
    //Controladores de textos dos recursos da thread
    [SerializeField] private List<TMP_Text> _repeticoesRecursos;
    //Quantidade de recursos, repeti��es em um dado instante e n�mero de etapas
    [SerializeField] private int _minimoRecursoPorVez, _maximoRecursoPorVez, _minimasRepeticoes, _maximasRepeticoes, _minimasEtapas, _maximaEtapas;
    //Tempo m�nimo e m�ximo de processamento
    [SerializeField] private float _tempoMinimo, _tempoMaximo;

    //Controlador de recursos do jogo
    private RecursosController _controladorRecursos;

    //Controlador de imagem da barra de progresso
    private Image _barraProgresso;
    //Tempo processado, tempo total, quando foi a ultima etapa e intervalo at� a pr�xima
    private float _progresso, _tempoTotal, _ultimaEtapa, _proximaEtapa;

    //Se j� limpou os slots
    private bool _jaLimpou;
    //N�mero de etapas total, quantas j� foram processados e quantos recursos est� esperando para avan�ar
    private int _numeroDeEtapas, _etapasProcessadas, _esperandoRecursos;
    //A lista de recursos necess�rios para as etapas e a lista de recursos usado na �ltima etapa
    private List<int[]> _recursosDesejados, _ultimosRecursosUsados;

    //Para calcular quando ser� a pr�xima etapa
    private void CalcularProximaEtapa()
    {
        //Salva quando come�ou
        _ultimaEtapa = Time.time;

        //Se ainda h� etapas a serem processadas
        if (_numeroDeEtapas > _etapasProcessadas)
            //Calcula quando ser� a pr�xima, com uma pequena varia��o
            _proximaEtapa = _tempoTotal / _numeroDeEtapas * UnityEngine.Random.Range(0.9f, 1f);
        //Se j� processou todas as etapas
        else
            //Utiliza um valor grande o suficiente para n�o passar por outra etapa
            _proximaEtapa = Time.time * 3;
    }

    //Para atualizar os slots de recursos
    private void AtualizarVisualRecurso(int index, Color cor)
    {
        //Atualiza a cor da image e do texto relacionados
        _slotsRecursos[index].color = cor;
        _repeticoesRecursos[index].color = cor;
    }

    //Para verificar os estados dos recursos necess�rios
    private void ChecarDisponiveis()
    {
        //Se algum recurso estiver barrado pelo sem�foro, ent�o a thread como um todo tamb�m estar�
        bool estaBarrado = false;

        //Para cada recurso
        foreach(int[] val in _recursosDesejados)
        {
            //Se ele n�o j� estiver alocado
            if (_slotsRecursos[_recursosDesejados.IndexOf(val)].color != Color.green)
            {
                //Verifica se est� dispon�vel
                if (_controladorRecursos.EstaDisponivel(val[0]))
                {
                    //Se sim, atualiza o recurso para dizer que est� � espera
                    AtualizarVisualRecurso(_recursosDesejados.IndexOf(val), Color.yellow);

                    //Se n�o estiver barrado
                    if (!estaBarrado)
                        //Atualiza a cor da barra
                        _barraProgresso.color = Color.yellow;
                }
                //Se n�o estiver dispon�vel
                else
                {
                    //Atualiza o recurso para dizer que est� barrado
                    AtualizarVisualRecurso(_recursosDesejados.IndexOf(val), Color.red);

                    //Atualiza a cor da barra
                    _barraProgresso.color = Color.red;
                    //Salva que est� barrada
                    estaBarrado = true;
                }
            }
        }
    }

    //Para limpar os recursos
    private void LimparRecursos()
    {
        //Reinstancia a lista de recursos usados na �ltima etapa
        _ultimosRecursosUsados = new List<int[]>();

        //Para cada recurso
        for (int i = 0; i < _recursosDesejados.Count; i++)
        {
            //Diminui o n�mero de repeti��es em 1
            _recursosDesejados[i][1]--;

            //Se ele tiver terminado de ser processado
            if (_recursosDesejados[i][1] <= 0)
            {
                //Para cada slot antes do �ltimo ocupado
                for (int j = i; j < _recursosDesejados.Count - 1; j++)
                {
                    //Move os dados do de cima para o de baixo
                    _slotsRecursos[j].sprite = _slotsRecursos[j + 1].sprite;
                    _slotsRecursos[j].color = _slotsRecursos[j + 1].color;
                    _repeticoesRecursos[j].text = _repeticoesRecursos[j + 1].text;
                }

                //Limpa o �ltimo ocupado
                _slotsRecursos[_recursosDesejados.Count - 1].color = Color.yellow;
                _slotsRecursos[_recursosDesejados.Count - 1].enabled = false;
                _repeticoesRecursos[_recursosDesejados.Count - 1].text = "";

                //Avisa o controlador de recursos do jogo que liberou o recurso
                _controladorRecursos.RecursoLiberado(_recursosDesejados[i][0]);

                //Salva qual recurso est� sendo removido
                _ultimosRecursosUsados.Add(_recursosDesejados[i]);
                //Remove ele da lista
                _recursosDesejados.Remove(_recursosDesejados[i]);

                //Diminui i em 1 pois a lista perdeu um valor
                i--;
            }
            //Se n�o acabou de processar
            else
            {
                //Atualiza o n�mero de repeti��es
                _repeticoesRecursos[i].text = "x" + _recursosDesejados[i][1];
            }
        }

        //Salva que j� limpou
        _jaLimpou = true;
    }

    //Para pedir novos recursos
    private void PedirRecursos()
    {
        //Define que ser� necess�ria uma limpeza
        _jaLimpou = false;

        //Calcula quantos recursos novos ele quer
        //Se j� tiver algum recurso restante da etapa anterior, diminui o limite e a chance de requisitar novos
        _esperandoRecursos = UnityEngine.Random.Range(_minimoRecursoPorVez - _recursosDesejados.Count, _maximoRecursoPorVez - _recursosDesejados.Count + 1);

        //Se n�o quiser recursos novos
        if (_esperandoRecursos <= 0)
        {
            //Define que n�o est� esperando recursos novos
            _esperandoRecursos = 0;
            //Calcula quando ser� a pr�xima etapa
            CalcularProximaEtapa();
            //Sai do ciclo
            return;
        }

        //Lista com todos os recursos
        List<int> possiveisRecursos = Enum.GetValues(typeof(Recursos)).Cast<int>().ToList();

        //https://stackoverflow.com/questions/42460302/search-a-list-of-string-array-to-find-a-value-in-matching-element-and-return-ano

        //Para cada recurso
        for(int i = 0; i < possiveisRecursos.Count; i++)
        {
            //Pega seu valor relacionado
            int val = possiveisRecursos[i];

            //Para cada valor em _recursosDesejados, verifica se � igual ao valor relacionado ao recurso, se sim, salva que existe um valor igual
            bool existe = false;
            foreach(int[] n in _recursosDesejados)
            {
                if (n[0] == val)
                {
                    existe = true; 
                    break; 
                }
            }

            //Pega o primeiro retorno
            //Como n�o podem ter valores repetidos, basta verificar o primeiro ou se sequer existe um
            if(existe)
            {
                //Se sim, remove o valor dos recursos
                possiveisRecursos.Remove(val);
                //Diminuiu i em 1 pois removeu um valor da lista do loop
                i--;
                continue;
            }

            //Para cada valor em _ultimosRecursosUsados, verifica se � igual ao valor relacionado ao recurso, se sim, salva que ele n�o deveria ser utilizado novamente t�o cedo
            existe = false;
            foreach (int[] n in _ultimosRecursosUsados)
            {
                if (n[0] == val)
                {
                    existe = true; 
                    break;
                }
            }

            //Pega o primeiro retorno
            //Como n�o podem ter valores repetidos, basta verificar o primeiro ou se sequer existe um
            if (existe)
            {
                //Se sim, remove o valor dos recursos
                possiveisRecursos.Remove(val);
                //Diminuiu i em 1 pois removeu um valor da lista do loop
                i--;
                continue;
            }
        }

        //Se ele deseja mais recursos do que a quantidade de op��es
        if (_esperandoRecursos > possiveisRecursos.Count)
            //Limita � pegar as op��es dispon�veis
            _esperandoRecursos = possiveisRecursos.Count;

        //Quantos valores ele tinha antes da adi��o dos novos
        int valoresJaExistentes = _recursosDesejados.Count;

        //Para cada recurso requisitado
        //i est� deslocado para n�o interferir em slots que j� possuam recursos da etapa anterior
        for (int i = valoresJaExistentes; i < _esperandoRecursos + valoresJaExistentes; i++)
        {
            //Escolhe um recurso aleat�rio da lista
            int recurso = possiveisRecursos[UnityEngine.Random.Range(0, possiveisRecursos.Count)];
            //Remove ele da lista
            possiveisRecursos.Remove(recurso);

            //Adiciona o recurso � lista de recursos desejados, com uma repeti��o aleat�ria dentro do limite
            _recursosDesejados.Add(new int[2] { recurso, UnityEngine.Random.Range(_minimasRepeticoes, _maximasRepeticoes + 1) });

            //Se o n�mero de repeti��es com o recurso for maior que o n�mero de etapas restantes
            if (_recursosDesejados[i][1] > _numeroDeEtapas - _etapasProcessadas)
                //Atualiza o n�mero de repeti��es
                _recursosDesejados[i][1] = _numeroDeEtapas - _etapasProcessadas;

            //Ativa o slot do recurso
            _slotsRecursos[i].enabled = true;
            //Seleciona a imagem relacionada
            _slotsRecursos[i].sprite = _spritesRecursos[recurso];
            //Escreve o n�mero de repeti��es
            _repeticoesRecursos[i].text = "x" + _recursosDesejados[i][1];
        }

        //Depois de salvar todos os recursos novos
        //Verifica o estado de cada um
        ChecarDisponiveis();
    }

    //Quando o jogador soltar um recurso na tela
    public void OnDrop(PointerEventData eventData)
    {
        //Para o jogador n�o poder alocar recursos quando o jogo est� parado
        if (Time.timeScale == 0f)
            return;

        //Define qual o valor do recurso pela sua tag
        int recurso = (int)Enum.Parse(typeof(Recursos), eventData.pointerDrag.tag);

        //Para cada valor em _recursosDesejados, verifica se � igual ao valor relacionado ao recurso e, se for, salva sua posi��o na lista
        int pos = -1;

        for(int i = 0; i < _recursosDesejados.Count; i++)
        {
            if (_recursosDesejados[i][0] == recurso)
            {
                pos = i;
                break;
            }
        }
        
        //Se possui uma posi��o
        if (pos >= 0)
        {
            //Atualiza que recebeu o recurso
            AtualizarVisualRecurso(pos, Color.green);
            //Define que est� esperando um a menos agora
            _esperandoRecursos--;

            //Destroy o objeto do recurso
            Destroy(eventData.pointerDrag);
            //Avisa o controlador de recursos do jogo que ele foi alocado
            _controladorRecursos.RecursoDado(recurso);

            //Se todos os recursos foram alocados
            if(_esperandoRecursos == 0)
            {
                //Calcula quando ser� a pr�xima etapa
                CalcularProximaEtapa();

                //Atualiza a cor da barra
                _barraProgresso.color = Color.green;
            }
        }
    }

    void Start()
    {
        //Encontra o controlador de recursos do jogo
        _controladorRecursos = GameObject.FindGameObjectWithTag("GameController").GetComponent<RecursosController>();

        //Para cada controlador de imagem dos objetos-filhos
        foreach (var item in GetComponentsInChildren<Image>())
        {
            //Se for do tipo filled
            if (item.type == Image.Type.Filled)
            {
                //Salva o controlador, pois pertence � barra de progresso
                _barraProgresso = item;
                break;
            }
        }

        //Zera o progresso
        _barraProgresso.fillAmount = 0;
        _progresso = 0;

        //Calcula um n�mero de etapas aleat�rio
        _numeroDeEtapas = UnityEngine.Random.Range(_minimasEtapas, _maximaEtapas);
        //Define que n�o foram processadas nenhuma
        _etapasProcessadas = 0;
        //Calcula o tempo de processamento no intervalo
        _tempoTotal = UnityEngine.Random.Range(_tempoMinimo, _tempoMaximo);

        //Calcula quando ser� a pr�xima etapa
        CalcularProximaEtapa();

        //Define que j� limpou os slots, pois eles iniciam limpos
        _jaLimpou = true;
        //Define que n�o est� esperando nenhum recurso
        _esperandoRecursos = 0;

        //Instancia a lista de recursos necess�rios para as etapas
        _recursosDesejados = new List<int[]>();

        //Instancia a lista de recursos usados na �ltima etapa
        _ultimosRecursosUsados = new List<int[]>();
    }

    void Update()
    {
        //Se concluiu o processamento
        if (_barraProgresso.fillAmount >= 1)
        {
            //Limpa os recursos para liberar qualquer um que tenha permanecido
            LimparRecursos();

            //Marca para destruir este script, pois concluiu
            Destroy(this);
            //Sai da fun��o
            return;
        }

        //Se estiver esperando recursos
        if (_esperandoRecursos > 0)
        {
            //Verifica o estado dos recursos
            ChecarDisponiveis();
            //Sai da fun��o
            return;
        }

        //Se estiver processando

        //Verifica se est� na metade da etapa
        if (_ultimaEtapa + _proximaEtapa / 2f <= Time.time && !_jaLimpou)
        {
            //Se sim, libera os recursos
            LimparRecursos();
            //Aumenta o n�mero de etapas processadas
            _etapasProcessadas++;
        }

        //Se Concluiu a etapa
        if (_ultimaEtapa + _proximaEtapa <= Time.time)
        {
            //Pede novos recursos
            PedirRecursos();
        }
        //Sen�o
        else
        {
            //Aumenta o progresso
            _progresso += Time.deltaTime;
            _barraProgresso.fillAmount = _progresso / _tempoTotal;
        }
    }
}
