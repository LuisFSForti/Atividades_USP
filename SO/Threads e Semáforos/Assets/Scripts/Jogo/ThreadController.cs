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
    //Quantidade de recursos, repetições em um dado instante e número de etapas
    [SerializeField] private int _minimoRecursoPorVez, _maximoRecursoPorVez, _minimasRepeticoes, _maximasRepeticoes, _minimasEtapas, _maximaEtapas;
    //Tempo mínimo e máximo de processamento
    [SerializeField] private float _tempoMinimo, _tempoMaximo;

    //Controlador de recursos do jogo
    private RecursosController _controladorRecursos;

    //Controlador de imagem da barra de progresso
    private Image _barraProgresso;
    //Tempo processado, tempo total, quando foi a ultima etapa e intervalo até a próxima
    private float _progresso, _tempoTotal, _ultimaEtapa, _proximaEtapa;

    //Se já limpou os slots
    private bool _jaLimpou;
    //Número de etapas total, quantas já foram processados e quantos recursos está esperando para avançar
    private int _numeroDeEtapas, _etapasProcessadas, _esperandoRecursos;
    //A lista de recursos necessários para as etapas e a lista de recursos usado na última etapa
    private List<int[]> _recursosDesejados, _ultimosRecursosUsados;

    //Para calcular quando será a próxima etapa
    private void CalcularProximaEtapa()
    {
        //Salva quando começou
        _ultimaEtapa = Time.time;

        //Se ainda há etapas a serem processadas
        if (_numeroDeEtapas > _etapasProcessadas)
            //Calcula quando será a próxima, com uma pequena variação
            _proximaEtapa = _tempoTotal / _numeroDeEtapas * UnityEngine.Random.Range(0.9f, 1f);
        //Se já processou todas as etapas
        else
            //Utiliza um valor grande o suficiente para não passar por outra etapa
            _proximaEtapa = Time.time * 3;
    }

    //Para atualizar os slots de recursos
    private void AtualizarVisualRecurso(int index, Color cor)
    {
        //Atualiza a cor da image e do texto relacionados
        _slotsRecursos[index].color = cor;
        _repeticoesRecursos[index].color = cor;
    }

    //Para verificar os estados dos recursos necessários
    private void ChecarDisponiveis()
    {
        //Se algum recurso estiver barrado pelo semáforo, então a thread como um todo também estará
        bool estaBarrado = false;

        //Para cada recurso
        foreach(int[] val in _recursosDesejados)
        {
            //Se ele não já estiver alocado
            if (_slotsRecursos[_recursosDesejados.IndexOf(val)].color != Color.green)
            {
                //Verifica se está disponível
                if (_controladorRecursos.EstaDisponivel(val[0]))
                {
                    //Se sim, atualiza o recurso para dizer que está à espera
                    AtualizarVisualRecurso(_recursosDesejados.IndexOf(val), Color.yellow);

                    //Se não estiver barrado
                    if (!estaBarrado)
                        //Atualiza a cor da barra
                        _barraProgresso.color = Color.yellow;
                }
                //Se não estiver disponível
                else
                {
                    //Atualiza o recurso para dizer que está barrado
                    AtualizarVisualRecurso(_recursosDesejados.IndexOf(val), Color.red);

                    //Atualiza a cor da barra
                    _barraProgresso.color = Color.red;
                    //Salva que está barrada
                    estaBarrado = true;
                }
            }
        }
    }

    //Para limpar os recursos
    private void LimparRecursos()
    {
        //Reinstancia a lista de recursos usados na última etapa
        _ultimosRecursosUsados = new List<int[]>();

        //Para cada recurso
        for (int i = 0; i < _recursosDesejados.Count; i++)
        {
            //Diminui o número de repetições em 1
            _recursosDesejados[i][1]--;

            //Se ele tiver terminado de ser processado
            if (_recursosDesejados[i][1] <= 0)
            {
                //Para cada slot antes do último ocupado
                for (int j = i; j < _recursosDesejados.Count - 1; j++)
                {
                    //Move os dados do de cima para o de baixo
                    _slotsRecursos[j].sprite = _slotsRecursos[j + 1].sprite;
                    _slotsRecursos[j].color = _slotsRecursos[j + 1].color;
                    _repeticoesRecursos[j].text = _repeticoesRecursos[j + 1].text;
                }

                //Limpa o último ocupado
                _slotsRecursos[_recursosDesejados.Count - 1].color = Color.yellow;
                _slotsRecursos[_recursosDesejados.Count - 1].enabled = false;
                _repeticoesRecursos[_recursosDesejados.Count - 1].text = "";

                //Avisa o controlador de recursos do jogo que liberou o recurso
                _controladorRecursos.RecursoLiberado(_recursosDesejados[i][0]);

                //Salva qual recurso está sendo removido
                _ultimosRecursosUsados.Add(_recursosDesejados[i]);
                //Remove ele da lista
                _recursosDesejados.Remove(_recursosDesejados[i]);

                //Diminui i em 1 pois a lista perdeu um valor
                i--;
            }
            //Se não acabou de processar
            else
            {
                //Atualiza o número de repetições
                _repeticoesRecursos[i].text = "x" + _recursosDesejados[i][1];
            }
        }

        //Salva que já limpou
        _jaLimpou = true;
    }

    //Para pedir novos recursos
    private void PedirRecursos()
    {
        //Define que será necessária uma limpeza
        _jaLimpou = false;

        //Calcula quantos recursos novos ele quer
        //Se já tiver algum recurso restante da etapa anterior, diminui o limite e a chance de requisitar novos
        _esperandoRecursos = UnityEngine.Random.Range(_minimoRecursoPorVez - _recursosDesejados.Count, _maximoRecursoPorVez - _recursosDesejados.Count + 1);

        //Se não quiser recursos novos
        if (_esperandoRecursos <= 0)
        {
            //Define que não está esperando recursos novos
            _esperandoRecursos = 0;
            //Calcula quando será a próxima etapa
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

            //Para cada valor em _recursosDesejados, verifica se é igual ao valor relacionado ao recurso, se sim, salva que existe um valor igual
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
            //Como não podem ter valores repetidos, basta verificar o primeiro ou se sequer existe um
            if(existe)
            {
                //Se sim, remove o valor dos recursos
                possiveisRecursos.Remove(val);
                //Diminuiu i em 1 pois removeu um valor da lista do loop
                i--;
                continue;
            }

            //Para cada valor em _ultimosRecursosUsados, verifica se é igual ao valor relacionado ao recurso, se sim, salva que ele não deveria ser utilizado novamente tão cedo
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
            //Como não podem ter valores repetidos, basta verificar o primeiro ou se sequer existe um
            if (existe)
            {
                //Se sim, remove o valor dos recursos
                possiveisRecursos.Remove(val);
                //Diminuiu i em 1 pois removeu um valor da lista do loop
                i--;
                continue;
            }
        }

        //Se ele deseja mais recursos do que a quantidade de opções
        if (_esperandoRecursos > possiveisRecursos.Count)
            //Limita à pegar as opções disponíveis
            _esperandoRecursos = possiveisRecursos.Count;

        //Quantos valores ele tinha antes da adição dos novos
        int valoresJaExistentes = _recursosDesejados.Count;

        //Para cada recurso requisitado
        //i está deslocado para não interferir em slots que já possuam recursos da etapa anterior
        for (int i = valoresJaExistentes; i < _esperandoRecursos + valoresJaExistentes; i++)
        {
            //Escolhe um recurso aleatório da lista
            int recurso = possiveisRecursos[UnityEngine.Random.Range(0, possiveisRecursos.Count)];
            //Remove ele da lista
            possiveisRecursos.Remove(recurso);

            //Adiciona o recurso à lista de recursos desejados, com uma repetição aleatória dentro do limite
            _recursosDesejados.Add(new int[2] { recurso, UnityEngine.Random.Range(_minimasRepeticoes, _maximasRepeticoes + 1) });

            //Se o número de repetições com o recurso for maior que o número de etapas restantes
            if (_recursosDesejados[i][1] > _numeroDeEtapas - _etapasProcessadas)
                //Atualiza o número de repetições
                _recursosDesejados[i][1] = _numeroDeEtapas - _etapasProcessadas;

            //Ativa o slot do recurso
            _slotsRecursos[i].enabled = true;
            //Seleciona a imagem relacionada
            _slotsRecursos[i].sprite = _spritesRecursos[recurso];
            //Escreve o número de repetições
            _repeticoesRecursos[i].text = "x" + _recursosDesejados[i][1];
        }

        //Depois de salvar todos os recursos novos
        //Verifica o estado de cada um
        ChecarDisponiveis();
    }

    //Quando o jogador soltar um recurso na tela
    public void OnDrop(PointerEventData eventData)
    {
        //Para o jogador não poder alocar recursos quando o jogo está parado
        if (Time.timeScale == 0f)
            return;

        //Define qual o valor do recurso pela sua tag
        int recurso = (int)Enum.Parse(typeof(Recursos), eventData.pointerDrag.tag);

        //Para cada valor em _recursosDesejados, verifica se é igual ao valor relacionado ao recurso e, se for, salva sua posição na lista
        int pos = -1;

        for(int i = 0; i < _recursosDesejados.Count; i++)
        {
            if (_recursosDesejados[i][0] == recurso)
            {
                pos = i;
                break;
            }
        }
        
        //Se possui uma posição
        if (pos >= 0)
        {
            //Atualiza que recebeu o recurso
            AtualizarVisualRecurso(pos, Color.green);
            //Define que está esperando um a menos agora
            _esperandoRecursos--;

            //Destroy o objeto do recurso
            Destroy(eventData.pointerDrag);
            //Avisa o controlador de recursos do jogo que ele foi alocado
            _controladorRecursos.RecursoDado(recurso);

            //Se todos os recursos foram alocados
            if(_esperandoRecursos == 0)
            {
                //Calcula quando será a próxima etapa
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
                //Salva o controlador, pois pertence à barra de progresso
                _barraProgresso = item;
                break;
            }
        }

        //Zera o progresso
        _barraProgresso.fillAmount = 0;
        _progresso = 0;

        //Calcula um número de etapas aleatório
        _numeroDeEtapas = UnityEngine.Random.Range(_minimasEtapas, _maximaEtapas);
        //Define que não foram processadas nenhuma
        _etapasProcessadas = 0;
        //Calcula o tempo de processamento no intervalo
        _tempoTotal = UnityEngine.Random.Range(_tempoMinimo, _tempoMaximo);

        //Calcula quando será a próxima etapa
        CalcularProximaEtapa();

        //Define que já limpou os slots, pois eles iniciam limpos
        _jaLimpou = true;
        //Define que não está esperando nenhum recurso
        _esperandoRecursos = 0;

        //Instancia a lista de recursos necessários para as etapas
        _recursosDesejados = new List<int[]>();

        //Instancia a lista de recursos usados na última etapa
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
            //Sai da função
            return;
        }

        //Se estiver esperando recursos
        if (_esperandoRecursos > 0)
        {
            //Verifica o estado dos recursos
            ChecarDisponiveis();
            //Sai da função
            return;
        }

        //Se estiver processando

        //Verifica se está na metade da etapa
        if (_ultimaEtapa + _proximaEtapa / 2f <= Time.time && !_jaLimpou)
        {
            //Se sim, libera os recursos
            LimparRecursos();
            //Aumenta o número de etapas processadas
            _etapasProcessadas++;
        }

        //Se Concluiu a etapa
        if (_ultimaEtapa + _proximaEtapa <= Time.time)
        {
            //Pede novos recursos
            PedirRecursos();
        }
        //Senão
        else
        {
            //Aumenta o progresso
            _progresso += Time.deltaTime;
            _barraProgresso.fillAmount = _progresso / _tempoTotal;
        }
    }
}
