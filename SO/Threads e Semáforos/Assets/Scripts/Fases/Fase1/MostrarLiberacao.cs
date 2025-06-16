using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MostrarLiberacao : MonoBehaviour
{
    [SerializeField] private RecursosController _controladorRecrusos;
    [SerializeField] private GameObject _avisoLiberacao;

    private int _quantidadeAnterior;

    private void Start()
    {
        _quantidadeAnterior = _controladorRecrusos.RecursosDisponiveis();
    }

    void Update()
    {
        if(_quantidadeAnterior < _controladorRecrusos.RecursosDisponiveis())
        {
            _avisoLiberacao.SetActive(true);
            Destroy(this);
        }
        else
        {
            _quantidadeAnterior = _controladorRecrusos.RecursosDisponiveis();
        }
    }
}
