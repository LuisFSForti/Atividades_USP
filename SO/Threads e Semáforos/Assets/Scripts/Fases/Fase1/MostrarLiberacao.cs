using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MostrarLiberacao : MonoBehaviour
{
    //O controlador de recursos da fase
    [SerializeField] private RecursosController _controladorRecrusos;
    //O objeto da mensagem de aviso
    [SerializeField] private GameObject _avisoLiberacao;

    //A quantidade de recursos anterior
    private int _quantidadeAnterior;

    private void Start()
    {
        //Salva a quantidade de recursos disponíveis inicialmente
        _quantidadeAnterior = _controladorRecrusos.RecursosDisponiveis();
    }

    void Update()
    {
        //Se a quantidade de recursos atual for maior do que estava anteriormente (se um recurso foi liberado)
        if (_quantidadeAnterior < _controladorRecrusos.RecursosDisponiveis())
        {
            //Ativa a mensagem
            _avisoLiberacao.SetActive(true);
            //Destrói este script
            Destroy(this);
        }
        //Se não mudou ou se agora for menor
        else
        {
            //Atualiza a quantidade de recursos atuais
            _quantidadeAnterior = _controladorRecrusos.RecursosDisponiveis();
        }
    }
}
