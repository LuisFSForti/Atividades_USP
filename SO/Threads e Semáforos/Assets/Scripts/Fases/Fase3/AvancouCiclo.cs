using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class AvancouCiclo : MonoBehaviour
{
    [SerializeField] private RecursosController _controladorRecursos;
    [SerializeField] private TMP_Text _texto;
    [SerializeField] private GameObject _mensagem;

    private string _textoAnterior = "";

    void Update()
    {
        if(_texto.text != _textoAnterior)
        {
            if(_controladorRecursos.TodosDisponiveis())
            {
                _textoAnterior = _texto.text;
            }
            else
            {
                _mensagem.SetActive(true);
                Destroy(this);
            }
        }
    }
}
