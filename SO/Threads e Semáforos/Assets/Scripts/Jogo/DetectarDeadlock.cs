using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DetectarDeadlock : MonoBehaviour
{
    //A mensagem de aviso
    [SerializeField] private GameObject _mensagem;

    //A lista dos controladores de threads da fase
    private List<ThreadController> _controladoresThreads;

    //Como o teste é recursivo, há um intervalo entre testes para não sobrecarregar
    private float _ultimaVerificacao, _intervalo = 1f;

    //Teste recursivo
    private void Detectar(List<int> threadsPassadas, int threadAtual)
    {
        //Se a thread atual estiver processando, ela não pode gerar um deadlock
        if (!_controladoresThreads[threadAtual].EstaParado())
            //Sai do teste
            return;

        //A lista de recursos desejados pela thread atual
        List<int[]> desejosThread = _controladoresThreads[threadAtual].RecursosDesejados;

        //Para cada thread da fase
        for (int i = 0; i < _controladoresThreads.Count; i++)
        {
            //Se for a thread atual
            if (i == threadAtual)
                //Avança pra próxima
                continue;

            //Se ela estiver processando, não pode gerar um deadlock
            if (!_controladoresThreads[i].EstaParado())
                //Avança pra próxima
                continue;

            //A lista de recursos reservados pela thread em análise
            List<int> reservadosI = _controladoresThreads[i].RecursosReservados;

            //Para cada valor da lista de recursos desejados da thread atual
            foreach (int[] valI in desejosThread)
            {
                //Se a thread em análise tiver o recurso reservado
                if (reservadosI.Contains(valI[0]))
                {
                    //Se a thread em análise já foi processada como a thread atual
                    if(threadsPassadas.Contains(i))
                    {
                        //Foi encontrado um ciclo!!!
                        //Deadlock!!!

                        //Ativa a mensagem
                        _mensagem.SetActive(true);
                        //Destrói este script
                        Destroy(this);
                    }
                    //Se ela ainda não foi processada
                    else
                    {
                        //Adiciona a thread atual à lista de threads processadas
                        threadsPassadas.Add(threadAtual);
                        //Processa a thread em análise
                        Detectar(threadsPassadas, i);
                        //Remove a thread atual da lista de threads processadas
                        threadsPassadas.Remove(threadAtual);
                    }
                }
            }
        }
    }

    void Start()
    {
        //Encontra as threads da fase
        GameObject[] threads = GameObject.FindGameObjectsWithTag("Thread");

        //Inicaliza a lista
        _controladoresThreads = new List<ThreadController>();
        //Para cada controlador
        foreach(GameObject thread in threads)
        {
            //Salva o controlador da thread
            _controladoresThreads.Add(thread.GetComponent<ThreadController>());
        }

        //Define quando foi a última verificação
        _ultimaVerificacao = Time.time;
    }

    void Update()
    {
        //Se passou do momento de verificar novamente
        if(Time.time > _ultimaVerificacao + _intervalo)
        {
            //Define quando foi a última verificação
            _ultimaVerificacao = Time.time;

            //Procura por deadlock, iniciando em cada uma das threads
            for(int i = 0; i < _controladoresThreads.Count; i++)
                //Procura um deadlock, começando pela thread atual
                Detectar(new List<int>(), i);
        }
    }
}
