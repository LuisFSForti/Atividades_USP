using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class EsperandoOutrosRecursos : MonoBehaviour
{
    [SerializeField] private RecursosController _controladorRecursos;
    [SerializeField] private Image _barraProgresso;
    [SerializeField] private GameObject _mensagemEsperando;

    private void Update()
    {
        if(!_controladorRecursos.TodosDisponiveis() && _barraProgresso.color == Color.yellow)
        {
            _mensagemEsperando.SetActive(true);
        }
        if(_barraProgresso.color == Color.green)
        {
            _mensagemEsperando.SetActive(false);
            Destroy(this);
        }
    }
}
